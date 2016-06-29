#ifndef __CADENA_H__
#define __CADENA_H__

typedef struct _Cadena {
    char* dato;
    unsigned tam;
} Cadena;

Cadena* cadena_inicializar(Cadena* this, char* valor_inicial, unsigned tam);
Cadena* cadena_modificar(Cadena* this, char* valor_inicial);
Cadena* cadena_concatenar(Cadena* this, char* valor_inicial);
Cadena* cadena_print(Cadena* this);
Cadena* cadena_limpiar(Cadena* this);


#endif
