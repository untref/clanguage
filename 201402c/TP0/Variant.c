#include <stdlib.h>
#include <string.h>

#include "Variant.h"


void initialize(Variant* variant) {
  variant->dataSize = 0;
  variant->data = 0;
  variant->count = 0;
}

void release(Variant* variant) {
  variant->dataSize = 0;
  variant->count = 0;

  if ( variant->data )
    free( variant->data );

  variant->data = 0;
}

void set( Variant* v, void* data, unsigned length, unsigned elements) {
  v->dataSize = length;
  v->count = elements;   // Estoy configurando un único entero

  // COMO DATA ES UN PUNTERO QUE NUNCA RECIBIO UN
  // MALLOC NO APUNTA A UN LUGAR CON SUFICIENTE ESPACIO
  // PARA CONTENER UN ENTERO.  ENTONCES HAGO UN ALLOC
  //
  // OJO
  // Antes de hacer un malloc me fijo si el puntero tiene
  // un valor alguien antes realizo un malloc, entonces
  // libero y luego aloco
  //
  if ( v->data )
    free( v->data );

  v->data = malloc( length );

  // Ahora necesito copiar el contenido
  memcpy( v->data, data, length);

}

int getInteger(Variant* v) {
  int result = *(int*)v->data;
  return result;
}

double getDouble(Variant* v) {
  double result = *(double*)v->data;
  return result;
}

char* getString(Variant* v) {
  return (char*)v->data;
}
