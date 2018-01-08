/**************************************************************************//**
* @file settings.h
* @brief Contains configurable #defines and widely used constant #defines
* @version 0.0.1
******************************************************************************/


#ifndef INC_SETTINGS_H_
#define INC_SETTINGS_H_

/* Constant #defines */

#define BLUE_LED  GPIO_PIN_2
#define BUFSIZE 1024
#define SAMPLE_RATE 16000
#define FFTSIZE BUFSIZE / 2
#define MFCC_SIZE 12
#define ADC_SAMPLE_BUF_SIZE     256
#define WORD_LENGTH 57
//maybe word lenght 50?


#endif /* INC_SETTINGS_H_ */
