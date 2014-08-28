#include <stdio.h>

int main(int argc, char** argv) {
  float f = 25.96875;   // 0x41cfc000
  unsigned char* p = &f;

  // Checkout the output...
  for( int i = 0; i < sizeof(f); ++i ) {
    printf( "%x\n", p[i] );
  }

  return 0;
}
