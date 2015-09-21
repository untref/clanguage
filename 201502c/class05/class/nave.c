#include <string.h>
#include <stdio.h>

#include "nave.h"

void nave_init(Nave* this, const char* nombre) {
    this->vida = 10;
    const char* n = (nombre) ? nombre : "";

    strcpy(this->nombre, n);
}

void nave_daniar(Nave* this, int danio) {
    this->vida -= danio;
}

void nave_print(Nave* this) {
    printf("nombre: %s - vidas: %d\n", this->nombre, this->vida);
}
