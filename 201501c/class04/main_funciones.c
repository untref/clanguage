#include <stdio.h>

// Forward declaration
void printDouble(void* value) {
  double* v = value;
  printf("Valor: %f\n", *v );
}

// Iteracion de array floats
void iterate(double* values, unsigned count, void (doit)(void*) ) {
  unsigned i;
  for( i = 0; i < count; ++i ) {
    (*doit)(values+i);
  }
}

// Iteracion generica
void iterate2(void* values, unsigned sizeOfEach, unsigned count, void (doit)(void*) ) {

    /**
     * Noten q el puntero a void puede utilizarse para hacer cuentas.
     * Al utilizarlo e incrementarlo este aumenta en una unidad (tal como lo hace)
     * char*, diferente ocurre con los otros tipos de punteros los que se incrementan
     * de modo de apuntar al siguiente elemento del hipotetico array
     */

    unsigned i;
    for( i = 0; i < count; ++i ) {
        (*doit)( values + i * sizeOfEach );
    }
}


int main(int argc, char** argv) {
  double array[] = { 4, 6, 2};

  printf("First iteration...\n");
  iterate( array, sizeof(array) / sizeof(double), printDouble );

  printf("Second iteration...\n");
  iterate2( array, sizeof(double), sizeof(array) / sizeof(double), printDouble );

};


