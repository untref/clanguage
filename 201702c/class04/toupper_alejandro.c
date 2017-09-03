#include <stdio.h>
#include <stdlib.h>

void upper_case(char* a){
	while(*a != '\0'){
		if(*a >= 'a' && *a <= 'z'){
		   *a -= 32;
		}
		a++;
	}
}

void lower_case(char* a){
	while(*a != '\0'){
		if(*a >= 'A' && *a <= 'Z'){
			*a += 32;
		}
		a++;
	}
}

void capitalize(char* a){
	*a -= 32;
}

void imprimir(char* a){
	while(*a != '\0'){
		printf("%c", *a);
		a++;
	}
}

int main(int argc, char** argv) {

	// char arrayToUpper [] = {'a','b','c','\0' };
	char* arrayToUpper = "abc";
	char arrayToLower [] = {'A','B','C','\0' };
	char arrayCapitalize [] = {'a','b','c','\0' };
	upper_case(arrayToUpper);
	lower_case(arrayToLower);
	capitalize(arrayCapitalize);

	imprimir(arrayToUpper);
    printf("\n");
	imprimir(arrayToLower);
    printf("\n");
	imprimir(arrayCapitalize);
    printf("\n");
	imprimir(arrayCapitalize);

	return 0;
}
