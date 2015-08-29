#include <stdio.h>
#include <stdlib.h>

#include "../assertion.h"

int main()
{
  setupTestEnv();

  {
    int array[] = {1,2,3,4,5};
    int* pi = array;

    assert(pi, array);
    assert(pi, &array);
    assert(pi, &(array[0]));

    assert(array[3], 4);

    assert(*(array + 5), array[5]);

    assert(array[3], *(array + 3));
    assert(array[1], *(array + 1));
    assert(array[0], *(array + 0));
    assert(array[1], 2);
    assert(sizeof(array), sizeof(int) * 5);
    assert(sizeof(pi), 4);

  }


  int i = 4;
  float f = 25555.354;

  int* pi = &i;

  // Este puntero apunta a un espacio donde existe un float
  int* piInvalido = &f;

  // Este puntero aputna a una dirección prohibida
  int* piFueraStack = 0xffffffff;

  // Puntero, puntero a entero. OJO HAY QUE CASTEAR
  int* pi3 = &pi;

  // Puedo utilizar la POSICION de memoria
  assert(piFueraStack, 0xffffffff);

  // Esto arroja error porq la dir esta prohibida
  // *piFueraStack

  // Puedo acceder al puntero del puntero pero casteando
  assert(*(int*)*pi3, 4);

  assert( i, 4);
  assert(pi, &i);
  assert(*pi, 4);
  assert(*pi, i);

  assert(piInvalido, &f);
  deny(*piInvalido, 2);

  return 0;
}
