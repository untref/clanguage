#include <stdio.h>
#include <stdlib.h>

#include "../../assertion.h"

unsigned longitud(char* str) {
    char* p = str;

    while( *p ) {
        p++;
    }

    return p - str;
}

void copiar(char* dest, char* orig) {
    while( *dest++ = *orig++);
}

void swap(void* _a, void* _b, unsigned tam) {
#if 0
    char* a = _a;
    char* b = _b;
    char tmp;
    int i;
    for(i = 0; i < tam; i++) {
        tmp = *a;
        *a = *b;
        *b = tmp;
        ++a;
        ++b;
    }
#endif // 0

    char* a = _a;
    char* b = _b;
    char tmp;

    while ( tam-- ) {
        tmp = *a;
        *a = *b;
        *b = tmp;
        ++a;
        ++b;
    }
    return;
}

int main()
{
    int i = 4;
    int j = 5;
    double a = 2.3;
    double b = 8.0;

    swap(&i, &j, sizeof(int));
    swap(&a, &b, sizeof(double));

    assert(i, 5);
    assert(j, 4);
    assert(a, 8.0);
    assert(b, 2.3);


    char str[] = "Longitud de str";
    char buffer[1024];

    assert( strlen(str), 15);
    assert( longitud(str), 15);

    copiar(buffer, str);
    assertStr( buffer, "Longitud de str");


//    int numero = 0;
//    printf("%d\n", numero = 10 );
//    printf("%d\n", numero );

    return 0;
}
