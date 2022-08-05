#include <stdio.h>
#include <assert.h>

int pedirEntero (void) {
    int x;
    printf("De un número entero positivo\n");
    scanf("%d",&x);
    assert (x > 0);
    return x;
}

void holaHasta (int n){
    while (n > 0)
    {
       printf("Hola\n");
       n = n-1;
    }
    
}
int main (void) {
    holaHasta(pedirEntero());
    return 0;
}