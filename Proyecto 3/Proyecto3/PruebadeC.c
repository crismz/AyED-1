#include <stdio.h>  /* biblioteca estandar, hay otra biblioteca para los booleanos que es <stdbool.h> que toma 1 como true y 0 como false */
int main (void)  /* main devuelve un int (primer termino) y no toma argumentos (por void) */
{
   printf ("Goodbye to a World \n");            /* Resultado de la función */

  int x, y, i;
   printf("Ingrese un valor \n");
   scanf("%d", &x);
   printf("Ingrese otro valor \n");
   scanf("%d", &y);
   i = x * y;
   printf("El resultado de su multiplación es %d \n",i);

   return 0;                    /* Valor que devuelve main, no necesiriamente tiene uso, en este caso esta para llenar */

}
