#include <stdio.h>

int sumatoria (int a[], int tam) {
    int i;
    i = 0;
    while (tam > 0) {
        i = i + a[tam-1];
        tam = tam - 1;
    }
    return i;
}
    

int main (void) {
    int a[4];
    int i;
    i = 0;
    while (i < 4){
        printf("Dar el valor para la posición %d del arreglo\n",i);
        scanf("%d",&a[i]);
        i = i + 1;
    }
    printf("La suma de los elementos del array es %d",sumatoria(a,4));
    return 0;
}