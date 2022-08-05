#include <stdio.h>
#include <assert.h>

typedef struct {
    int cociente;
    int resto;
} div_t;


div_t division (int x, int y) {
    div_t dupla;
    dupla.cociente = 0;
    while (x>=y) {
        x = x - y;
        dupla.cociente = dupla.cociente + 1;
    }
    dupla.resto = x;
    return(dupla);
}


int main (void) {
    div_t dupla;
    int x;
    int y;
    printf("De un número entero positivo\n");
    scanf("%d",&x);
    printf("De un número entero positivo\n");
    scanf("%d",&y);
    assert(y > 0 && x >= 0);
    dupla = division(x,y);
    printf("El cociente es %d y el resto es %d\n",dupla.cociente,dupla.resto);
    return 0;
    }