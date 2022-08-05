#include <stdio.h>
#include <assert.h>

/* Intercambio de variables
Var x,y,z : Int;
{y = B ∧ x = A}
z := x;
x := y;
y := z
{y = A ∧ x = B} */

int pedirEntero (void) {
    int x;
    printf("De un número entero \n");
    scanf("%d",&x);
    return x;
}

void intercambio (int x,int y) {
    int z;
    z = x;
    x = y;
    y = z;
    printf("Si x = %d e y = %d, con el intercambio queda x = %d e y = %d\n" ,x,y,y,x);
}

int main (void) {
    intercambio(pedirEntero(),pedirEntero());
    return 0;
}
