#include <stdio.h>
#include <math.h>
#include "func.h"


int dimension()
{
    return 2;
}

double f_value(int n, double a[], struct sample sampleall[])
{
    double E = 0.0;
    for (int i; i < n; i++) {
        E += pow(sampleall[i].temp - a[0] * sampleall[i].alt - a[1], 2.0);
    }
    return E;
}

void f_gradient(int n, double a[], double g[], struct sample sampleall[])
{
    for (int i = 0; i < 2; i++) { //dimにしたい
        g[i] = 0;
    }
    for (int i = 0; i < n; i++) {
        g[0] += -2 * sampleall[i].alt * (sampleall[i].temp - a[0] * sampleall[i].alt - a[1]);
        g[1] += -2 * (sampleall[i].temp - a[0] * sampleall[i].alt - a[1]);
    }
}

int comp_altitude(const void* x0, const void *x1)
{
    const struct sample *p0 = (struct sample*)x0;
    const struct sample *p1 = (struct sample*)x1;
    
    if (p0->alt > p1->alt) {
        return 1;
    }
    else {
        return -1;
    }
}