#include <stdio.h>
#include <stdlib.h>

typedef void (*Acumulador)(void* /* lo acumulado */, void* /* elemento array */);

void acumulador_enteros(void* _acum, void* _valor) {
  int* acum = (int*)_acum;
  int* valor = (int*)_valor;
  *acum += *valor;
} 

void sumatoria(void* vector, unsigned tam_dato, int cant, void* resultado, Acumulador f) {
  while(cant--) {
    (*f)(resultado, vector);
    vector += tam_dato;
  }
}

void binit(void* p, unsigned c) ;
int main(int argc, char* argv[]) {
  int enteros[] = {1,2,3,4};
  int r = 0x0;
  sumatoria(enteros,   sizeof(int),   sizeof(enteros)/sizeof(int), 
      &r, &acumulador_enteros);

  printf("sumatoria: %d\n", r);
}

void binit(void* p, unsigned c) {
  char* t = p;
  while(c--) {
    *t = 0x0;
    t++;
  }
}

