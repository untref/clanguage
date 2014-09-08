#include <stdio.h>

// Foward DECLARATION
void printIntIt(unsigned index, void* value);

// DECLARATION AND DEFINITION AT THE SAME TIME
void printDoubleIt(unsigned index, void* value) {
    double* pI = value;
    printf("indice: %4d, valor: %lf\n", index, *pI);
}

/******
 * This function iterates a collection of objects (in the sence of C language)
 * and execute a function 'doit'
 *
 * @param  collection: collection beginning
 * @param  size: size of one element of the collection
 * @param  count: number of elements withing the collection
 * @param  doit: function applied to each element of the collection
 *
 * @return Nothing
 */
void iterate( void* collection, unsigned size, unsigned count, void (doit)(unsigned, void*) ) {
  unsigned i = 0;

  for( i = 0; i < count; ++i ) {
    (*doit)(i, collection + i * size );

  }
}


int main( int argc, char** argv) {
  int integers[] = { 1, 3, 78, 9, -1 };

  iterate( integers, 
      sizeof(int),                     // Sizeof one element
      sizeof(integers) / sizeof(int),  // collection count
      printIntIt);                     // doit pointer function 

  double floats[] = { 1.4, 3.001, 78 };

  iterate( floats, 
      sizeof(double),                     // Sizeof one element
      sizeof(floats) / sizeof(double),    // collection count
      printDoubleIt);                     // doit pointer function 

  return 0;
}


// DEFINITION of the function
void printIntIt(unsigned index, void* value) {
    int* pI = value;
    printf("indice: %4d, valor: %8d\n", index, *pI);
}

