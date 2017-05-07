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

int main(int argc, char** argv) {
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

