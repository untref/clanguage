#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct _Palabra {
    char* valor;
} Palabra;

Palabra* palabra_init(Palabra* this, const char* strPalabra) {
    this->valor = malloc( sizeof(char) * (strlen(strPalabra) + 1));
    strcpy(this->valor, strPalabra);

    return this;
};

void palabra_release(Palabra* this) {
    if ( this->valor ) {
        free( this->valor );
    }
    this->valor = 0x0;
};

void palabra_imprimir(Palabra* this) {
    printf("%s", this->valor);
};

Palabra* palabra_reemplazarCon(Palabra* this, const char* strPalabra) {
    this->valor = realloc( this->valor, strlen(strPalabra) + 1);
    strcpy(this->valor, strPalabra);

    return this;
};

unsigned palabra_es_igual(Palabra* this, const char* strPalabra) {
    return strcmp(this->valor, strPalabra);
};

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

}
