#include <stdio.h>

void incShort(double* acm, void* pValue) ;
void printShort(unsigned index, void* value);

void iterate( void* collection, unsigned size, unsigned count, 
    void (doit)(unsigned, void*) );
double acumulate( void* collection, unsigned size, unsigned count, 
    void (acumulator)(double*, void*) ) ;

int main(int argc, char* argv[] ) {
  // EJERCICIO 0
  // Representar los números en punto flotante de 32bits (según IEEE 754):
  // 
  // Número 1: -1.4211822E-29     -> 0x8f902000
  // Número 2: 1.04018739E9       -> 0x4e780000
  // 

  // EJERCICIO 1
  // Cuál sería la representación binaria de estos números (16 bits de representación CON signo)
  // 
  // Número 3: 127
  // Número 4: -127
  //
  // EJERCICIO 2 
  // Una vez obtenida la respuesta anterior, si el mismo número fuera sin signo (unsigned short) 
  // cuál sería el valor que imprimiría el printf para ambos números? (predecir antes de escribir el
  // programa)
  // 
  short numero_3 = 127;
  short numero_4 = -127;

  unsigned short unumero_3 = numero_3;
  unsigned short unumero_4 = numero_4;

  printf("Numero 3: %d, numero 4: %d, uNumero3: %d, uNumero4: %d\n", numero_3, 
      numero_4, unumero_3, unumero_4 );

  // EJERCICIO 3
  // Dado un array de números (signed int, unsigned int, float, double, unsigend short ) implementar de 
  // el acumulado de todos los valores de la collection. 
  //
  // 
  short short_integers[] = { 1, 3, 4, 5, 129 };

  printf("Lista de numero a acumular\n");
  iterate( short_integers, sizeof(short),
      sizeof(short_integers) / sizeof(short),
      printShort);

  double acm = acumulate( short_integers, sizeof(short),
      sizeof(short_integers) / sizeof(short),
      incShort);

  printf("Lo acumulado: %lf\n", acm );


  return 0;
}

double acumulate( void* collection, unsigned size, unsigned count, 
    void (acumulator)(double*, void*) ) {
  unsigned i = 0;
  double acm = 0.0;

  for( i = 0; i < count; ++i ) {
    (*acumulator)(&acm, collection + i * size );
  }

  return acm;
}

void iterate( void* collection, unsigned size, unsigned count, 
    void (doit)(unsigned, void*) ) {
  unsigned i = 0;

  for( i = 0; i < count; ++i ) {
    (*doit)(i, collection + i * size );

  }
}


void incShort(double* acm, void* pValue) {
    short* pI = pValue;
    *acm += *pI;
}

void printShort(unsigned index, void* value) {
    short* pI = value;
    printf("indice: %4d, valor: %8d\n", index, *pI);
}


