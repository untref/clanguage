#include <stdlib.h>
#include <string.h>
#include <stdio.h>

typedef int (*TipoOperadorBinario)(int, int);

int suma(int a, int b) {
  return a + b;
}

int resta(int a, int b) {
  return a - b;
}

int mult(int a, int b) {
  return a * b;
}

int buscar(char o, char* operadores, unsigned cant) {
  char* b = operadores;
  while(cant--) {
    if ( *b == o) {
      return b - operadores;
    }
    b++;
  }
  return 0;
}

int main(int argc, char* argv[]) {

  int a = atoi(argv[1]);
  char* o = argv[2];
  int b = atoi(argv[3]);
  int resultado = 0;
  TipoOperadorBinario operador_binario = &suma;
  char        operadores[] = {'+',    '-',    't' };
  TipoOperadorBinario ob[] = { &suma, &resta, &mult };

  int indice = buscar(*o, operadores, sizeof(operadores));
  operador_binario = ob[indice];
  resultado = (*operador_binario)(a,b);
  printf("%d %s %d = %d\n", a, o, b, resultado);

  return 0;
}
