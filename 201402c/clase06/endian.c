#include <stdio.h>

int main(int argc, char** argv) {
  unsigned short a = 0x000f; 
  unsigned short b = 0x0f00; 
      
  printf("%d\n", a);
  printf("%d\n", b);

  unsigned short n = 25;

  printf("%d\n", ~n + 1);
        
  return 0; 

}
