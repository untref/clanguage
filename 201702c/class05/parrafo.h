#ifndef __PARRAFO_H__
#define __PARRAFO_H__

#include "palabra.h"

typedef struct _parrafo {
    Palabra* palabras;
    unsigned cantidad;
} Parrafo;

void parrafo_inicializar(Parrafo* this);
void parrafo_mostrar(Parrafo* this);

void parrafo_reemplazar(Parrafo* this, const char* palabra, const char* otraPalabra);

void parrafo_liberar(Parrafo* this);

void parrafo_agregar_palabra(Parrafo* this, char* thisalabra) ;



#endif
