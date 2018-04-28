#include <stdio.h>

int main(int argc, char** argv) {
    char* str = "UNTREF";
    char* strBis = str;

    printf("%d. %s\n", __LINE__, "POST incremento");
    printf("%d. %p\n", __LINE__, strBis);
    printf("%d. %c\n", __LINE__, *strBis++);
    printf("%d. %p - %c\n", __LINE__, strBis, *strBis);

    strBis = str;
    printf("%d. %s\n", __LINE__, "PRE incremento");
    printf("%d. %p\n", __LINE__, strBis);
    printf("%d. %c\n", __LINE__, *++strBis);
    printf("%d. %p - %c\n", __LINE__, strBis, *strBis);
}
