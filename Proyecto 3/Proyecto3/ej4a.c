#include <stdio.h>
int main (void)
{ 
    int x,y;
    printf("De un valor para x \n");
    scanf("%d",&x);
    printf("De un valor para y \n");
    scanf("%d",&y);
    if (x >= y) {
        x = 0;   
    }  else {
        x = 2;
    }
    printf("El valor de x = %d e y = %d \n",x,y);
    return 0;
}

/* ingresando valor x=3 e y=1 produce una salida x = 0 e y = 1 
   ingresando valor x=(-100) e y=1 produce una salida x = 2 e y = 1 
*/