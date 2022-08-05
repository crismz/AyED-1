#include <stdio.h>
#include <stdbool.h>
int main (void)  {
    int x,i,res;
    i = 2;
    res = true;
    printf("De un valor para x\n");
    scanf("%d",&x);
    
    while (i < x && res) {
        res = res && (x % i != 0);
        i = i + 1;
    }

    if (res == true) {
        printf("%d es un número primo\n",x);
    } else  {
        printf("%d no es un número primo\n",x);
    }

    return 0;
}

/* Inicial:  x -> 5, i -> 0, res -> False
   Iteración 1: x -> 5, i -> 2, res -> True 
   Iteración 2: x -> 5, i -> 3, res -> True 
   Iteración 3: x -> 5, i -> 4, res -> True
   Iteración 4: x -> 5, i -> 5, res -> True 
*/

/* Esta función te dice si un numero es primo o no */