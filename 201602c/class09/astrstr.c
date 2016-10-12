#include <stdio.h>
#include <string.h>

void usage() {
  printf("strstr utilities - ver: 0.0.1\n");
  printf(" - commands:\n");
  printf("    + c: count words \n");
}

long unsigned count(char* word) {
  char* p = word;

  while ( *p++ ) ;

  return p - word - 1;
}


/**
 * Comando para realizar operaciones con strigns
 **/
int main(int argc, char** argv) {
  char commandCount[] = "c";
  char commandInc[] = "inc";
  char commandIntersect[] = "int";
  char* command = argv[1];
  
  // @MAL if ( command == "c" ) {
  //
  // 0. actualizar esta version del if (strcmp)
  if ( *command == *commandCount ) {
    // @MAL printf("%s: %lu\n", command, sizeof(argv[2]) ); // 8
    printf("%s: %lu\n", command, count(argv[2]) );
  else if ( strcmp(command, commandInc) == 0  ) {
     // 1. completar implementando la primitiva 'strstr' 
     //
     // 2. completar utilizando la primitiva 'strstr' 
  } else {
    return 1;
  }

  return 0;
}

