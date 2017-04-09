#include <stdio.h>

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

    while( --elementCount ) {
        (*doIt)(current);
        current += typeSize;
    }

};

int main(int argc, char** argv) {
    int enteros[] = {1,2,3,4};
    float decimales[] = {1.1,2.2,3.3,4.4};

    iterar(enteros, sizeof(enteros), sizeof(int), &printEntero);
    printf("\n");
    iterar(decimales, sizeof(decimales), sizeof(float), &printDecimales);
}

