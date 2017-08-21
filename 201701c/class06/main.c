#include <stdio.h>

int esta_prendido_mascara( unsigned paquete, unsigned mascara) {
    return (paquete & mascara) == mascara;
}

int esta_prendido( unsigned paquete, unsigned bit) {
    unsigned mascara = 0x1u << bit;
    return esta_prendido_mascara(paquete, mascara);
}

int esta_prendido_varios( unsigned paquete, unsigned bit0, unsigned bit1) {
    unsigned mascara = (0x1u << bit0) | (0x1u << bit1);
    return esta_prendido_mascara(paquete, mascara);
}

unsigned encender(unsigned paquete, unsigned bit ) {
    unsigned mascara = (0x1u << bit);
    return mascara | paquete;
}

unsigned apagar(unsigned paquete, unsigned bit ) {
    unsigned mascara = (0x1u << bit);
    return ~mascara & paquete;
}

unsigned copy_to_from(unsigned dst, unsigned src, unsigned *bitsToCopy, unsigned bitsCount) {
    unsigned result = dst;
    unsigned* whichBit = bitsToCopy;

    while ( bitsCount-- ) {
        if ( esta_prendido( src, *whichBit) ) {
            result = encender(result, *whichBit);
        } else {
            result = apagar(result, *whichBit);
        }
        whichBit++;
    }
    return result;
}

int main(int argc, char** argv) {
    {
        unsigned bitsToCopy[] = { 3, 2, 0 };
        // 1000 -> 8 
        // 1100 -> c  
        // 0001 -> 1  
        // 1101 -> d
        unsigned source = 0x1u;
        unsigned result = copy_to_from( source, 0xcu, bitsToCopy, sizeof(bitsToCopy) / sizeof(unsigned) );
        printf("Resultado 0x%x\n", result);
    }

    {
        unsigned bitsToCopy[] = { 3, 2, 0 };
        // 1000 -> 8 
        // 1100 -> c  
        // 0001 -> 1  
        // 1101 -> d
        unsigned source = 0x1u;
        unsigned result = copy_inverted_to_from( source, 0xcu, bitsToCopy, sizeof(bitsToCopy) / sizeof(unsigned) );
        printf("Resultado 0x%x\n", result);
    }

    return 0;

    {
        unsigned paquete = 0x10u;
        printf("Esta prendido el 1 de 0x%x - %u\n", paquete, 
            esta_prendido(paquete, 0x1u));
    }

    {
        unsigned paquete = 0x10u;
        printf("Esta prendido el 1 de 0x%x - %u\n", paquete, 
                esta_prendido( paquete, 0x4u));
    }

    {
        unsigned paquete = 0x57f8;
        printf("Esta prendido el 1 de 0x%x - %u\n", paquete, 
                esta_prendido_varios( paquete, 0x30u, 0x15u));
        printf("Esta prendido el 1 de 0x%x - %u\n", paquete, 
                esta_prendido( paquete, 0x3u));
    }

    {
        unsigned paquete = 0x57f8;
        unsigned nuevoPaquete = encender(paquete, 0xdu);
        printf("Paquete 0x%x - nuevo 0x%x\n", paquete, nuevoPaquete);
    }

    {
        unsigned paquete = 0x57f8;
        unsigned nuevoPaquete = apagar(paquete, 0xau);
        printf("Paquete 0x%x - nuevo 0x%x\n", paquete, nuevoPaquete);
    }

    {
        unsigned i;
        printf("Operación shift de 0 - 31\n");
        for( i = 0; i < 32; i++) {
            printf("shift %d - %u - %x\n", i, 0x1u << i, 0x1u << i);
        }
    }

}

