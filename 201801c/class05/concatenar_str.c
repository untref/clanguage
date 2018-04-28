#include <stdio.h>

void concatena_str(char* str1, char* str2) {
    while( *str1 ) {
        str1++;
    }

    while ( *str2 ) {
        *str1 = *str2;
        ++str1;
        ++str2;
    }

    ++str1;
    *str1 = 0x0;
}

int main(int argc, char** argv) {
    char str[1024] = "Hola ";
    char* hola = "Untref !";

    concatena_str(str, hola);


    printf("%d. str(%s)\n", __LINE__, str);

}



































