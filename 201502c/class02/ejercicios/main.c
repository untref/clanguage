#include <stdio.h>
#include <stdlib.h>

#include "../../assertion.h"

#define ARRAY_ENTEROS_TAMANO 1024
#define ARRAY_FLOTANTES_TAMANO 1024

void copiarArrayEnteros(int dest[], int* orig) {
    return;
}

// Devuelve 1 si son iguales, sino 0
unsigned compararArrayEnteros(int *a1, int *a2 ) {
    return;
}

void copiarArrayFlotantes(double dest[], double* orig) {
    return;
}

// Devuelve 1 si son iguales, sino 0
unsigned compararArrayFlotantes(double *a1, double* a2 ) {
    return;
}

// Modificar el código de las funciones y de ser necesario sus parámetros de modo
// de hacer que los tests pasen.
int main()
{
    { // Array de enteros
        int arrayEnteros00[] = { 1, 2, 3, 4, 5, 6, 7, 8};

        deny(compararArrayEnteros(arrayEnteros01,arrayEnteros00), 1);

        copiarArrayEnteros(arrayEnteros01, arrayEnteros00);
        assert(compararArrayEnteros(arrayEnteros01,arrayEnteros00), 1);
    }

    { // Array de doubles
        double arrayFlotantes00[] = { 1.1, 2.2, 3.3, 4.4, 5.5, 6.6, 7.7, 8.8};

        deny(compararArrayFlotantes(arrayFlotantes01,arrayFlotantes00), 1);

        copiarArrayFlotantes(arrayFlotantes01, arrayFlotantes00);
        assert(compararArrayFlotantes(arrayFlotantes01,arrayFlotantes00), 1);
    }

    { // String
        char* string[] = "Insertar aqui otra cosa";
        char otraCosa[] = "esto";

        // Definir funcion para que el assert pase
  
        assertStr(string, "Insertar esto otra cosa" );

        // Hacer que el assert pase escribiendo solo una linea
        assert(string, "Insertar");
    }
    return 0;
}



















































// TODO
// - Heap
// - Que tan generica es la memoria
// - Intercambiar variables
// - Structs
// - Listas
