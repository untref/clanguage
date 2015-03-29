#include <stdio.h>

int main(int argc, char** ) {
  int enteros[] = { 1, 2, 3, 78 };

  int alumnos = 7;

  int* pi = 0;

  printf("que significa este valor y cuanto vale: %d\n", pi );

  pi = &alumnos;

  printf("que significa este valor y cuanto vale: %d\n", pi );
}
