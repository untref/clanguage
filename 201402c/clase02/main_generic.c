#include <stdio.h>

int main(int argc, char** argv) {
  double f = 3.14;
  short  i = -512;
  void* p = &i;

  printf( "short value: %d\n", *((short*)p));  // 127
  p = &f;
  printf( "double value: %lf\n", *((double*)p));  
  return 0;
}



