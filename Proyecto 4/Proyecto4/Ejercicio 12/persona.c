#include <stdio.h>

typedef struct {
    char *nombre;
    int edad;
    float altura;
    float peso;
} persona_t;

float peso_promedio(persona_t arr[], unsigned int longitud) {
    unsigned int i;
    float p;
    i = 0;
    p = 0;
    while (i < longitud) {
        p = arr[i].peso + p;
        i = i + 1;
    }
    p = p / longitud;
    return p;
}

persona_t persona_de_mayor_edad(persona_t arr[], unsigned int longitud) {
    unsigned int i,x;
    int edad;
    i = 0;
    edad = 0;
    while (i < longitud) {
        if (arr[i].edad > edad) {
            edad = arr[i].edad;
            x = i;
        }
        i = i + 1;
    }
    return arr[x];
}

persona_t persona_de_menor_altura(persona_t arr[], unsigned int longitud) {
    unsigned int i,x;
    float alt;
    i = 0;
    alt = 1000;
    while (i < longitud) {
        if (arr[i].altura < alt) {
            alt = arr[i].altura;
            x = i;
        }
        i = i + 1;
    }
    return arr[x];
}

int main (void) {
    persona_t p1 = {"Paola",21,1.85,75};
    persona_t p2 = {"Luis",54,1.75,69};
    persona_t p3 = {"Julio",40,1.70,80};
    unsigned int longitud = 3;
    persona_t arr[] = {p1,p2,p3};
    printf("El peso promedio es %f\n",peso_promedio(arr,longitud));
    persona_t p = persona_de_mayor_edad(arr, longitud);
    printf("El nombre de la persona con mayor edad es %s\n",p.nombre);
    p = persona_de_menor_altura(arr,longitud);
    printf("El nombre de la persona con menor altura es %s\n",p.nombre);
    return 0;
}