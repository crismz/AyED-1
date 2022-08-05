#include <stdio.h>
#include <assert.h>

/* Mínimo
Var r,x,y : Int;
{True}
if x>=y -> 
    r := y
[] y>x ->
    r := x
fi
{r = x min y} */

int pedirEntero (void) {
    int x;
    printf("De un número entero \n");
    scanf("%d",&x);
    return x;
}

int minimo (int x, int y) {
    int r;
    if (x >= y) {
        r = y;   
    }  else {
        r = x;
    }
    assert(r <= x && r <= y);
    return r;
}

int main (void) {
    int x;
    x = minimo(pedirEntero(),pedirEntero());
    printf("El minimo es %d\n", x);
    return 0;
}