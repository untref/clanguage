#include <stdio.h>
#include <string.h>

/***
 * Cambio de especificación. Si existe devuelve el puntero sin 0x0
 *
 * @param   vector      Puntero al comienzo del array
 * @param   tamElemento tamano del elemento 
 * @param   tamVector   tamano del vector
 * @param   elemento    puntero al elemento
 *
 * @returnr 0x0 o puntero al elemento
 *
 *
 * @NOTA    Cambio char* por void* para evitar warnings de compilación
 */
void* encontrar_valor(void* vector, unsigned tamElemento, unsigned tamVector, void* elemento) {
    void* corriente = vector;

    while ( 
            (corriente - vector) < tamVector &&
            (memcmp(corriente, elemento, tamElemento) != 0) 
    ) {
        corriente += tamElemento;
    }

    if ( (corriente - vector) >= tamVector) {
        corriente = 0x0;
    }

    return corriente;
}


int main(){

    {
    int array[] = {3,7,9};
    int valor = 9;
    void* donde = encontrar_valor(array, sizeof(int), sizeof(array), &valor) ;


    if ( donde == 0x0 ) {
        return 0;
    }
    
    printf("la direccion es: 0x%x\n", donde);

    // Para derreferenciar tengo que castear (así sea un char*)
    printf("El valor apuntado : %d\n", *(int*)donde);
    }
    {
    double array[] = {3.3, 7.7 , 9.9, 10.10, 11.11};
    double valor = 10.10;
    void* donde = encontrar_valor(array, sizeof(double), sizeof(array), &valor) ;


    if ( donde == 0x0 ) {
        return 0;
    }
    
    printf("la direccion es: 0x%x\n", donde);

    // Para derreferenciar tengo que castear (así sea un char*)
    printf("El valor apuntado : %f\n", *(double*)donde);
    }
}

