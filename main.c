#include "myfirstheader.h"

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

void hlp(void){
    printf(
    "Use 1st digit to choose the comand: \t1) Root\n \t2) Integral\n"
    "Use 2nd and 3rd digits to choose the functions:\n"
    "\t1) exp(x) + 2\n \t2) -2 * x + 8\n \t3) -5 / x"
    "If you have chosen comand << 2) Integral >>, write << 0 >> on 2nd place"
    "If you want to get the answer of my 8th varint, write << 999 >>"
    "If you want to stop the program, write << 666 >>"
    );
}

int wrt(void){
    int dgt, a, b;
    printf("Enter 3-digits number code: ");
    if (!scanf("%d\n", &dgt)) {
        hlp();
        wrt();
    }
    else{
        if (dgt == 999) printf("My answer: %lf", 
        integral(f2, root(f2, f3, -4, 5, eps1), root(f2, f1, -4, 5, eps1), eps2) + 
        integral(f3, root(f1, f3, -4, 5, eps1), root(f2, f3, -4, 5, eps1), eps2) - 
        integral(f1, root(f1, f3, -4, 5, eps1), root(f2, f1, -4, 5, eps1), eps2));
        else if (dgt == 666) return 0;
        else{
            printf("Enter left and right ends of the segment: ");
            scanf("%d %d\n", &a, &b);
            if ( (dgt % 100) / 10 == 0){
                if (dgt / 100 == 1){ 
                    printf("Integral 1) exp(x) + 2 on [%d, %d] = %lf", a, b, integral(f1, a, b, eps2));
                }
                else if (dgt / 100 == 2){ 
                    printf("Integral 2) -2 * x + 8 on [%d, %d] = %lf", a, b, integral(f2, a, b, eps2));
                }
                else printf("Integral 3) -5 / x on [%d, %d] = %lf", a, b, integral(f3, a, b, eps2));
            }
            else{
                if (((dgt / 100 == 1) && ((dgt % 100) / 10 == 2)) || ((dgt / 100 == 2) && ((dgt % 100) / 10 == 1))){ 
                    printf("Root 1) exp(x) + 2 and 2) -2 * x + 8 on [%d, %d] = %lf", a, b, root(f1, f2,a, b, eps1));
                }
                else if (((dgt / 100 == 1) && ((dgt % 100) / 10 == 3)) || ((dgt / 100 == 3) && ((dgt % 100) / 10 == 1))){ 
                    printf("Root 1) exp(x) + 2 and 3) -5 / x on [%d, %d] = %lf", a, b, root(f1, f3,a, b, eps1));
                }
                else printf("Root 3) -5 / x and 2) -2 * x + 8 on [%d, %d] = %lf", a, b, root(f3, f2,a, b, eps1));
                }
        }
        printf("Something else? ");
        wrt();
    }
}

int main(void){
    wrt();
}