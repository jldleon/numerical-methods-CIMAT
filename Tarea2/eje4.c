/* Tarea 2. M ́etodos iterativos para ecuaciones no lineales.
   Metodos Numericos.

                        José Luis de León Carmona.

    Ejercicio 4.



    ******************************/



#include <stdio.h>
#include <math.h>

double bisection(double, double, double, int);

double newton(double, double, int);

double secant(double, double, double, int);

double false_position(double, double, double, int);

double fder(double);

double function(double);

int main() {
    double x0 = 0.1;
    double x1 = 0.5; //Necesitamos intervalo para Biseccion y Secante, voy a suponer este
    double TOL = 0.0001;
    int N = 20;

    printf("Biseccion: %lf \n", bisection(x0, x1, TOL, N));
    printf("Newton: %lf \n", newton(x0, TOL, N));
    printf("Secante: %lf \n", secant(x0, x1, TOL, N));
    printf("Falsa Posicion: %lf \n", false_position(x0, x1, TOL, N));
    return 0;
}


double newton(double p0, double TOL, int N0 ) {
    int i;

    for (i = 1; i <= N0; i++) {
        double p = p0 - function(p0)/fder(p0);

        if (fabs(p - p0) < TOL) {
            return p;
            break;
        }

        p0 = p;
    }

    printf("The method failed after %d iterations", N0);
}

double function(double x) {
    double result = 1000000*exp(x)+(435000/x)*(exp(x)-1)-1564000;
    return result;
}

double fder( double x) {
    double result = 1000000*exp(x)+435000*(x*exp(x)-exp(x)+1)/(x*x);

    return result;
}

double secant(double p0, double p1, double TOL, int N0) {
    int i;

    double q0 = function(p0);
    double q1 = function(p1);

    for (i = 2; i <= N0; i++) {
        double p = p1 - q1*(p1 - p0)/(q1 - q0);

        if (fabs(p - p1) < TOL) {
            return p;
            break;
        }

        p0 = p1;
        q0 = q1;
        p1 = p;
        q1 = function(p);
    }

    printf("The method failed after %d iterations", N0);
}

double false_position(double p0, double p1, double TOL, int N0) {
    int i;

    double q0 = function(p0), p, q;
    double q1 = function(p1);

    for (i = 2; i <= N0; i++) {
        p = p1 - q1*(p1 - p0)/(q1 - q0);

        if (fabs(p-p1) < TOL) {
            return p;
            break;
        }

        q = function(p);

        if (q*q1 < 0) {
            p0 = p1;
            q0 = q1;
        }

        p1 = p;
        q1 = q;
    }

    printf("Method failed after %d iteraions", N0);

}


double bisection(double a, double b, double TOL, int N) {
    int i;
    double FA = function(a), p, FP;
        for (i = 1; i <= N; i++ ) {
            p = a + (b-a)/2;
            FP = function(p);

            if (FP == 0 || (b-a)/2 < TOL ) {
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

double fixedpoint(double p0, double TOL, int N) {
    int i;
    double p;

    for (i = 1; i <= N; i++){
        p = function(p0);

        if (fabs(p - p0) < TOL) {
            return p;
            break;
        }

        p0 = p;
    }
    printf("The method failed after %d iterations", N);
}
