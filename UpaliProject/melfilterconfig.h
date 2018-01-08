/**************************************************************************//**
* @file melfilterconfig.h
* @brief Contains Mel Filterbank for use in mfcc.c
* @version 0.0.1
******************************************************************************/


#ifndef INC_MELFILTERCONFIG_H_
#define INC_MELFILTERCONFIG_H_

#include "settings.h"

float32_t filterbank2[256] = {
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0.3333333,
0.6666667,
1,
0.6666667,
0.3333333,
0,
0.3333333,
0.6666667,
1,
0.75,
0.5,
0.25,
0,
0.25,
0.5,
0.75,
1,
0.75,
0.5,
0.25,
0,
0.2,
0.4,
0.6,
0.8,
1,
0.8,
0.6,
0.4,
0.2,
0,
0.1666667,
0.3333333,
0.5,
0.6666667,
0.8333333,
1,
0.8,
0.6,
0.4,
0.2,
0,
0.1428571,
0.2857143,
0.4285714,
0.5714286,
0.7142857,
0.8571429,
1,
0.8571429,
0.7142857,
0.5714286,
0.4285714,
0.2857143,
0.1428571,
0,
0.1428571,
0.2857143,
0.4285714,
0.5714286,
0.7142857,
0.8571429,
1,
0.8888889,
0.7777778,
0.6666667,
0.5555556,
0.4444444,
0.3333333,
0.2222222,
0.1111111,
0,
0.1111111,
0.2222222,
0.3333333,
0.4444444,
0.5555556,
0.6666667,
0.7777778,
0.8888889,
1,
0.8888889,
0.7777778,
0.6666667,
0.5555556,
0.4444444,
0.3333333,
0.2222222,
0.1111111,
0,
0.0909091,
0.1818182,
0.2727273,
0.3636364,
0.4545455,
0.5454545,
0.6363636,
0.7272727,
0.8181818,
0.9090909,
1,
0.9090909,
0.8181818,
0.7272727,
0.6363636,
0.5454545,
0.4545455,
0.3636364,
0.2727273,
0.1818182,
0.0909091,
0,
0.0833333,
0.1666667,
0.25,
0.3333333,
0.4166667,
0.5,
0.5833333,
0.6666667,
0.75,
0.8333333,
0.9166667,
1,
0.9285714,
0.8571429,
0.7857143,
0.7142857,
0.6428571,
0.5714286,
0.5,
0.4285714,
0.3571429,
0.2857143,
0.2142857,
0.1428571,
0.0714286,
0,
0.0714286,
0.1428571,
0.2142857,
0.2857143,
0.3571429,
0.4285714,
0.5,
0.5714286,
0.6428571,
0.7142857,
0.7857143,
0.8571429,
0.9285714,
1,
0.9375,
0.875,
0.8125,
0.75,
0.6875,
0.625,
0.5625,
0.5,
0.4375,
0.375,
0.3125,
0.25,
0.1875,
0.125,
0.0625,
0,
0.0625,
0.125,
0.1875,
0.25,
0.3125,
0.375,
0.4375,
0.5,
0.5625,
0.625,
0.6875,
0.75,
0.8125,
0.875,
0.9375,
1,
0.9473684,
0.8947368,
0.8421053,
0.7894737,
0.7368421,
0.6842105,
0.6315789,
0.5789474,
0.5263158,
0.4736842,
0.4210526,
0.3684211,
0.3157895,
0.2631579,
0.2105263,
0.1578947,
0.1052632,
0.0526316,
0,
0.05,
0.1,
0.15,
0.2,
0.25,
0.3,
0.35,
0.4,
0.45,
0.5,
0.55,
0.6,
0.65,
0.7,
0.75,
0.8,
0.85,
0.9,
0.95,
1,
0.952381,
0.9047619,
0.8571429,
0.8095238,
0.7619048,
0.7142857,
0.6666667,
0.6190476,
0.5714286,
0.5238095,
0.4761905,
0.4285714,
0.3809524,
0.3333333,
0.2857143,
0.2380952,
0.1904762,
0.1428571,
0.0952381,
0.047619};

