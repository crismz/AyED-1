/* {Pre: x = X, y = Y}
   z := x
   x := x + 1 
   y := z + y
   {Post: x = X + 1, y = X + Y}*/

#include <stdio.h>

int pedirEntero (void) {
    int x;
    printf("De un número entero \n");
    scanf("%d",&x);
    return x;
}

void multiple (int y, int x) {
    int z;
    z = x;
    x = x + 1;
    y = z + y;
    printf("x = %d, y = %d\n",x,y);
}

int main (void) {
    multiple (pedirEntero(),pedirEntero());
    return 0;
}