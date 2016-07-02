#include <stdio.h>

#include "Cadena.h"

int main(int argc, char** argv) {
    char valor_inicial[] = { 0x0, 0x0, 0x1, 0x10, 'A', 'b'};
    Cadena c;

    cadena_inicializar(&c, valor_inicial, sizeof(valor_inicial));
    cadena_print(&c);

    cadena_modificar(&c, "HOLA");
    cadena_print(&c);
    
    cadena_concatenar(&c, " UNTREF");
    cadena_print(&c);
    
    cadena_limpiar(&c);
    return 0 ;
}
