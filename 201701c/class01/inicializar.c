#include <stdio.h>

int main(int argc, char** argv) {
    int enteros[45];
    double flotantes[5];
    int* p = enteros + 4;

    printf("Tamano del entero: %lu\n", sizeof(int));
    printf("Tamano del array enteros: %lu\n", sizeof(enteros));

    printf("Tamano del float: %lu\n", sizeof(double));
    printf("Tamano del array floats: %lu\n", sizeof(flotantes));

    printf("Dir array enteros %lu, %lu\n", enteros, &enteros);

    printf("Guido pruebaDir array enteros %lu, %lu\n", 
            &enteros + 4, enteros + 4 );

}
