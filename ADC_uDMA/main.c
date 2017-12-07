#include <stdbool.h>
#include <stdint.h>

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



#define ADC_SAMPLE_BUF_SIZE     256

#pragma DATA_ALIGN(ucControlTable, 1024)
uint8_t ucControlTable[1024];

static uint16_t ADC_OUT[ADC_SAMPLE_BUF_SIZE];
uint32_t n=0;

void init_ADC(void);
static uint32_t g_ui32DMAErrCount = 0;
static uint32_t g_ui32SysTickCount;
volatile uint32_t start, stop;


void uDMAErrorHandler(void)
{
    uint32_t ui32Status;
    ui32Status = ROM_uDMAErrorStatusGet();
    if(ui32Status)
    {
        ROM_uDMAErrorStatusClear();
        g_ui32DMAErrCount++;
    }
}

void SysTick_Handler(void)
{
    //
    // Update our system tick counter.
    //
    g_ui32SysTickCount++;
}

void ADC0SS0_Handler()
{
    stop = g_ui32SysTickCount;
    ADCIntClear(ADC0_BASE, 0);
    n++;


    if(!ROM_uDMAChannelIsEnabled(UDMA_CHANNEL_ADC0))
    {
        uDMAChannelTransferSet(UDMA_CHANNEL_ADC0 | UDMA_PRI_SELECT, UDMA_MODE_BASIC, (void *)(ADC0_BASE + ADC_O_SSFIFO0), &ADC_OUT, ADC_SAMPLE_BUF_SIZE);


        uDMAChannelEnable(UDMA_CHANNEL_ADC0);
    }

    start = stop;


}

int main(void)
{

    SysCtlClockSet(SYSCTL_SYSDIV_2_5|SYSCTL_USE_PLL|SYSCTL_OSC_MAIN|SYSCTL_XTAL_16MHZ);

    SysCtlDelay(20);

    ROM_SysCtlPeripheralEnable(SYSCTL_PERIPH_TIMER0);


    SysCtlPeripheralEnable(SYSCTL_PERIPH_ADC0);    //Enable the clock to ADC module
    SysCtlDelay(10); // Time for the peripheral enable to set

    SysCtlPeripheralEnable(SYSCTL_PERIPH_UDMA);    //Enable the clock to uDMA 
    SysCtlDelay(10);

    
    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOE);   //Enables the clock to PORT E
    SysCtlDelay(30);

	ROM_SysTickPeriodSet(SysCtlClockGet() / 1000000 - 1); //Sets the period of the SysTic counter to 1us 
    ROM_SysTickIntEnable();
    ROM_SysTickEnable();

    ROM_TimerConfigure(TIMER0_BASE, TIMER_CFG_PERIODIC);
    ROM_TimerLoadSet(TIMER0_BASE, TIMER_A, 4999);   //TODO: Timer Load Value is set here
    ROM_TimerControlTrigger(TIMER0_BASE, TIMER_A, true);


    GPIOPinTypeADC(GPIO_PORTE_BASE, GPIO_PIN_2);

    SysCtlDelay(80);

    IntMasterEnable();

    init_ADC();


    ROM_TimerEnable(TIMER0_BASE, TIMER_A);

    start = g_ui32SysTickCount;



    while(1)
    {
    }
}

void init_ADC()
{

    ADCClockConfigSet(ADC0_BASE, ADC_CLOCK_SRC_PIOSC | ADC_CLOCK_RATE_HALF, 1);

    SysCtlDelay(10); // Time for the clock configuration to set

    IntDisable(INT_ADC0SS0);
    ADCIntDisable(ADC0_BASE, 0);
    ADCSequenceDisable(ADC0_BASE,0);
    // With sequence disabled, it is now safe to load the new configuration parameters

    ADCSequenceConfigure(ADC0_BASE, 0, ADC_TRIGGER_TIMER, 0);	

    ADCSequenceStepConfigure(ADC0_BASE,0,0,ADC_CTL_CH1| ADC_CTL_END | ADC_CTL_IE);

    ADCSequenceEnable(ADC0_BASE,0); //Once configuration is set, re-enable the sequencer
    ADCIntClear(ADC0_BASE,0);

    uDMAEnable(); // Enables uDMA
    uDMAControlBaseSet(ucControlTable);

    ADCSequenceDMAEnable(ADC0_BASE,0);
    // Allows DMA requests to be generated based on the FIFO level of the sample sequencer (SS0)

    uDMAChannelAttributeDisable(UDMA_CHANNEL_ADC0, UDMA_ATTR_ALTSELECT | UDMA_ATTR_HIGH_PRIORITY | UDMA_ATTR_REQMASK);

    uDMAChannelAttributeEnable(UDMA_CHANNEL_ADC0, UDMA_ATTR_USEBURST);
    // Only allow burst transfers

    uDMAChannelControlSet(UDMA_CHANNEL_ADC0 | UDMA_PRI_SELECT, UDMA_SIZE_16 | UDMA_SRC_INC_NONE | UDMA_DST_INC_16 | UDMA_ARB_1);


    uDMAChannelTransferSet(UDMA_CHANNEL_ADC0 | UDMA_PRI_SELECT, UDMA_MODE_BASIC, (void *)(ADC0_BASE + ADC_O_SSFIFO0), &ADC_OUT, ADC_SAMPLE_BUF_SIZE);


    ADCIntEnable(ADC0_BASE,0);
    IntEnable(INT_ADC0SS0);
    uDMAChannelEnable(UDMA_CHANNEL_ADC0); // Enables DMA channel so it can perform transfers

}
