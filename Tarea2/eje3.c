/* Tarea 2. M ́etodos iterativos para ecuaciones no lineales.
   Metodos Numericos.

                        José Luis de León Carmona.

    Ejercicio 3. Hallar una ra ́ız de f(x) = x
4 + 3x
2 − 2 por medio de las siguientes 4 formulaciones de punto fijo utilizando

p0 = 1:

a) x = (2 − x^4)/3
b) x = (2 − 3x^2)^(1/4)
c) x = 2− x^4 /3x
d) x = ( 2 − 3x^2 / x)^(1/3)

a) Las ra ́ıces de f(x) deben de coincidir con las ra ́ıces de x − g(x). Grafica f(x) y x − g(x). Comenta lo
observado. (1 puntos)
b) Crea una tabla comparativa para comparar el resultado de las ra ́ıces de f(x) con la ra ́ız alcanzada con
cada una de las 4 formulaciones. Usa m ́aximo 20 iteraciones y tol = 0.0001. Explica lo sucedido. (2
puntos)

******************************************************************************************************************/

#include <stdio.h>
#include <math.h>

#define functionA(x) sqrt((2-pow(x,4.0))/3)      //Resultado  0.74
#define functionB(x) pow((2-3*pow(x, 2.0)),1.0/4.0)  //Resultado 1
#define functionC(x) (2-pow(x,4.0))/(3*x)        //Fallo
#define functionD(x) pow(((2-3*pow(x,2.0))/x),1.0/3.0)  //Resultado 1

double fixedpointA( double, double, int);

double fixedpointB( double, double, int);

double fixedpointC( double, double, int);

double fixedpointD( double, double, int);

int main() {
    //Parametros para el metodo de punto fijo
    double p0 = 1.0;
    double TOL = 0.0001;
    int N = 20, i;

    for(i = 1; i <= N; i++){
        printf("%d %lf %lf %lf %lf \n", i, fixedpointA(p0, TOL, i), fixedpointB(p0, TOL, i), fixedpointC(p0, TOL, i), fixedpointD(p0, TOL, i) );
    }

    printf("%lf", functionB(p0));
    return 0;
}


double fixedpointA(double p0, double TOL, int N) {
    int i = 1;
    double p;

    for (i; i <= N; i++){
        p = functionA(p0);
        p0 = p;
    }

    return p;
}


double fixedpointB(double p0, double TOL, int N) {
    int i = 1;
    double p;

    for (i ; i <= N; i++){
        p = functionB(p0);
        p0 = p;
    }

    return p;
}


double fixedpointC(double p0, double TOL, int N) {
    int i = 1;
    double p;

    for (i; i <= N; i++){
        p = functionC(p0);
        p0 = p;
    }

    return p;
}


double fixedpointD(double p0, double TOL, int N) {
    int i = 1;
    double p;

    for (i; i <= N; i++){
        p = functionD(p0);

        p0 = p;
    }

    return p;
}

