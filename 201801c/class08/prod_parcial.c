#include <stdio.h>

double prod_alan(void* numeros, unsigned elemNum, double (*prod)(void*, unsigned) ) {

    double result = 1;
    unsigned i;

    for(i = 0; i < elemNum; i++) {
        result *= prod(numeros, i);
    }

    return result;
}

double prod_int(void* vector, unsigned indice) {
    int* enteros = (int*)vector;
    return (double)enteros[indice];
}


void prod_marcelo(void* numeros, unsigned longNumeros, unsigned elemTam, void* result, 
        void (*prod)(void* /* result */, void* /* valor elemento */) ){
    unsigned i;

    for(i = 0; i < longNumeros; i += elemTam) {
        (*prod)(result, numeros + i);
    }

}

void prod_int_marcelo_double(void* result, void* elem) {
    double* doubleResult = result;
    int* enteroElemento = elem;

    *doubleResult *= *enteroElemento;
}


int main(int argc, char** argv) {
    {
        int enteros[] = { 1, 2, 3, 5 };
        double result = 1;

        prod_marcelo(
            enteros, 
            sizeof(enteros),
            sizeof(int),
            &result,
            &prod_int_marcelo_double
        );
        printf("result#1: %f\n", result);
    }

    {
        int enteros[] = { 1, 2, 3, 5 };

        double result = prod_alan(
            enteros, 
            sizeof(enteros) / sizeof(int),
            &prod_int
        );
        printf("result#2: %f\n", result);
    }
}
