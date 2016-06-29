#include "Cadena.h"

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

Cadena* cadena_inicializar(Cadena* this, char* valor_inicial, unsigned tam) {
    this->dato = (char*)malloc(tam);
    memcpy(this->dato, valor_inicial, tam);
    this->tam = tam;
};

Cadena* cadena_modificar(Cadena* this, char* valor_inicial) {
    if ( this->dato ) {
        free(this->dato);
    }

    this->tam = strlen( valor_inicial );
    this->dato = (char*)malloc( this->tam );
    memcpy( this->dato, valor_inicial, this->tam );
    
}

Cadena* cadena_concatenar(Cadena* this, char* valor) {
    unsigned l = strlen(valor);
    unsigned nuevaLongitud = this->tam + l;
    char* nuevoDato = malloc(nuevaLongitud);

    memcpy(nuevoDato, this->dato, this->tam);
    memcpy(nuevoDato + this->tam, valor, l);

    free(this->dato);

    this->dato = nuevoDato;
    this->tam = nuevaLongitud;
};
    
Cadena* cadena_print(Cadena* this) {
    unsigned t = this->tam;
    char* p = this->dato;

    while (t--) {
        printf("0x%02X ", *p);
        ++p;
    }

    printf("\n");
};

Cadena* cadena_limpiar(Cadena* this) {
    if ( this->dato ) {
        free(this->dato);
    }

    this->dato = 0;
    this->tam = 0;
};
