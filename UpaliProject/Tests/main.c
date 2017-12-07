#include <string.h>
#include <stdio.h>

int main()
{
    double x[2] = {1., 2.};
    double y[4] = {0., 0., 0., 0.};

    memcpy(y, x, 2 * sizeof(*x));
              /* ^ 2 elements of size -> sizeof(double) */

    return 0;
}
