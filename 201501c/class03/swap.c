#include <stdio.h>

void swap( double a, double b ) { // IT'S WORNG!!!!
  double tmp = b;
  b = a;
  a = tmp;
}

// FORWARD DECLARTION
void swap2( double* a, double* b );

int main(int argc, char** argv) {
  double array[] = { 4, 6, 2};

  printf("Swapping values...\n");
  swap( array[0], array[2] );

  printf("Let's try new swapping ...\n");
  swap2( array+0, array+2 );

}

// DEFINITION
void swap2( double* a, double* b ) {
  double tmp = *b;
  *b = *a;
  *a = tmp;
}

