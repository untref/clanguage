#include <stdio.h>

/****
 * Imprimir valores de un enterosay de enteros
 * */
void imprimir(int* enteros /* es equivalente a 'int enteros[]' */, unsigned cant) {
  // Cual es el sizeof(enteros)? Porqué?
  unsigned inx = 0;

  for(inx = 0; inx < cant; ++inx) {
    int *pi = enteros + inx;
    printf("Indice (%2d) Valor: (%4d)\n", 
        inx, *pi);
  }

  printf("========================\n");
}

int main(int argc, char** argv){
  int enteros[] = {1,2,3,4};

  // Maneras equivalentes de acceder al incio de un array
  imprimir(enteros, sizeof(enteros) / sizeof(int));
  imprimir(&enteros, sizeof(enteros) / sizeof(int));
  imprimir(&enteros[0], sizeof(enteros) / sizeof(int));

  // Cual es el sizeof(enteros)?
  unsigned inx = 0,
           cant = sizeof(enteros) / sizeof(int);

  for(inx = 0; inx < cant; ++inx) {
    int *pi = enteros + inx;
    printf("Indice (%2d) Valor: (%4d)\n", 
        inx, *pi);
  }

  return 0;
}
