#include <stdio.h>
#include <strings.h>
#include <stdlib.h>

#define TDA_TAM_CLAVE 10

struct un_tda {
    char clave[TDA_TAM_CLAVE];
    void* valor;
    unsigned tam;
};

void tda_init( struct un_tda* tda ) {
    bzero( tda, TDA_TAM_CLAVE);
};

void tda_clave_valor( struct un_tda* tda, char* clave, void* valor, unsigned tam) {
    strncpy( tda->clave, clave, TDA_TAM_CLAVE - 1);

    if ( tda->valor ) {
        free( tda->valor);
    }

    tda->valor = malloc( tam);
    memcpy( tda->valor, valor, tam);
    tda->tam = tam;
}

void tda_liberar(struct un_tda* tda) {
    if ( tda->valor ) {
        free(tda->valor);
        tda->valor = 0;
    }
}

// Esta funcion duplicara el tda origen
//
// IMPLEMENTARLA
//
struct un_tda* tda_duplicar( struct un_tda* origen) {
    return 0;
}

int main( int argc, char** argv) {
    struct un_tda uno;
    struct un_tda* replica;

    unsigned char valor_clave[] = { 0x21, 0x57, 0x1b };

    tda_init(&uno);

    tda_clave_valor(&uno, "esta q se va a cortar", valor_clave, sizeof(valor_clave) );

    replica = tda_duplicar(&uno);

    // Ejercicios:
    // 1. Escribir la funcion de ducplicacion
    // 2. Escribir todo el codigo necesario para que los recursos tomados (memoria) se
    // liberen antes q el codigo termine su ejecucion.
}
