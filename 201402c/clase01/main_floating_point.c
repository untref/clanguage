#include <stdio.h>

int main(int argc, char** argv) {
  float f = 25.96875;   // 0x41cfc000
  unsigned char* p = &f;

  printf( "Floating point: %f\n", f );

  // Checkout the output...
  for( int i = 0; i < sizeof(f); ++i ) {
    printf( "%x\n", p[i] );
  }

  p[0] = 0x0;
  p[1] = 0x0;
  p[2] = 0x0;
  p[3] = 0xff;

  printf( "Floating point: %f\n", f );
  
  return 0;
}
