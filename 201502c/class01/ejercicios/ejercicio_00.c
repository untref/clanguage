  #include <stdio.h>
#include <stdlib.h>

#include "../../assertion.h"

int main()
{
  setupTestEnv();

  {
      // Necesitaríamos agregar un elemento al array, como podríamos hacer? Se puede?
      int enteros[] = { 2, 5 };

      // Ojo piso mem
      // assert(enteros[2], 9);

      // Aquí definimos un array con 256 enteros
      int enteros2[256];

      // Copiar desde enteros a enteros2 los datos y agregar el 9 al final
      enteros2[0] = enteros[0];
      enteros2[1] = enteros[1];
      enteros2[2] = 9;
      assert(enteros2[0], 2);
      assert(*(enteros2+1), 5);
      assert(*(enteros2+2), 9);


  }
  {

      // Dado el siguiente array hacer pasar los tests
      double numeros[] = { 2.4, 5.2, 3.7 };

      assert(sizeof(numeros), 24);
      assert(sizeof(double), 8);
      assert(numeros[2], 3.7);

      double* punteroDouble = numeros + 1;
      assert(punteroDouble, &numeros[1]);
      assert(*punteroDouble, 5.2);


      // Modificar elementos de un array
      numeros[0] = 4.2;
      *(numeros + 0) = 4.2;
      assert(*numeros, 4.2 );


      // Intercambiar elementos de un array. Pasar elemento 0 a 1
      double tmp = numeros[0];
      numeros[0] = numeros[1];
      numeros[1] = tmp;
      assert(numeros[1], 4.2);


      // IMPORTANTE
      //
      // En función de la arquitectura el tamaño de un puntero puede ser 4 u 8
      //
      // Cual es el tamano de un puntero a double (el tamano del double es 8)?
      assert(sizeof(double*), 4);

      // Cual es el tamano de un puntero a char (el tam del char es 1)?
      assert(sizeof(char*), 4);

      // Cual es el tamano de un puntero a char (el tam del int es 4)?
      assert(sizeof(int*), 4);

  }

  {
      int i = 29;
      int j = 13;

      int* pi;

      pi = 0x0;
      assert(pi, 0);
      assert(pi, NULL);

      pi = pi + 2; // equivalents to pi += 2

      // IMPORTANTE
      // Si bien estamos operando con el puntero y este se incrementará
      // aunque la dirección no sea válida podemos hacer todas las operaciones
      // correspondientes a aritmética de punteros. Mientras no lo dereferenciemos!!!!
      // No hacer *pi!

      assert(pi, 0x8);

      // Aquí pi apunta a la dirección de j
      pi = &j;

      #if 0
      printf("dir i: 0x%x\n", &i);
      printf("dir j: 0x%x\n", &j);
      printf("dir pi: 0x%x\n", &pi);
      printf("val pi: 0x%x\n", pi);
      printf("dval pi: %d\n", *pi);
      printf("pi: %d\n", *pi);
      printf(".....\n");
      #endif

      // En esta linea lo único que importa es que
      // pi se incrementará en sizeof(int), apuntando a la siguiente
      // poscion de memoria contigüa a &j (4 bytes más allá de &j)
      *pi++;

      // Mapa de memoria
      printf("dir i: 0x%x\n", &i);
      printf("dir j: 0x%x\n", &j);
      printf("dir pi: 0x%x\n", &pi);
      printf("val pi: 0x%x\n", pi);
      printf("dval pi: %d\n", *pi);
      printf("pi: %d\n", *pi);
      printf(".....\n");

      assert(*pi, 29);

      pi = &i;
      *pi += 2;
      assert(*pi, i);
  }
  return 0;
}
