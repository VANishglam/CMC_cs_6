#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int k = 0; //Сounter for solving the equation
double eps1 = 0.0001, eps2 = 0.0001;

double f1(double x);

double f2(double x);

double f3(double x);

double root(double ( *f)(double x), double  ( *g)(double x), double a, double b, double eps1){
    double upward = b, bottom = a, mid;
    while (upward - bottom > eps1){
        k++;
        mid = (bottom + upward) / 2;
        if ((( *f)(mid) - ( *g)(mid)) * (( *f)(bottom) - ( *g)(bottom)) <= 0) upward = mid;//We need a segment at the ends of which the functions has different signs
        else bottom = mid;
    }
    k = 0;
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

int main(void){
    printf("You need help(-help) or solutions(1)?\n");
    if (scanf("%d")){

    }
    else{
        
    }
    printf("%lf", f1(2.0));
}