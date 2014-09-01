#include <stdio.h>

int main(int argc, char** argv) {
  double f = 3.14;
  short  i = -512;
  unsigned char* pf = &f;
  unsigned char* pi = &i;

  printf( "%d, %f\n", i, f);

  char value = 127;
  char value01 = 127;

  printf( "value: %d\n", value);  // 127
  value++;
  printf( "value: %d\n", value);  // -128
  printf( "value: %d\n", value01 + 1);  // It must be -128, isn't? It isn't
  return 0;
}



