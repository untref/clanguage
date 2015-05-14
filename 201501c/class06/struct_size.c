#include <stdio.h>





typedef struct _x {
  char c1;
  char c2;
  long s1;
} MyStruct;



int main(int argc, char** argv) {

  MyStruct s;

  printf("sizeof(MyStruct): %d, %d\n", 
   sizeof(MyStruct), sizeof(long));

}
