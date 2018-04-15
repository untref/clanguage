#include <stdio.h>

void swap( char* pA,  char* pB, unsigned tam) {

    for( unsigned i = 0; i < tam; i++) {
        char tmp = *pA;

        *pA = *pB;

        *pB = tmp;

        pA = pA + 1;
        pB = pB + 1;

    }
}

void intercambiar( double* a,  double* b) {
    double tmp = *a;

    *a = *b;

    *b = tmp;
}

int main(int argc, char** argv) {
    {
        double  a = 1.0;
        double b = 2.0;


        printf("linea: %d - antes a(%f) b(%f)\n", __LINE__, a, b);

        swap( &a, &b, sizeof(double));

        printf("linea: %d - despues a(%f) b(%f)\n", __LINE__, a, b);
    }
    
#if 0
    {
        double a = 1.0;
        double b = 2.0;


        printf("linea: %d - antes a(%f) b(%f)\n", __LINE__, a, b);

        intercambiar( &a, &b);

        printf("linea: %d - despues a(%f) b(%f)\n", __LINE__, a, b);
    }
#endif

} 
