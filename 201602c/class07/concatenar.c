#include <stdio.h>
#include <strings.h>

void concatenar(char* dest, char* orig) {
  // Busco final del dest
  while( *dest ) {
    dest++;
  }

  // copio de origen a dest
  while( *orig ) 
    *dest++ = *orig++;

  *dest = 0x0; 
}

strcpy
/****
 * Moraleja:
 * 
 * Que debe cumplir el destino?
 *
 **/
int main(int argc, char** argv) {
  char dest[6] = "AAA";
  char orig[] = "BBB";
 
  concatenar(dest, orig); 
  printf("dest: %s |\n", dest);
}

