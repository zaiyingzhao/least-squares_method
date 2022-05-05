#pragma once
#include "func.h"

int optimize(const double alpha, const int dim, const int n, double a[], struct sample sampleall[], 
             void (*calc_grad)(int, double[], double[], struct sample sampleall[]), double (*calc_value)(int, double[], struct sample sampleall[]));
