#include "Nave.h"

#include <string.h>
#include <stdio.h>
#include <stdlib.h>

void nave_init(Nave* this, char* nombre) {
  this->vida = 10;
  this->nombre = malloc( strlen(nombre) + 1);
  strcpy(this->nombre, nombre);
}

void nave_clonar(Nave* this, Nave* otra) {
  otra->vida = this->vida;
  otra->nombre = malloc( strlen(this->nombre) + 1);
  strcpy(otra->nombre, this->nombre);
}

void nave_limpiar(Nave* this) {
  if ( this->nombre ) {
    free(this->nombre);
  }
  this->nombre = 0;
};

void nave_print(Nave* this) {
  printf("Nave: vidas(%d) - nombre('%s')\n", this->vida, this->nombre);
}



