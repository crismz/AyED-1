#include <stdio.h>
#include <assert.h>
int main (void)
{ int x,y;
    printf("De un valor para x\n");
    scanf("%d", &x);
    printf("De un valor para y\n");
    scanf("%d", &y);
    assert(x == 2);
    assert(y == 5);
    y = y + y;
    x = x + y;
    printf("x = %d y = %d \n", x,y);
    return 0;
}

/* ingresando valor x=2 e y=5 produce una salida x = 12 e y = 10 
   ingresando valor x=1 e y=1 produce una salida x = 3 e y = 2
   ingresando valor x=(-2) e y=4 produce una salida x = 6 e y = 8 
*/