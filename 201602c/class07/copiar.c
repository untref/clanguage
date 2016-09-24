#include <stdio.h>
#include <strings.h>

unsigned longitud_2(char* o) {
  char * p = o;

  while( *o ) 
    *++o;

  return o - p;
}

unsigned longitud(char* o) {
  unsigned i = 0;

  while( *o ) {
    i++;
    o++;
  }

  return i;
}
void copiar(char* d, char* o) {
  int i;

  for( i = 0; i < strlen(o) + 1; ++i) {
    d[i] = o[i];
  }
}

void copiar_1(char* d, char* o) {

  while( *o ) {
    *d = *o;
    ++d;
    ++o;
  }

  *d = 0x0; 
}

void copiar_2(char* d, char* o) {
  while( *o ) 
    *d++ = *o++;

  *d = 0x0; 
}

int main(int argc, char** argv) {
  char dest[1024] = "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!";
  char orig[] = "pepe";
  char* p = orig;
  
  copiar_2(dest, orig);

  printf("dest: %s |\n", dest);
  printf("longitud de dest: %u |\n", longitud_2(dest) );

  printf("%c \n", *p );
  printf("%c \n", *++p ); 
}
