/* Tarea 2. M ́etodos iterativos para ecuaciones no lineales.
   Metodos Numericos.

                        José Luis de León Carmona.

Ejercicio 1. Escribe un programa para calcular la constante matem ́atica e, considerando la definici ́on

    e = limn→∞(1 + 1/n)**n,

es decir, calcula (1 + 1/n)**n para n = 10k para k = 1, 2, ..., 20. Determina el error relativo y absoluto de las
aproximaciones compar ́andolas con exp(1).

**********************************************************************************************/
#include <stdio.h>
#include <math.h>



int main() {
    double x = 1.0;
    double e = exp(1);

    printf("k  n                        exp aprox        exp real      error abs      error rel: \n");

    for(int k=1; k < 21; k++) {
        double n = pow(10, k);

        double expAprox = pow(1 + 1/n, n);

        double errAbs = fabs(e - expAprox);

        double errRel = (errAbs / e);

        printf("%-2d %-25.0f %-14.10f %-14.10f %-14.10f %-14.10f \n", k, n, expAprox, e, errAbs, errRel);

    }

    return 0;
}

