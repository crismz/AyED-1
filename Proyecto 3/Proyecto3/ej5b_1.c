#include <stdio.h>
int main (void)  {
    int x,y,i;
    i = 0;
    printf("De un valor para x\n");
    scanf("%d",&x);
    printf("De un valor para y\n");
    scanf("%d",&y);
    
    while (x >= y) {
        x = x - y;
        i = i + 1;
    }

    printf("La división entera de x con y es igual a %d con resto %d\n",i,x);

    return 0;
}

/* Inicial:  x -> 13, y -> 3, i -> 0
   Iteración 1: x -> 10, y -> 3, i -> 1 
   Iteración 2: x -> 7, y -> 3, i -> 2 
   Iteración 3: x -> 4, y -> 3, i -> 3
   Iteración 4: x -> 1, y -> 3, i -> 4 
*/

/* Esta función hace la división entera entre dos numeros */