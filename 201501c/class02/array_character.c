#include <stdio.h>


#define BUFFER_SIZE 5

int main(int argc, char** argv) {
  char* s1  = "UNTREF";
  char s2[] = "fiuba";

  char buffer[BUFFER_SIZE];

  char* pc = s2;

  printf("%s\n", s1 );
  printf("%s\n", s2 );
}
