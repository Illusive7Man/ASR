/**************************************************************************//**
* @file mfcc.c
* @brief Calculates MFCCs from raw data
* @version 0.0.1
******************************************************************************/

#include <stdlib.h>
#include <string.h>
#include "arm_math.h"
#include "arm_const_structs.h"
#include "mfcc.h"
#include "settings.h"
#include "melfilterconfig.h"

// Compute forward FFT
#define INVERSE_FFT 0
#define REVERSE_BIT 1

// Center frequencies of the filters
const int centerFreq[28] = {10,  12,  15,  18,  21,  25,  29,  33,  38,  43,  49,  54,  61,
        68,  75,  84,  93, 102, 113, 124, 136, 150, 164, 180, 196, 215, 235, 255};
	
/* @brief
 * @param[in] spectralData Mel-Scaled FFT data to be used in coefficient calculation
 * @param[out] coeffs Pointer to output array for MFCCs
 * @param[in] S DCT4 Initialized Instance (Adapted to be used in DCT2)
 * @param[in] stateDCT state buffer for DCT function
 */
void get_MFCC(float32_t *dataf, float32_t *datamfcc, float32_t *power)
{
	float32_t datafft[BUFSIZE / 2]; // FFT output data with only real values
	float32_t filter[FFTSIZE];
	uint8_t ind = 0;
	float32_t mk;
	float32_t sum = 0;
	float32_t bs[FFTSIZE];
	
	// Liftering coefficients * sqrt(2/N)
	float32_t lift[12] = {1.1357290,  1.5408959,  1.9178372,  2.2581328,  2.554181, 2.7993685,  2.9882183,  3.1165118,
                        3.1813831,  3.1813831, 3.1165118,  2.9882183};

	// Set coefficients to 0
	// This might be unnecessary, but maybe...
	arm_fill_f32(0, datamfcc, 12);

	/* Process the data through the CFFT/CIFFT module */
  arm_cfft_f32(&arm_cfft_sR_f32_len512, dataf, INVERSE_FFT, REVERSE_BIT);
	arm_cmplx_mag_f32(dataf, datafft, FFTSIZE);
	//datafft[FFTSIZE-1] = 0; // Edit out spike at end of FFT data
	

	arm_fill_f32(1, bs, FFTSIZE);
	for(int i = 0; i < 26; i ++){
		arm_fill_f32(0, filter, FFTSIZE); //Initialize the filter with 0's
		//Because riangular filters have only 50% overlap,
		//they can be divided into 2 arrays
		//and using the center frequencies to index into those arrays
		//and extract original triangular filters
		if(ind) {
		  // Odd Triangular filters
			memcpy(filter + centerFreq[i], filterbank2 + centerFreq[i], 
			(centerFreq[i + 2] - centerFreq[i]) * sizeof(*filterbank2));
			ind = 0;
		}
		else {
			// Even Triangular filters
			memcpy(filter + centerFreq[i], filterbank1 + centerFreq[i], 
			(centerFreq[i + 2] - centerFreq[i]) * sizeof(*filterbank1));
			ind = 1;
	  }
		arm_dot_prod_f32(filter, bs, FFTSIZE, &sum);
		if(sum > 50)
			ind = ind;
		arm_dot_prod_f32(datafft, filter, FFTSIZE, &mk);
		
		// Calculate and store the coefficients
		// Didn't use a cosines function due to memory limitations,
		// but, instead, the pre-calculated values
		for(int j = 0; j< 12; j++) {		
			datamfcc[j] += logf(mk)* cosines[j][i];	
		}
		
		//Accounting for the fact that a0 = sqrt(1/N)
		if(i == 0)
			arm_scale_f32(datamfcc, 0.7071067, datamfcc, 12);
	} 
	
	// Liftering with L=22 and normalizing with sqrt(2/N)
	//arm_mult_f32(datamfcc, lift, datamfcc, 12);
	// Calculating the energy (won't be using this one
  arm_mean_f32(datafft, FFTSIZE, power); 

}
