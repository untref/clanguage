#include <stdio.h>

void toUpperCase(char* arg) {
    while (*arg) {
        if ( *arg >= 'a' && *arg <= 'z' ) {
            *arg -= 32;
        }
        arg++;
    }
}


int main(int argc, char** argv) {
    char arg[] = ;

    toUpperCase(arg);

    printf("%s\n", arg);
};

