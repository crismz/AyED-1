#include <stdio.h>
int main (void)
{ 
    int x,y,z,m;
    printf("De un valor para x \n");
    scanf("%d",&x);
    printf("De un valor para y \n");
    scanf("%d",&y);
    printf("De un valor para z \n");
    scanf("%d",&z);
    printf("De un valor para m \n");
    scanf("%d",&m);

    if (x < y) {
        m = x;   
    }  else {
        m = y;
    }

    if (m < z) {
        ;
    } else {
        m = z;
    }

    printf("El valor de x = %d  y = %d  z = %d  m = %d \n",x,y,z,m);
    return 0;
}

/* Precondición: x -> 5, y -> 4, z -> 8, m -> 0
   Condición 1: x -> 5, y -> 4, z -> 8, m -> 4
   Condición 2: x -> 5, y -> 4, z -> 8, m -> 4
*/

/* El programa compara los valores de las tres primeras variables dadas y selecciona el menor y se la asigna a m.
 El valor final de m va a ser igual al menor valor entre x, y, z. Dicho de otra forma m = min x (min y z) */