#include <stdio.h>

#include "iterarl.h"

void printEntero(void* v) {
    int* pi = v;
    printf("%d\n", *pi);
};

void printDecimales(void* v) {
    float* pf = v;
    printf("%f\n", *pf);
};

void iterar(void* array, unsigned arrayLength, unsigned typeSize, void (*doIt)(void*)) {
    void* current = array;
    unsigned elementCount = arrayLength / typeSize;

    while( elementCount-- ) {
        (*doIt)(current);
        current += typeSize;
    }

};
