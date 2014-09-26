#include <stdio.h>
#include <stdlib.h>

#include "Variant.h"

int main()
{
  // Esta estructura esta toda alocada en el stack, hay espacio para
  // cada uno de los atributos que contiene la estructura (data, dataSize)
  // OJO!
  // Hay espacio para el puntero y para el tamaño
  //
  Variant variantEntero;   
  int miEntero = 572;

  // El primer argumento es un puntero a la estructura
  initialize( &variantEntero );

  // Dado que el variant no contiene un entero, lo almaceno
  set( &variantEntero, &miEntero, sizeof(int) /* 4 bytes */, 1 );

  printf( "Valor variant: %d\n", getInteger( &variantEntero ) );

  // Hay que liberar los datos contenidos por el variant
  release( &variantEntero );


  // Esta NO ES ESTRUCTURA ESTA UN PUNTERO A LA ESTRUCTURA, como es
  // un puntero necesito alocarlo antes de poder utilizar sus datos
  // OJO!
  // Hay NO HAY ESPACIO para el puntero y para el tamaño
  //
  Variant* punteroVariantDouble;
  double  miDouble = 7.343297972349;

  // Alojemos espacio para la estructrua
  // ES MI RESPONSABILIDAD LIBERAR ESTE PUNTERO MÁS ADELANTE
  punteroVariantDouble = (Variant*)malloc( sizeof(Variant) );

  // no está inicializada la estructura, inicializo
  //
  // ATENCIÓN:
  // En este caso no es necesario la utilización del operador '&' ya que
  // esta variable ya es un puntero 
  initialize( punteroVariantDouble );

  set( punteroVariantDouble, &miDouble, sizeof(double) /* 8 bytes */, 1 );

  printf( "Valor variant: %e\n", getDouble(punteroVariantDouble) );

  // Hay que liberar los datos contenidos por el variant
  release( punteroVariantDouble );

  free( punteroVariantDouble ) ; punteroVariantDouble = 0;


  Variant varString;
  initialize( &varString );
  char miString[] = "este es un string que quiero almacenar en el variant";
  int  otroEntero = 128;

  // NO HAY QUE PASARLE A miString el operador '&'
  set( &varString, miString, sizeof(miString) + 1 /* agrego espacio para el \0 */, 
      sizeof(miString) + 1 /*cantidad de elementos por array*/ );

  printf( "Valor variant: '%s'\n", getString(&varString) );

  // Le cambio el contenido del variant
  set( &varString, &otroEntero, sizeof(otroEntero), 1 );
  printf( "Valor variant: %d\n", getInteger(&varString) );


  // Hay que liberar los datos contenidos por el variant
  release( &varString);

  // NO HAY PUNTERO QUE LIBERAR

return 0;
}
