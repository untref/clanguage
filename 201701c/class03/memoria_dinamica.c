#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "iterarl.h"

#define TAM_ENTEROS 4

int main(int argc, char** argv) {
    int* enteros;
    unsigned volumen = sizeof(int) * TAM_ENTEROS;

    // Allocar memoria
    enteros = malloc( volumen );

    printf("Puntero allocado: 0x%p\n", enteros);

    enteros = realloc(enteros, 50000 * volumen);

    printf("Puntero realloc: 0x%p\n", enteros);

    volumen *= 50000;

    // Inicializo la memoria alocada
    memset(enteros, 0x0, volumen);

    enteros[TAM_ENTEROS - 1] = 19;

    iterar(enteros, volumen, sizeof(int), printEntero) ;

    free(enteros);
    printf("Valor puntero luego del free: 0x%p\n", enteros);
    // No olvidarse colocar en 0 el puntero liberado
    enteros = 0x0;

    return 0;

}


