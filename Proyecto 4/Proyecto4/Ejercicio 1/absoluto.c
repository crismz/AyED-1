#include <stdio.h>
#include <assert.h>

/* Valor absoluto
Var x,r : Int;
{True}
if x >= 0 -> 
    r := x
[] x < 0 ->
    r := -x
fi
{r = |x|} */

int pedirEntero (void) {
    int x;
    printf("De un número entero \n");
    scanf("%d",&x);
    return x;
}

int absoluto (int x) {
    int r;
    if (x >= 0) {
        r = x;   
    }  else {
        r = -x;
    }
    assert(r == x || r == -x);
    return r;
}

int main (void) {
    int x;
    x = absoluto(pedirEntero());
    printf("El valor absoluto es %d\n", x);
    return 0;
}