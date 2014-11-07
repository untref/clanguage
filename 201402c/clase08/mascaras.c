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

/****
 * Ejemplo de utilización de máscaras:
 *  - Como saber si un bit de un empaquetado está encendido?
 *  - Como prender un bit de un empaquetado?
 *  - Como apagar un bit de un empaquetado?
 *  - Como invertir un bit de un empaquetado?
 **/
int main(int argc, char** argv) {

  unsigned char empaquetadoDeBits01 = 0xbc;    // 1011 1100 
  unsigned char empaquetadoDeBits02 = 0xac;    // 1010 1100 

  // Primera aproximación (máscara fija): 
  // Suponiendo que necesitamos operar sobre el bit 4 del número empaquetado 
  // (elegí bit en cuestión arbitrariamente para el ejemplo) con el fin realizar 
  // todas las operaciones listadas antes del main.
  //
  // ¿Cómo haríamos?
  //
  // Ya que el lenguaje no nos provee una manera de acceder al bit 4 del empaquetado
  // vamos a necesitar operar este bit atrevés de una máscara. 
  //
  // La máscara será otro empaquetado (char) con solo el bit 4 encendido!
  // ¿Porqué el bit 4 encendido? Porque es sobre el cuál queremos operar!
  //
  unsigned char mascara = 0x10;              // 0001 0000

  // Utilizando esta máscara realizaremos todas las operaciones requeridas

  /**
  * Si quiero saber si un bit está prendido
  */
  printf("Consultando bits\n");
  printf("El bit 4 del número '0x%x' está encendido (mascara: 0x%x)? -> %u\n", 
      empaquetadoDeBits02, mascara,
      empaquetadoDeBits02 & mascara /* el and da 0 cuando el bit está apagado */ );

  printf("El bit 4 del número '0x%x' está encendido (mascara: 0x%x)? -> %u\n", 
      empaquetadoDeBits01, mascara,
      empaquetadoDeBits01 & mascara /* el and da 0 cuando el bit está apagado */ );

  /**
  * Si quiero encender un bit 
  */
  printf("\n");
  printf("Encenciendo bits\n");
  printf("El bit 4 del número '0x%x' está apagado lo enciendo utilizando OR (mascara: 0x%x)\n",
    empaquetadoDeBits02, mascara );
  printf("El resultado de encenderlos: '0x%x'.\n", empaquetadoDeBits02 | mascara);
 
  /**
  * Si quiero apagar un bit 
  */
  printf("\n");
  printf("Apagando bits\n");
  printf("El bit 4 del número '0x%x' está encendido lo apago utilizando AND y NEG (mascara: 0x%x)\n",
    empaquetadoDeBits01, mascara );
  // Aquí invierto la máscara para que solo quede pagado el bit 4.
  // Teniendo la mascara: 0001 0000
  // La inversión:        1110 11111
  //
  // Ahora con la mascara invertida hago el and:
  // Valor empaquetado:   1011 1100
  // mascara invertida:   1110 1111
  //
  // and:                 1010 1100
  //
  // Como resultado obtenemos el bit 4 apagado
  printf("El resultado de apagarlo: '0x%x'.\n", empaquetadoDeBits02 & ~mascara);
 
  /**
  * Si quiero invertir el valor de un bit 
  */
  printf("\n");
  printf("Invirtiendo bits\n");
  printf("El bit 4 del número '0x%x' está encendido lo invierto utilizando XOR (mascara: 0x%x)\n",
    empaquetadoDeBits01, mascara );
  printf("El resultado de apagarlo: '0x%x'.\n", empaquetadoDeBits01 ^ mascara);
  printf("Lo vuelvo a invertir obteniendo el valor inicial: '0x%x'.\n", 
    (empaquetadoDeBits01 ^ mascara) ^ mascara );

 
  return 0; 

}
