#include <stdio.h>

/****
 * Imprimir valores de un array de enteros
 * */

int main(int argc, char** argv){
  int enteros[] = {1,2,3,4};
  unsigned inx = 0,
           cant = sizeof(enteros) / sizeof(int);

  for(inx = 0; inx < cant; ++inx) {
    int *pi = enteros + inx;
    printf("Indice (%2d) Valor: (%4d)\n", 
        inx, *pi);
  }
  return 0;
}
