#include <stdio.h>

#define BUFFER_SIZE         5
#define ANOTHER_BUFFER_SIZE 1024

/****
 * En todos los ejercicios NO se puede utilizar FOR ni corchetes
 */
int main(int argc, char** argv) {
  char* long_string = "this is a long string";

  char buffer[BUFFER_SIZE];
  int  value = 7;

  // Ej.1:
  // Copiar el contenido del 'long_string' a buffer (solo los bytes que se pueden)
  // Imprimir buffer y value

  char another_buffer[] = "initial value";
  int another_value = 9;

  // Ej.2:
  // Concatenar el contenido de 'long_string' al contenido de another_buffer
  // Imprimir 'another_buffer' y another_value

  // Ej.3:
  // Copiar el contenido de buffer al contenido de another_buffer
  // Imprimir 'another_buffer' y another_value
}
