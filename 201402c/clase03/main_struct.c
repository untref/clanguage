#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef unsigned Intero;
typedef float    Flotane;


typedef struct Variant {
  unsigned int size;
  void*        data;
  char         c;
} Variant;

int main(int argc, char** argv ) {
  Variant* pVariant = 0;

  pVariant = (Variant*)malloc( sizeof(struct Variant) );

  printf( "size: %d\n", pVariant->size );
  printf( "char: %d\n", pVariant->c);

  printf("sizeof: %d\n", sizeof(Variant));
  return 0;
}


