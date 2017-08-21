#include <stdio.h>
#include <string.h>

void inicializar_flotantes(double* baseOfArray, unsigned lengthOfArray, double value) {
    double* current = baseOfArray;

    while ( (current - baseOfArray) < lengthOfArray ) {
        *current++ = value;
    };

    return;
};

void inicializar_integers(int* baseOfArray, unsigned lengthOfArray, int value) {
    int* current = baseOfArray;

    while ( (current - baseOfArray) < lengthOfArray ) {
        *current++ = value;
    };

    return;
};

void inicializar(void* baseOfArray, unsigned lengthOfArray, void* value, unsigned lengthOfValue) {
    void* current = baseOfArray;

    while ( (current - baseOfArray) < lengthOfArray ) {
        memcpy(current, value, lengthOfValue);
        current++;
    };

    return;
};


int main(int argc, char** argv) {
    {
        double doubles[4];
        //
        // Duplicamos código
        inicializar_flotantes( doubles, sizeof(doubles) / sizeof(double), 0 );
    }

    {   
        int integers[4];
        //
        // Duplicamos código
        inicializar_integers( integers, sizeof(integers) / sizeof(int), 4 );
    }

    {
        long long long_integers[10];
        long long value = 9;

        inicializar( long_integers, sizeof(long_integers), &value, sizeof(value) );
    }

    return 0;
};
