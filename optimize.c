#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "func.h"
#include "optimize.h"

double calc_norm(const int dim, double v[])
{
    double tmp = 0;
    for (int i = 0; i < dim; i++) {
	tmp += v[i] * v[i];
    }
    tmp = sqrt(tmp);
    return tmp;
}

int optimize(const double alpha, const int dim, const int n, double a[], struct sample sampleall[],
            void (*calc_grad)(int, double[], double[], struct sample sampleall[]), double (*calc_value)(int, double[], struct sample sampleall[]))
{
    // 勾配ベクトルを記録する領域を確保
    double *g = malloc(dim * sizeof(double));

    int iter = 0;
    while (++iter < 10000) {
	
	// 引数で渡された関数を使って勾配ベクトルを計算
	(*calc_grad)(n, a, g, sampleall);

    double norm = calc_norm(dim, g);
	
    printf("iteration = %d", iter);
    printf(", norm = %7.4f", norm);

	for (int i = 0; i < dim; i++) {
	    printf(", a[%d] = %7.4f", i, a[i]);
	}
	printf(", f(x) = %7.4f\n", (*calc_value)(n, a, sampleall));
	
	if (norm < 0.001) break;
	
	// 最急降下法による更新
	for (int i = 0; i < dim; i++) {
	    a[i] -= alpha * g[i];
	}
    }
    
    free(g);
    
    return iter;
}