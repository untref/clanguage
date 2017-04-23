void mostrarParrafo(char** parrafo, unsigned palabras ) {
  char** palabraActual = parrafo;
  while (palabras--) {
      printf("%s ", *palabraActual);
      palabraActual++;
  }
  printf("\n");
}

void liberarParrafo(char** nuevoParrafo, unsigned palabras) {
  char** palabraActual = nuevoParrafo;

  while (palabras--) {
      free( *palabraActual );
      palabraActual++;
  }

  free( nuevoParrafo );
}

char** replaceAll( char** parrafo, unsigned palabras, char* palabra, char* reemplazo) {
  char** nuevoParrafo = (char**)malloc( palabras * sizeof(char*) );

  memcpy(nuevoParrafo, parrafo, palabras * sizeof(char*) );

  char** palabraActual = nuevoParrafo;

  while (palabras--) {
      if ( strcmp( *palabraActual, palabra ) == 0 ) {
          *palabraActual = (char*)malloc( strlen(reemplazo) + 1 );
          strcpy(*palabraActual, reemplazo);
      } else {
          char* copiaPalabraActual = *palabraActual;
          *palabraActual = (char*)malloc( strlen(*palabraActual) + 1);
          strcpy(*palabraActual, copiaPalabraActual);
      };
      palabraActual++;
  }
  return nuevoParrafo;
}

int main(int argc, char** argv) {
  char* parrafo[] = {
    "Diego Capusoto",
    "es",
    "es",
    "uno",
    "de",
    "los",
    "humoristas",
    "más",
    "grandes",
    "grandes",
    "de",
    "Arg"
  };

  mostrarParrafo( parrafo, sizeof(parrafo) / sizeof(char*) );

  char** nuevoParrafo = replaceAll(
          parrafo, 
          sizeof(parrafo) / sizeof(char*), 
          "es", 
          "ESSSSS"
    );
    
  mostrarParrafo( nuevoParrafo, sizeof(parrafo) / sizeof(char*) );

  liberarParrafo(nuevoParrafo, sizeof(parrafo) / sizeof(char*));

  printf("sizeof parrafo: %lu\n", sizeof(parrafo));
  // Reemplazar, 'es' por 'eeeeeeeeeeees' y 'grandes' por 'fenomeno'
  
}
