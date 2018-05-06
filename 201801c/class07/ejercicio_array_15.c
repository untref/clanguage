#include <stdio.h>
#include <string.h>

char* proximo(char* str) {
    char* aux = str;

    while(*aux != ' ' && *aux != '\0') {
        ++aux;
    }
    return str + (aux - str);
}

unsigned ocurrencias(char* parrafo, const char* busqueda, char** result, unsigned tam) {
    char* prox = parrafo;
    unsigned insertionIndex = 0;

    while (*prox != 0x0 && tam != 0x0) {
        if ( strncmp(prox + 1, busqueda, strlen(busqueda)) == 0x0 ) {
            result[insertionIndex] = prox;
            --tam;
            ++insertionIndex;

            // printf("%ld - %u - %u\n", prox - parrafo, tam, insertionIndex );
        }

        prox = proximo(prox + 1);
    }

    return insertionIndex;
}

int main(int argc, char** argv) {
    char* parrafo = "palabra es un parrafo donde buscamos esta palabra a ver si aparece o no la palabra palabra";
    char* result[5];
    unsigned count = sizeof(result) / sizeof(char*);

    count = ocurrencias(parrafo, "palabra", result, count);
    
    for(unsigned i = 0; i < count; ++i) {
        printf("%u - %p - %p: %s\n", i, parrafo, result + i, result[i]);
    }
}

#if 0
// No devolver punteros a memoria local
char** ocurrencias(char* parrafo, const char* busqueda) {
    char* p1 = parrafo + 1;
    char* p2 = parrafo + 10;

    char* result[2];

    result[0] = p1;
    result[1] = p2;


    return result;
}
#endif 

#if 0
char** ocurrencias(char* parrafo, const char* busqueda) {
    char* p1 = parrafo + 1;
    char* p2 = parrafo + 10;

    char** result = (char**)malloc( 2 * sizeof(char*) );

    result[0] = p1;
    result[1] = p2;


    return result;
}
#endif


