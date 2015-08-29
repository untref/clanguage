#include <stdio.h>
#include <stdlib.h>

#include "../../assertion.h"

#define BUFFER_SIZE 1024

// IMPORTANTE
// Param es un char* => sizeof = 4
//
void imprimir(char param[]) {
    printf("%s\n", param);
}


void copiar(char* dest, char* orig) {
    while( *orig != '\0' ) {
        *dest = *orig;
        dest++;
        orig++;
    }

    // No olvidar el '\0' al final de dest
    *dest = '\0';
}

void concatenar(char* dest, char* orig) {
  while ( *dest != '\0' ) {
    dest++;
  }

  copiar(dest, orig);
}

// IMPORTANTE
// NUNCA SIN EXCEPTION DEVUELVAN UN PUNTERO A ALGUNA VARIABLE INTERNA DE LA
// FUNCION.
// Si bien el result contiene suficiente espacio para alocar origen, el resultado de
// la función será un puntero a result  (almacenado en el stack).  Esta area
// se destruirá luego de la invocación de la función 'davidCopy'.
//
// NO SE PUEDE HACER EL COPY DE ESTA MANERA
//
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

int main()
{

    // Aquí estamos creando un array de caracteres (string). No le estamos
    // agregando el '\0' necesario para que todas las funciones que operen
    // con strings sepan cuando el string finaliza.
    char strSinBarraCero[] = { 'u', 'n', 't', 'r', 'e', 'f' };

    // Por lo que comentamos anteriormente creamos un string utilizando como
    // último caracter el '\0'
    char strConCodigosDecimales[] = { 'H', 'o', 'l', 'a', 32, 'U', '\0' };

    // Las formas anteriores son muy incómodas, C nos provee el siguiente
    // atajo.  Este SÍ incluye el '\0' al final del string
    char strConBarraCero[] = "HOLA UNTREF";

    assert(sizeof(strSinBarraCero), 6);           // NO Incluye el '\0' POR QUE NO LO AGREGAMOS
    assert(sizeof(strConCodigosDecimales), 7);    // SI Incluye el '\0' POR QUE LO AGREGAMOS
    assert(sizeof(strConBarraCero), 12);          // Incluye el '\0'


    // Imprimamos para ver que tienen los strings
    // printf("strSinBarraCero: %s\n", strSinBarraCero);
    // printf("strConCodigosDecimales: %s\n", strConCodigosDecimales);
    // printf("strConBarraCero: %s\n", strConBarraCero );

    // En lugar de imprimir el contenido del str para comprobar que es lo
    // que tiene, podemos hacer unos tests
    denyStr(strConBarraCero, "untref");
    assertStr(strConCodigosDecimales, "Hola U");
    assertStr(strConBarraCero, "HOLA UNTREF");

    // Ahora quiero agregarle al string strConBarraCero el str 2015. NO HAY LUGAR LUEGO DE LA 'F'
    // porque solo alocamos espacio para 'HOLA UNTREF'.
    // Necesitamos creear un buffer en el cual entre 'HOLA UNTREF 2015'
    char buffer[BUFFER_SIZE];

    // Copiamos el contenido de strConBarraCero al buffer
    copiar(buffer, strConBarraCero);
    concatenar(buffer, " 2015");
    assertStr(buffer, "HOLA UNTREF 2015");

    #if 0
    char* str3 = davidCopy(strConBarraCero);
    printf("%s\n", str3);
    #endif
    return 0;
}
