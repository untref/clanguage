#ifndef LISTA_INCLUDED
#define LISTA_INCLUDED

typedef struct _Nodo Nodo;
typedef struct _Nodo {
    void* dato;
    Nodo* proximo;
} Nodo;

void lista_init(Nodo* this);
void lista_push(Nodo* this, const void* dato, unsigned tamanio);

#endif // LISTA_INCLUDED
