#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "Nave.h"

Nave* nave_init(Nave* this, const char* nombre) {
    this->vida = 100;
    // opt 1 - OJO
    // this->nombre = nombre;
    // opt 2 - OJO
    // strcpy(this->nombre, nombre);
    this->nombre = (char*)malloc( sizeof(char) * (strlen(nombre) + 1) );
    strcpy(this->nombre, nombre);

    return this;
}

void nave_release(Nave* this) {
    if ( this->nombre ) {
        free( this->nombre );
    }
    this->nombre = 0x0;
}

void nave_imprimir(void* this) {
    Nave* self = (Nave*)this;
    printf("nombre: %s, vida: %d\n", self->nombre, self->vida);
}

