/* Tarea 3. Metodos Numericos.
    Sistema de ecuaciones 1.

                    José Luis de León Carmona.

Este codigo incluye una subrutina como solucion al ejercicio 4.

Ejercicio 4. Genera un programa en C que resuelva un sistema de ecuaciones de la forma Ax = b, con pivoteo parcial. (4
puntos). Para ello te sugiero:
Crear una funci´on que intercambie 2 filas cualesquiera de una matriz.
Crear una funci´on que encuentre el m´aximo de un vector.
Modificar el algoritmo del eliminaci´on gaussiana del ejercicio 3 para hallar la soluci´on de un sistema de
ecuaciones con pivoteo parcial

Con esta subrutina resolvemos el insiso b) del 5.

********************************/

#include <stdio.h>
#include <math.h>

void printArr(int ren, int col, double m[][col]); //Subrutina para imprimir la matriz

void printVec(int dim, double vec[]);

void GaussianaPartialPivoting(int m, int n, double matriz[m][n]);

void Backwardsubstitution(int dim, double U[][dim],double b[dim], double x[dim]);


int main() {

    int dim = 5;

    //Voy a introducir la matriz aumentada [A,b]

    double A[][5] = {
        {2, 20, 18, 20, 18},
        {6, 16, 18, 20, 18},
        {18, 14, 4, 6, 4},
        {16, 16, 2, 16, 16},
        {6, 10, 4, 2, 8}

    };

    printf("Matriz aumentada A: \n");
    printArr(dim, dim, A);
    printf("\n");
    printf("Construcción de la matriz triangular superior con pivoteo: \n");

    GaussianaPartialPivoting(dim, dim, A);
    printArr(dim, dim, A);
    printf("\n");

    double b[5] = {532, 360, 204, 396, 172};

    printf("Vector b: \n");
    printVec(dim, b);
    printf("\n");

    double x[dim]; //Vector que guarda la solucion

    Backwardsubstitution(dim, A,b, x);

    printf("Solucion: \n");
    printVec(dim, x);

    return 0;
}

void GaussianaPartialPivoting(int m, int n, double a[m][n]){
    int i,j,k;
    for(i=0;i<m-1;i++){
        //Partial Pivoting
        for(k=i+1;k<m;k++){
            //If diagonal element(absolute vallue) is smaller than any of the terms below it
            if(fabs(a[i][i])<fabs(a[k][i])){
                //Swap the rows
                for(j=0;j<n;j++){
                    double temp;
                    temp=a[i][j];
                    a[i][j]=a[k][j];
                    a[k][j]=temp;
                }
            }
        }
        //Begin Gauss Elimination
        for(k=i+1;k<m;k++){
            double  term=a[k][i]/ a[i][i];
            for(j=0;j<n;j++){
                a[k][j]=a[k][j]-term*a[i][j];
            }
        }
    }

}

void Backwardsubstitution(int dim, double U[][dim],double b[dim], double x[dim]) {
/* Este algoritmo recibe como argumento una matriz triangular superior de dim x dima
    Ademas del vector B con sus parametros respectivos y un vector x donde se almacena la solucion*/
    int i, j;
    double aux;

    for (i = dim - 1; i > -1; i--) {
        aux = b[i];
        for (j = dim - 1; j > i; j--) {
            aux -= U[i][j]*x[j];
        }
        x[i] = aux/U[i][i];
    }
}


void printArr(int ren, int col, double m[][col]) {
    int i, j;

    for (i = 0; i < ren; i++) {
        for (j = 0; j < col; j++) {
            printf("%lf ", m[i][j]);
        }
        printf("\n");
    }
}

void printVec(int dim, double vec[]) {
    int i;

    for (i = 0; i < dim; i++) {
        printf("%lf \n", vec[i]);
    }
}
