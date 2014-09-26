#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Variant.h"

void variosVariants();
void asignacionVariants();
void duplicacionVariants();

int main()
{
  printf( "Ejemplo de varios variants\n" );
  variosVariants();
  printf( "\n" );
  printf( "\n" );
  printf( "Asignacion de variants\n" );
  asignacionVariants();
  printf( "\n" );
  printf( "\n" );
  printf( "Duplicación de variants\n" );
  duplicacionVariants();

  return 0;
}

void variosVariants() {
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

}

void asignacionVariants() {
  Variant varUnString;
  Variant varOtroString;
  char miString[] = "valor un string";
  double miDouble = 741.34;


  initialize( &varUnString );
  initialize( &varOtroString );

  set(&varUnString, miString, strlen(miString) + 1, strlen(miString) + 1 );
  printf( "Valor varUnString: %s\n", getString(&varUnString) );

  assign( &varOtroString, &varUnString );
  printf( "Valor varOtroString: %s\n", getString(&varOtroString) );

  // Aquí lo interesante del variant que puedo almacenar otro
  // dato
  set(&varOtroString, &miDouble, sizeof(miDouble), 1 );

  printf( "Luego de la asignación ambos deberan ser independientes\n" );
  printf( "Valor varUnString: %s\n", getString(&varUnString) );
  printf( "Valor varOtroString: %f\n", getDouble(&varOtroString) );


  release( &varOtroString );
  release( &varUnString );

}

void duplicacionVariants() {
  Variant variantEntero;   
  int miEntero = 572;

  initialize( &variantEntero );
  set( &variantEntero, &miEntero, sizeof(int) /* 4 bytes */, 1 );

  Variant* nuevoVariant = duplicate( &variantEntero );

  printf( "Valor del variant origen: %d\n", 
      getInteger(&variantEntero) );
  printf( "Valor del nuevo variant (debe ser igual al origen): %d\n", 
      getInteger(nuevoVariant) );

  double miDouble = 741.34;
  set(nuevoVariant, &miDouble, sizeof(miDouble), 1 );

  printf( "Valor del nuevo variant: %f\n", 
      getDouble(nuevoVariant) );

  printf( "Luego de modificar el variant duplicado el origen no cambia: %d\n", 
      getInteger(&variantEntero) );

  // EL NUEVO VARIANT TENGO QUE liberarlo
  free( nuevoVariant );
}
