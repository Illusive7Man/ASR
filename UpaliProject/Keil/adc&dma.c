/**************************************************************************//**
* @file mfcc.c
* @brief Initiates ADC, along with uDMA
* @version 0.0.1
******************************************************************************/

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
#include "settings.h"
#include "adc&dma.h"


#pragma DATA_ALIGN(ucControlTable, 1024)
uint8_t ucControlTable[1024];


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


    uDMAChannelTransferSet(UDMA_CHANNEL_ADC0 | UDMA_PRI_SELECT, UDMA_MODE_BASIC, (void *)(ADC0_BASE + ADC_O_SSFIFO0), &ADC_OUT, ADC_SAMPLE_BUF_SIZE);


    ADCIntEnable(ADC0_BASE,0);
    IntEnable(INT_ADC0SS0);
    uDMAChannelEnable(UDMA_CHANNEL_ADC0); // Enables DMA channel so it can perform transfers

}