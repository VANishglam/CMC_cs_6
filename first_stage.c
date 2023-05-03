#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

double eps = 0.001;

double f1(double x){
    return (1.5 * x);
}

double f2(double x){
    return (10 - 3.5 * x);
}

double f3(double x){
    return (exp(x));
}

double f4(double x){
    return (27);
}

double f5(double x){
    return (x * x * x);
}

double f6(double x){
    return (x * x);
}

double root(double ( *f)(double x), double  ( *g)(double x), double a, double b, double eps1){
    double upward = b, bottom = a, mid;
    while (upward - bottom > eps1){
        mid = (bottom + upward) / 2;
        if ((( *f)(mid) - ( *g)(mid)) * (( *f)(bottom) - ( *g)(bottom)) <= 0) upward = mid;//We need a segment at the ends of which the functions has different signs
        else bottom = mid;
    }
    return mid;
}

double integral(double ( *f)(double x), double a, double b, double eps2){
    int n = 10;
    double sum1 = 0, sum2 = 0;
    double h = (b - a)/ n;
    for (int i = 0; i < n; i++){
        sum2 += ( *f)(a + (i + 0.5) * h);
    }
    sum2 *= h;
    while (fabs((sum2 - sum1) / 3) > eps2){
        n *= 2;
        sum1 = sum2;
        sum2 = 0;
        h = (b - a) / n;
        for (int i = 0; i < n; i++){
            sum2 += ( *f)(a + (i + 0.5) * h);
        }
        sum2 *= h;

    }
    return sum2;
}

int main(void)
{
    double a = -3, b = 8;
    printf("Integrals:\n");
    printf("Right: %lf My: %lf\n", 2980.9082, integral(f3, a, b, eps));
    printf("Right: %lf My: %lf\n", 179.666, integral(f6, a, b, eps));
    printf("Roots:\n");
    printf("Right: %lf My: %lf\n", 2.0, root(f1, f2, a, b, eps));
    printf("Right: %lf My: %lf\n", 3.0, root(f4, f5, a, b, eps));
    return 0;
}
