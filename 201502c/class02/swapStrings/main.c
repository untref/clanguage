#include <stdio.h>
#include <stdlib.h>

#include "../../assertion.h"

void swapStr(char** a, char**b )  {
    char* tmp = *a;
    *a = *b;
    *b = tmp;
}

int main()
{
    char str01[] = "str01";
    char str02[] = "str02";

    assertStr(str01, "str01");
    assertStr(str02, "str02");

    swapStr(&str01, &str02);

    assertStr(str02, "str01");
    assertStr(str01, "str02");

    return 0;
}
