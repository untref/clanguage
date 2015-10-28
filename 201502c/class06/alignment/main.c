#include <stdio.h>
#include <string.h>

typedef struct _mystrunct {
  char    character;
  double  d;
  char    c;
} MyStruct;

int main(int argc, char** argv) {
  MyStruct s;

  memset(&s, 0x9, sizeof(MyStruct) );

  s.character = 'a';
  s.d = -7.02;

  char* p = (char*)&s;

  unsigned n = 3;
  printf("Cual es el valor del byte %4d? -> %d. Porque?\n", n, p[n] );

  printf("Cual es el tamano de la estructura? %d\n", sizeof(MyStruct) );


}
