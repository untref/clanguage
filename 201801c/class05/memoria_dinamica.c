#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void reemplazar_palabra_por_en(char* palabra, char* reemplazo, char* parrafo) {
    char* reemplazarEn = 0x0;

    while ( (reemplazarEn = strstr(parrafo, palabra) ) ){
        memcpy(reemplazarEn, reemplazo, strlen(reemplazo));
        reemplazarEn += strlen(reemplazo);
    }

    // COMPLETAR
};

int main(int argc, char** argv) {
    char* parrafo = "Para la mano Macri, Macri, Macri!";
    //              "Para la mano gatooooo, Macri, Macri!";

    char* nuevoParrafo = malloc( strlen(parrafo) + 1);
    strcpy(nuevoParrafo, parrafo);

    reemplazar_palabra_por_en("Macri", "MACRI", nuevoParrafo);

    free(nuevoParrafo);

    printf("%d. str(%s)\n", __LINE__, nuevoParrafo);

}



































