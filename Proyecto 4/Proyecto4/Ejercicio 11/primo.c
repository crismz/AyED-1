#include <stdio.h>
#include <assert.h>

int nesimo_primo (int N) {
    int contador,n,i;
    int primos[N];
    primos[0] = 2;
    n = 3;
    for (contador=1; contador < N; contador++)
    {   i = 0;
         while (i < contador) {
            if (n%primos[i] == 0) {
                n = n + 1;
                i = 0;
            }  else   {
                if (i == contador - 1) {
                    primos[contador] = n;
                    i = i + 1;
                    n = n + 1;
                } else {
                    i = i + 1;
                }
                }
            }
        }
        return primos[N-1];
    }

int main (void) {
    int N;
    N = 0;
    while (N < 1) {
    printf("Ingrese un numero entero positivo\n");
    scanf("%d",&N);
        if (N < 1) {
         printf("El valor dado no es positivo\n");
        }
    }
    assert (N > 0);
    printf("%d",nesimo_primo(N));
    return 0;
}