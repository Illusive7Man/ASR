/**************************************************************************//**
* @file mfcc.h
* @brief Contains function prototypes for mfcc.c
* @version 0.0.1
******************************************************************************/

#ifndef DSP_MFCC_H_
#define DSP_MFCC_H_

#include "arm_math.h"

void getMFCC(float32_t *dataf, float32_t *datamfcc);

#endif /* DSP_MFCC_H_ */
