#include "Parrafo.h" 

#include <stdio.h>
#include <string.h>
#include <stdlib.h>


Parrafo* parrafo_inicializar_vacio(Parrafo* this) {
    memset(this, 0x0, sizeof(Parrafo));
    return this;
}

Parrafo* parrafo_inicializar_con(Parrafo* this, char** parrafo, unsigned palabras) {
    parrafo_inicializar_vacio(this);
    this->cantidad = palabras;
    this->palabras = (char**)malloc( palabras * sizeof(char*));

    char** actual = parrafo;
    char** destino = this->palabras;

    while (palabras--) {
        *destino = (char*)malloc( strlen(*actual) + 1);
        strcpy(*destino, *actual);
        ++destino;
        ++actual;
    }

    return this;
}


Parrafo* parrafo_mostrar(Parrafo* this) {
    unsigned cantidad = this->cantidad;
    char** palabraActual = this->palabras;
    printf("cantidad: %d\n", this->cantidad);

    if ( !this->palabras ) {
        printf("no hay palabras\n");
        return this;
    }

    while (cantidad--) {
        printf("%s ", *palabraActual);
        palabraActual++;
     }

    return this;
}

Parrafo* parrafo_reemplazar_todo(Parrafo* this, char* palabra, char* reemplazo) {
    unsigned palabras = this->cantidad;
    char** palabraActual = this->palabras;

    while (palabras--) {
        if ( strcmp( *palabraActual, palabra ) == 0 ) {
            free( *palabraActual );
            *palabraActual = (char*)malloc( strlen(reemplazo) + 1 );
            strcpy(*palabraActual, reemplazo);
        } 
        ++palabraActual;
    };
    return this;
}

