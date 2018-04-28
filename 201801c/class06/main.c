#include <stdio.h>

void iterar_e_imprimir_enteros(int* enteros, unsigned elemNum) {
    unsigned i;
    for(i = 0; i < elemNum; ++i) {
        printf("a[%d]: %d\n", i, enteros[i]);
    }

}

void iterar_e_imprimir_flotantes(float* flotantes, unsigned elemNum) {
    unsigned i;
    for(i = 0; i < elemNum; ++i) {
        printf("a[%d]: %f\n", i, flotantes[i]);
    }

}

void imprimir_un_entero(unsigned index, int* valor) {
    printf("a[%d]: %d\n", index, *valor);
}

void iterar_e_imprimir_enteros2(int* enteros, unsigned elemNum, void (*hacer)(unsigned, int* ) ) {
    unsigned i;
    for(i = 0; i < elemNum; ++i) {
        (*hacer)(i, enteros + i);
    }

}

void imprimir_un_entero_3(unsigned index, void* valor) {
    printf("a[%d]: %d\n", index, *(int*)valor);
}

void imprimir_un_flotantes_3(unsigned index, void* valor) {
    printf("a[%d]: %f\n", index, *(float*)valor);
}

void iterar_e_imprimir_enteros3( void* enteros, unsigned elemNum, unsigned tamTipo, 
    void (*hacer)(unsigned, void* ) ) {
    unsigned i;
    for(i = 0; i < elemNum; i += tamTipo) {
        (*hacer)(i / tamTipo, enteros + i);
    }

}

int main(int argc, char** argv) {
    {
        int enteros[] = { 81, 18 };

        iterar_e_imprimir_enteros3(
            enteros, 
            sizeof(enteros),
            sizeof(int),
            &imprimir_un_entero_3
        );
    }
    {
        int enteros[] = { 9, 27 };

        iterar_e_imprimir_enteros2(
            enteros, 
            sizeof(enteros) / sizeof(int),
            &imprimir_un_entero
        );
    }

    {
        int enteros[] = { 1,2 };

        iterar_e_imprimir_enteros(enteros, sizeof(enteros) / sizeof(int));
    }

    {
        float flotantes[] = { 3.14159, 1.618033 };

        iterar_e_imprimir_enteros3(
            flotantes, 
            sizeof(flotantes),
            sizeof(float),
            &imprimir_un_flotantes_3
        );
    }
}


