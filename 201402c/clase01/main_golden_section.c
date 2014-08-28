#include <stdio.h>
#include <math.h>

int main(int argc, char** argv) {
  // Auto truncamiento
  float exprDiv = 1 / 2;
  printf( "Ojo con esta expresión '1 / 2', resulta: %f\n", exprDiv );       // El valor de esta expresión será 0

  exprDiv = 1 / 2.0;
  printf( "Ojo con esta expresión '1 / 2.0', resulta: %f\n", exprDiv );       // El valor de esta expresión será 0.5


  // Auto promoción
  printf( "Acerca de los tamaños: %d\n", sizeof(2.0));                      // Porqué el valor es 8 y no 4 (tamaño del float)

  // Numero auro
  double fi = ( 1.0 + sqrt(5.0) ) / 2.0;
  double invFi = 1.0 / fi;

  printf("golden ratio: %lf\n", fi);
  printf("inverse golden ratio: %lf\n", invFi);

  // -1 / fi = 1 - fi
  printf( "-1 / fi = 1 - fi: %f\n", (+1.0 / fi) + 1.0 - fi);

  // fi * fi = 1 + fi
  printf( "fi * fi: %f\n", fi * fi) ;
  printf( "- 1 - fi: %f\n", - 1 - fi) ;

  printf( "Precedencia de operadores: %f\n", 12 + 6 / 2.0);                 // El valor de esta expresión será 0.5

  int increment = 55;

  printf("Initial value: %d\n", increment );
  printf("Pre increment: %d\n", ++increment );
  printf("Pos increment: %d\n", increment++ );
  printf("Final value: %d\n", increment );
  return 0;
}




