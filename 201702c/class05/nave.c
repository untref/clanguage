#include <stdlib.h>
#include <string.h>

#include "nave.h"

void nave_init(Nave* this, char* nombre) {
    this->vidas = 12;

    if ( nombre == 0x0 ) {
        this->nombre = nombre;
        return;
    } 

    this->nombre = (char*)malloc( strlen(nombre) + 1);
    strcpy(this->nombre, nombre);
};

void nave_release(Nave* this) {
    if ( this->nombre ) {
        free( this->nombre );
    }
    this->nombre = 0x0;
};


