#include <stdio.h>
#include <assert.h>
int main (void)
{ int x;
    printf("De un valor para x\n");
    scanf("%d", &x);
    assert(x == 1);
    x = 5;
    printf("x = %d \n", x);
    return 0;
}

/* ingresando valor 10 produce una salida x = 5
   ingresando valor 0 produce una salida x = 5
   ingresando valor 5 produce una salida x = 5
*/