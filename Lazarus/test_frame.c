
#include "arm_math.h"

float32_t signal[1024] = {
	-2.1650000e+03,
0.0000000e+00,
-2.6400000e+02,
0.0000000e+00,
-5.8100000e+02,
0.0000000e+00,
7.6600000e+02,
0.0000000e+00,
1.5580000e+03,
0.0000000e+00,
-7.6600000e+02,
0.0000000e+00,
0.0000000e+00,
0.0000000e+00,
9.2400000e+02,
0.0000000e+00,
9.5100000e+02,
0.0000000e+00,
2.6400000e+02,
0.0000000e+00,
-6.6000000e+02,
0.0000000e+00,
-1.8500000e+02,
0.0000000e+00,
8.7100000e+02,
0.0000000e+00,
5.8100000e+02,
0.0000000e+00,
3.4300000e+02,
0.0000000e+00,
5.8100000e+02,
0.0000000e+00,
4.4900000e+02,
0.0000000e+00,
3.4300000e+02,
0.0000000e+00,
1.4000000e+03,
0.0000000e+00,
9.7700000e+02,
0.0000000e+00,
5.0200000e+02,
0.0000000e+00,
4.7500000e+02,
0.0000000e+00,
5.2800000e+02,
0.0000000e+00,
1.5050000e+03,
0.0000000e+00,
9.2400000e+02,
0.0000000e+00,
5.3000000e+01,
0.0000000e+00,
1.3200000e+02,
0.0000000e+00,
5.5500000e+02,
0.0000000e+00,
1.2410000e+03,
0.0000000e+00,
4.2300000e+02,
0.0000000e+00,
-1.0600000e+02,
0.0000000e+00,
3.9600000e+02,
0.0000000e+00,
1.0030000e+03,
0.0000000e+00,
1.0030000e+03,
0.0000000e+00,
-2.6000000e+01,
0.0000000e+00,
7.9000000e+01,
0.0000000e+00,
2.3800000e+02,
0.0000000e+00,
2.1100000e+02,
0.0000000e+00,
8.7100000e+02,
0.0000000e+00,
-8.4500000e+02,
0.0000000e+00,
-3.1700000e+02,
0.0000000e+00,
8.9800000e+02,
0.0000000e+00,
5.8100000e+02,
0.0000000e+00,
3.1700000e+02,
0.0000000e+00,
4.4900000e+02,
0.0000000e+00,
4.2300000e+02,
0.0000000e+00,
9.5100000e+02,
0.0000000e+00,
7.9200000e+02,
0.0000000e+00,
8.9800000e+02,
0.0000000e+00,
1.1620000e+03,
0.0000000e+00,
7.9200000e+02,
0.0000000e+00,
6.3400000e+02,
0.0000000e+00,
1.0300000e+03,
0.0000000e+00,
1.1090000e+03,
0.0000000e+00,
5.8100000e+02,
0.0000000e+00,
3.4300000e+02,
0.0000000e+00,
6.8700000e+02,
0.0000000e+00,
1.4520000e+03,
0.0000000e+00,
1.0830000e+03,
0.0000000e+00,
3.4300000e+02,
0.0000000e+00,
1.0560000e+03,
0.0000000e+00,
1.4520000e+03,
0.0000000e+00,
1.0300000e+03,
0.0000000e+00,
6.8700000e+02,
0.0000000e+00,
7.6600000e+02,
0.0000000e+00,
9.7700000e+02,
0.0000000e+00,
5.5500000e+02,
0.0000000e+00,
5.5500000e+02,
0.0000000e+00,
6.0700000e+02,
0.0000000e+00,
6.3400000e+02,
0.0000000e+00,
3.1700000e+02,
0.0000000e+00,
2.9000000e+02,
0.0000000e+00,
6.8700000e+02,
0.0000000e+00,
3.4300000e+02,
0.0000000e+00,
0.0000000e+00,
0.0000000e+00,
2.3800000e+02,
0.0000000e+00,
3.4300000e+02,
0.0000000e+00,
5.5500000e+02,
0.0000000e+00,
7.9000000e+01,
0.0000000e+00,
-5.3000000e+01,
0.0000000e+00,
2.3800000e+02,
0.0000000e+00,
2.3800000e+02,
0.0000000e+00,
0.0000000e+00,
0.0000000e+00,
7.9000000e+01,
0.0000000e+00,
1.0600000e+02,
0.0000000e+00,
-1.0600000e+02,
0.0000000e+00,
-2.1100000e+02,
0.0000000e+00,
2.6400000e+02,
0.0000000e+00,
1.0600000e+02,
0.0000000e+00,
-3.1700000e+02,
0.0000000e+00,
2.6000000e+01,
0.0000000e+00,
3.4300000e+02,
0.0000000e+00,
1.8500000e+02,
0.0000000e+00,
-3.1700000e+02,
0.0000000e+00,
-3.4300000e+02,
0.0000000e+00,
1.5800000e+02,
0.0000000e+00,
-1.8500000e+02,
0.0000000e+00,
-5.8100000e+02,
0.0000000e+00,
-5.5500000e+02,
0.0000000e+00,
-6.0700000e+02,
0.0000000e+00,
-4.2300000e+02,
0.0000000e+00,
-4.2300000e+02,
0.0000000e+00,
-7.3900000e+02,
0.0000000e+00,
-6.6000000e+02,
0.0000000e+00,
-5.8100000e+02,
0.0000000e+00,
-7.1300000e+02,
0.0000000e+00,
-5.0200000e+02,
0.0000000e+00,
-9.7700000e+02,
0.0000000e+00,
-9.2400000e+02,
0.0000000e+00,
-6.8700000e+02,
0.0000000e+00,
-6.8700000e+02,
0.0000000e+00,
-7.1300000e+02,
0.0000000e+00,
-8.7100000e+02,
0.0000000e+00,
-1.0300000e+03,
0.0000000e+00,
-6.0700000e+02,
0.0000000e+00,
-5.5500000e+02,
0.0000000e+00,
-8.9800000e+02,
0.0000000e+00,
-7.6600000e+02,
0.0000000e+00,
-7.3900000e+02,
0.0000000e+00,
-7.3900000e+02,
0.0000000e+00,
-7.6600000e+02,
0.0000000e+00,
-1.1350000e+03,
0.0000000e+00,
-7.1300000e+02,
0.0000000e+00,
-6.0700000e+02,
0.0000000e+00,
-1.0560000e+03,
0.0000000e+00,
-7.9200000e+02,
0.0000000e+00,
-6.6000000e+02,
0.0000000e+00,
-8.4500000e+02,
0.0000000e+00,
-8.9800000e+02,
0.0000000e+00,
-7.1300000e+02,
0.0000000e+00,
-8.4500000e+02,
0.0000000e+00,
-8.9800000e+02,
0.0000000e+00,
-1.0300000e+03,
0.0000000e+00,
-7.3900000e+02,
0.0000000e+00,
-7.3900000e+02,
0.0000000e+00,
-1.1620000e+03,
0.0000000e+00,
-1.0030000e+03,
0.0000000e+00,
-6.0700000e+02,
0.0000000e+00,
-1.0560000e+03,
0.0000000e+00,
-8.9800000e+02,
0.0000000e+00,
-7.1300000e+02,
0.0000000e+00,
-8.1900000e+02,
0.0000000e+00,
-8.7100000e+02,
0.0000000e+00,
-6.8700000e+02,
0.0000000e+00,
-7.6600000e+02,
0.0000000e+00,
-6.0700000e+02,
0.0000000e+00,
-7.6600000e+02,
0.0000000e+00,
-9.2400000e+02,
0.0000000e+00,
-7.9200000e+02,
0.0000000e+00,
-4.7500000e+02,
0.0000000e+00,
-1.0560000e+03,
0.0000000e+00,
-6.0700000e+02,
0.0000000e+00,
-6.0700000e+02,
0.0000000e+00,
-7.3900000e+02,
0.0000000e+00,
-2.9000000e+02,
0.0000000e+00,
-5.2800000e+02,
0.0000000e+00,
-5.2800000e+02,
0.0000000e+00,
-5.5500000e+02,
0.0000000e+00,
-6.8700000e+02,
0.0000000e+00,
-5.0200000e+02,
0.0000000e+00,
-5.2800000e+02,
0.0000000e+00,
-9.2400000e+02,
0.0000000e+00,
-5.2800000e+02,
0.0000000e+00,
-5.2800000e+02,
0.0000000e+00,
-6.0700000e+02,
0.0000000e+00,
-4.7500000e+02,
0.0000000e+00,
-7.9200000e+02,
0.0000000e+00,
-3.7000000e+02,
0.0000000e+00,
-5.8100000e+02,
0.0000000e+00,
-3.9600000e+02,
0.0000000e+00,
-6.0700000e+02,
0.0000000e+00,
-6.3400000e+02,
0.0000000e+00,
-3.9600000e+02,
0.0000000e+00,
-4.7500000e+02,
0.0000000e+00,
-3.9600000e+02,
0.0000000e+00,
-5.5500000e+02,
0.0000000e+00,
-5.5500000e+02,
0.0000000e+00,
-3.9600000e+02,
0.0000000e+00,
-3.7000000e+02,
0.0000000e+00,
-3.7000000e+02,
0.0000000e+00,
-3.7000000e+02,
0.0000000e+00,
-7.9000000e+01,
0.0000000e+00,
0.0000000e+00,
0.0000000e+00,
5.3000000e+01,
0.0000000e+00,
-2.6000000e+01,
0.0000000e+00,
-7.9000000e+01,
0.0000000e+00,
7.9000000e+01,
0.0000000e+00,
2.9000000e+02,
0.0000000e+00,
2.1100000e+02,
0.0000000e+00,
2.6000000e+01,
0.0000000e+00,
3.1700000e+02,
0.0000000e+00,
1.8500000e+02,
0.0000000e+00,
2.9000000e+02,
0.0000000e+00,
2.1100000e+02,
0.0000000e+00,
2.6000000e+01,
0.0000000e+00,
2.9000000e+02,
0.0000000e+00,
5.0200000e+02,
0.0000000e+00,
4.7500000e+02,
0.0000000e+00,
2.6400000e+02,
0.0000000e+00,
2.3800000e+02,
0.0000000e+00,
5.8100000e+02,
0.0000000e+00,
2.6400000e+02,
0.0000000e+00,
1.5800000e+02,
0.0000000e+00,
7.9200000e+02,
0.0000000e+00,
3.4300000e+02,
0.0000000e+00,
4.4900000e+02,
0.0000000e+00,
4.4900000e+02,
0.0000000e+00,
3.1700000e+02,
0.0000000e+00,
4.4900000e+02,
0.0000000e+00,
5.5500000e+02,
0.0000000e+00,
4.2300000e+02,
0.0000000e+00,
5.0200000e+02,
0.0000000e+00,
6.0700000e+02,
0.0000000e+00,
7.6600000e+02,
0.0000000e+00,
6.6000000e+02,
0.0000000e+00,
6.6000000e+02,
0.0000000e+00,
8.1900000e+02,
0.0000000e+00,
5.5500000e+02,
0.0000000e+00,
5.5500000e+02,
0.0000000e+00,
7.1300000e+02,
0.0000000e+00,
7.1300000e+02,
0.0000000e+00,
5.8100000e+02,
0.0000000e+00,
8.4500000e+02,
0.0000000e+00,
7.1300000e+02,
0.0000000e+00,
6.3400000e+02,
0.0000000e+00,
9.2400000e+02,
0.0000000e+00,
8.4500000e+02,
0.0000000e+00,
6.3400000e+02,
0.0000000e+00,
8.7100000e+02,
0.0000000e+00,
1.0300000e+03,
0.0000000e+00,
7.1300000e+02,
0.0000000e+00,
8.7100000e+02,
0.0000000e+00,
7.1300000e+02,
0.0000000e+00,
6.0700000e+02,
0.0000000e+00,
5.5500000e+02,
0.0000000e+00,
5.2800000e+02,
0.0000000e+00,
3.7000000e+02,
0.0000000e+00,
5.0200000e+02,
0.0000000e+00,
5.0200000e+02,
0.0000000e+00,
5.0200000e+02,
0.0000000e+00,
2.9000000e+02,
0.0000000e+00,
6.0700000e+02,
0.0000000e+00,
5.2800000e+02,
0.0000000e+00,
2.6400000e+02,
0.0000000e+00,
6.0700000e+02,
0.0000000e+00,
3.1700000e+02,
0.0000000e+00,
4.7500000e+02,
0.0000000e+00,
6.6000000e+02,
0.0000000e+00,
5.0200000e+02,
0.0000000e+00,
6.0700000e+02,
0.0000000e+00,
5.8100000e+02,
0.0000000e+00,
5.2800000e+02,
0.0000000e+00,
7.9200000e+02,
0.0000000e+00,
5.8100000e+02,
0.0000000e+00,
6.8700000e+02,
0.0000000e+00,
6.8700000e+02,
0.0000000e+00,
4.2300000e+02,
0.0000000e+00,
5.8100000e+02,
0.0000000e+00,
7.1300000e+02,
0.0000000e+00,
1.8500000e+02,
0.0000000e+00,
7.1300000e+02,
0.0000000e+00,
6.0700000e+02,
0.0000000e+00,
3.4300000e+02,
0.0000000e+00,
5.8100000e+02,
0.0000000e+00,
5.0200000e+02,
0.0000000e+00,
4.2300000e+02,
0.0000000e+00,
5.0200000e+02,
0.0000000e+00,
6.0700000e+02,
0.0000000e+00,
3.9600000e+02,
0.0000000e+00,
5.8100000e+02,
0.0000000e+00,
5.8100000e+02,
0.0000000e+00,
5.0200000e+02,
0.0000000e+00,
5.0200000e+02,
0.0000000e+00,
5.2800000e+02,
0.0000000e+00,
5.8100000e+02,
0.0000000e+00,
4.2300000e+02,
0.0000000e+00,
4.2300000e+02,
0.0000000e+00,
5.8100000e+02,
0.0000000e+00,
5.0200000e+02,
0.0000000e+00,
5.0200000e+02,
0.0000000e+00,
5.2800000e+02,
0.0000000e+00,
4.4900000e+02,
0.0000000e+00,
4.4900000e+02,
0.0000000e+00,
4.2300000e+02,
0.0000000e+00,
4.7500000e+02,
0.0000000e+00,
5.5500000e+02,
0.0000000e+00,
4.4900000e+02,
0.0000000e+00,
5.5500000e+02,
0.0000000e+00,
3.9600000e+02,
0.0000000e+00,
2.6400000e+02,
0.0000000e+00,
4.2300000e+02,
0.0000000e+00,
4.4900000e+02,
0.0000000e+00,
4.7500000e+02,
0.0000000e+00,
5.0200000e+02,
0.0000000e+00,
3.4300000e+02,
0.0000000e+00,
4.7500000e+02,
0.0000000e+00,
4.4900000e+02,
0.0000000e+00,
2.1100000e+02,
0.0000000e+00,
2.6400000e+02,
0.0000000e+00,
3.9600000e+02,
0.0000000e+00,
4.2300000e+02,
0.0000000e+00,
3.9600000e+02,
0.0000000e+00,
2.9000000e+02,
0.0000000e+00,
3.9600000e+02,
0.0000000e+00,
3.4300000e+02,
0.0000000e+00,
3.9600000e+02,
0.0000000e+00,
3.9600000e+02,
0.0000000e+00,
2.9000000e+02,
0.0000000e+00,
3.1700000e+02,
0.0000000e+00,
4.4900000e+02,
0.0000000e+00,
3.4300000e+02,
0.0000000e+00,
4.7500000e+02,
0.0000000e+00,
3.9600000e+02,
0.0000000e+00,
2.6400000e+02,
0.0000000e+00,
2.6400000e+02,
0.0000000e+00,
3.1700000e+02,
0.0000000e+00,
3.7000000e+02,
0.0000000e+00,
2.1100000e+02,
0.0000000e+00,
1.3200000e+02,
0.0000000e+00,
3.9600000e+02,
0.0000000e+00,
2.6400000e+02,
0.0000000e+00,
3.7000000e+02,
0.0000000e+00,
1.5800000e+02,
0.0000000e+00,
2.1100000e+02,
0.0000000e+00,
3.7000000e+02,
0.0000000e+00,
2.1100000e+02,
0.0000000e+00,
2.1100000e+02,
0.0000000e+00,
1.0600000e+02,
0.0000000e+00,
1.0600000e+02,
0.0000000e+00,
1.0600000e+02,
0.0000000e+00,
1.0600000e+02,
0.0000000e+00,
1.8500000e+02,
0.0000000e+00,
5.3000000e+01,
0.0000000e+00,
-2.6000000e+01,
0.0000000e+00,
2.6000000e+01,
0.0000000e+00,
-1.3200000e+02,
0.0000000e+00,
-1.8500000e+02,
0.0000000e+00,
-1.0600000e+02,
0.0000000e+00,
-1.8500000e+02,
0.0000000e+00,
-5.3000000e+01,
0.0000000e+00,
0.0000000e+00,
0.0000000e+00,
-1.8500000e+02,
0.0000000e+00,
-7.9000000e+01,
0.0000000e+00,
-7.9000000e+01,
0.0000000e+00,
-2.3800000e+02,
0.0000000e+00,
-2.3800000e+02,
0.0000000e+00,
-1.0600000e+02,
0.0000000e+00,
-3.1700000e+02,
0.0000000e+00,
-3.1700000e+02,
0.0000000e+00,
-2.6400000e+02,
0.0000000e+00,
-2.9000000e+02,
0.0000000e+00,
-3.1700000e+02,
0.0000000e+00,
-4.2300000e+02,
0.0000000e+00,
-3.4300000e+02,
0.0000000e+00,
-3.4300000e+02,
0.0000000e+00,
-1.0600000e+02,
0.0000000e+00,
-1.0600000e+02,
0.0000000e+00,
-3.4300000e+02,
0.0000000e+00,
-3.1700000e+02,
0.0000000e+00,
-1.0600000e+02,
0.0000000e+00,
-3.7000000e+02,
0.0000000e+00,
-2.9000000e+02,
0.0000000e+00,
-2.6400000e+02,
0.0000000e+00,
-3.1700000e+02,
0.0000000e+00,
-4.4900000e+02,
0.0000000e+00,
-3.7000000e+02,
0.0000000e+00,
-5.0200000e+02,
0.0000000e+00,
-6.0700000e+02,
0.0000000e+00,
-6.6000000e+02,
0.0000000e+00,
-6.0700000e+02,
0.0000000e+00,
-5.8100000e+02,
0.0000000e+00,
-5.8100000e+02,
0.0000000e+00,
-7.1300000e+02,
0.0000000e+00,
-8.4500000e+02,
0.0000000e+00,
-7.1300000e+02,
0.0000000e+00,
-7.1300000e+02,
0.0000000e+00,
-7.3900000e+02,
0.0000000e+00,
-9.7700000e+02,
0.0000000e+00,
-1.0560000e+03,
0.0000000e+00,
-1.1350000e+03,
0.0000000e+00,
-1.0830000e+03,
0.0000000e+00,
-1.0830000e+03,
0.0000000e+00,
-1.0300000e+03,
0.0000000e+00,
-1.0300000e+03,
0.0000000e+00,
-9.5100000e+02,
0.0000000e+00,
-8.9800000e+02,
0.0000000e+00,
-1.0300000e+03,
0.0000000e+00,
-9.7700000e+02,
0.0000000e+00,
-5.0200000e+02,
0.0000000e+00,
-6.3400000e+02,
0.0000000e+00,
-7.1300000e+02,
0.0000000e+00,
-7.3900000e+02,
0.0000000e+00,
-8.1900000e+02,
0.0000000e+00,
-8.4500000e+02,
0.0000000e+00,
-8.1900000e+02,
0.0000000e+00,
-8.4500000e+02,
0.0000000e+00,
-9.2400000e+02,
0.0000000e+00,
-7.9200000e+02,
0.0000000e+00,
-7.3900000e+02,
0.0000000e+00,
-9.5100000e+02,
0.0000000e+00,
-6.8700000e+02,
0.0000000e+00,
-9.5100000e+02,
0.0000000e+00,
-8.7100000e+02,
0.0000000e+00,
-8.9800000e+02,
0.0000000e+00,
-6.3400000e+02,
0.0000000e+00,
-8.4500000e+02,
0.0000000e+00,
-8.7100000e+02,
0.0000000e+00,
-7.6600000e+02,
0.0000000e+00,
-7.9200000e+02,
0.0000000e+00,
-8.4500000e+02,
0.0000000e+00,
-6.0700000e+02,
0.0000000e+00,
-6.8700000e+02,
0.0000000e+00,
-7.9200000e+02,
0.0000000e+00,
-6.0700000e+02,
0.0000000e+00,
-7.1300000e+02,
0.0000000e+00,
-7.1300000e+02,
0.0000000e+00,
-4.4900000e+02,
0.0000000e+00,
-5.2800000e+02,
0.0000000e+00,
-5.0200000e+02,
0.0000000e+00,
-2.6400000e+02,
0.0000000e+00,
-1.0600000e+02,
0.0000000e+00,
-2.9000000e+02,
0.0000000e+00,
-2.3800000e+02,
0.0000000e+00,
-1.3200000e+02,
0.0000000e+00,
-2.1100000e+02,
0.0000000e+00,
0.0000000e+00,
0.0000000e+00,
-1.3200000e+02,
0.0000000e+00,
2.6000000e+01,
0.0000000e+00,
1.5800000e+02,
0.0000000e+00,
1.8500000e+02,
0.0000000e+00,
2.6000000e+01,
0.0000000e+00,
1.3200000e+02,
0.0000000e+00,
2.1100000e+02,
0.0000000e+00,
2.9000000e+02,
0.0000000e+00,
2.1100000e+02,
0.0000000e+00,
4.2300000e+02,
0.0000000e+00,
4.7500000e+02,
0.0000000e+00,
4.2300000e+02,
0.0000000e+00,
3.9600000e+02,
0.0000000e+00,
3.7000000e+02,
0.0000000e+00,
4.2300000e+02,
0.0000000e+00,
4.2300000e+02,
0.0000000e+00,
6.0700000e+02,
0.0000000e+00,
5.8100000e+02,
0.0000000e+00,
6.0700000e+02,
0.0000000e+00,
6.6000000e+02,
0.0000000e+00,
7.6600000e+02,
0.0000000e+00,
8.7100000e+02,
0.0000000e+00,
8.7100000e+02,
0.0000000e+00,
1.0030000e+03,
0.0000000e+00,
7.9200000e+02,
0.0000000e+00,
8.7100000e+02,
0.0000000e+00,
8.7100000e+02,
0.0000000e+00,
8.9800000e+02,
0.0000000e+00,
9.7700000e+02,
0.0000000e+00,
1.0830000e+03,
0.0000000e+00,
8.4500000e+02,
0.0000000e+00,
9.5100000e+02,
0.0000000e+00,
1.0030000e+03,
0.0000000e+00,
8.4500000e+02,
0.0000000e+00,
9.2400000e+02,
0.0000000e+00,
7.6600000e+02,
0.0000000e+00,
7.6600000e+02,
0.0000000e+00,
8.4500000e+02,
0.0000000e+00,
8.1900000e+02,
0.0000000e+00,
6.3400000e+02,
0.0000000e+00,
6.0700000e+02,
0.0000000e+00,
6.6000000e+02,
0.0000000e+00,
7.1300000e+02,
0.0000000e+00,
7.6600000e+02,
0.0000000e+00,
6.6000000e+02,
0.0000000e+00,
6.3400000e+02,
0.0000000e+00,
7.6600000e+02,
0.0000000e+00,
6.3400000e+02,
0.0000000e+00,
7.9200000e+02,
0.0000000e+00,
7.3900000e+02,
0.0000000e+00,
5.2800000e+02,
0.0000000e+00,
4.4900000e+02,
0.0000000e+00,
3.7000000e+02,
0.0000000e+00,
4.2300000e+02,
0.0000000e+00,
2.1100000e+02,
0.0000000e+00,
2.6000000e+01,
0.0000000e+00,
5.3000000e+01,
0.0000000e+00,
-1.0600000e+02,
0.0000000e+00,
-2.3800000e+02,
0.0000000e+00,
-2.6400000e+02,
0.0000000e+00,
-3.9600000e+02,
0.0000000e+00,
-5.5500000e+02,
0.0000000e+00,
-7.1300000e+02,
0.0000000e+00,
-6.0700000e+02,
0.0000000e+00,
-5.8100000e+02,
0.0000000e+00,
-9.2400000e+02,
0.0000000e+00,
-9.2400000e+02,
0.0000000e+00,
-9.5100000e+02,
0.0000000e+00,
-1.1350000e+03,
0.0000000e+00,
-1.2150000e+03,
0.0000000e+00,
-1.3200000e+03,
0.0000000e+00,
-1.4260000e+03,
0.0000000e+00,
-1.5840000e+03,
0.0000000e+00,
-1.6370000e+03,
0.0000000e+00,
-1.8220000e+03,
0.0000000e+00,
-2.0600000e+03,
0.0000000e+00,
-2.1650000e+03,
0.0000000e+00,
-2.1390000e+03,
0.0000000e+00,
-2.2180000e+03,
0.0000000e+00,
-2.1650000e+03,
0.0000000e+00,
-2.2710000e+03,
0.0000000e+00,
-2.1920000e+03,
0.0000000e+00,
-2.4030000e+03,
0.0000000e+00,
-2.0860000e+03,
0.0000000e+00,
-2.1390000e+03,
0.0000000e+00,
-2.1390000e+03,
0.0000000e+00
};