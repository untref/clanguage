#include <stdio.h>

struct s {
  double d01;
  char   c01;
  short  s01;
};

int main(int argc, char** argv) {
  int i = 0;

  printf("%d\n", i );
  printf("%d\n", ++i );
  printf("%d\n", i++ );
  printf("%d\n", i );
}
