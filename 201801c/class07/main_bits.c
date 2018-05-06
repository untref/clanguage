#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char** argv) {
    printf("%d\n", argc);

    for(unsigned i = 0; i < argc; ++i) {
        printf("%d - %s\n", i, argv[i]);
    }
}

