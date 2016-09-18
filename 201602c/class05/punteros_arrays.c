/*
 * main.c
 *
 *  Created on: Jul 31, 2016
 *      Author: alumno
 */
#include <stdio.h>

int main(int argc, char** argv) {
	char array[] = { 'A', 66, 0x20, 'v', 0x1, 0x0 };

	char* p = array + 2;
	char* q = 0x0;

	*p = 9;

	int numero = *p;
	int* otroNumero = p;
	printf("Que va a imprimir esto? '%d'\n", numero );


	char* p;

	// Inicializar puntero (nos importa el valor de q al momento de dereferenciarlo)
	char* q = 0xbf000dfd;

	printf("array: %s\n", array);

	// Asignacion y aritmetica de punteros
	printf("Que va a imprimir esto? '%x'\n", p );

	p = p + 500;

	p = array + 2;

	// Dereferenciacion
	printf("Que va a imprimir esto? '%c'\n", *p );

	printf("Valor absoluto de array: 0x%x\n", array);

	printf("Que va a imprimir esto? '%c'\n", *(array + 3) );
	printf("Valor elemento '%d' del array '%c'\n", 0, array[0]);
	printf("Valor elemento '%d' del array '%c'\n", 2, array[2]);
	printf("Valor elemento '%d' del array '%c'\n", 4, array[4]);
	printf("Valor elemento '%d' del array '%c'\n", 99, array[99]);
	printf("Valor elemento '%d' del array '%c'\n", -1, array[-1]);
	return 0;
}
