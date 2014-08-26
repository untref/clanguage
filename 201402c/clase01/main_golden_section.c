#include <stdio.h>
#include <math.h>

int main(int argc, char** argv) {
  double fi = (1.0 + sqrt(5.0)) / 2.0;
  double invFi = 1.0 / fi;

  printf("golden ratio: %lf\n", fi);
  printf("inverse golden ratio: %lf\n", invFi);

  // -1 / fi = 1 - fi
  printf( "-1 / fi = 1 - fi: %f\n", (+1.0 / fi) + 1.0 - fi);

  // fi * fi = 1 + fi
  printf( "fi * fi: %f\n", fi * fi) ;
  printf( "- 1 - fi: %f\n", - 1 - fi) ;
  printf( "%d\n", sizeof(- fi + -1) );

  return 0;
}




