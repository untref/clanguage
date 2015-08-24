#include <stdio.h>
#include <stdlib.h>

#include "assertion.h"

int main()
{
  setupTestEnv();

  {
      // Necesitaríamos agregar un elemento al array, como podríamos hacer? Se puede?
      int enteros[] = { 2, 5 };

      assert(enteros[2], 9);

      // Aquí definimos un array con 256 enteros
      int enteros2[256];

      // Copiar desde enteros a enteros2 los datos y agregar el 9 al final
      assert(enteros2[0], 2);
      assert(*(enteros2+1), 5);
      assert(*(enteros2+2), 9);
      
      
  }
  
  {

      // Dado el siguiente array hacer pasar los tests
      double numeros[] = { 2.4, 5.2, 3.7 };

      assert(sizeof(numeros), 0);
      assert(sizeof(double), 0);
      assert(numeros[2], 0.0);

      double* punteroDouble = numeros + 1;
      assert(punteroDouble, 0);
      assert(*punteroDouble, 0.0);


      // Modificar elementos de un array

      assert(*numeros, 4.2 );


      // Intercambiar elementos de un array. Pasar elemento 0 a 1
      assert(numeros[1], 2.4);

      // Cual es el tamano de un puntero a double (el tamano del double es 8)?
      assert(sizeof(double*), 1);

      // Cual es el tamano de un puntero a char (el tam del char es 1)?
      assert(sizeof(char*), 0);

      // Cual es el tamano de un puntero a char (el tam del int es 4)?
      assert(sizeof(int*), 0);
      
  }

  {
      int i = 29;
      int j = 13;

      int* pi;

      assert(pi, 0);
      assert(pi, NULL);

      pi = pi + 2; // equivalents to pi += 2

      pi = &j;
      *pi++;

      assert(*pi, 0);

      pi = &i;
      *pi += 2;
      assert(*pi, 0);
  }
  
  return 0;
}
