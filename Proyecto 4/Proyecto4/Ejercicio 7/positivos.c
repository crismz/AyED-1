#include <stdio.h>
#include <stdbool.h>

bool existe_positivo (int a[], int tam) {
    bool i;
    i = 0;
    while (tam > 0) {
        i = (a[tam-1] > 0) || i;
        tam = tam - 1;
    }
    return i;
}

bool todos_positivos (int a[],int tam) {
    bool i;
    i = 1;
    while (tam > 0) {
        i = (a[tam-1] > 0) && i;
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
    
    int x;
    x = 0;
    while (x != 1 && x != 2) {
        printf("Elija que función ejecutar, existe_positivo o todos_positivos. Para elegir escriba 1 o 2 respectivamente\n");
        scanf("%d",&x);
    }

    if (x == 1) {
        printf("%d\n",existe_positivo(a,4));
    }  if (x == 2)  {
        printf("%d\n",todos_positivos(a,4));
    }
}
