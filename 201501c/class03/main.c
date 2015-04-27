#include <stdio.h>

#include "tda.h"

int main(int argc, char** argv) {
    // Utilizacion del struct
    // struct _Persona p;

    // Utilizacion del typedef
    Persona p1;

    persona_init(&p1, "mi nombre es juan de los palotes", "mi apellido es largo");

    persona_print(&p1);

    printf("\n");
};
