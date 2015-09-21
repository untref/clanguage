#include <stdlib.h>

#include "lista.h"

void lista_init(Nodo* this) {
    memset(this, 0, sizeof(Nodo));
};

void lista_push(Nodo* this, const void* dato, unsigned tamano) {
    this->dato = malloc(tamano);
    memcpy(this->dato, dato, tamano);
}

void lista_liberar(Nodo* this) {
    free(this->dato);
    this->dato = 0;
}


