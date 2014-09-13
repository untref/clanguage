#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MEGA 1024

int main(int argc, char** argv ) {
  char* str = (char*)malloc( 2 * MEGA );

  strcpy(str, "Contenido del string contiene mas de 20 caracteres");

  printf( "Str:         %s\n", str );


  char another_str[] = "Tamaño str";
  printf( "another_str: %s\n", another_str );

  printf("sizeof(str): %d, sizeof(another_str): %d\n", 
      sizeof(str), sizeof(another_str));


  return 0;
}

