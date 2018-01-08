#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#include "settings.h"
#include "mfcc.h"
//#include "sampler.h"

#include "forward.h"

#include "inc/hw_ints.h"
#include "inc/hw_memmap.h"
#include "inc/hw_adc.h"
#include "inc/hw_types.h"
#include "inc/hw_udma.h"
#include "inc/hw_emac.h"
#include "driverlib/debug.h"
#include "driverlib/gpio.h"
#include "driverlib/interrupt.h"
#include "driverlib/pin_map.h"
#include "driverlib/sysctl.h"
#include "driverlib/uart.h"
#include "driverlib/adc.h"
#include "driverlib/udma.h"
#include "driverlib/emac.h"
#include "driverlib/timer.h"
#include "driverlib/rom.h"

void UDMAERR_Handler(void);
void SysTick_Handler(void);
void ADC0SS0_Handler(void);

void init_ADC(void);
void init_peripherals(void);

#pragma DATA_ALIGN(ucControlTable, 1024)
uint8_t ucControlTable[1024];
uint32_t n = 0;
uint32_t g_ui32DMAErrCount = 0;
uint32_t g_ui32SysTickCount = 0;
int16_t ADC_OUT_0[ADC_SAMPLE_BUF_SIZE];
int16_t ADC_OUT_1[ADC_SAMPLE_BUF_SIZE];
uint8_t ucControlTable[1024];
volatile uint32_t start, stop;


/*--------------------------------------------------------------------
* External Input and Output buffer Declarations used as an example
* --------------------------------------------------------------------*/
static float32_t input_f32_16khz[BUFSIZE];
float32_t features[MFCC_SIZE];
volatile uint32_t ind = 0;
extern float32_t testInput_f32_10khz[1024];

// start
float32_t exponents[12];
float32_t differences[12];
float32_t exponents_sum;
float32_t ones_b[12];
float32_t probability = 0;

float32_t b[4];
float32_t alphas_f32[4];
float32_t alphas_prev_f32[4];
float32_t scale;

arm_matrix_instance_f32 A;
arm_matrix_instance_f32 alphas_prev;
arm_matrix_instance_f32 alphas;

float32_t ones_a[4];
//end
static float32_t observations[WORD_LENGTH][MFCC_SIZE];  // Pass-through buffer for observations
static float32_t a = 0;
static int min = 0;
static uint32_t time = 0;
static float32_t a_old = 0;

int main(void)
{
	
	uint8_t boot_up;
	int i, j, k, p;
	uint32_t n_prev = 0;
	float32_t halved_frame[256];		// Place to store (ADC_OUT - 2047) * 3.3 / 4095
	float32_t halved_frame_prev[256]; // Place for above's previous value, after it's been updated
	float32_t ADC_median[256];			// Has all the 2047
	float32_t power = 0;
	float32_t powers[WORD_LENGTH];
	static float32_t min_power = 0;
  uint8_t skip = 1;
	static uint32_t plavo = 0;
	
	i = 0;													// Index for the pass-trough buffer
	p = 0;
	// Sets the clock to 80MHz
	SysCtlClockSet(SYSCTL_SYSDIV_2_5|SYSCTL_USE_PLL|SYSCTL_OSC_MAIN|SYSCTL_XTAL_16MHZ);
	SysCtlDelay(20);
	
		// Initialize everything that is necessary
	init_peripherals();
	
	arm_fill_f32(2047, ADC_median, 256);


	boot_up = 56;   // remove?
	
	init_forward();
	arm_fill_f32(0, input_f32_16khz, BUFSIZE);  //starting point, i.e., all 0s
	

	
	
	while(1)
	{
		if(n == n_prev)		// Wait until there is a new sample batch ready
			continue;
		
		// Following is due to PING_PONG DMA
		if(n%2 == 1){
			for(j = 0; j < 256; j++)
				halved_frame[j] = ADC_OUT_0[j];
			//arm_q15_to_float(ADC_OUT_0, halved_frame, 256);
		}
		else {
			for(j = 0; j < 256; j++)
				halved_frame[j] = ADC_OUT_1[j];
			
		}

		//arm_scale_f32(halved_frame, 32768, halved_frame, 256);	//necessary for conversion
		arm_sub_f32(halved_frame, ADC_median, halved_frame, 256);
		
		// Normalize ADC data
		arm_scale_f32(halved_frame, 8.0586081e-04, halved_frame, 256);
		
		// Copy the second half, of the expanded input, over to the first half
		//memcpy(input_f32_16khz, input_f32_16khz + 512, (512 * sizeof(*input_f32_16khz)));
		
		arm_fill_f32(0, input_f32_16khz, BUFSIZE);
		// Now copy the halved_frame over the second half
		for(j = 0; j < 256; j++){
			input_f32_16khz[j * 2] = halved_frame_prev[j];
			input_f32_16khz[512 + j * 2] = halved_frame[j];
		}
		
		arm_copy_f32(halved_frame, halved_frame_prev, 256);
		//arm_copy_f32(testInput_f32_10khz, input_f32_16khz, 1024);
		
		
		getMFCC(input_f32_16khz, features, &powers[i]);
		
		//if(powers[p] > 1.0f)
			//ind = 1;
		memcpy(observations[i], features, 12 * sizeof(*features));

		i = (i + 1) % WORD_LENGTH;
		
		
		if(boot_up > 0){
			boot_up--;
			continue;
		}
		
		arm_copy_f32(start_prob, alphas_f32, 4);
		arm_copy_f32(alphas_f32, alphas_prev_f32, 4);
		probability = 0;
		for(j = i; j < WORD_LENGTH; j++){
			if(skip){
				skip = 0;
				continue;
			}
			emission(j, b);
			forward_step();
		}
		for(k = 0; k < i; k++){
			if(skip){
				skip = 0;
				continue;
			}
			emission(k, b);
			forward_step();
		}
		skip = 1;   // it's used to skip the first coefficient
		
		
		arm_mean_f32(powers, WORD_LENGTH, &min_power);
		
		n_prev = n;
		if(!isinf(probability) && !isnan(probability))
			a = probability;
		if(0.45f > min_power && min_power > 0.25f)
			min++;
		if(a > 1000.0f && a < 1100.0f && (0.45f > min_power && min_power > 0.25f)){
			plavo++;
			a_old = a;}
			


		
	}
	
}

