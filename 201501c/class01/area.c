#include <stdio.h>



#define PI 3.14



int main( int argc, char** argv) {
  float radio = 5;
  float area = PI * radio * radio;
  printf("El area de la circ. de radio: %.2f es: %.2f\n", radio, area);
  printf("El area de la circ. de radio: %d es: %.2f\n", radio, area);
  return 0;
}
