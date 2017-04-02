#include <stdio.h>

int main(int argc, char** argv) {
    char untref[] = { 65, 'U', 'N', 252, 'T', 'R', 'E', 'F', 0x0 };
    char partido[] = "tres de febrero";

    printf("valor untref: %s\n", untref);
    printf("partido: %s\n", partido);

}
