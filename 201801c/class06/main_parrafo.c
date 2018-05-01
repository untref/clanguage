#include <stdio.h>

#include "Palabra.h"
#include "Parrafo.h"

int main(int argc, char** argv) {
    { 
        Palabra palabras[3];

        palabra_init(palabras, "Macri");
        palabra_init(palabras + 1, "para la mano");
        palabra_init(palabras + 2, "Macri");

        if ( !palabra_es_igual(palabras, "Macri") ) {
            palabra_reemplazarCon(palabras, "GATOOOOOO");
        }

        if ( !palabra_es_igual(palabras + 2, "Macri") ) {
            palabra_reemplazarCon(palabras + 2, "GATOOOOOO");
        }

        palabra_imprimir(palabras);
        palabra_imprimir(palabras + 2);
        printf("\n\n");

    }

    { 
        Palabra macri;

        palabra_init(&macri, "Macri");
        palabra_imprimir( palabra_reemplazarCon(&macri, "para la mano Macri") );
        
    }

    {
        Parrafo p;

        parrafo_init(&p);

        parrafo_agregar_palabra(&p, "Macri ");
        parrafo_agregar_palabra(&p, "para ");
        parrafo_agregar_palabra(&p, "la ");
        parrafo_agregar_palabra(&p, "mano ");
        parrafo_agregar_palabra(&p, "Macri ");
        parrafo_agregar_palabra(&p, ".");

        parrafo_imprimir(&p);

        parrafo_reemplazar_palabra_con(&p, "Macri ", "GATOOOOOOO ");

        printf("\n");

        parrafo_imprimir(&p);

        printf("\n");

        parrafo_release(&p);
    }

}
