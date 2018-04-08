#include <stdio.h>

//void imprimirEnteros(int otrosEnteros[] ) {
void imprimirEnteros(int* otrosEnteros, int count ) {
    printf("linea: %d - anidado\n", __LINE__);
    printf("linea: %d - tamano enteros (%lu)\n", __LINE__, sizeof(otrosEnteros));

    for( int i = 0; i < count; ++i) {
        printf("linea: %d - [%d]: (%d)\n", __LINE__, i, otrosEnteros[i]);
    }

}

int main(int argc, char** argv) {
    int enteros[] = { 1, 2, 3, 6,6,7,7,8};


    printf("linea: %d - tamano enteros (%lu)\n", __LINE__, sizeof(enteros));

    for( int i = 0; i < sizeof(enteros) / sizeof(int); ++i) {
        printf("linea: %d - [%d]: (%d)\n", __LINE__, i, enteros[i]);
    }



    imprimirEnteros(enteros, sizeof(enteros) / sizeof(int) );

} 
