/*
 * main.c
 *
 *  Created on: Jul 31, 2016
 *      Author: alumno
 */
#include <stdio.h>

int main(int argc, char** argv) {
	unsigned int i = 0x2;
	char c = 0x1;
	char d;

    // Con & optenemos dirección de memoria
	unsigned int* pi = &i;
	char* pc = pi;

	*pc = 9;

	printf("Derreferenciar pi: %d\n", *pi);
	printf("Derreferenciar pc: %d\n", *pc);


	printf("Tamano unsigned: %d\n", sizeof(i) );
	printf("Tamano int: %d\n", sizeof(int));
	printf("Tamano char: %d\n", sizeof(char));
	printf("Tamano char puntero: %d\n", sizeof(char*));
	printf("Tamano int puntero: %d\n", sizeof(int*));

	return 0;
}
