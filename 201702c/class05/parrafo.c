#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "parrafo.h"

void parrafo_inicializar(Parrafo* this) {
    this->palabras = 0x0;
    this->cantidad = 0;
};

void parrafo_liberar(Parrafo* this) {
    Palabra* corriente = this->palabras;

    while( (corriente - this->palabras) < this->cantidad ) {
        palabra_liberar( corriente );
        corriente++;
    }

    free( this->palabras );
};

void parrafo_mostrar(Parrafo* this) {
    Palabra* corriente = this->palabras;

    while( (corriente - this->palabras) < this->cantidad ) {
        palabra_mostrar( corriente );
        printf(" ");
        corriente++;
    }
};

void parrafo_reemplazar(Parrafo* this, const char* palabra, const char* otraPalabra) {

    Palabra* corriente = this->palabras;

    while( (corriente - this->palabras) < this->cantidad ) {
        palabra_reemplazar_si_coincide(corriente, palabra, otraPalabra);
        corriente++;
    }
};

void parrafo_agregar_palabra(Parrafo* this, char* palabra)  {
    unsigned nuevaCantidad = this->cantidad + 1;

    this->palabras = realloc( this->palabras, sizeof(Palabra) * nuevaCantidad);

    palabra_inicializar( this->palabras + this->cantidad, palabra );

    this->cantidad = nuevaCantidad;
};


