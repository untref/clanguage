#include <stdio.h>

int main(int argc, char** argv) {
  char cadena[] = { 'U', 'N', 'T', 'R', 'E', 'F', 0x0, '\0' };
  char otraCadena[] = "Caseros II";

  printf("cadena: %s| longitud cadena: %lu | longitud array: %lu |\n", cadena, strlen(cadena), sizeof(cadena) );
  printf("otraCadena: %s|\n", otraCadena);

  printf("long %d\n", sizeof(long)); 
  printf("long long %d\n", sizeof(long long)); 
  printf("float %d\n", sizeof(float)); 
  printf("double %d\n", sizeof(double)); 
  printf("long double %d\n", sizeof(long double)); 
}
