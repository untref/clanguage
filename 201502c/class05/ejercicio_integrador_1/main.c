#include <stdio.h>
#include <stdlib.h>

#include "../../assertion.h"

double sumatoria(void* numeros, unsigned total_bytes, unsigned tam_elem,  void (*sumar)(void*, void*) ) {
    void* current = numeros;
    double result = 0;

    while ( (current - numeros) < total_bytes ) {
        sumar(&result, current);
        current += tam_elem;
    }

    return result;
};

void productoria( void* numeros,
                  unsigned total_bytes,
                  unsigned tam_elem,
                  void* result,
                  void (*prod)(void*, void*) ) {
    void* current = numeros;

    while ( (current - numeros) < total_bytes ) {
        prod(result, current);
        current += tam_elem;
    }
};

void sumar_int(void* result, void* elm) {
    double* r = (double*)result;
    int* i = (int*)elm;

    *r += *i;
};

void sumar_double(void* result, void* elm) {
    double* r = (double*)result;
    double* i = (double*)elm;

    *r += *i;
};

void prod_double(void* result, void* elm) {
    double* r = (double*)result;
    double* i = (double*)elm;

    *r *= *i;
};

void prod_short(void* result, void* elm) {
    short* r = (short*)result;
    short* i = (short*)elm;

    *r *= *i;
};

int main()
{

    // Definir la funcion sumatoria para que funcione con varios tipos.
    // Definir ademas todas las funciones extras necesarias para que los
    // tests pasen.
    //
    // Hacer lo propio con la productoria.
    //
    // NOTA: SI O SI LA PRODUCTORIA NO DEBE SER UNA FUNCION SINO
    // UN PROCEDIMIENTO.
    {
        int numeros[] = {1, 2, 3, 4, 5};
        assert( sumatoria(numeros, sizeof(numeros), sizeof(int), sumar_int), 15);
    }

    {
        double numeros[] = {1.0, 2.0, 3.0, 4.0, 9.0};
        assert( sumatoria(numeros, sizeof(numeros), sizeof(double), sumar_double), 19.0);
    }

    {
        double numeros[] = { 1.0, 2.0, 3.0};
        double resultado = 1;

        productoria(numeros, sizeof(numeros), sizeof(double), &resultado, prod_double);

        assert(resultado, 6.0);
    }

    {
        short numeros[] = { 3, 4, 5};
        short resultado = 1;

        productoria(numeros, sizeof(numeros), sizeof(short), &resultado, prod_short);

        assert(resultado, 60);
    }
    return 0;
}
