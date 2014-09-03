#include <stdio.h>

void swap( double a, double b ) { // IT'S WORNG!!!!
  double tmp = b;
  b = a;
  a = tmp;
}

// FORWARD DECLARTION
void swap2( double* a, double* b );

double average(double a, double b) {
  return (a+b)/2.0;
}

double average2( double* values, unsigned count ) {
  double acum = 0;

  for( unsigned i = 0; i < count; ++i ) {
    acum += values[i];
  }

  return acum / (double)count;
}

void print(void* value) {
  double* v = value;
  printf("Valor: %f\n", *v );
}

void iterate(double* values, unsigned count, void (doit)(void*) ) {
  for( unsigned i = 0; i < count; ++i ) {
    (*doit)(values+i);
  }
}

void iterate2(void* values, unsigned sizeOfEach, unsigned count, void (doit)(void*) ) {
  for( unsigned i = 0; i < count; ++i ) {
    (*doit)( values + i * sizeOfEach );
  }
}


int main(int argc, char** argv) {
  double array[] = { 4, 6, 2};
  printf("Average between 4 and 6: %f\n", average( 4, 6 ) );
  printf("Average between 4, 6, 2: %f\n", average2( array, sizeof(array) / sizeof(double) ));

  printf("First iteration...\n");
  iterate( array, sizeof(array) / sizeof(double), print );

  printf("Second iteration...\n");
  iterate2( array, sizeof(double), sizeof(array) / sizeof(double), print );


  printf("Swapping values...\n");
  swap( array[0], array[2] );
  iterate( array, sizeof(array) / sizeof(double), print );

  printf("Let's try new swapping ...\n");
  swap2( array+0, array+2 );
  iterate( array, sizeof(array) / sizeof(double), print );

 
}


// DEFINITION
void swap2( double* a, double* b ) {
  double tmp = *b;
  *b = *a;
  *a = tmp;
}

