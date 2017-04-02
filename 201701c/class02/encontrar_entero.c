#include <stdio.h>

/***
 * Busca entero 
 *
 * @param   array_enteros   Puntero al comienzo del array
 * @param   cantidad        Cantidad de elementos en el array
 * @param   elemento        lo que busco
 *
 * @returns -1 no lo encuentra indice si lo encontró
 */
int encontrar_entero_facundo(int* array_enteros, unsigned cantidad, int elemento){

    int * puntero;
    unsigned i;
    int resultado = -1;
    for( i = 0; i < cantidad; i++ ) {

        puntero = array_enteros + i;

        if(*puntero == elemento){
            resultado = i;
        }
    }
    return resultado;
}

/***
 * Busca entero 
 *
 * @param   array_enteros   Puntero al comienzo del array
 * @param   cantidad        Cantidad de elementos en el array
 * @param   elemento        lo que busco
 *
 * @returns -1 no lo encuentra indice si lo encontró
 */
int encuentra_valores_mejorado(int* array_enteros, int cantidad, int elemento){
    int* puntero = array_enteros;

    while (cantidad != 0) {
        if ( *puntero == elemento ) {
            return (puntero - array_enteros);
        }
        puntero++;
        cantidad--;
    }

    return -1;
}

/***
 * Cambio de especificación. Si existe devuelve el puntero sin 0x0
 *
 * @param   array_enteros   Puntero al comienzo del array
 * @param   cantidad        Cantidad de elementos en el array
 * @param   elemento        lo que busco
 *
 * @returnr 0x0 o puntero al elemento
 */
int* encuentra_entero(int* array_enteros, int cantidad, int elemento){
    while (cantidad--) {
        if ( *array_enteros == elemento ) {
            return array_enteros;
        }
        array_enteros++;
    }

    return 0x0;
}

int main(){

    int array[] = {3,7,9};

    {
        int valor = 6;
        char* leyenda = "implementación mejorada";
        int index = encontrar_entero_facundo(array, sizeof(array) / sizeof(int), valor) ;

        printf("===================================================\n");
        printf("%s\n", leyenda);
        if ( index == -1 ) {
            printf("no existe elemento: %d\n", valor );
        }

        valor = 7;
        index = encontrar_entero_facundo(array, sizeof(array) / sizeof(int), valor) ;

        printf("---------------------------------------------------\n");
        printf("%s\n", leyenda);
        printf("elemento %d en posición %d\n", valor, index );
    }

    {
        int valor = 76;
        char* leyenda = "implementación mejorada";
        int index = encuentra_valores_mejorado(array, sizeof(array) / sizeof(int), valor) ;

        printf("===================================================\n");
        printf("%s\n", leyenda);
        if ( index == -1 ) {
            printf("no existe elemento: %d\n", valor );
        }

        valor = 9;
        index = encuentra_valores_mejorado(array, sizeof(array) / sizeof(int), valor) ;

        printf("---------------------------------------------------\n");
        printf("%s\n", leyenda);
        printf("elemento %d en posición %d\n", valor, index );
    }

    {
        int valor = 76;
        char* leyenda = "cambio especificación ";
        int* donde = encuentra_entero(array, sizeof(array) / sizeof(int), valor) ;

        printf("===================================================\n");
        printf("%s\n", leyenda);
        if ( donde == 0x0 ) {
            printf("no existe elemento: %d\n", valor );
        }

        valor = 9;
        donde = encuentra_entero(array, sizeof(array) / sizeof(int), valor) ;

        printf("---------------------------------------------------\n");
        printf("%s\n", leyenda);
        printf("elemento %d aquí 0x%x y la base es 0x%x\n", valor, donde, array );
    }
}

