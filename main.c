#include "myfirstheader.h"

int k = 0; //Сounter for solving the equation
double eps1 = 0.0001, eps2 = 0.0001;

double f1(double x);

double f2(double x);

double f3(double x);

double root(double ( *f)(double x), double  ( *g)(double x), double a, double b, double eps1){//Binary root search
    double upward = b, bottom = a, mid;
    while (upward - bottom > eps1){
        k++;
        mid = (bottom + upward) / 2;
        if ((( *f)(mid) - ( *g)(mid)) * (( *f)(bottom) - ( *g)(bottom)) <= 0) upward = mid;//We need a segment at the ends of which the functions has different signs
        else bottom = mid;
    }
    return mid;
}

double integral(double ( *f)(double x), double a, double b, double eps2){//Calculation of the integral by the rectangle method
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
    char cmnd[10], optns[10];
    char hlp[] = "-help", rt[] = "root", sqr[] = "square", ans[] = "answer", tst[] = "test";
    scanf("%s", cmnd);
    if (!strcmp(cmnd, hlp)){ //Input processing
        printf("Comands:\n"
                "   answer test\n\n"
                "Test options:\n"
                "   root     square\n\n"
                "Option parameters:\n"
                "   function, section\n\n"
                "Functions:\n"
                "   1 —— (exp(x) + 2)     2 —— (-2 * x + 8)     3 —— (-5 / x)\n\n"
                "Ends of the section:\n"
                "   double a, double b\n\n"
                "Example: test root 2 1 -23 5\n"
                );
        return 0;
    }
    else if (!strcmp(cmnd, ans)) {//For my personal task
            double a = integral(f2, root(f2, f3, -5, 0, eps1), root(f2, f1, -1, 3, eps1), eps2);
            double b = integral(f3, root(f1, f3, -5, 0, eps1), root(f3, f2, -5, 0, eps1), eps2);
            double c = integral(f1, root(f1, f3, -5, 0, eps1), root(f2, f1, -1, 3, eps1), eps2);
            printf("Answer for my 8th variant: %lf\n", (a + b - c));
            return 0;
        }
    else{
        if (!strcmp(cmnd, tst)){//For testing ... 
            scanf("%s", optns);
            if (!strcmp(optns, rt)){// ... roots
                int n1, n2;
                double a, b;
                scanf("%d %d %lf %lf", &n1, &n2, &a, &b);
                if (((n1 == 1) && (n2 == 2)) || ((n2 == 1) && (n1 == 2))){
                    printf("The root of (exp(x) + 2) and (-2 * x + 8) on section [%lf, %lf]: %lf\n", a, b, root(f1, f2, a, b, eps1));
                    printf("Iterations: %d\n", k);
                    k = 0;
                    return 0;
                }
                else if (((n1 == 2) && (n2 == 3)) || ((n2 == 2) && (n1 == 3))){
                    printf("The root of (-5 / x) and (-2 * x + 8) on section [%lf, %lf]: %lf\n", a, b, root(f3, f2, a, b, eps1));
                    printf("Iterations: %d\n", k);
                    k = 0;
                    return 0;
                }
                else if (((n1 == 1) && (n2 == 3)) || ((n2 == 1) && (n1 == 3))){
                    printf("The root of (-5 / x) and (exp(x) + 2) on section [%lf, %lf]: %lf\n", a, b, root(f1, f3, a, b, eps1));
                    printf("Iterations: %d\n", k);
                    k = 0;
                    return 0;
                }
            }
            else{
                if (!strcmp(optns, sqr)){// ... integrals
                    int n;
                    double a, b;
                    scanf("%d %lf %lf", &n, &a, &b);
                    if (n == 1){
                        printf("The square of (exp(x) + 2) on section [%lf, %lf]: %lf\n", a, b, integral(f1, a, b, eps2));
                        return 0;
                    }
                    else if (n == 2){
                        printf("The square of (-2 * x + 8) on section [%lf, %lf]: %lf\n", a, b, integral(f2, a, b, eps2));
                        return 0;
                    }
                    else if (n == 3){
                        printf("The square of (-5 / x) on section [%lf, %lf]: %lf\n", a, b, integral(f3, a, b, eps2));
                        return 0;
                    }
                }
            }
        }
    }  
}