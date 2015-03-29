// Directivas de precompilador
#include <stdio.h>
#define PI 3.14

int main( int argc, char** argv) {
	printf("pasaron argumentos: %d. valor verdad: %d\n", argc, argc > 2 );
    
	// Valor de verdad 0 es falso y todo otro valor <> 0 es verdadero
 	if ( 172 ) {
 		printf("si\n");
  }

	printf( "primer argumento: %s - %s\n", argv[0], argv[1] );

  printf("hola mundo\n");
  printf( "%f\n", 2.0 * 2.0 * PI );

  return 0;
}
