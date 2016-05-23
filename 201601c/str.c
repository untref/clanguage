#include <stdio.h>

unsigned len(char *s) {
  char *t = s;
  while ( *t++ );
  return (t - s - 1);
}


int main(int argc, char**argv) {
  char *untref = "UNTREF CASEROS";

  printf("%s : %d\n", untref, len(untref));
}
