#include <stdio.h>

#define TAM_ARRAY 4
 
int main(int argc, char** argv) {
  int enteros[] = { 1, 2, 3, 78 };
  int alumnos = 7;
  int* pi = 0;

  printf("que significa este valor y cuanto vale: 0x%x\n", pi );

  pi = &alumnos;

  printf("que significa este valor y cuanto vale: 0x%x\n", pi );

  pi = enteros;

  printf("cual es el valor de la siguiente expresión %d?\n", *pi);

  int* pj = enteros;

  // Que es lo que está haciendo este bloque de código?
  {
    int valor = *(pj+2);

    pi = pi + 3;

    pj[2] = *pi;

    *pi = valor;
  }

  // Imprimir array enteros (sin utilizar los corchetes ni la expresión FOR)!!!!


}
