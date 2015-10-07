#include "cadena.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void cadena_init(Cadena* this, const char* dato, unsigned largo) {
    memset(this, 0, sizeof(Cadena));

    if ( !dato )
        return;

    this->datos = malloc( sizeof(char) * largo);
    this->cantidad = largo;

    memcpy(this->datos, dato, largo);
}

void cadena_modificar(Cadena* this, const char* dato) {
    if ( !dato ) {
        return;
    }

    if ( this->datos ) {
        free(this->datos);
    };

    this->cantidad = strlen(dato);
    this->datos = malloc( sizeof(char) * this->cantidad);
    memcpy(this->datos, dato, this->cantidad);
};

void cadena_concatenar(Cadena* this, const char* dato) {
    char* nuevo;
    unsigned nuevaCantidad;

    if ( !dato )
        return;

    nuevaCantidad = this->cantidad + strlen(dato);
    nuevo = malloc( sizeof(char) * nuevaCantidad);

    memcpy(nuevo, this->datos, this->cantidad);
    memcpy(nuevo + this->cantidad, dato, strlen(dato));

    free(this->datos);
    this->cantidad = nuevaCantidad;
    this->datos = nuevo;
}

void cadena_print(Cadena* this) {
    char* corriente = this->datos;

    while ( (corriente - this->datos) < this->cantidad) {
        printf("0x%x - %c\n", *corriente, *corriente);
        corriente++;
    }
}