void init_forward()
{
	arm_fill_f32(1, ones_a, 4);
	arm_fill_f32(1, ones_b, 12);
	arm_mat_init_f32(&A, 4, 4, transitions);
	// Unnecessary because of the scaling
	//emission(0, b);
	//arm_mult_f32(start_prob, b, alphas_prev, 4);
	arm_copy_f32(start_prob, alphas_f32, 4);
	
	arm_mat_init_f32(&alphas_prev, 1, 4, alphas_prev_f32);
	arm_mat_init_f32(&alphas, 1, 4, alphas_f32);
	//arm_copy_f32(alphas_f32, alphas_prev_f32, 4);
}

void emission(int t, float32_t *b)
{
		for(int i=0; i<4; i++)
	{
		arm_sub_f32(observations[t], means[i], differences, 12);
		arm_mult_f32(differences, differences, differences, 12);
		arm_mult_f32(differences, denominators[i], exponents, 12);
		arm_dot_prod_f32(exponents, ones_b, 12, &exponents_sum);
		exponents_sum = -exponents_sum;
		b[i] = expf(exponents_sum);
		b[i] *= covars_norm[i];
	}
}

void forward_step(void) {
		arm_mat_mult_f32(&alphas_prev, &A, &alphas);

		arm_mult_f32(alphas_f32, b, alphas_f32, 4);
		arm_dot_prod_f32(alphas_f32, ones_a, 4, &scale);
		//if(alphas_f32[0] != alphas_f32[0])
			//ind = 1;
		scale = 1 / scale;
		arm_scale_f32(alphas_f32, scale, alphas_f32, 4);
		probability += logf(scale);
		arm_copy_f32(alphas_f32, alphas_prev_f32, 4);
}

void UDMAERR_Handler()
{
    uint32_t ui32Status;
    ui32Status = ROM_uDMAErrorStatusGet();
    if(ui32Status)
    {
        ROM_uDMAErrorStatusClear();
        g_ui32DMAErrCount++;
    }
}
void SysTick_Handler()
{
    //
    // Update our system tick counter.
    //
    g_ui32SysTickCount++;
}

void ADC0SS0_Handler()
{
		volatile uint32_t ui32Mode;
    stop = g_ui32SysTickCount;
    ADCIntClear(ADC0_BASE, 0);
    n++;
		
    ui32Mode = ROM_uDMAChannelModeGet(UDMA_CHANNEL_ADC0 | UDMA_PRI_SELECT);
    if(ui32Mode == UDMA_MODE_STOP)
    {
				uDMAChannelTransferSet(UDMA_CHANNEL_ADC0 | UDMA_PRI_SELECT, UDMA_MODE_PINGPONG, (void *)(ADC0_BASE + ADC_O_SSFIFO0), &ADC_OUT_0, ADC_SAMPLE_BUF_SIZE);


        uDMAChannelEnable(UDMA_CHANNEL_ADC0);
    }

		ui32Mode = ROM_uDMAChannelModeGet(UDMA_CHANNEL_ADC0 | UDMA_ALT_SELECT);
    if(ui32Mode == UDMA_MODE_STOP)
    {
				uDMAChannelTransferSet(UDMA_CHANNEL_ADC0 | UDMA_ALT_SELECT, UDMA_MODE_PINGPONG, (void *)(ADC0_BASE + ADC_O_SSFIFO0), &ADC_OUT_1, ADC_SAMPLE_BUF_SIZE);


        uDMAChannelEnable(UDMA_CHANNEL_ADC0);
    }
    start = stop;


}

