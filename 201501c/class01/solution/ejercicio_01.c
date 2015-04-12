#include <stdio.h>

#define TAM_ARRAY 4
 
int main(int argc, char** argv) {
  int enteros[] = { 1, 2, 3, 78 };
  int alumnos = 7;
  int* pi = 0;  // Es equivalente a escribir pi = NULL

  // El puntero pi apunta a NULL
  printf("que significa este valor y cuanto vale: 0x%x\n", pi );

  pi = &alumnos;

  // pi es un puntero que apunata a la dirección dende está almacenado
  // el entero alumnos
  printf("que significa este valor y cuanto vale: 0x%x\n", pi );

  // pi es un puntero que apunta al comienzo del array (primer elemento)
  // pi es la dirección donde el array comienza
  pi = enteros;

  // El primer elemento del array enteros (1)
  printf("cual es el valor de la siguiente expresión %d?\n", *pi);

  int* pj = enteros;

  // Que es lo que está haciendo este bloque de código?
  // Intercambio elemento 3 del array por el 2
  {
    int valor = *(pj+2);

    pi = pi + 3;

    pj[2] = *pi;

    *pi = valor;
  }

  // Imprimir array enteros (sin utilizar los corchetes ni la expresión FOR)!!!!
  while( pj - enteros < sizeof(enteros) / sizeof(int) ) {
    printf("%d\n", *pj++);
  }
    

}
