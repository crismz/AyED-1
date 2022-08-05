#include <stdio.h>
#include  <assert.h>

int suma_hasta (int N) {
    int x;
    x = (N * (N+1))/2;   
    return x;
}

int main (void) {
    int N;
    printf("De un número entero positivo\n");
    scanf("%d",&N);
    assert(N >= 0);
    N = suma_hasta(N);
    printf("La suma hasta N es %d \n",N);
    return 0;
}
