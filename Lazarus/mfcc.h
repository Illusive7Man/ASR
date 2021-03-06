/**************************************************************************//**
* @file mfcc.h
* @brief Contains function prototypes for mfcc.c
* @version 1
******************************************************************************/

#ifndef DSP_MFCC_H_
#define DSP_MFCC_H_

#include "arm_math.h"

void get_MFCC(float32_t *dataf, float32_t *datamfcc, float32_t *);

#endif /* DSP_MFCC_H_ */
