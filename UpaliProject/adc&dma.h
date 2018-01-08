/**************************************************************************//**
* @file mfcc.h
* @brief Contains function prototypes for adc&dma.c
* @version 1
******************************************************************************/

static uint16_t ADC_OUT[ADC_SAMPLE_BUF_SIZE];
void init_ADC(void);
static uint32_t g_ui32DMAErrCount = 0;
void uDMAErrorHandler(void);

