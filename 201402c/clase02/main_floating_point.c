#include <stdio.h>

int main(int argc, char** argv) {
  float f = 25.96875;   // 0x41cfc000
  unsigned char* p = &f;

  printf( "Floating point: %f\n", f );

  // Checkout the output...
  int i;
  for( i = 0; i < sizeof(f); ++i ) {
    printf( "%x\n", p[i] );
  }

  return 0;
}
