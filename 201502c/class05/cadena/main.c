#include <stdio.h>
#include <stdlib.h>

#include "../../assertion.h"

#include "cadena.h"

int main()
{
    Cadena c;
    const char datoInical[] = { 0x0, 0xf, 0x0, 0xa };

    cadena_init(&c, datoInical, sizeof(datoInical));
    cadena_print(&c);

    cadena_modificar(&c, "UNTREF");
    cadena_print(&c);

    cadena_concatenar(&c, " 2015");
    cadena_print(&c);

    cadena_liberar(&c);

    return 0;
}
