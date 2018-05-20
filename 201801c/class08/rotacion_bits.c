#include <stdio.h>
#include <stdlib.h>

char fMascara(unsigned shift) {
    char result = 0x0;

    for(unsigned i = 0; i < shift; ++i) {
        result = result | 0x1 << i;
    }

    return result;
}

unsigned char shift_n(unsigned c, unsigned shift) {
    unsigned char d = c >> shift;
    unsigned char mascara = fMascara(shift);
    unsigned char loQueRota = c & mascara;
    unsigned char loQueRotaRotado = loQueRota << (sizeof(char) * 8 - shift);
#if 0
    printf("d: 0x%x\n", d);
    printf("mascara: 0x%x\n", mascara);
    printf("loQueRota: 0x%x\n", loQueRota);
    printf("loQueRotaRotado: 0x%x\n", loQueRotaRotado);
#endif

    unsigned resultado = d | loQueRotaRotado;

    return d | loQueRotaRotado;
}


int main(int argc, char** argv) {
    unsigned char c = 0x19;

    
    printf("argv[0]: %s\n", argv[0]);
    printf("argv[1]: %s\n", argv[1]);
    printf("argv[2]: %s\n", argv[2]);

    printf("resultado: 0x%x\n", shift_n(c, atoi(argv[2])) );


}
