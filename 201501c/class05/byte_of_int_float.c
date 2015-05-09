#include <stdio.h>


void printBytes(void*, unsigned); 


int main(int argc, char** argv) {
  int n = 4;
  unsigned m = 1;
  float f = 155.3125;

  // Imprimir los bytes q componen a los números:
  // n, m y f
  printBytes( &n, sizeof(int) );
  printBytes( &m, sizeof(unsigned) );
  printBytes( &f, sizeof(float) );

  char overflow = 127;

  printf("%d\n", overflow);

  overflow++;
   
  printf("%d\n", overflow);

  overflow++;
   
  printf("%d\n", overflow);
}



void printBytes(void* data, unsigned size) {
  void* p = data;

  while ( (p - data) < size ) {
    printf("0x%x\n", *(char*)p );
    ++p;
  }
}
