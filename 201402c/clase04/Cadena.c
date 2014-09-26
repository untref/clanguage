#include "Cadena.h"

#include <string.h>
#include <stdlib.h>

Cadena* inicializar(Cadena* c) {
  c->data = 0;
  c->length = 0;
  return c;
}

void liberar(Cadena* c) {
  if ( c->data ) 
    free( c->data );

  c->data = 0;
  c->length = 0;
}

const char* devolverStr(Cadena* c) {
  return c->data;
}

Cadena* modificar(Cadena* c, const char* dato) {
  if ( c->data )
    free(c->data);

  c->data = (char*)malloc( strlen(dato) + 1);
  memcpy( c->data, dato, strlen(dato) + 1);
  c->length = strlen(dato);
}

Cadena* concatenarStr(Cadena* c, const char* dato) {
  if ( dato == 0)   /* null str */
    return c;

  if ( strlen(dato) == 0) /* empty str */
    return c;

  c->data = realloc(c->data, strlen(dato) + 1 );
  memcpy( c->data + c->length,  dato, strlen(dato) + 1);
  c->length += strlen(dato);
}

Cadena* concatenarCadena(Cadena* dst, Cadena* org) {
  concatenarStr( dst, org->data );
}
