#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "optimize.h"
#include "func.h"


int main(const int argc, const char **argv)
{
    // 引数の個数が1の時だけ、alpha に第1引数を採用し、それ以外は0.01
    const double alpha = (argc == 2) ? atof(argv[1]) : 0.01;
    
    const int dim = dimension();
    int n; //要素数
    char location[MAX_LEN];
    double altitude = 0;
    double temperature = 0;
    struct sample sampleall[MAX_LEN];


    FILE *fp;
    fp = fopen("data.csv", "r");
    int i = 0;
    while (fscanf(fp, "%[^,], %lf, %lf\n", location, &altitude, &temperature) != EOF) {
        strcpy(sampleall[i].loc, location);
        sampleall[i].alt = altitude;
        sampleall[i].temp = temperature;
        i++;
    }
    n = i;

    qsort(sampleall, n, sizeof(sampleall[0]), comp_altitude); //標高でソートする
    
    for (int i = 0; i < n; i++) {
        printf("location = %s, altitude = %f, temperature = %f\n", sampleall[i].loc, sampleall[i].alt, sampleall[i].temp);
    }
    
    double *a = malloc(dim * sizeof(double)); //最適化したい定数[a,b]
    for (int i = 0; i < dim; i++) {
        a[i] = 0;
    }
    
    printf("alpha = %f\n", alpha);
    
    const int iter = optimize(alpha, dim, n, a, sampleall, f_gradient, f_value);
    
    printf("number of iterations = %d\n", iter);
    
    free(a);  
    
    return 0;
}