#include <stdio.h>

// void inicializarArray(int elementos[]) {
void inicializarArray(char* elementos, unsigned cantidad) {
    while (cantidad != 0 ) {
        cantidad--;
        *elementos = 0x0;
        elementos++;
    }
}

int main(int argc, char** argv) {
    int enteros[2];
    double flotantes[4];

    printf("Tamano de los enteros : %lu\n", sizeof(enteros));
    inicializarArray(enteros, sizeof(enteros));
    inicializarArray(flotantes, sizeof(flotantes));
}

