#include <stdio.h>

int pedirEntero (void) {
    int x;
    printf("De un número entero \n");
    scanf("%d",&x);
    return x;
}

void imprimeEntero (int x) {
    printf("%d \n",x);
    return;
}

int main (void) {
   imprimeEntero(pedirEntero());
   return 0 ;
}