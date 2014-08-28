#include <stdio.h>

/************
 * Ejercicio próxima clase 
 *  Instalar entorno y experimentar con printf (%d, %f, \n \", etc.)
 *  Imprimir las siguientes salidas:
 *    - Como hago para imprimir este caracter "?
 *    - Y este otro %?
 *    - Imprimir 1, 0002, 0004, 1.6180
 *
 *  SUGERENCIAS: 
 *    investigar sobre función printf
 *
 */

int main(int argc, char* argv[] ) {
  printf("Aquí está el caracter en cuestión: \"\n");
  printf("Aquí está el caracter en cuestión: \%\n");

  printf("Valores, %d, %04d, %04d, %1.4f: \n", 1, 2, 4, 1.6180);
  
  return 0;
}

