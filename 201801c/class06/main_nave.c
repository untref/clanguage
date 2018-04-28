#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "Nave.h"

int main(int argc, char** argv) {
    { 
    Nave gamma;

    nave_imprimir( nave_init(&gamma, "Gamma") );

    nave_release(&gamma);
    }

#if 0
    { // NO HACERLO
    Nave alpha;

    printf("nombre: %s, vida: %d\n", alpha.nombre, alpha.vida);
    }

    { 
    Nave beta;
    Nave* pBeta = &beta;

    printf("nombre: %s, vida: %d\n", (*pBeta).nombre, (*pBeta).vida);
    printf("nombre: %s, vida: %d\n", pBeta->nombre, pBeta->vida);
    }
#endif

}
