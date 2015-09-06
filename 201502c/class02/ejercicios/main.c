#include <stdio.h>
#include <stdlib.h>

#include "../../assertion.h"

#define ARRAY_ENTEROS_TAMANO 1024
#define ARRAY_FLOTANTES_TAMANO 1024

void copiarArrayEnteros(int dest[], unsigned int dCount, int* orig, unsigned oCount) {
#if 0   // Con corchetes
    int i;

    // Copio si hay lugar en el destino
    for (i = 0; i < dCount && i < oCount; ++i) {
        dest[i] = orig[i];
    }
#endif // 0

    // Mientras que haya lugar en destino y elementos en origen
    while( dCount-- && oCount-- ) {
        *dest++ = *orig++;
    }

    return;
}

void copiarArrayFlotantes(double dest[], unsigned int dCount,
                          double* orig, unsigned int oCount ) {
    // Mientras que haya lugar en destino y elementos en origen
    while( dCount-- && oCount-- ) {
        *dest++ = *orig++;
    }

    return;
}


// Devuelve 1 si son iguales, sino 0
unsigned igualdadArrayEnteros(int *a1, unsigned int a1Count,
                              int *a2, unsigned int a2Count ) {

#if 0
    int igualdad = 1;
    int count = 0;

    while (count < ARRAY_ENTEROS_TAMANO && igualdad) {
        igualdad = *a2 == *a1;
        ++a1;
        ++a2;
        count++;
    }

    return igualdad;
#endif

#if 0
    int i;
    int result = a1Count == a2Count;

    for(i = 0; i < a1Count && result; ++i) {
        result = a1[i] == a2[i];
    }
#endif // 0
    int result = a1Count == a2Count;

    while( result && a1Count--) {
        result = *a1++ == *a2++;
    };

    return result;
}

// Devuelve 1 si son iguales, sino 0
unsigned igualdadArrayFlotantes(double *a1, unsigned int a1Count,
                                double* a2, unsigned int a2Count ) {
    int result = a1Count == a2Count;

    while( result && a1Count--) {
        result = *a1++ == *a2++;
    };

    return result;
}

unsigned compare(void* _a1, unsigned s1, void* _a2, unsigned s2 ) {
    unsigned result = s1 == s2;
    char* a1 = _a1;
    char* a2 = _a2;

    while( result && s1--) {
        result = *a1++ == *a2++;
    };

    return result;
}

void copy(void* dest, unsigned s1, void* orig, unsigned s2 ) {
    char* d = dest;
    char* o = orig;

    while( s1-- && s2-- ) {
        *d++ = *o++;
    }

    return;
}

char* buscar(char* donde, char* que) {
    char* resultado = donde;
    char* copiaQue = que;

    // Busco mientras que donde no se haya terminado y mientras que copiaQue
    // no sea nula (si se volvió nula es porque encontré 'que' en 'donde'
    while( *donde && *copiaQue) {
        copiaQue = que;

        // Siempre me guardo donde empiezo a buscar porque si lo
        // encuentro ya se donde empezó
        resultado = donde;

        // Busco 'que' en donde mientras que 'donde' no se termine y
        // además mientras q donde contenga toda la secuencia 'que'
        while( *donde && *donde++ == *copiaQue) {
            ++copiaQue;
        }
    }

    return resultado;

}
void reemplazar(char* contenido, char* palabra, char* otraPalabra ) {
    char* busqueda = buscar(contenido, palabra);

    // Fase de reemplazo
    while( *busqueda && *otraPalabra) {
        *busqueda++ = *otraPalabra++;
    };
}


void debug(int* array, unsigned count) {
    while (count--) {
        printf("%d\n", *array++);
    }
}
// Modificar el código de las funciones y de ser necesario sus parámetros de modo
// de hacer que los tests pasen.
int main()
{
    { // Array de enteros
        int arrayEnteros00[] = { 1, 2, 3, 4, 5, 6, 7, 8};
        int arrayEnteros01[] = { 1, 2, 3, 4, 5, 6, 7, 8};

        deny(
             igualdadArrayEnteros(
                                  arrayEnteros01,
                                  sizeof(arrayEnteros01) / sizeof(int),
                                  arrayEnteros00,
                                  sizeof(arrayEnteros00) / sizeof(int)
                                  ),
             0
             );
    }

    { // Array de enteros
        int a0[] = { 1, 2, 3, 4, 5, 6, 7, 8};
        int a1[] = { 1, 2, 3, 5, 5, 6, 7, 8};

        deny( igualdadArrayEnteros(
                                   a1, sizeof(a1) / sizeof(int), a0, sizeof(a0) / sizeof(int)
                                   ), 1
              );
    }

    {
        int array[] = { 11, 22, 33, 44, 55, 66, 77, 88};

        // Aloco sizeof(int) * ARRAY_ENTEROS_TAMANO bytes. Contien basura
        int otroArray[ARRAY_ENTEROS_TAMANO];

        copiarArrayEnteros(otroArray, sizeof(otroArray) / sizeof(int), array, sizeof(array) / sizeof(int));
        assert(
               igualdadArrayEnteros(
                                    array, sizeof(array) / sizeof(int),
                                    otroArray, sizeof(array) / sizeof(int) ), 1 );

    }
    { // Array de doubles
        double arrayFlotantes00[] = { 1.1, 2.2, 3.3, 4.4, 5.5, 6.6, 7.7, 8.8};
        double destino[ARRAY_FLOTANTES_TAMANO];

        unsigned tamOrig = sizeof(arrayFlotantes00) / sizeof(double);
        unsigned tamDest = sizeof(destino) / sizeof(double);


        deny( igualdadArrayFlotantes( arrayFlotantes00, tamOrig, destino, tamOrig ), 1);
        copiarArrayFlotantes(destino, tamDest, arrayFlotantes00, tamOrig);
        assert( igualdadArrayFlotantes( arrayFlotantes00, tamOrig, destino, tamOrig ), 1);


    }


    // Aprovechando la genericidad de la memoria
    {
        int eD[ARRAY_ENTEROS_TAMANO] = {};
        int eO[] = {1,2,3,4};

        double fD[ARRAY_FLOTANTES_TAMANO] = {};
        double fO[] = {1.1,2.2,3.3,4.4};

        unsigned tamEO = sizeof(eO);
        unsigned tamFO = sizeof(fO);

        deny(compare(eO, tamEO, eD, tamEO), 1);
        deny(compare(fO, tamFO, fD, tamFO), 1);

        copy(eD, sizeof(eD), eO, sizeof(eO));
        copy(fD, sizeof(fD), fO, sizeof(fO));

        assert(compare(eO, tamEO, eD, tamEO), 1);
        assert(compare(fO, tamFO, fD, tamFO), 1);

    }

    { // String
        char string[] = "Insertar aqui otra cosa";

        // Definir funcion para que el assert pase
        reemplazar(string, "aqui", "esto");
        assertStr(string, "Insertar esto otra cosa" );

        // Hacer que el assert pase escribiendo solo una linea
        string[8] = 0;
        assertStr(string, "Insertar");
    }
    return 0;
}



















































// TODO
// - Heap
// ok Que tan generica es la memoria
// ok Intercambiar variables
// - Structs
// - Listas
