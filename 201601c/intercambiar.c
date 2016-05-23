#include <stdio.h>

void intercambiar(int a, int b) {
    int t = a;
    a = b;
    b = t;
};

void intercambiar2(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
};

int main(int argc, char** argv){
    int a = 10;
    int b = 1;

    // Intercambia los valores de a y b?
    intercambiar(a, b);

    printf("a: %d, b: %d\n", a, b);

    intercambiar2(&a, &b);
    printf("a: %d, b: %d\n", a, b);

    return 0;
}

