#include <stdio.h>

#if 0
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
  return ~ ( 0x1 << bit) & field;
}
#endif

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
  unsigned char mascaraBit4 = 0x10;              // 0001 0000

  // Utilizando esta máscara realizaremos todas las operaciones requeridas

  /**
  * Si quiero saber si un bit está prendido
  */
  printf("Consultando bits\n");
  printf("El bit 4 del número '0x%x' está encendido (mascaraBit4: 0x%x)? -> %u\n",
      empaquetadoDeBits02, mascaraBit4,
      empaquetadoDeBits02 & mascaraBit4 /* el and da 0 cuando el bit está apagado */ );

  printf("El bit 4 del número '0x%x' está encendido (mascaraBit4: 0x%x)? -> %u\n",
      empaquetadoDeBits01, mascaraBit4,
      empaquetadoDeBits01 & mascaraBit4 /* el and da 0 cuando el bit está apagado */ );

  /**
  * Si quiero encender un bit
  */
  printf("\n");
  printf("Encenciendo bits\n");
  printf("El bit 4 del número '0x%x' está apagado lo enciendo utilizando OR (mascaraBit4: 0x%x)\n",
    empaquetadoDeBits02, mascaraBit4 );
  printf("El resultado de encenderlos: '0x%x'.\n", empaquetadoDeBits02 | mascaraBit4);

  /**
  * Si quiero apagar un bit
  */
  printf("\n");
  printf("Apagando bits\n");
  printf("El bit 4 del número '0x%x' está encendido lo apago utilizando AND y NEG (mascaraBit4: 0x%x)\n",
    empaquetadoDeBits01, mascaraBit4 );
  // Aquí invierto la máscara para que solo quede pagado el bit 4.
  // Teniendo la mascaraBit4: 0001 0000
  // La inversión:        1110 11111
  //
  // Ahora con la mascaraBit4 invertida hago el and:
  // Valor empaquetado:   1011 1100
  // mascaraBit4 invertida:   1110 1111
  //
  // and:                 1010 1100
  //
  // Como resultado obtenemos el bit 4 apagado
  printf("El resultado de apagarlo: '0x%x'.\n", empaquetadoDeBits02 & ~mascaraBit4);

  /**
  * Si quiero invertir el valor de un bit
  */
  printf("\n");
  printf("Invirtiendo bits\n");
  printf("El bit 4 del número '0x%x' está encendido lo invierto utilizando XOR (mascaraBit4: 0x%x)\n",
    empaquetadoDeBits01, mascaraBit4 );
  printf("El resultado de apagarlo: '0x%x'.\n", empaquetadoDeBits01 ^ mascaraBit4);
  printf("Lo vuelvo a invertir obteniendo el valor inicial: '0x%x'.\n",
    (empaquetadoDeBits01 ^ mascaraBit4) ^ mascaraBit4 );


  /****
  * Ahora bien, que ocurre si deberíamos operar sobre el bit 5 en lugar del 4?
  * Deberíamos definir otra máscara que sería:
  **/
  unsigned char mascaraBit5 = 0x20;     // 0010 0000

  // Para el bit 7
  unsigned char mascaraBit7 = 0x80;     // 1000 0000


  /***
  * Obviamente esto no escala.  Para no tener que utilizar estas constantes surge la
  * utilización del operador shift (<<).   Esto nos permite agregar 0 a la izquierda
  * de un empaquetado.
  */
  unsigned char mascaraShiftBit1 = 0x1;
  unsigned char mascaraShiftBit2 = 0x1 << 1;    // Agrego un 0 a la izquierda del 2
  unsigned char mascaraShiftBit3 = 0x1 << 2;    // Agrego un 0 a la izquierda del 3

  // De esta manera podemos construir cualquier máscara

  unsigned i = 0;
  for (i = 0; i < 32; ++i)
  {
    printf("El bit %i encendido genera máscara -> 0x%2x\n", i, 0x1 << i);
  }

  return 0;

}
