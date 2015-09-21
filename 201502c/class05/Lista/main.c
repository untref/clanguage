#include <stdio.h>
#include <stdlib.h>

#include "lista.h"

int main()
{
    Node lista;
    const Node* current;
    int i = 29;
    float f = 2.3;

    lista_init(&lista);

    lista_push(&lista, &i, sizeof(int));
    lista_push(&lista, &f, sizeof(float));

    current = lista_at(&lista, 0);
    printf("%d\n", *(int*)current->data);
    current = lista_at(&lista, 1);
    printf("%f\n", *(float*)current->data);
    return 0;
}
