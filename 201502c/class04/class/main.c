#include <stdio.h>
#include <stdlib.h>

#include "../../assertion.h"

int compare_int(const void* e1, const void* e2) {
  const int* a = e1;
  const int* b = e2;

  return *a - *b;
}

int compare_float(const void* e1, const void* e2) {
  const float* a = e1;
  const float* b = e2;

  return *a - *b;
}

/*****
 * Impresión de enteros
 *
 * */
void print_enteros_0(int* numeros, unsigned elementos) {
    int i;

    printf("print_enteros_0 - sin puntero a función\n");
    for(i = 0; i < elementos; ++i) {
        printf("%d: %d\n", i, numeros[i]);
    }
}

void print_enteros_1(int* numeros, unsigned elementos, void (*print)(unsigned, int)) {
    int i;

    printf("print_enteros_1 - con puntero a función y parámetro tipo int\n");
    for(i = 0; i < elementos; ++i) {
      print(i, numeros[i]);
    }
}

void print_enteros_2(int* numeros, unsigned elementos, void (*print)(unsigned, const void*)) {
    int i;

    printf("print_enteros_2 - con puntero a función y parámetro generico\n");
    for(i = 0; i < elementos; ++i) {

      // OJO q ahora el parametro a print es un puntero!!!
      print(i, numeros + i);
    }
}

void print_entero_parametro_fijo(unsigned index, int value ) {
  printf("%d: %d\n", index, value);
}

void print_entero_parametro_generico(unsigned index, const void* value ) {
  printf("%d: %d\n", index, *(int*)value);
}

void print_entero(size_t index, const void* value) {
        printf("%d: %d\n", index, *(int*)value);
}

void print_entero_en_pesos(size_t index, const void* value) {
        printf("%d: $ %d\n", index, *(int*)value);
}


/*****
 * Impresión de flotantes
 *
 * */
void print_float_0(float* numeros, unsigned elementos) {
    int i;

    printf("print_float_0 - sin puntero a función\n");
    for(i = 0; i < elementos; ++i) {
        printf("%d: %f\n", i, numeros[i]);
    }
}

void print_float_1(float* numeros, unsigned elementos, void (*print)(unsigned, float) ) {
    int i;

    printf("print_float_1 - con puntero a función y parámetro tipo float\n");
    for(i = 0; i < elementos; ++i) {
      print(i, numeros[i]);
    }
}

void print_float_2(float* numeros, unsigned elementos, void (*print)(unsigned, const void*) ) {
    int i;

    printf("print_float_2 - con puntero a función y parámetro generico\n");
    for(i = 0; i < elementos; ++i) {
      print(i, numeros + i);
    }
}

void print_float_parametro_fijo(unsigned index, float value ) {
  printf("%d: %f\n", index, value);
}

void print_float_parametro_generico(unsigned index, const void* value) {
  printf("%d: %f\n", index, *(float*)value);
}

void print_flotante(size_t index, const void* value) {
        printf("%d: %f\n", index, *(float*)value);
}

void print_flotante_en_pesos(size_t index, const void* value) {
        printf("%d: $ %f\n", index, *(float*)value);
}

void print_short(size_t index, const void* value) {
        printf("%d: %d\n", index, *(short*)value);
}


void iterar(const void* array,
            size_t array_size,
            size_t element_size,
            void (*doit)(size_t, const void*) ) {
    void* current = array;

    while ( current - array < array_size ) {
        doit( (current - array) / element_size, current );
        current += element_size;
    }
}

