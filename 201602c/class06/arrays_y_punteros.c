/*
 * main.c
 *
 *  Created on: Jul 31, 2016
 *      Author: alumno
 */
#include <stdio.h>

void nombre(unsigned* otrosEnteros, unsigned lon /* unsigned otrosEnteros[] */) {
	printf("Tamano de otrosEnteros: %d, %d\n", sizeof(otrosEnteros), lon);

	otrosEnteros[2] = 0x9; /* *(otrosEnteros + 2) = 0x000000009 */
}

void nombreConError(unsigned otrosEnteros[]) {
    /***
     * OJO 
     * El sizeof de otrosEnteros no es 12 !!!!
     */
	printf("Tamano de otrosEnteros: %d\n", sizeof(otrosEnteros));
}

int main(int argc, char** argv) {
	unsigned enteros[] = { 1,2,3 };

	printf("Tamano del entero: %d\n", sizeof(unsigned));
	printf("Tamano de enteros: %d\n", sizeof(enteros));


	nombre(enteros, sizeof(enteros));

	printf("Tamano de 3re entero: %d\n", enteros[2]);

	return 0;
}
