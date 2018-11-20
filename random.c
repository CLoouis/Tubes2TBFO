#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <complex.h>

double complex arr;
double r;

int main(){
    scanf("%lf", &r);
    arr = (double complex)r * I;
    printf("%.6f %.6f %.6f\n",r, creal(arr), cimag(arr));
    return 0;
}