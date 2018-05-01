#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "Palabra.h"

Palabra* palabra_init(Palabra* this, const char* strPalabra) {
    this->valor = malloc( sizeof(char) * (strlen(strPalabra) + 1));
    strcpy(this->valor, strPalabra);

    return this;
};

void palabra_release(void* self) {
    Palabra* this = (Palabra*)self;
    if ( this->valor ) {
        free( this->valor );
    }
    this->valor = 0x0;
};

void palabra_imprimir(void* self) {
    Palabra* this = (Palabra*)self;
    printf("%s", this->valor);
};

Palabra* palabra_reemplazar_con(Palabra* this, const char* strPalabra) {
    this->valor = realloc( this->valor, strlen(strPalabra) + 1);
    strcpy(this->valor, strPalabra);

    return this;
};

unsigned palabra_es_igual(Palabra* this, const char* strPalabra) {
    return !strcmp(this->valor, strPalabra);
};

