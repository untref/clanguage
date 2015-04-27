#include "tda.h"

#include <string.h>

void persona_init(Persona* p, const char* nombre, const char* apellido) {
    strncpy( p->nombre, nombre, PERSONA_NOMBRE_LONG - 1);
    strncpy( p->apellido, apellido, PERSONA_APELLIDO_LONG - 1);
}

void persona_print(Persona* p) {
    printf("Persona[%s,%s]", p->nombre, p->apellido);
}
