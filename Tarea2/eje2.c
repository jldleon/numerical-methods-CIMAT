/* Tarea 2. M ́etodos iterativos para ecuaciones no lineales.
   Metodos Numericos.

                        José Luis de León Carmona.

    Ejercicio 2. La ecuaci ́on x^3 + x = 6 tiene una ra ́ız en el intervalo [1,55, 1,75], ¿cu ́antas iteraciones se necesitan para obtener
una aproximaci ́on de la ra ́ız con error menor a 0.0001 con el m ́etodo de bisecci ́on? Verifica con el m ́etodo de
bisecci ́on tu predicci ́on de la ra ́ız.

*****************************************************/

#include <stdio.h>
#include <math.h>

#define function(x) pow(x,3)+x-6

double bisection(double, double, double, int);

int main() {
    float a, b, TOL;
    int N;

    //Intervalo
    a = 1.55;
    b = 1.75;
    TOL = 0.0001;

    //Iteraciones
    N = 20;
    double result = bisection(a, b, TOL, N);
    printf(" el resultado es: %lf", result);



    return 0;
}


double bisection(double a, double b, double TOL, int N) {
    int i;
    double FA = function(a), p, FP;
        for (i = 1; i <= N; i++ ) {
            p = a + (b-a)/2;
            FP = function(p);

            if (FP == 0 || (b-a)/2 < TOL ) {
                printf(" En %d iteraciones", i);
                return p;
                break;
            }

            if (FA*FP > 0) {
                a = p;
                FA = FP;
            } else {
                b = p;
            }
        }

    printf("Method failed after %d iterations", N);
}
