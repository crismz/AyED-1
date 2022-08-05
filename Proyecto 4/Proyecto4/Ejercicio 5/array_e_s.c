#include <stdio.h>
#include <assert.h>

void pedirArreglo (int a[], int n_max) {
    int i;
    i = 0;
    while (i < n_max){
        printf("Dar el valor para la posición %d del arreglo\n",i);
        scanf("%d",&a[i]);
        i = i + 1;
    }
}

void imprimeArreglo (int a[], int n_max) {
    int i;
    i = 0;
    while (i < n_max) {
        printf("La posicion %d tiene valor %d\n",i,a[i]);
        i = i + 1;
    }
}

int main (void) {
    int n;
    printf("Introduzca la cantidad de elementos que quiere que tenga el arreglo\n");
    scanf("%d",&n);
    assert(n>=0);
    int a[n];
    pedirArreglo(a,n);
    imprimeArreglo(a,n);
    return 0;
}