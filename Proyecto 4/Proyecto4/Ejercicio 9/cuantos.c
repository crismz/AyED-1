#include <stdio.h>
#include <assert.h>

typedef struct  {
    int menores;
    int iguales;
    int mayores;
 } comp_t;


comp_t cuantos(int a[], int tam, int elem) {
    int i;
    comp_t tripla;
    tripla.mayores = 0;
    tripla.menores = 0;
    tripla.iguales = 0;
    while (tam > 0) {
        i = tam - 1;
        if (a[i] > elem) {
            tripla.mayores = 1 + tripla.mayores;
        } 
        if (a[i] < elem) {
            tripla.menores = 1 + tripla.menores;
        }
        if (a[i] == elem) {
            tripla.iguales = 1 + tripla.iguales;
        }
        tam = tam - 1;
    }
    return tripla;
}

int main (void) {
    int t;
    printf("De un numero para el tamaño que quiera que tenga el arreglo, como maximo 10\n");
    scanf("%d",&t);
    assert(t <= 10 && t > 0);

    int a[t];
    int n;
    n = 0;
    while (n < t){
        printf("Dar el valor para la posición %d del arreglo\n",n);
        scanf("%d",&a[n]);
        n = n + 1;
    }

    int x;
    printf("De un numero entero\n");
    scanf("%d",&x);

    comp_t tripla = cuantos(a,t,x);
    printf("Hay %d menores, %d iguales y %d mayores a %d",tripla.menores,tripla.iguales, tripla.mayores,x);
    return 0;
}