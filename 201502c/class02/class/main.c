#include <stdio.h>
#include <stdlib.h>

#define BUFFER_SIZE 1024

void imprimir(char* param) {
    printf("%s\n", param);
}

void copiar(char* dest, char* orig) {
  while( *orig != '\0' ) {
    *dest = *orig;
    dest++;
    orig++;
  }
  *dest = '\0';
}

void concatenar(char* dest, char* orig) {
  while ( *dest != '\0' ) {
    dest++;
  }

  copiar(dest, orig);
}
#if 0
char* davidCopy(char* orig) {
  char result[BUFFER_SIZE];
  char* dest = result;

  while( *orig != '\0' ) {
    *result = *orig;
    dest++;
    orig++;
  }
  *dest = '\0';

  return result;
};
#endif
int main()
{
    char p[] = { 'H', 'o', 'l', 'a', 32, 'U', '\0' };
    char str[] = "HOLA UNTREF";
    char str2[BUFFER_SIZE];

    // char* str3 = davidCopy(str);
    copiar(str2, str) ;
    concatenar(str2, " 2015");

    imprimir(str2);
#if 0
    printf("%s\n", p);
    printf("%s\n", str);

    printf("%d\n", sizeof(p));
    printf("%d\n", sizeof(str));

    imprimir(p);
    imprimir(str);
#endif
    return 0;
}
