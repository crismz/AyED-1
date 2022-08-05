#include <stdio.h>
#include <stdbool.h>
int main (void) 
{ 
    int x,y,z,b,w;
    printf("De un valor para x \n");             
    scanf("%d",&x);
    printf("De un valor para y \n");
    scanf("%d", &y);
    printf("De un valor para z \n");
    scanf("%d",&z);
    printf("Siendo 1 = True y 0 = False de un valor que sea 1 o 0 para b \n");
    scanf("%d",&b);
    printf("Siendo 1 = True y 0 = False de un valor que sea 1 o 0 para w \n");
    scanf("%d",&w);

    // Ejercicio 2
    printf("La expresión %d %% 4 == 0 es %d \n", x,x % 4 == 0);
    printf("La expresión %d + %d == 0 && %d - %d == (-1) * %d es %d \n",x,y,y,x,z, (x + y == 0) && (y - x == (-1) * z));
    printf("La expresión not %d && %d es %d \n\n",b,w, ! (b && w));

    // Ejercicio 1 
    printf("La expresión %d + %d + 1 = %d \n",x,y,x+y+1);                
    printf("La expresión %d * %d + %d * 45 - 15 * %d = %d \n",z,z,y,x,z*z+y*45-15*x);
    printf("La expresion %d - 2 == (%d * 3 + 1) %% 5 es %d \n",y,x,y - 2 == (x * 3 + 1) % 5);
    printf("La expresión %d / 2 * %d = %d \n",y,x, y/2*x);
    printf("La expresión %d < %d * %d es %d \n",y,x,z,y < x * z);
    return 0;
}

/* Ej 1:                        (x->7, y->3, z->5)                  (x->1, y->10, z->8)                                 
x + y + 1 =                             11                                   12
z * z + y * 45 - 15 * x =               55                                   499
y - 2 == (x * 3 + 1) % 5 es             False                                False
y / 2 * x =                             7                                    5
y < x * z =                             True                                 False
*/

/* Ej 1: La ultima expresión es de tipo Bool, pero como C no tiene booleanos, usa numeros para representar a los bool, en este caso 0 es False y 1 es True */

/* Ej 2: (x -> 4, y -> -4, z -> 8, b -> 1 (True), w -> 1 (True) ) */
