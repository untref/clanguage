#include <stdio.h>

unsigned toggleBit(unsigned field, unsigned bit ) {
  return field ^ (0x1 << bit);
}

unsigned isOnBit(unsigned field, unsigned bit ) {
  return field & (0x1 << bit);
}

unsigned setBit(unsigned field, unsigned bit ) {
  return field | (0x1 << bit);
}

unsigned unSetBit(unsigned field, unsigned bit ) {
  return field & ( 0xffffff ^ 0x1 << bit);
}

int main(int argc, char** argv) {
  // En SO Unix los enteros se almacenan en formato
  // little endian.
  //
  // En memoria el numero 'a' sera almacenado :
  //  Mem[0] = 0x0f
  //  Mem[1] = 0x0
  //
  // En memoria el numero 'a' sera almacenado :
  //  Mem[0] = 0x01
  //  Mem[1] = 0x0d
  //
  //
  unsigned short a = 0x000f; 
  unsigned short b = 0x0d01; 
      
  printf("Valor decimal numero 'a': %d - 0x%x\n", a, a);
  printf("Valor decimal numero 'b': %d - 0x%x\n", b, b);

  printf("\n");

  // Si el numero 'b' es tal q proviene de un SO que codifica los numero
  // en big endian esto significa que los bytes estan invertidos
  // Para intercambiarlos
  unsigned short intercambio = 0;

  printf("Fijense que los bits menos significativos se pierden!!\n" );
  printf("Me quedo con los digitos mas significativos de 'b': 0x%x\n", b >> 8 );
  printf("\n");
  printf("OJO que lo que resulta de hacer shift hacia izquierda es...\n");
  printf("Me quedo con los digitos menos significativos de 'b': 0x%x\n", b << 8);
  printf("\n");
  printf("Para quitar el 0xd (mas significatiovo) del numero 0x%x aplicamos una mascara...\n", b << 8);
  printf("Me quedo con los digitos menos significativos de 'b': 0x100\n"); // b << 8 && 0xffff);
  printf("\n");
  printf("Ahora combinamos los resultados 0x%x OR 0x%x AND 0x%x...\n", (b >> 8), (b << 8), 0xffff);
  printf("Nos queda: 0x%x\n", (b >> 8) | (b << 8) & 0xffff );

  unsigned short n = 25;

  printf("Complemento a 2 del nunmero '%d' -> %d\n", n, ~n + 1);

  unsigned field    = 0x0000ffa0;  // 0000 0000 0000 0000 1111 1111 1010 0000
  unsigned mascara  = 0x00001000;  // 0000 0000 0000 0000 0001 0000 0000 0000

  printf("Mascara utilizada: 0x%x 0x%x\n", mascara, 0x1 << 12);
  printf("Toggle bit 12. Inicial: 0x%x, Resultado: 0x%x\n", field, toggleBit(field, 12) );

  printf("Esta prendido el bit 12 ?: %d\n", isOnBit(field, 12) );
  printf("Esta prendido el bit 0  ?: %d\n", isOnBit(field, 0) );
        
  printf("Prendo el bit 0. Inicial: 0x%x, Resultado: 0x%x\n", field, setBit(field, 0) );
  printf("Apago el bit 13. Inicial: 0x%x, Resultado: 0x%x\n", field, unSetBit(field, 13) );
  return 0; 

}
