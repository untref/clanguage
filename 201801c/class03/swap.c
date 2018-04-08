#include <stdio.h>

void intercambiar( double* a,  double* b) {
    double tmp = *a;

    *a = *b;

    *b = tmp;
}

int main(int argc, char** argv) {
    double a = 1.0;
    double b = 2.0;


    printf("linea: %d - antes a(%f) b(%f)\n", __LINE__, a, b);

    intercambiar( &a, &b);

    printf("linea: %d - despues a(%f) b(%f)\n", __LINE__, a, b);

} 
