#include <stdio.h>

#include "Cadena.h"

int main(int argc, char** argv) {
  Cadena miCadena;
  Cadena miOtraCadena;

  inicializar(&miCadena);
  inicializar(&miOtraCadena);

  modificar( &miCadena, "Este es el" );

  concatenarStr( &miCadena, " contenido del array" );

  printf( "array: %s\n", devolverStr(&miCadena) );

  concatenarCadena( &miCadena, &miOtraCadena);

  printf( "array: %s\n", devolverStr(&miCadena) );
}
