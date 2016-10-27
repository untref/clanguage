
/***
 * repeat <word> <time>
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char** argv) {
  int time = atoi(argv[2]);
  unsigned size = strlen(argv[1]) * time + 1;
  char* aux = (char*) malloc( size );
  int i;

  for( i = 0; i < time; ++i) {
    strcat(aux, argv[1]);
  }

  printf("%s\n", aux);

  free(aux);

  return 0;
}

