#include <stdio.h>
#include <assert.h>

typedef struct {
    float maximo;
    float minimo;
    float promedio;
} datos_t;

datos_t stats (float a[], int tam) {
    datos_t tripla;
    int i,tam2;
    float n,max,min;
    tam2 = tam;
    n = 0;
    i = tam2 - 1;
    max = a[i];
    min = a[i];
    while (tam2 > 0) {
        if (a[i] > max) {
            max = a[i];
        }
        if (a[i] < min) {
            min = a[i];
        }
        tam2 = tam2 - 1;
        n = n + a[i];
        i = i - 1;
    }
    tripla.maximo = max;
    tripla.minimo = min;
    tripla.promedio = n/tam;

    return tripla;
}


int main (void) {
    int t;
    printf("De un numero para el tamaño que quiera que tenga el arreglo, como maximo 10\n");
    scanf("%d",&t);
    assert(t <= 10 && t > 0);

    float a[t];
    int n;
    n = 0;
    while (n < t) {
        printf("Dar el valor para la posición %d del arreglo\n",n);
        scanf("%f",&a[n]);
        n = n + 1;
    }

    datos_t tripla = stats(a,t);
    printf("El maximo del arreglo es %f, el minimo %f y el promedio %f",tripla.maximo,tripla.minimo,tripla.promedio);
    return 0;
}