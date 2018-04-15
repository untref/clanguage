#include <stdio.h>
#include <string.h>

int mauricio(char* a, char* b) {
    int j = 16;
    return j;
}

char* concatenar(char* a, char* b) {
    char concat[11];

    // no devolver punteros a variables locales

    return concat;


}

int main(int argc, char** argv) {
    {
        char str[] = { 'a', 0x0, 'x', 0x0 };
        char str2[] = "ABC"; // { 'a', 0x0 }
        short enteros[] = { 1, 2, 3 };

        char* concatenacion = concatenar(str, str2);

        int k = mauricio(str, str2);

        printf("linea: %d - %p - str: %s\n", __LINE__, str, str);
        printf("linea: %d - %p - str: %s\n", __LINE__, str2, str2);
    }

}
