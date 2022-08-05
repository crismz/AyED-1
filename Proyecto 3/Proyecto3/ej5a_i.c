#include <stdio.h>
int main (void)
{
    int i;
    printf("De un valor para i\n");
    scanf("%d",&i);

    while (i != 0) {
        i = 0;
    }

    printf("El valor de i es %d",i);
    
    return 0;
}