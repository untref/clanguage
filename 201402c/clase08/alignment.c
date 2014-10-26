#include <stdio.h>

typedef struct _mystruct { 
    char c;
    double a; 
} MyStruct; 


int main(int argc, char** argv) {
  MyStruct s[2];

  printf("Size of MyStruct:  %d\n", sizeof(MyStruct) );


  printf("Memory address s[0].a: %d\n", &(s[0].a) );
  printf("Memory address s[0].c: %d\n", &(s[0].c) );

  printf("Memory address s[1].a: %d\n", &(s[1].a) );
  printf("Memory address s[1].c: %d\n", &(s[1].c) );
}
