#include <stdio.h>

int main(int argc, char** argv) {
  signed int value = 0;

  printf( "pre increment: %d\n", ++value );
  printf( "post increment: %d\n", value++ );
  printf( "value: %d\n", value );
  
  return 0;
}




