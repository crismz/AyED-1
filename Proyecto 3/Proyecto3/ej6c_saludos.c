#include <stdio.h>

void imprimeHola (void) {
    printf("hola \n");
    return;
}

void imprimeChau (void) {
    printf("chau \n");
    return;
}

int main (void) {
    imprimeHola();
    imprimeHola();
    imprimeChau();
    imprimeChau();

    return 0;
}