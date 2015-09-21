#include <stdio.h>
#include <stdlib.h>

int main()
{

    // Definir la funcion sumatoria para que funcione con varios tipos.
    // Definir ademas todas las funciones extras necesarias para que los
    // tests pasen.
    //
    // Hacer lo propio con la productoria.
    //
    // NOTA: SI O SI LA PRODUCTORIA NO DEBE SER UNA FUNCION SINO
    // UN PROCEDIMIENTO.
    {
        int numeros[] = {1, 2, 3, 4, 5};
        assert( sumatoria(...), 15);
    }

    {
        double numeros[] = {1.0, 2.0, 3.0, 4.0, 5.0};
        assert( sumatoria(...), 15.0);
    }

    {
        double numeros[] = { 1.0, 2.0, 3.0};
        double resultado;

        productoria(numeros, sizeof(numeros), sizeof(double), ...);

        assert(resultado, 6.0);
    }

    {
        short numeros[] = { 3, 4, 5};
        short resultado;

        productoria(numeros, sizeof(numeros), sizeof(double), ...);

        assert(resultado, 60);
    }
    return 0;
}
