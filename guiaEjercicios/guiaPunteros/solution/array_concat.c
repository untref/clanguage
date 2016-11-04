#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void concat_array(
        void* array1, unsigned size_of_array_1, 
        void* array2, unsigned size_of_array_2, 
        void* dest
);

void print_integers(int* integers, unsigned size_of_integers);
void print_doubles(double* doubles, unsigned size_of_doubles);

int main(int argc, char** argv) {
    int integers_0[] = { 1, 2, 3 };
    int integers_1[] = { 4, 5, 6 };

    double doubles_0[] = { 7.1, 7.2, 7.3 };
    double doubles_1[] = { 7.4, 7.5, 7.6 };
    
    unsigned size_of_all_integers =  sizeof(integers_0) + sizeof(integers_1);
    int* all_integers = (int*)malloc( size_of_all_integers );

    concat_array(integers_0, sizeof(integers_0), integers_1, sizeof(integers_1), all_integers);

    print_integers( all_integers, size_of_all_integers);

    unsigned size_of_all_doubles =  sizeof(doubles_0) + sizeof(doubles_1);
    double* all_doubles = (double*)malloc( size_of_all_doubles );

    concat_array(doubles_0, sizeof(doubles_0), doubles_1, sizeof(doubles_1), all_doubles);

    print_doubles( all_doubles, size_of_all_doubles);

    free(all_doubles);
    free(all_integers);
};


void concat_array( void* array1, unsigned size_of_array_1, void* array2, unsigned size_of_array_2, void* dest) {
    memcpy(dest, array1, size_of_array_1);
    memcpy(dest + size_of_array_1, array2, size_of_array_2);
    return;
}

void print_doubles(double* doubles, unsigned size_of_doubles) {
    int i;

    for( i = 0; i < size_of_doubles / sizeof(doubles); ++i) {
        printf("[%2d]: %2lf\n", i, doubles[i]); 
    }
}

void print_integers(int* integers, unsigned size_of_integers) {
    int i;

    for( i = 0; i < size_of_integers / sizeof(int); ++i) {
        printf("[%2d]: %2d\n", i, integers[i]); 
    }
}
