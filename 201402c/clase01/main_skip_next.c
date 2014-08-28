#include <stdio.h>

int main(int argc, char** argv) {
  long long**  array0;
  long long   array1[] = { 0, 0, 0, 0 };

  printf("BASE addres array0: 0x%8lx, addres array1: 0x%8lx\n", array0, array1 );
  printf("sizeof array %d, array1: %d\n", sizeof(array0), sizeof(array1) );
  for(unsigned step = 0; step < 0xf; ++step) {
    printf("step: %2d, addres array0: 0x%8lx, addres array1: 0x%8lx\n", step, array0+step, &array1[step] );
    printf("step: %2d, value array0: 0x%8lx, value array1: 0x%8lx\n", step, *(array0+step), array1[step] );
  }

  return 0;
}



