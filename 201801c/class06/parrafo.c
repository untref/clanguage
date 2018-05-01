#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "Parrafo.h"

void iterar(
    void* array, 
    unsigned elemCount, unsigned sizeOfType, 
    void (*doWork)(void*) 
) {
    unsigned i;
    for(i = 0; i < elemCount; i += sizeOfType) {
        (*doWork)(array + i);
    }
}

Parrafo* parrafo_init(Parrafo* this) {
    this->palabras = 0x0;
    this->cant  = 0x0;
    return this;
};

void parrafo_release(Parrafo* this) {
    if ( !this->palabras ) {
        return;
    }

    iterar(
        this->palabras, 
        this->cant * sizeof(Palabra), 
        sizeof(Palabra), 
        palabra_release
    );

    free( this->palabras );
    this->palabras = 0x0;
    this->cant = 0x0;
};

void parrafo_imprimir(Parrafo* this) {
    iterar(
        this->palabras, 
        this->cant * sizeof(Palabra), 
        sizeof(Palabra), 
        palabra_imprimir
    );
};

void parrafo_agregar_palabra(Parrafo* this, const char* strPalabra) {
    this->cant++;
    this->palabras = realloc(this->palabras, 
        this->cant * sizeof(Palabra) );

    // Initialize the new word
    unsigned offset = this->cant - 1;

    palabra_init( this->palabras + offset, strPalabra);
}

Parrafo* parrafo_reemplazar_palabra_con(
    Parrafo* this, const char* strPalabra, const char* strReemplazo) {
    unsigned index;

    for( index = 0; index < this->cant; ++index) {
        Palabra* p = this->palabras + index;

        if (palabra_es_igual(p, strPalabra) ) {
            palabra_reemplazar_con(p, strReemplazo);
        }
    };

    return this;
}

