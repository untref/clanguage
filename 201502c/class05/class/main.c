#include <stdio.h>
#include <stdlib.h>

#include "../../assertion.h"

#include "nave.h"
#include "lista.h"

int main()
{

    Nodo n;
    Nave nave;

    int i = 25;
    float f = 2.3;

    lista_init(&n);
    // lista_push(&n, &i, sizeof(int));
    // lista_push(&n, &f, sizeof(float));
    lista_push(&n, &nave, sizeof(Nave));

    lista_liberar(&n);

    #if 0
    Nave nave;

    nave_init(&nave, "alpha");
    nave_print(&nave);

    nave_daniar(&nave, 4);
    nave_print(&nave);
#endif
    return 0;
}
