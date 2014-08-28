#include <stdio.h>

int main(int argc, char** argv) {
  double f = 3.14;
  short  i = -512;
  unsigned char* pf = &f;
  unsigned char* pi = &i;

  printf( "%d, %f\n", i, f);
  return 0;
}



