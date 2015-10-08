#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../../assertion.h"

#include "matriz.h"

int main()
{

  // n x n
  // 1 0 0 ... 0
  // 0 1 0 ... 0
  // 0 0 1 ... 0
  // 0 0 1 ... 0
  // ...
  // ...
  // 0 0 0 ... 0
  // 0 0 0 ... 1
  //
  Matriz identidad;

  matriz_init(&identidad, 3);

  matriz_set_at(&identidad, 0, 0, 1);
  matriz_set_at(&identidad, 1, 1, 1);
  matriz_set_at(&identidad, 1, 0, 0);
  matriz_set_at(&identidad, 2, 1, 9);
  matriz_set_at(&identidad, 1, 2, 5);
  
  assert( matriz_at(&identidad, 0,0), 1);
  assert( matriz_at(&identidad, 1,1), 1);
  assert( matriz_at(&identidad, 1,0), 0);
  assert( matriz_at(&identidad, 2,1), 9);
  assert( matriz_at(&identidad, 1,2), 5);

  matriz_free(&identidad);

  return 0;


}
