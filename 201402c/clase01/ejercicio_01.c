#include <stdio.h>

/************
 * Ejercicio próxima clase 
 *
 */

int main(int argc, char* argv[] ) {
  // EJERCICIO 0
  // Dados los strings s0 y s1, copiar el contenido de uno en el otro
  //
  // SUGERENCIA:
  //  Crear arrays lo suficientemente grandes
  char s0[] = "Este es el contenido del string 0";
  char s1[sizeof(s0)] = "";
  char* p0 = s0;
  char* p1 = s1;

  while( *p1++ = *p0++ );

  //
  // Codigo aquí
  //
  
  // Verificación
  printf( "s0: %s\n", s0 );
  printf( "s1: %s\n", s1 );
  
  // EJERCICIO 1
  //
  // Dada frase, contar la cantidad de palabras que esta tiene
  //
  // SUGERENCIA:
  //  ' ' es el ascii para el espacio 
  char frase[] = "esta es la frase. el número de palabras es";
  int inicioPalabra;
  int finPalabra;
  int cantidadPalabras = 0;

  for(inicioPalabra = 0; inicioPalabra < sizeof(frase); ++inicioPalabra ) {
    if ( frase[inicioPalabra] == ' ' || frase[inicioPalabra] == '\0' ) {
      cantidadPalabras++;
      inicioPalabra++;
    }
  }

  // Verificación
  printf( "frase: %s\n", frase);
  printf( "cantidad palabras: %d\n", cantidadPalabras);
  
  // EJERCICIO 2
  // 
  // Dada los array de flotantes floats00 y floats01 (ambas de la misma longitud)
  // copiar su contenido de una a otra
  //
  double floats00[] = { 3.141516f, 1.65f, 7.48f, 12.7000000001f };
  double floats01[sizeof(floats00) / sizeof(double)];
  int index;
  double* pf0 = floats00;
  double* pf1 = floats01;

  while( pf0 - floats00 < (sizeof(floats00) / sizeof(double)) )
    *pf1++ = *pf0++;

  // Verificación
  for( index = 0; index < sizeof(floats00) / sizeof(double); ++index ){
    printf( "Array 00 - elemento %d - valor: %f\n", index, floats00[index] );
    printf( "Array 01 - elemento %d - valor: %f\n", index, floats01[index] );
  }
  
  
  // EJERCICIO FINAL
  // 
  // Dado que el código del ejercicio 0 y 2 son prácticamente el mismo. 
  // Escribir un único código que funcione para ambos arrays.
  //
  // SUGERENCIAS
  //  Utilizar char*
  //
  long double otrosFlotantes[] = { 3.141516, 1.65};
  long double otrosMasFlotantes[sizeof(otrosFlotantes) / sizeof(long double)];
  char* pA0 = otrosFlotantes;
  char* pA1 = otrosMasFlotantes;
  char* pHead = otrosFlotantes;
  unsigned count = sizeof(otrosFlotantes);

  while( pA0 - pHead < count )
    *pA1++ = *pA0++;

  for( index = 0; index < sizeof(otrosFlotantes) / sizeof(long double); ++index ){
    printf( "otrosFlotantes - elemento %d - valor: %Lf\n", index, otrosFlotantes[index] );
    printf( "otrosMasFlotantes - elemento %d - valor: %Lf\n", index, otrosMasFlotantes[index] );
  }

  return 0;
}

