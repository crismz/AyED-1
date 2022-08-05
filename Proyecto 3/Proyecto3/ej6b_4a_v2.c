#include <stdio.h>

int pedirEntero (void) {
    int x;
    printf("De un número entero \n");
    scanf("%d",&x);
    return x;
}

int menor_2 (int x, int y) {
    if (x < y) {
        x = 2;   
    }  else {
        x = 0;
    }
    return x;
}

int main (void)    { 
    int x,y;
    x = pedirEntero();
    y = pedirEntero();

    printf("El valor de x = %d e y = %d \n",menor_2(x,y),y);
    return 0;
}
