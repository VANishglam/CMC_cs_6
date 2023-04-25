#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

double eps = 0.001;

double f1(double x){
    return (x);
}

double f2(double x){
    return (10 - x);
}

double f3(double x){
    return (- 5 / x);
}

double root(double f(double x), double  g(double x), double a, double b, double eps1){
    double upward = b, bottom = a, mid;
    while (upward - bottom > eps1){
        mid = (bottom + upward) / 2;
        printf("%lf %lf\n", upward, bottom);
        if ((f(mid) - g(mid)) * (f(bottom) - g(bottom)) <= 0) upward = mid;
        else bottom = mid;
    }
    return mid;
}

double integral(double f(double x), double a, double b, double eps2){
    int n = 10;
    double sum1 = 0, sum2 = 0;
    double h = (b - a)/ n;
    for (int i = 0; i < n; i++){
        sum2 += f(a + (i + 0.5) * h);
    }
    sum2 *= h;
    while (fabs((sum2 - sum1) / 3) > eps2){
        n *= 2;
        sum1 = sum2;
        h = (b - a)/ n;
        for (int i = 0; i < n; i++){
            sum2 += f(a + (i + 0.5) * h);
        }
        sum2 *= h;
    }
    return sum2;
}

int main(void)
{
    double a, b;
    scanf("%lf %lf", &a, &b);
    printf("%lf\n", integral(sin, a, b, eps));
    printf("%lf", root(f1, f2, a, b, eps));
    return 0;
}
