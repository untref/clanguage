#include <string.h>
#include <stdlib.h>

#include "matriz.h"

void matriz_init(Matriz* this, unsigned elementCount) {
  this->elementCount = elementCount;
  this->elements = malloc(sizeof(int) * elementCount * elementCount);
}

void matriz_free(Matriz* this) {
    if ( !this || !this->elements ) {
        return;
    };
    free(this->elements);
    this->elements = NULL;
    this->elementCount = 0;
};

void matriz_set_at(Matriz* this, unsigned row, unsigned col, int value) {
    // Completar con el codigo que hacen funcionar los tests
    //
    // Ayuda: Como los punteros son enteros se pueden sumar, restar
    // multiplicar.
    return;
}

int matriz_at(Matriz* this, unsigned row, unsigned col) {
    // Completar con el codigo que hacen funcionar los tests
    //
    // Ayuda: Como los punteros son enteros se pueden sumar, restar
    // multiplicar.

    return 0;
};
