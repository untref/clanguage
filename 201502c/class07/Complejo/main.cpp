#include <iostream>

// Implementar la clase complejo

int main()
{
    Complejo c(109, 2);
    Complejo d;

    c.sumar(d);
    c.print();

    c.restar(d);
    c.print();

    printf("modulo de c %f\n", c.modulo());

    return 0;
}
