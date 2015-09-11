#include <stdio.h>
#include <stdlib.h>

#include "../../assertion.h"
int compare_int(const void* e1, const void* e2 ) {
    const int* integer1 = e1;
    const int* integer2 = e2;
    return *integer1 - *integer2;
};

int compare_float(const void* e1, const void* e2 ) {
    const float* float1 = e1;
    const float* float2 = e2;
    return *float1 - *float2;
};

void print_int(const int* numeros, size_t array_size, size_t element_size) {
    const int* current = numeros;

    while( current - numeros < array_size / element_size ) {
        printf("%ld: %d\n", (current - numeros), *current++);
    }
}

void print_float(const float* numeros, size_t array_size, size_t element_size) {
    const float* current = numeros;

    while( current - numeros < array_size / element_size ) {
        printf("%ld: %f\n", (current - numeros), *current++);
    }
}


void iterar(const void* array, size_t array_size, size_t element_size, void (*doit)(size_t, const void*) ) {
    void* current = array;

    while ( current - array < array_size ) {
        doit( (current - array) / element_size, current );
        current += element_size;
    }
}

void do_float(size_t index, const void* element ) {
    printf("%d: %f\n", index, *( (float*)element ) );
};

int main()
{
    setupTestEnv();

    {
        int numeros[] = {1,2,3,4,3,2,1};

        deny(numeros[3] < numeros[4], 1);
        qsort(numeros, sizeof(numeros) / sizeof(int), sizeof(int), compare_int);
        print_int(numeros, sizeof(numeros), sizeof(int));

        assert(numeros[0] <= numeros[1], 1);
        assert(numeros[1] <= numeros[2], 1);
        assert(numeros[2] <= numeros[3], 1);
        assert(numeros[3] <= numeros[4], 1);
        assert(numeros[4] <= numeros[5], 1);

    }

    {
        float numeros[] = {1.1, 2.2, 3.3, 4.4, 3.3, 2.2, 1.1};

        deny(numeros[3] < numeros[4], 1);
        qsort(numeros, sizeof(numeros) / sizeof(float), sizeof(float), compare_float);
        print_float(numeros, sizeof(numeros), sizeof(float));

        assert(numeros[0] <= numeros[1], 1);
        assert(numeros[1] <= numeros[2], 1);
        assert(numeros[2] <= numeros[3], 1);
        assert(numeros[3] <= numeros[4], 1);
        assert(numeros[4] <= numeros[5], 1);

        iterar(numeros, sizeof(numeros), sizeof(float), do_float);
    }
}

