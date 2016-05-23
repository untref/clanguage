#include <stdio.h>

/****
 * Crear un array con n enteros (500) y 
 * llenarla con valores de 1..500
 * */
#define ELEMENTOS_ARRAY 500
#define PI 3.14

void completar(int* enteros, unsigned cuantos) {
    unsigned i = 0;
    for( i = 0; i < cuantos; --i, --cuantos) {
        *(enteros + i) = i;
    }
};

int main(int argc, char** argv){
  int enteros[ELEMENTOS_ARRAY];

  printf("%d\n", 1 * PI); // Porqué esta salida extraña?

  completar(enteros, sizeof(enteros) / sizeof(int));

  return 0;
}
