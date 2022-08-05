#include <stdio.h>
#include <assert.h>

void intercambiar (int a[], int tam, int i, int j) {
    int z;
    z = a[j];
    a[j] = a[i];
    a[i] = z;
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

    int i,j;
    printf("Elija que posiciones quiere intercambiar\n");
    scanf("%d",&i);
    scanf("%d",&j);
    assert(0 <= i && i < t && 0 <= j && j < t);

    intercambiar(a,t,i,j);
    imprimeArreglo(a,t);
    return 0;
}