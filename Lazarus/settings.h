/**************************************************************************//**
* @file settings.h
* @brief Contains configurable #defines and widely used constant #defines
* @version 0.0.1
******************************************************************************/


#ifndef INC_SETTINGS_H_
#define INC_SETTINGS_H_

/* Constant #defines */

#define BLUE_LED  GPIO_PIN_2
#define GREEN_LED GPIO_PIN_3
#define BUFSIZE 1024
#define SAMPLE_RATE 16000
#define FFTSIZE BUFSIZE / 2
#define MFCC_SIZE 12
#define ADC_SAMPLE_BUF_SIZE     256
#define WORD_LENGTH 30
//maybe word lenght 50?

#define GPIO_PORTF_DATA_R       (*((volatile unsigned long *)0x400253FC))
#define GPIO_PORTF_DIR_R        (*((volatile unsigned long *)0x40025400))
#define GPIO_PORTF_AFSEL_R      (*((volatile unsigned long *)0x40025420))
#define GPIO_PORTF_PUR_R        (*((volatile unsigned long *)0x40025510))
#define GPIO_PORTF_DEN_R        (*((volatile unsigned long *)0x4002551C))
#define GPIO_PORTF_LOCK_R       (*((volatile unsigned long *)0x40025520))
#define GPIO_PORTF_CR_R         (*((volatile unsigned long *)0x40025524))
#define GPIO_PORTF_AMSEL_R      (*((volatile unsigned long *)0x40025528))
#define GPIO_PORTF_PCTL_R       (*((volatile unsigned long *)0x4002552C))
#define SYSCTL_RCGC2_R          (*((volatile unsigned long *)0x400FE108))

#endif /* INC_SETTINGS_H_ */