float32_t filterbank1[256] = {
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0.3333333,
0.6666667,
1,
0.6666667,
0.3333333,
0,
0.3333333,
0.6666667,
1,
0.6666667,
0.3333333,
0,
0.25,
0.5,
0.75,
1,
0.75,
0.5,
0.25,
0,
0.25,
0.5,
0.75,
1,
0.8,
0.6,
0.4,
0.2,
0,
0.2,
0.4,
0.6,
0.8,
1,
0.8333333,
0.6666667,
0.5,
0.3333333,
0.1666667,
0,
0.2,
0.4,
0.6,
0.8,
1,
0.8571429,
0.7142857,
0.5714286,
0.4285714,
0.2857143,
0.1428571,
0,
0.1428571,
0.2857143,
0.4285714,
0.5714286,
0.7142857,
0.8571429,
1,
0.8571429,
0.7142857,
0.5714286,
0.4285714,
0.2857143,
0.1428571,
0,
0.1111111,
0.2222222,
0.3333333,
0.4444444,
0.5555556,
0.6666667,
0.7777778,
0.8888889,
1,
0.8888889,
0.7777778,
0.6666667,
0.5555556,
0.4444444,
0.3333333,
0.2222222,
0.1111111,
0,
0.1111111,
0.2222222,
0.3333333,
0.4444444,
0.5555556,
0.6666667,
0.7777778,
0.8888889,
1,
0.9090909,
0.8181818,
0.7272727,
0.6363636,
0.5454545,
0.4545455,
0.3636364,
0.2727273,
0.1818182,
0.0909091,
0,
0.0909091,
0.1818182,
0.2727273,
0.3636364,
0.4545455,
0.5454545,
0.6363636,
0.7272727,
0.8181818,
0.9090909,
1,
0.9166667,
0.8333333,
0.75,
0.6666667,
0.5833333,
0.5,
0.4166667,
0.3333333,
0.25,
0.1666667,
0.0833333,
0,
0.0714286,
0.1428571,
0.2142857,
0.2857143,
0.3571429,
0.4285714,
0.5,
0.5714286,
0.6428571,
0.7142857,
0.7857143,
0.8571429,
0.9285714,
1,
0.9285714,
0.8571429,
0.7857143,
0.7142857,
0.6428571,
0.5714286,
0.5,
0.4285714,
0.3571429,
0.2857143,
0.2142857,
0.1428571,
0.0714286,
0,
0.0625,
0.125,
0.1875,
0.25,
0.3125,
0.375,
0.4375,
0.5,
0.5625,
0.625,
0.6875,
0.75,
0.8125,
0.875,
0.9375,
1,
0.9375,
0.875,
0.8125,
0.75,
0.6875,
0.625,
0.5625,
0.5,
0.4375,
0.375,
0.3125,
0.25,
0.1875,
0.125,
0.0625,
0,
0.0526316,
0.1052632,
0.1578947,
0.2105263,
0.2631579,
0.3157895,
0.3684211,
0.4210526,
0.4736842,
0.5263158,
0.5789474,
0.6315789,
0.6842105,
0.7368421,
0.7894737,
0.8421053,
0.8947368,
0.9473684,
1,
0.95,
0.9,
0.85,
0.8,
0.75,
0.7,
0.65,
0.6,
0.55,
0.5,
0.45,
0.4,
0.35,
0.3,
0.25,
0.2,
0.15,
0.1,
0.05,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0};

