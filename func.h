#pragma once
#define MAX_LEN 50

struct sample {
    char loc[50];   // location name
    double alt;  // altitude (km)
    double temp; // temperature (centigrade)
};

int dimension();
double f_value(int n, double a[], struct sample sampleall[]);
void f_gradient(int n, double a[], double g[], struct sample sampleall[]);
int comp_altitude(const void* x0, const void *x1);