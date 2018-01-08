#include <stdlib.h>
#include "arm_math.h"
#include "arm_const_structs.h"
#include "parameters.h"
#include "forward.h"


float32_t exponents[12];
float32_t differences[12];
float32_t exponents_sum;
float32_t ones_b[12];
float32_t probability = 0;

float32_t b[4];
float32_t alphas_f32[4];
float32_t alphas_prev_f32[4];
float32_t scale;

arm_matrix_instance_f32 A;
arm_matrix_instance_f32 alphas_prev;
arm_matrix_instance_f32 alphas;

float32_t ones_a[4];

void init_forward()
{
	arm_fill_f32(1, ones_a, 4);
	arm_fill_f32(1, ones_b, 12);
	arm_mat_init_f32(&A, 4, 4, transitions);
	// Unnecessary because of the scaling
	//emission(0, b);
	//arm_mult_f32(start_prob, b, alphas_prev, 4);
	arm_copy_f32(start_prob, alphas_f32, 4);
	
	arm_mat_init_f32(&alphas_prev, 1, 4, alphas_prev_f32);
	arm_mat_init_f32(&alphas, 1, 4, alphas_f32);
	arm_copy_f32(alphas_f32, alphas_prev_f32, 4);
}

void emission(int t, float32_t *b)
{
		for(int i=0; i<4; i++)
	{
		arm_sub_f32(mfcc[t], means[i], differences, 12);
		arm_mult_f32(differences, denominators[i], exponents, 12);
		arm_dot_prod_f32(exponents, ones_b, 12, &exponents_sum);
		exponents_sum = -exponents_sum;
		b[i] = expf(exponents_sum);
		b[i] *= covars_norm[i];
	}
}

void forward_step(void) {
		arm_mat_mult_f32(&alphas_prev, &A, &alphas);
		arm_mult_f32(alphas_f32, b, alphas_f32, 4);
		arm_dot_prod_f32(alphas_f32, ones_a, 4, &scale);
		scale = 1 / scale;
		arm_scale_f32(alphas_f32, scale, alphas_f32, 4);
		probability += logf(scale);
		arm_copy_f32(alphas_f32, alphas_prev_f32, 4);
}