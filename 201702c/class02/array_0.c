#include <stdio.h>

// void tamano_array(double flotantes[]) {
void tamano_array(double* flotantes) {
    printf("Tamaño del array en funcion: %lu\n", sizeof(flotantes) );  
};

void no_modifico_array(double* a) {
    a[2] = 4.9;
};


void que_modifica_aqui(double* a) {
    *(a + 4) = 2;
};

int main(int argc, char** argv) {
    double flotantes[] = { 1.1, 2.2, 3.3 };
    //
    // 4: 8 
    // 8: 1
    // 24:
    printf("Tamaño del array: %lu\n", sizeof(flotantes) );  
    printf("Tamaño de un elemento: %lu\n", sizeof(*flotantes) );  
    printf("Tamaño de un puntero: %lu\n", sizeof(&flotantes) );  


    //
    // 4: 3 
    // 8: 0
    // 24: 10
    tamano_array(flotantes);

    no_modifico_array(flotantes);
    printf("Elemento %lu del array: %f\n", 2, flotantes[2]);  
        
    que_modifica_aqui(flotantes);

    return 0;
};
