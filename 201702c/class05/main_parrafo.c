#include <stdio.h>

#include "parrafo.h"

int main(int argc, char** argv) {
    {
        Parrafo p;
        parrafo_inicializar( &p );

        // Que no hacer!!!
        //
        //
        // printf("parrafo: %s\n", p.palabras[0]);

        parrafo_mostrar( &p );
    }

    {
        Parrafo p;
        parrafo_inicializar( &p );
        parrafo_agregar_palabra( &p, "palabra 1" );
        parrafo_mostrar( &p );
        parrafo_liberar( &p );
        printf("\n");
    }

    {
        Parrafo p;
        parrafo_inicializar( &p );
        parrafo_agregar_palabra( &p, "palabra 1" );
        parrafo_agregar_palabra( &p, "palabra 2" );
        parrafo_mostrar( &p );
        parrafo_liberar( &p );
        printf("\n");
    }

    {
        Parrafo p;
        parrafo_inicializar( &p );

        parrafo_agregar_palabra( &p, "palabra 1" );
        parrafo_agregar_palabra( &p, "palabra 2" );
        parrafo_agregar_palabra( &p, "palabra 2" );
        parrafo_agregar_palabra( &p, "palabra 2" );
        parrafo_agregar_palabra( &p, "palabra 2" );
        parrafo_mostrar( &p );
        printf("\n");

        parrafo_reemplazar( &p, "palabra 2", "capusotto");
        parrafo_mostrar( &p );

        parrafo_liberar( &p );
        printf("\n");
    }
}

