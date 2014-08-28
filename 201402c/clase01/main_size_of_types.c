#include <stdio.h>

int main(int argc, char** argv) {
  char unit[] = "byte";
  char units[] = "bytes";
  char c = 'a';

  printf("Size type is bounded to the SO.  "
      "I got the results listed below by running this"
      "program on: "
      "Linux crunchbang 3.2.0-4-686-pae #1 SMP Debian 3.2.46-1+deb7u1 i686 GNU/Linux\n");
  printf("sizeof char:            %d %s\n",                sizeof(signed char), unit );               // 1 byte
  printf("sizeof char:            %d %s\n",                sizeof('a'), unit );                       // 4 byte
  printf("sizeof short:           %d %s\n",                sizeof(signed short), units );             // 2 bytes
  printf("sizeof int:             %d %s\n",                sizeof(signed int), units );               // 4 bytes
  printf("sizeof long:            %d %s\n",                sizeof(signed long), units );              // 4 bytes
  printf("sizeof long long:       %d %s\n",                sizeof(signed long long), units );         // 8 bytes
  printf("sizeof float:           %d %s\n",                sizeof(float), units );                    // 4 bytes
  printf("sizeof double:          %d %s\n",                sizeof(double), units );                   // 8 bytes
  printf("sizeof long double:     %d %s\n",                sizeof(long double), units );              // 12 bytes
  printf("\n");                                                                                                   
  printf("Types with sign\n");                                                                                    
  printf("sizeof char:            %d %s\n",                sizeof(unsigned char), unit );             // 1 byte
  printf("sizeof short:           %d %s\n",                sizeof(unsigned short), units );           // 2 bytes
  printf("sizeof int:             %d %s\n",                sizeof(unsigned int), units );             // 4 bytes
  printf("sizeof long:            %d %s\n",                sizeof(unsigned long), units );            // 4 bytes
  printf("sizeof long long:       %d %s\n",                sizeof(unsigned long long), units );       // 8 bytes
  printf("sizeof float:           %d %s\n",                sizeof(float), units );                    // 4 bytes
  printf("sizeof double:          %d %s\n",                sizeof(double), units );                   // 8 bytes
  printf("sizeof long double:     %d %s\n",                sizeof(long double), units );              // 12 bytes
  printf("\n");                                                                                                   

  int* pi;
  long long* pll;
  long double* pld;

  printf("Size of pointers (all the same)\n");                                                        
  printf("sizeof p int:           %d %s\n",                sizeof(pi), units );                       // 4 bytes
  printf("sizeof p long long:     %d %s\n",                sizeof(pll), units );                      // 4 bytes
  printf("sizeof p long double:   %d %s\n",                sizeof(pld), units );                      // 4 bytes

  printf("%d\n" ,sizeof(char*));
  printf("%d\n" ,sizeof(void*));
  return 0;
}