void init_peripherals()
 {
	 ROM_SysCtlPeripheralEnable(SYSCTL_PERIPH_TIMER0);


    ROM_SysCtlPeripheralEnable(SYSCTL_PERIPH_ADC0);    // Enable the clock to ADC module
    SysCtlDelay(10); // Time for the peripheral enable to set

    ROM_SysCtlPeripheralEnable(SYSCTL_PERIPH_UDMA);    // Enable the clock to uDMA 
    SysCtlDelay(10);

    
    ROM_SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOE);   // Enables the clock to PORT E
    SysCtlDelay(30);

	  ROM_SysTickPeriodSet(SysCtlClockGet() / 1000000 - 1); // Sets the period of the SysTic counter to 1us 
    ROM_SysTickIntEnable();
    ROM_SysTickEnable();

    ROM_TimerConfigure(TIMER0_BASE, TIMER_CFG_PERIODIC);
    ROM_TimerLoadSet(TIMER0_BASE, TIMER_A, 4999);   // Timer Load Value is set here. 16kHz
    ROM_TimerControlTrigger(TIMER0_BASE, TIMER_A, true);

		
    GPIOPinTypeADC(GPIO_PORTE_BASE, GPIO_PIN_2); // Configures PE2 for use as ADC input

    SysCtlDelay(80);

    ROM_IntMasterEnable();

    init_ADC();

    ROM_TimerEnable(TIMER0_BASE, TIMER_A);
		
		start = g_ui32SysTickCount;
 }
/* @brief Enables ADC and uDMA
 * It's setting an interrupt to happen every 256 samples.
 */
void init_ADC()
{

    ADCClockConfigSet(ADC0_BASE, ADC_CLOCK_SRC_PIOSC | ADC_CLOCK_RATE_HALF, 1);

    SysCtlDelay(10); // Time for the clock configuration to set

    IntDisable(INT_ADC0SS0);
    ADCIntDisable(ADC0_BASE, 0);
    ROM_ADCSequenceDisable(ADC0_BASE,0);
    // With sequence disabled, it is now safe to load the new configuration parameters

    ROM_ADCSequenceConfigure(ADC0_BASE, 0, ADC_TRIGGER_TIMER, 0);	

    ROM_ADCSequenceStepConfigure(ADC0_BASE,0,0,ADC_CTL_CH1| ADC_CTL_END | ADC_CTL_IE);

    ROM_ADCSequenceEnable(ADC0_BASE,0); //Once configuration is set, re-enable the sequencer
    ROM_ADCIntClear(ADC0_BASE,0);

    uDMAEnable(); // Enables uDMA
    uDMAControlBaseSet(ucControlTable);

    ADCSequenceDMAEnable(ADC0_BASE,0);
    // Allows DMA requests to be generated based on the FIFO level of the sample sequencer (SS0)

    uDMAChannelAttributeDisable(UDMA_CHANNEL_ADC0, UDMA_ATTR_ALTSELECT | UDMA_ATTR_HIGH_PRIORITY | UDMA_ATTR_REQMASK);

    uDMAChannelAttributeEnable(UDMA_CHANNEL_ADC0, UDMA_ATTR_USEBURST);
    // Only allow burst transfers

    uDMAChannelControlSet(UDMA_CHANNEL_ADC0 | UDMA_PRI_SELECT, UDMA_SIZE_16 | UDMA_SRC_INC_NONE | UDMA_DST_INC_16 | UDMA_ARB_1);
    uDMAChannelControlSet(UDMA_CHANNEL_ADC0 | UDMA_ALT_SELECT, UDMA_SIZE_16 | UDMA_SRC_INC_NONE | UDMA_DST_INC_16 | UDMA_ARB_1);


    uDMAChannelTransferSet(UDMA_CHANNEL_ADC0 | UDMA_PRI_SELECT, UDMA_MODE_PINGPONG, (void *)(ADC0_BASE + ADC_O_SSFIFO0), &ADC_OUT_0, ADC_SAMPLE_BUF_SIZE);
    uDMAChannelTransferSet(UDMA_CHANNEL_ADC0 | UDMA_ALT_SELECT, UDMA_MODE_PINGPONG, (void *)(ADC0_BASE + ADC_O_SSFIFO0), &ADC_OUT_1, ADC_SAMPLE_BUF_SIZE);



    ADCIntEnable(ADC0_BASE,0);
    IntEnable(INT_ADC0SS0);
    uDMAChannelEnable(UDMA_CHANNEL_ADC0); // Enables DMA channel so it can perform transfers

}