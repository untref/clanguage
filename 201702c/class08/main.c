#include <stdio.h>

int main(int argc, char** argv) {
    unsigned short c = 0xa ;
    unsigned short c1 = 0x55aa ;

    printf("    c: 0x%x       , %u\n", c, c);
    printf("Not c: 0x%x, %u\n", ~c, ~c);

    // Apagar bit 1 vía AND
    unsigned short d = c & 0xfffc ;
    printf("    d: 0x%x\n", d);

    // encender 7 via OR
    unsigned short e = c | 0x80 ;
    printf("    e: 0x%x\n", e);

    // desplazar en 1
    unsigned short f = c << 0x1 ;
    printf("    f: 0x%x\n", f);

    // apagar con shift 
    unsigned short g = c & ~(0x1 << 0x1);
    printf("    g: 0x%x\n", g);

    // enciendo 7 y 8 
    unsigned short h = c | (0x3 << 0x7);
    printf("    h: 0x%x\n", h);

    // apagar 14 y 12 
    unsigned short i = c1 & ~( (0x1u << 0xc) | (0x1u << 0xe) );
    printf("    i: 0x%x\n", i);

    // consultar bit 1 de c
    unsigned short maskForJ = (0x1 << 0x1);
    unsigned short j = ( c & maskForJ ) == maskForJ;
    printf("encendido el bit 1 de c: %u\n", j); 
    
    // shift derecha bit 1 de c
    unsigned short k = c >> 0x1;
    printf("    k: 0x%x\n", k);
    

    unsigned short littleEndian = 0x9c2e;

    printf("1: 0x%x\n", littleEndian >> 0x8);
    printf("2: 0x%x\n", littleEndian << 0x8);
    printf("3: 0x%x\n", (littleEndian >> 0x8 | littleEndian << 0x8));
    printf("4: 0x%x\n", ~(0xff << 16) );
    printf("5: 0x%x\n", 
            (littleEndian >> 0x8 | littleEndian << 0x8)
            & ~(0xff << 16)
            );

}


