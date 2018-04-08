#include <stdio.h>

double perimetro( double radio,  double* pi) {
    *pi = 1.0;
    return 2.0 * (*pi) * radio;
}

int main(int argc, char** argv) {
    // Aritmetica punteros
    double pi = 3.14159;
    double* punteroPi = &pi;
    //
    // Stack
    double p = perimetro( 4 /* radio */,  punteroPi);

    printf("linea: %d - perimetro de circuns radio (%d): (%f)\n", __LINE__, 4, p);

    p = perimetro( 4 /* radio */,  punteroPi);
    printf("linea: %d - perimetro de circuns radio (%d): (%f)\n", __LINE__, 4, p);
} 