int main()
{
    setupTestEnv();

    {
        int numeros[] = {1,2,3,4,3,2,1};


        deny(numeros[3] < numeros[4], 1);

        // Para ordenar el array de numeros utilizamos el qsort.  Para eso
        // necesitamos una función q compare dos elementos del array
        // como en este caso son enteros definimos una f 'compare_int' con la
        // firma que requiere el qsort
        //
        qsort(numeros, sizeof(numeros) / sizeof(int), sizeof(int), compare_int);

        assert(numeros[0] <= numeros[1], 1);
        assert(numeros[1] <= numeros[2], 1);
        assert(numeros[2] <= numeros[3], 1);
        assert(numeros[3] <= numeros[4], 1);
        assert(numeros[4] <= numeros[5], 1);

        // Hagamos una función que nos permita ver si el array impreso 
        // está ordenado
        // 
        // NOTA: Estas dos funciones 'print_enteros_0' y 'print_floats_0' 
        // tienen código idéntico. Vamos como reescribirlo para que el código
        // no se repita.
        //
        // HABRA MANERA DE ESCRIBIR UNA UNICA FUNCION Q NOS PERMITA ITERAR
        // UN ARRAY E IMPRIMIR SU CONTENIDO?
        // 
        print_enteros_0(
            numeros,                          /* base del array */
            sizeof(numeros) / sizeof(float)   /* cantidad de elementos */
        );
        // PRIMERA REFACTORIZACIOM:
        // Lo único q tienen de diferentes estas funciones son los printfs que dependen
        // de cada uno de los tipos (int o float), con el fin de sacar este código de 
        // esta función, defino un puntero a función que recibirá la función que imprime en 
        // efecto. Hacemos lo propio para floats
        //
        print_enteros_1(
            numeros,                          /* base del array */
            sizeof(numeros) / sizeof(float),  /* cantidad de elementos */
            print_entero_parametro_fijo
        );
        //
        // Esto no nos sirve para nada!!!!! Seguimos teniendo dos funciones y para colmo de males
        // ahora reciben un puntero a función!
        //
        // Cambiemos el puntero a función para que nos sirva en cualquier situación, ya sea
        // si los elementos son enteros o flotantes
        //
        print_enteros_2(
            numeros,                          /* base del array */
            sizeof(numeros) / sizeof(float),  /* cantidad de elementos */
            print_entero_parametro_generico
        );

        //
        // Logramos generalizar la función q se encarga de la impresión! Ahora solo nos resta
        // tener una única función que itere y le podamos pasar la f de impresión
        // Eso es iterar
        iterar(numeros, sizeof(numeros), sizeof(int), print_entero_en_pesos);
        iterar(numeros, sizeof(numeros), sizeof(int), print_entero);
    }

    {
        float numeros[] = {1.1, 2.2, 3.3, 4.4, 3.3, 2.2, 1.1};

        deny(numeros[3] < numeros[4], 1);

        // Para ordenar el array de numeros utilizamos el qsort.  Para eso
        // necesitamos una función q compare dos elementos del array
        // como en este caso son enteros definimos una f 'compare_float' con la
        // firma que requiere el qsort
        //
        qsort(numeros, sizeof(numeros) / sizeof(float), sizeof(float), compare_float);

        assert(numeros[0] <= numeros[1], 1);
        assert(numeros[1] <= numeros[2], 1);
        assert(numeros[2] <= numeros[3], 1);
        assert(numeros[3] <= numeros[4], 1);
        assert(numeros[4] <= numeros[5], 1);

        // Hagamos una función que nos permita ver si el array impreso 
        // está ordenado
        //
        // NOTA: Ver nota en invocación de 'print_enteros_0'
        //
        print_float_0(
            numeros,                          /* base del array */
            sizeof(numeros) / sizeof(float)   /* cantidad de elementos */
        );

        print_float_1(
            numeros,                          /* base del array */
            sizeof(numeros) / sizeof(float),  /* cantidad de elementos */
            print_float_parametro_fijo
        );

        print_float_2(
            numeros,                          /* base del array */
            sizeof(numeros) / sizeof(float),  /* cantidad de elementos */
            print_float_parametro_generico
        );

        iterar(numeros, sizeof(numeros), sizeof(float), print_flotante);
        iterar(numeros, sizeof(numeros), sizeof(float), print_flotante_en_pesos);
    }

    {
        
      // Lo interesante de nuestra f iterar es que se puede utilizar para cualquier 
      // tipo de dato
      short numeros[] = {1990, 1920, 1480};
      iterar(numeros, sizeof(numeros), sizeof(short), print_short);
    }

}