const float32_t cosines[12][26] = {
{1,	0.9547209,	0.8229839,	0.6167189,	0.3546049,	0.0603785,	-0.2393157,	-0.5173378,	-0.7485107,	-0.9118998,	-0.9927089,	-0.9836199,	-0.885456,	-0.7071068,	-0.4647232,	-0.180255,	0.1205367,	0.4104128,	0.6631227,	0.8557813,	0.9709418,	0.9981756,	0.9350162,	0.7871835,	0.5680647,	0.2975031},
{1,	0.9118998,	0.6631227,	0.2975031,	-0.1205367,	-0.5173378,	-0.8229839,	-0.9836199,	-0.9709418,	-0.7871835,	-0.4647232,	-0.0603785,	0.3546049,	0.7071068,	0.9350162,	0.9981756,	0.885456,	0.6167189,	0.2393157,	-0.180255,	-0.5680647,	-0.8557813,	-0.9927089,	-0.9547209,	-0.7485107,	-0.4104128},
{1,	0.8557813,	0.4647232,	-0.0603785,	-0.5680647,	-0.9118998,	-0.9927089,	-0.7871835,	-0.3546049,	0.180255,	0.6631227,	0.9547209,	0.9709418,	0.7071068,	0.2393157,	-0.2975031,	-0.7485107,	-0.9836199,	-0.9350162,	-0.6167189,	-0.1205367,	0.4104128,	0.8229839,	0.9981756,	0.885456,	0.5173378},
{1,	0.7871835,	0.2393157,	-0.4104128,	-0.885456,	-0.9836199,	-0.6631227,	-0.0603785,	0.5680647,	0.9547209,	0.9350162,	0.5173378,	-0.1205367,	-0.7071068,	-0.9927089,	-0.8557813,	-0.3546049,	0.2975031,	0.8229839,	0.9981756,	0.7485107,	0.180255,	-0.4647232,	-0.9118998,	-0.9709418,	-0.6167189},
{1,	0.7071067,	-1.608122E-16,	-0.7071067,	-1,	-0.7071067,	-1.8369702E-16,	0.7071067,	1,	0.7071067,	-5.8201672E-16,	-0.7071067,	-1,	-0.7071067,	1.3477304E-15,	0.7071067,	1,	0.7071067,	5.510910E-16,	-0.7071067,	-1,	-0.7071067,	1.1028011E-15,	0.7071067,	1,	0.7071067},
{1,	0.6167189,	-0.2393157,	-0.9118998,	-0.885456,	-0.180255,	0.6631227,	0.9981756,	0.5680647,	-0.2975031,	-0.9350162,	-0.8557813,	-0.1205367,	0.7071068,	0.9927089,	0.5173378,	-0.3546049,	-0.9547209,	-0.8229839,	-0.0603785,	0.7485107,	0.9836199,	0.4647232,	-0.4104128,	-0.9709418,	-0.7871835},
{1,	0.5173378,	-0.4647232,	-0.9981756,	-0.5680647,	0.4104128,	0.9927089,	0.6167189,	-0.3546049,	-0.9836199,	-0.6631227,	0.2975031,	0.9709418,	0.7071068,	-0.2393157,	-0.9547209,	-0.7485107,	0.180255,	0.9350162,	0.7871835,	-0.1205367,	-0.9118998,	-0.8229839,	0.0603785,	0.885456,	0.8557813},
{1,	0.4104128,	-0.6631227,	-0.9547209,	-0.1205367,	0.8557813,	0.8229839,	-0.180255,	-0.9709418,	-0.6167189,	0.4647232,	0.9981756,	0.3546049,	-0.7071068,	-0.9350162,	-0.0603785,	0.885456,	0.7871835,	-0.2393157,	-0.9836199,	-0.5680647,	0.5173378,	0.9927089,	0.2975031,	-0.7485107,	-0.9118998},
{1,	0.2975031,	-0.8229839,	-0.7871835,	0.3546049,	0.9981756,	0.2393157,	-0.8557813,	-0.7485107,	0.4104128,	0.9927089,	0.180255,	-0.885456,	-0.7071068,	0.4647232,	0.9836199,	0.1205367,	-0.9118998,	-0.6631227,	0.5173378,	0.9709418,	0.0603785,	-0.9350162,	-0.6167189,	0.5680647,	0.9547209},
{1,	0.180255,	-0.9350162,	-0.5173378,	0.7485107,	0.7871835,	-0.4647232,	-0.9547209,	0.1205367,	0.9981756,	0.2393157,	-0.9118998,	-0.5680647,	0.7071068,	0.8229839,	-0.4104128,	-0.9709418,	0.0603785,	0.9927089,	0.2975031,	-0.885456,	-0.6167189,	0.6631227,	0.8557813,	-0.3546049,	-0.9836199},
{1,	0.0603785,	-0.9927089,	-0.180255,	0.9709418,	0.2975031,	-0.9350162,	-0.4104128,	0.885456,	0.5173378,	-0.8229839,	-0.6167189,	0.7485107,	0.7071068,	-0.6631227,	-0.7871835,	0.5680647,	0.8557813,	-0.4647232,	-0.9118998,	0.3546049,	0.9547209,	-0.2393157,	-0.9836199,	0.1205367,	0.9981756},
{1,	-0.0603785,	-0.9927089,	0.180255,	0.9709418,	-0.2975031,	-0.9350162,	0.4104128,	0.885456,	-0.5173378,	-0.8229839,	0.6167189,	0.7485107,	-0.7071068,	-0.6631227,	0.7871835,	0.5680647,	-0.8557813,	-0.4647232,	0.9118998,	0.3546049,	-0.9547209,	-0.2393157,	0.9836199,	0.1205367,	-0.9981756}
};

#endif /* INC_MELFILTERCONFIG_H_ */
