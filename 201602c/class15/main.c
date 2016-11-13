#include <stdio.h>

int main(int argc, char** argv) {
  char c = 5;
  char d = 20;

  printf("0x%x\n", ~c);
  printf("0x%x\n", d);

  printf("and c d: 0x%x\n", c & d);
  printf("or  c d: 0x%x\n", c | d);
  printf("xor c d: 0x%x\n", c ^ d);
  printf("s2  c d: 0x%x\n", c << 0);
  printf("s2  c d: 0x%x\n", c << 1);
  printf("s2  c d: 0x%x\n", c << 2);
  printf("s2  c d: 0x%x\n", c >> 1);
  printf("s2  c d: 0x%x\n", c >> 2);
  printf("s2  c d: 0x%x\n", c >> 3);













  char dondeGuardarCodigo = 0x0;


  char primerBit =  0x0 << 0;
  char segundoBit = 0x0 << 1;
  char terceroBit = 0x1 << 2;
  char cuartoBit =  0x1 << 3;
  char quintoBit =  0x14 << 4;

  dondeGuardarCodigo = dondeGuardarCodigo | primerBit;
  dondeGuardarCodigo = dondeGuardarCodigo | segundoBit;
  dondeGuardarCodigo = dondeGuardarCodigo | terceroBit;
  dondeGuardarCodigo = dondeGuardarCodigo | cuartoBit;
  dondeGuardarCodigo = dondeGuardarCodigo | quintoBit;


  printf("donde:  0x%x\n", dondeGuardarCodigo);



}



