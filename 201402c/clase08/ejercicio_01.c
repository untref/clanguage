#include <stdio.h>
#include <string.h>

int main(int argc, char** argv) {
  // Convertir los siguientes numeros en formato
  // little endian -> big endian
  unsigned long long longLongInt = 0x0102030405060708;
  unsigned long longInt = 0x01020304;


  printf("Long value: 0x%lx \n", longInt ); 
  printf("Long Long value: 0x%llx \n", longLongInt ); 


}
