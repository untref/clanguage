#ifndef MATRIZ_H_INCLUDED
#define MATRIZ_H_INCLUDED

typedef struct _Matriz {
  unsigned elementCount;
  int* elements;
} Matriz;

void matriz_init(Matriz* this, unsigned elementCount);
void matriz_free(Matriz* this);
int matriz_at(Matriz* this, unsigned row, unsigned col);
void matriz_set_at(Matriz* this, unsigned row, unsigned col, int value);

#endif // MATRIZ_H_INCLUDED
