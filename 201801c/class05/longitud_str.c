#include <stdio.h>


unsigned strLen(char* str) {
    char* strBis = str;

    while (*strBis++);

    return strBis - str - 1;
}

unsigned strLen2(char* str) {
    unsigned tam = 0x0;

    while ( *str != 0x0 ) {
        ++tam;
        ++str;
    }

    return tam;
}

int main(int argc, char** argv) {
    char* str = "UNTREF";
    printf("%d. str(%s), strLen(): %d\n", __LINE__, str, strLen2(str));
    printf("%d. str(%s), strLen(): %d\n", __LINE__, "", strLen2(""));
    printf("%d. str(%s), strLen(): %d\n", __LINE__, str, strLen(str));
    printf("%d. str(%s), strLen(): %d\n", __LINE__, "", strLen(""));
}



































