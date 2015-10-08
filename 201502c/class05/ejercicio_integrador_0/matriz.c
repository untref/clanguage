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

int* matriz_offset(Matriz* this, unsigned row, unsigned col) {
    return (this->elements + row * this->elementCount * sizeof(int)) + (col * sizeof(int));
}

void matriz_set_at(Matriz* this, unsigned row, unsigned col, int value) {
    int * e = matriz_offset(this, row, col);
    *e = value;
    return;
}

int matriz_at(Matriz* this, unsigned row, unsigned col) {
    int * e = matriz_offset(this, row, col);
    return *e;
};
