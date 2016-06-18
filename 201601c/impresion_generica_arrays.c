#include <stdio.h>

typedef void (*FuncionImpresion)(void* );

void imprimir_entero(void*  i) {
    int* v = (int*)i;
    printf("%d\n", *v);
}

void imprimir_flotante(void*  i) {
    float* v = (float*)i;
    printf("%f\n", *v);
}

void imprimir_double(void*  i) {
    double* v = (double*)i;
    printf("%f\n", *v);
}

/****
 * Esta función itera un vector e invoca la funcion 'f' para cada uno de sus
 * elementos
 *
 * @param    vector:     Puntero al vector
 * @param  tam_dato: Tamaño del elemento del vector
 * @param      cant: Cantidad de elementos q tiene el vector
 * @param         f: Función impresión segun tipo de elemento del vector
 *
 */
void imprimir(void* vector, unsigned tam_data, int cant, FuncionImpresion f) {
  while(cant--) {
    (*f)(vector);
    vector += tam_data;
  }
}
int main(int argc, char* argv[]) {
  int enteros[] = {1,2,3,4};
  float decimales[] = {1.1,2.2};
  double DECIMALES[] = {3.1,3.2};

  imprimir(enteros,   sizeof(int),   sizeof(enteros)/sizeof(int),     &imprimir_entero);
  imprimir(decimales, sizeof(float), sizeof(decimales)/sizeof(float), &imprimir_flotante);
  imprimir(DECIMALES, sizeof(double), sizeof(DECIMALES)/sizeof(double), &imprimir_double);
}
