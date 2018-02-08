#include <stdbool.h>
//#include <stdint.h>
#include <stdio.h>
#include <string.h>

#include "driverlib/sysctl.h"
#include "settings.h"
#include "sampler.h"
#include "arm_math.h"
#include "forward.h"

#include "mfcc.h"
#include "arm_const_structs.h"

//int16_t data[7168];  //TEST: SOUND
uint32_t n_prev=0;		//TEST: SOUND
extern float32_t signal[1024];
extern float32_t probability;
extern float32_t alphas_prev_f32[4];
static float32_t prob;

int main(void)
{
	//uint32_t i = 0;			//TEST: SOUND
	//char num[6];				//TEST: SOUND
	int i = 0;
	int j, k;
	float32_t features[MFCC_SIZE];
	float32_t powers[WORD_LENGTH];
	float32_t observations[WORD_LENGTH][MFCC_SIZE];
	float32_t halved_frame[256];		// Place to store (ADC_OUT - 2047) * 3.3 / 4095
	float32_t halved_frame_prev[256]; // Place for above's previous value, after it's been updated
	float32_t input_f32_16khz[1024];
	uint8_t skip = 1;
	float32_t power_mean;
	
	
	double start_power = 1.0;
  double end_power = 1.0;
	uint8_t cnt1, cnt2;
	
	uint16_t count = 0;
	
	init_peripherals();
	init_forward();
	
	// 3.3 / 4095 * 32768  !!!
//
//	TEST: SOUND
//
//	while(i < 28)
//	{
//		if(n != n_prev)
//		{
//			if(n%2 == 1) {
//			
//			memcpy(data + i*256, ADC_OUT_0, 256 * sizeof(*ADC_OUT_0));
//			n_prev = n;
//			i++;
//			} 
//			else {
//			memcpy(data + i*256, ADC_OUT_1, 256 * sizeof(*ADC_OUT_1));
//			n_prev = n;
//			i++;
//			}
//		}
//	}
//	if(i==28)
//	{
//		for(i=0; i<7168; i++)
//		{
//			sprintf(num, "%d", data[i]);
//			strcat(num, "\n\r");
//			UARTSend((int8_t *)num);
//		}
//	}
//	
//	
//	for(i = 0; i < 28; i++)
//	{
//		if( n != n_prev){
//			arm_fill_f32(0, signal1, 1024);
//			for(int j = 0; j < 512; j++)
//				signal1[2 * j] = (data[i * 256 + j] - 2047) * 26.40644688;
//			
//			get_MFCC(signal1, features, powers);
//			memcpy(observations[i], features, 12 * sizeof(*features));
//		}
//	}
	
	while(1){
		
		if(n == n_prev)		// Wait until there is a new sample batch ready
			continue;
		// Following is due to PING_PONG DMA
		if(n%2 == 1){
			for(j = 0; j < 256; j++){
				halved_frame[j] = (ADC_OUT_0[j] - 2047) * 8.058608e-4;
			}
		}
		else {
			for(j = 0; j < 256; j++){
				halved_frame[j] = (ADC_OUT_1[j] - 2047) * 8.058608e-4;
			}
		}
		
		arm_fill_f32(0, input_f32_16khz, BUFSIZE); // Initialize the input array to 0s
		// The 'input_f32_16khz' is a complex array, and because its values are real,
		// every second element is 0. It's were we store the frame
		// 'halved_frame_prev' covers the first half of the array (256) samples, and
		// 'halved_frame' covers the second half (256 + 256 = 512 samples)
		for(j = 0; j < 256; j++){
			input_f32_16khz[j * 2] = halved_frame_prev[j];
			input_f32_16khz[512 + j * 2] = halved_frame[j];
		}
		memcpy(halved_frame_prev, halved_frame, 256 * sizeof(*halved_frame));
		
		get_MFCC(input_f32_16khz, features, powers + i);
		//memcpy(observations[i], features, 12 * sizeof(*features));
		arm_copy_f32(features, observations[i], 12);
		
//		if(features[0] > 40.0)
//			n = n;
		i = (i + 1) % WORD_LENGTH;
		
		arm_copy_f32(start_prob, alphas_prev_f32, 4);
		probability = 0;
		
		cnt1=0;
		cnt2=0;
		start_power = 1.1;
		end_power = 1.5;
		for(j = i; j < WORD_LENGTH; j++){
			if(skip){
				skip = 0;
				continue;
			}
			if(cnt1<4){
				start_power = (float32_t)(start_power + (powers[j] * powers[j]));
				cnt1++;}
			else if(cnt2 < 4){
				end_power += (double)(powers[j] * powers[j]);
				cnt2++;}
			emission(observations[j]);
			forward_step();
		}
		for(k = 0; k < i; k++){
			if(skip){
				skip = 0;
				continue;
			}
			if(cnt1<4){
				start_power += powers[k] * powers[k];
				cnt1++;}
			else if(cnt2 < 4){
				end_power += powers[k] * powers[k];
				cnt2++;}
			emission(observations[k]);
			forward_step();
		}
		skip = 1;   // it's used to skip the first coefficient
		
		
		prob = probability;
		
		if(prob < 600.0f && start_power > 0.35f && end_power > 0.35f)
			count++;
		n_prev = n;
	}
	while(1){}
	
}
