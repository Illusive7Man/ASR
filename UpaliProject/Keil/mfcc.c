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

// For MFCC Delta Calculation
#define n 2

/// Factors that decrease the influence of higher order coefficients,
/// as they contain less significant information.
/// Also builds in a normalization factor of sqrt(2/FFTSIZE) for the DCT
static const double influenceFactors[12] = {0.0945,
																							0.0945,
																							0.084,
																							0.0756,
																							0.0687,
																							0.0581,
																							0.054,
																							0.0504,
																							0.0445,
																							0.0398,
																							0.036,
																							0.0329};

// Center frequencies of the filters
const int centerFreq[28] = {9,	13,	17,	21,	26,	31,	37,	44,	51,	59,	68,	78,	89,	101,	115,	130,	147,	166,	187,	210,	235,	263,	295,	330,	369,	412,	459,	512};
	
	
/* @brief
 * @param[in] spectralData Mel-Scaled FFT data to be used in coefficient calculation
 * @param[out] coeffs Pointer to output array for MFCCs
 * @param[in] S DCT4 Initialized Instance (Adapted to be used in DCT2)
 * @param[in] stateDCT state buffer for DCT function
 */
void getMFCC(float32_t *dataf, float32_t *datamfcc)
{
	float32_t datafft[BUFSIZE / 2]; // FFT output data with only real
	float32_t filter[FFTSIZE];
	uint8_t ind = 0;
	float32_t coeff;
	arm_sqrt_f32(1 / 6, &coeff);
	float32_t mk;
	
	// Set coefficients to 0
	//arm_fill_f32(0, datamfcc, 14);

	/* Process the data through the CFFT/CIFFT module */
  arm_cfft_f32(&arm_cfft_sR_f32_len512, dataf, INVERSE_FFT, REVERSE_BIT);
	arm_cmplx_mag_f32(dataf, datafft, FFTSIZE);
	datafft[FFTSIZE-1] = 0; // Edit out spike at end of FFT data
	

	
	for(int i = 0; i < 14; i ++){
		arm_fill_f32(0, filter, FFTSIZE); //Initialize the filter with 0's
		//Because riangular filters have only 50% overlap,
		//they can be divided into 2 arrays
		//and using the center frequencies to index into those arrays
		//and extract original triangular filters
		if(ind) {
		  // Odd Triangular filters
			memcpy(filter + centerFreq[i], filterbank2 + centerFreq[i], 
			(centerFreq[i + 2] - centerFreq[i]) * sizeof(float32_t));
			ind = 0;
		}
		else {
			// Even Triangular filters
			memcpy(filter + centerFreq[i], filterbank1 + centerFreq[i], 
			(centerFreq[i + 2] - centerFreq[i]) * sizeof(*filterbank1));
			ind = 1;
	  }
		arm_dot_prod_f32(datafft, filter, FFTSIZE, &mk);
		
		// Adjusting the coefficient for the first mk
	  if( i == 0)
			mk /= 0.70710f;
		
		// Calculate and store the coefficients
		// Didn't use 'cos' due to memory limitations
		for(int j = 0; j< 12; j++) {		
			datamfcc[j] += logf(mk) * cosines[j][i];	
		}
	} 
	
	// Scale MFCCs to reduce influence of higher order coefficients
  // and normalize using factor sqrt(2/N)
	for(int j = 0; j < 12; j++)
	  datamfcc[j] = datamfcc[j] * influenceFactors[j];
	
	float32_t dCoeff = 0.0f;
  datamfcc[12] = datamfcc[1] - datamfcc[0];
  datamfcc[13] = datamfcc[2] - datamfcc[1];
  for(int i = n; i < (12); i++) {
    for(int j = 1; j <= n; j++) {
      dCoeff += j * (datamfcc[i+j] - datamfcc[i-j]);
    }
    dCoeff /= 10.0f; // Replaces bottom fraction of delta equation
    datamfcc[i+12] = dCoeff;
  }

}
