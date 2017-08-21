#include <stdio.h>
#include <string.h>

int* buscarValor(int* a, unsigned l, int v) {
    int* p = a;

    while ( (p - a) < l ) {
        if ( *p++ == v ) {
            return p - 1;
        }
    }

    return 0x0;
};

void* lookup(void* baseOrArray, unsigned length, unsigned sizeOfElem, void* value) {
    void* current = baseOrArray;

    while ( (current - baseOrArray) < length ) {
        if ( memcmp(current, value, sizeOfElem) == 0) {
            return current;
        }; 

        // skip element
        current += sizeOfElem;
    }

    return 0x0;
};

int main(int argc, char** argv) {
    int enteros[] = {1,2,3,4};

    {
    int *match = buscarValor(enteros, sizeof(enteros) / sizeof(int), 4);

    printf("Match: %p. Value: %d\n", match, *match);
    }

    {
    int *match = buscarValor(enteros, sizeof(enteros) / sizeof(int), 2);

    printf("Match: %p. Value: %d\n", match, *match);
    }

    {
    int *match = buscarValor(enteros, sizeof(enteros) / sizeof(int), 9);

    printf("Match: %p\n", match);
    }

    {
        int value = 9; 
        int *match = (int*)lookup(enteros, sizeof(enteros), sizeof(int), &value);

        printf("Match: %p, value: %d\n", match, *match);
    }


};
