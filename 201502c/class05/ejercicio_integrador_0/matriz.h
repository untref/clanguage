#ifndef MATRIZ_H_INCLUDED
#define MATRIZ_H_INCLUDED

typedef struct _Matriz {
  unsigned elementCount;
  int* elements;
} Matriz;

/**
 * Inicializa el TDA 
 */
void matriz_init(Matriz* this, unsigned elementCount);

/**
 * Libera recursos alocados por el TDA
 */
void matriz_free(Matriz* this);

/**
 * Retorna el valor de la celda en row, col
 */
int matriz_at(Matriz* this, unsigned row, unsigned col);

/**
 * Cambia el valor de la celda en row, col
 */
void matriz_set_at(Matriz* this, unsigned row, unsigned col, int value);

int* matriz_offset(Matriz* this, unsigned row, unsigned col);


#endif // MATRIZ_H_INCLUDED
