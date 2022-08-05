/* {Pre: x = X, y = Y, z = Z}
   a = x;
   b = y;
   x = y + y;
   y = a + z;
   z = a + b;
   {Post: x = Y, y = Y + X, z = Y + X}*/

#include <stdio.h>

int pedirEntero (void) {
    int x;
    printf("De un número entero \n");
    scanf("%d",&x);
    return x;
}

void multiple2 (int z, int y,int x) {
    int a,b;
    a = x;
    b = y;
    x = y + y;
    y = a + z;
    z = a + b;
    printf("x = %d, y = %d, z = %d\n",x,y,z);
}

int main (void) {
    multiple2 (pedirEntero(),pedirEntero(),pedirEntero());
    return 0;
}