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

void assign(Variant* dst, Variant* org) {
  // Antes de asignar los datos tengo que asegurarme que destino 
  // no tenga un puntero con valor que apunte al heap.  Si es así
  // lo libero
  if ( dst->data ) 
    free( dst->data );

  // Copio los datos entre estructuras
  dst->count = org->count;
  dst->dataSize = org->dataSize;

  // Aca tenemos que copiar los dataos
  // Si hacemos la siguiente asignación resultará que ambos 
  // variants compartiran el espacio de datos y esta no es la
  // intención
  //
  // dst->data = org->data
  //
  // ESTO NO ES LO QUE QUIERO
  //

  // Necesito generar un nuevo espacio de datos en el destino y
  // luego copiar los datos entre variants

  // Aloco la cantiad de datos segun el origen  requiera
  dst->data = malloc( org->dataSize );  

  // Copio los datos
  memcpy( dst->data, org->data, org->dataSize );

}

Variant* duplicate(Variant* org) {
  // Aquí sí es nesecario el caseteo por la asignación que
  // estamos haciendo
  Variant* result = (Variant*)malloc( sizeof(Variant) );

  // IMPORTANTE 
  // La precondicion del asignar es que ambas estructuras
  // esten inicializadas
  initialize( result );

  // Luego que aloqué memoria para el nuevo variant
  // puedo utilizar la asignación
  //
  // EN AMBOS CASOS NO NECESITO EN '&' AMBOS SON
  // PUNTEROS
  assign( result, org );

  return result;
}


