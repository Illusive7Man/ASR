#include "parameters.h"
#include "arm_math.h"

void init_forward(void);
void emission(float32_t *observation);
void forward_step(void);

extern float32_t probability;