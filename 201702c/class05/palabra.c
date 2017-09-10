#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "palabra.h"

void palabra_inicializar(Palabra* this, const char* texto) {
    this->texto = 0x0;

    if ( texto == 0x0 ) {
        return;
    };

    palabra_cambiar(this, texto);
};

void palabra_liberar(Palabra* this) {
    if ( this->texto != 0x0 ) {
        free( this->texto );
    }
    this->texto = 0x0;
};

void palabra_mostrar(const Palabra* this) {
    printf("%s", this->texto );
};

void palabra_cambiar(Palabra* this, const char* nuevoValor) {
    palabra_liberar(this);

    this->texto = (char*)malloc( strlen(nuevoValor) + 1);
    strcpy( this->texto, nuevoValor);
};

void palabra_reemplazar_si_coincide(Palabra* this, 
        const char* palabra, 
        const char* otraPalabra
) {
    if ( strcmp(this->texto, palabra) != 0x0 ) {
        return;
    };

    palabra_cambiar(this, otraPalabra);
};

