#ifndef __PARRAFO_H__
#define __PARRAFO_H__

typedef struct _Parrafo {
    char**      palabras;
    unsigned    cantidad;
} Parrafo;

Parrafo* parrafo_inicializar_vacio(Parrafo* this);
Parrafo* parrafo_inicializar_con(Parrafo* this, char** parrafo, unsigned palabras);
Parrafo* parrafo_mostrar(Parrafo* this);
Parrafo* parrafo_reemplazar_todo(Parrafo* this, char* palabra, char* reemplazo);

#endif
