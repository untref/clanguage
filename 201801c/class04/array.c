#include <stdio.h>
#include <string.h>

char sonIguales(void* pA, void* pB, unsigned tam) {
    return memcmp(pA, pB, tam) == 0x0;
}

void* buscamosEnteros( void* enteros, unsigned cantidadEnteros, unsigned tamElem,
    void* consulta) {

    for(unsigned i = 0; i < cantidadEnteros; i += tamElem) {
        if ( sonIguales( enteros+i, consulta, tamElem) ) {
            return enteros+i; // &enteros[i]
        }
    }

    return NULL; // 0x0, 0
}

int main(int argc, char** argv) {
    {
        short enteros[] = { 1, 2, 3 };

        short copia = 3;            // tengo que tener enteros[1]
        // enteros, &enteros, &enteros[0]
        short* pos = buscamosEnteros(
            enteros, 
            sizeof(enteros),
            sizeof(short),
            &copia
        );

        printf("linea: %d - %p - elemento: %d\n", __LINE__, pos, *pos);
    }

    {
        double enteros[] = { 1, 2, 3 };

        double copia = 3;            // tengo que tener enteros[1]
        // enteros, &enteros, &enteros[0]
        double* pos = buscamosEnteros(
            enteros, 
            sizeof(enteros),
            sizeof(double),
            &copia
        );

        printf("linea: %d - %p - elemento: %f\n", __LINE__, pos, *pos);
    }

    {
        double enteros[] = { 1, 2, 3 };

        double copia = 9;            // tengo que tener enteros[1]
        // enteros, &enteros, &enteros[0]
        double* pos = buscamosEnteros(
            enteros, 
            sizeof(enteros),
            sizeof(double),
            &copia
        );

        if ( pos == 0x0 ) {
            printf("linea: %d - no lo encontré\n", __LINE__);
            return -1;
        }

        printf("linea: %d - %p - elemento: %f\n", __LINE__, pos, *pos);
    }

} 

