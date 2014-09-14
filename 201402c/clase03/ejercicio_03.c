#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct complexData {
  unsigned  anInteger;
  char*     anArray; 
  unsigned  arraySize;
} ComplaxData ;

void initialize(ComplaxData* cmp);

void storeInteger(ComplaxData* cmp, unsigned data);

void storeData(ComplaxData* cmp, const char* data);

void destroy(ComplaxData* cmp);

void printComplex(const char* title, ComplaxData* cmp);

/***
 * @returns New instance of ComplaxData data
 **/
ComplaxData* createCopy(ComplaxData* cmp );

int main(int argc, char* argv[] ) { 
  // Creating an instance of a complex data
  ComplaxData* complex01 = (ComplaxData*)malloc( sizeof(ComplaxData) );

  initialize(complex01);

  storeInteger(complex01, 25 );
  storeData(complex01, "this is an string" );
  printComplex("1. Content of complex data", complex01);
  printf("\n" );

  storeInteger(complex01, 0xffffff40 );
  storeData(complex01, "this is a completely string" );
  printComplex("2. Content of complex data", complex01);
  printf("\n" );

  ComplaxData* clone = createCopy(complex01);
  printComplex("3. Content of CLONED data", clone);
  printf("\n" );

  storeInteger(clone, 1 );
  storeData(clone, "string stored on the cloned complex data" );

  printComplex("4. Content of CLONED data", clone);
  printComplex("5. Content of complex data", complex01);
  printf("\n" );
  
  destroy(complex01);   // Realeses data allocated by TDA
  free(complex01);      // Realeses data allocated by malloc

  printComplex("6. Content of CLONED data", clone);

  destroy(clone);
  free(clone);

  return 0;
}

void initialize(ComplaxData* cmp) {
  cmp->anInteger = 0;
  cmp->anArray = NULL;
  cmp->arraySize = 0;
}

void storeInteger(ComplaxData* cmp, unsigned data) {
  cmp->anInteger = data;
}

void storeData(ComplaxData* cmp, const char* data) {
  if ( cmp->anArray != NULL ) {
    free( cmp->anArray );
    cmp->anArray = 0 ;
  }

  cmp->arraySize = strlen(data) + 1;
  cmp->anArray = (char*)malloc( cmp->arraySize );
  strcpy( cmp->anArray, data );
}

void destroy(ComplaxData* cmp) {
  if ( cmp->anArray != NULL ) {
    free( cmp->anArray );
    cmp->anArray = NULL;
    cmp->arraySize = 0;
    cmp->anInteger = 0;
  }
}

/***
 * @returns New instance of ComplaxData data
 **/
ComplaxData* createCopy(ComplaxData* cmp ) {
  // COMPLETE THE MISSING CODE 
}

void printComplex(const char* title, ComplaxData* cmp){
  printf("%s\n", title );
  printf("Complex data( anInteger( %d ), anArray( '%s' )\n", cmp->anInteger , cmp->anArray );
}
