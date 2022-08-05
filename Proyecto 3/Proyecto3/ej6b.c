#include <stdio.h>

int pedirEntero (void) {
    int x;
    printf("De un número entero \n");
    scanf("%d",&x);
    return x;
}

void imprimeEntero (int x) {
    printf("El menor número es %d \n",x);
    return;
}

int menor (int x, int y) {
    int m;
    if (x < y) {
        m = x;   
    }  else {
        m = y;
    }
    return m;
}

int main (void) {
    int x,y,z;
    x = pedirEntero();
    y = pedirEntero();
    z = pedirEntero();

    imprimeEntero(menor(menor(x,y),z));
    return 0 ;
}

/* Las ventajas que tiene que en vez de poner varias veces la misma lineas con varios printf y scanf para pedir las variables, puedo usar la función que hace ambas cosas. */
/* Si se podria escribir una función para el condicional. Seria la función menor escrita mas arriba. */
/* Lo podria utilizar la función menor en el ejercicio 4a */