#include <stdio.h>
#include <stdlib.h>

#include "../../assertion.h"

#define TAM_STRING 1024

int main()
{
    {
        char s1[TAM_STRING] = {};
        char* esperado = "1234";

        strcpy(s1, esperado);
        assertStr(s1, esperado);

        strcpy(s1, "");
        denyStr(s1, esperado);

        // miStrCpy(s1, esperado);
        // assertStr(s1, esperado);
    }

    {
        char s1[TAM_STRING] = {};
        char* esperado = "1234";

        strcpy(s1, esperado);
        assert( strlen(s1), strlen(esperado) );
        // assert( miStrLen(s1), miStrLen(esperado) );
    }

    {
        char s1[TAM_STRING] = {};
        char* esperado = "1234abcd";

        strcpy(s1, "1234");
        strcat(s1, "abcd");
        assertStr(s1, esperado);

        strcpy(s1, "");
        denyStr(s1, esperado);

        // miStrCpy(s1, "1234");
        // miStrCat(s1, "abcd");
        // assertStr(s1, esperado);


        // assert( miStrLen(s1), miStrLen(esperado) );
    }

    {
        char s1[TAM_STRING] = "1234abcd";

        assert( strstr(s1, "1234"), s1);
        assert( strstr(s1, "ab"), s1 + 4);
        assert( strstr(s1, "no existe"), 0);

        assert( miStrStr(s1, "1234"), s1);
        assert( miStrStr(s1, "ab"), s1 + 4);
        assert( miStrStr(s1, "no existe"), 0);
    }
    return 0;
}
