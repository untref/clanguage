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

  assert( matriz_at(&identidad, 0,0), 1);
  assert( matriz_at(&identidad, 1,1), 1);
  assert( matriz_at(&identidad, 1,0), 0);

  matriz_free(&identidad);

  return 0;


}
