#include <stdlib.h>
#include <stdio.h>

/****
 * Problema pendiente de resolución
 */
int Numero ;

void inicializar(Numero* a, unsigned c) {
  while( c-- ) {
    *a = 0;
    a++;
  }
  bzero
  return;
};

Numero sumatoria(Numero * a, unsigned c) {
  Numero resultado = 0;

  while( c-- ) {
    resultado += *a;
    a++;
  }

  return resultado;
};

void imprimir(Numero* a, unsigned c) {
  Numero* b = a;

  while( c-- ) {
    printf("i: %ld v: %d\n", b - a, *b);
    b++;
  }

  return;
};

Numero main(Numero argc, char* argv[]) {

  // No es puede porq utilizamos stack
  // Numero enteros[] = {1,2};
  
  unsigned cant = 5;
  Numero* enteros = (Numero*)malloc(cant * sizeof(Numero));

  inicializar(enteros, cant);
  enteros[1] = 4;
  imprimir(enteros, cant);
  printf("sumatoria: %d\n", sumatoria(enteros, cant) );
  
  free(enteros);
  enteros = 0;

  return 0;
}
