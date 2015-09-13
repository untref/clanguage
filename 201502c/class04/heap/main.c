#include <stdio.h>
#include <stdlib.h>

int main()
{
    // EVITAR ALOCAR MEMORIA DENTRO DE ESTRUCTURAS DE CONTROL
    // FOR, WHILE, IF
    {
#if 0
        void* p;

        while ( 1 ) {
             p = malloc( sizeof(int) * 100  );
             for(j = 0; j < 10000; j++);
        }
#endif // 0

    }

    {
        // Le pido memoria al sistema operativo. Esta memoria pertence al HEAP
        void* p = malloc(sizeof(int) * 2);

        // Por el caracter generico de la memoria yo la puedo utilizar como me
        // parezca.  En este caso la utilizo como enteros
        int* pi = p;
        *pi  = 9;
        *(pi + 1) = 8;
        pi += 122;

        printf("%d, %d\n", pi[0], pi[1] );


        // Si quiero podue utilizar la mem como si fueran flotantes
        float* pf = p;
        pf[0] = 7.2;
        pf[1] = 1.3;

        printf("%f, %f\n", pf[0], pf[1] );

        // NO OLVIDAR DESALOCAR MEMORIA
        // NO OLVIDAR DESALOCAR MEMORIA
        // NO OLVIDAR DESALOCAR MEMORIA
        // NO OLVIDAR DESALOCAR MEMORIA
        // NO OLVIDAR DESALOCAR MEMORIA
        // NO OLVIDAR DESALOCAR MEMORIA
        // NO OLVIDAR DESALOCAR MEMORIA
        //
        // EL QUE ALOCA MEM ES RESPONSABLE DE LIBERARLA!!!!!
        // EL QUE ALOCA MEM ES RESPONSABLE DE LIBERARLA!!!!!
        // EL QUE ALOCA MEM ES RESPONSABLE DE LIBERARLA!!!!!
        // EL QUE ALOCA MEM ES RESPONSABLE DE LIBERARLA!!!!!
        // EL QUE ALOCA MEM ES RESPONSABLE DE LIBERARLA!!!!!
        free(p);

    }


    {
        // NUNCA PIERDAN REFERENCIA AL PUNTERO QUE DEVUELVE MALLOC PORQUE
        // ESTO GENERA UN MEMORY-LEAK
        void* p = malloc(sizeof(long double) * 50);

        // p = 0;  // Pierdo referencia y no voy a poder liberar la memoria

        free(p);

    }



    return 0;
}
