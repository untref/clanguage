#include <stdio.h>
#include <stdlib.h>

#include "circulo.h"

int main(int argc, char** argv ) {
  Circulo c;

  circulo_inicializar( &c );

  printf( "perimetro: %f\n", circulo_perimetro( &c ) );

  return 0;
}

