#include <stdio.h>

int main(int argc, char** argv) {
    char miCaracter;
    unsigned char* pc = 0x1;
    unsigned short* ps = 0x0;
    printf("linea: %d - valor ps: %p\n", __LINE__, ps);

    ps = 0xffffffff;
    printf("linea: %d - valor ps: %p\n", __LINE__, ps);

    printf("linea: %d - valor ps: %p\n", __LINE__, pc);

    printf("linea: %d - valor ps: %c\n", __LINE__, miCaracter);

    ps = 0xfffffff;

    printf("valor ps: %p. volumen: %d\n", ps, sizeof(unsigned short*));
}
