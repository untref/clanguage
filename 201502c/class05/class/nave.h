#ifndef NAVE_H_INCLUDED
#define NAVE_H_INCLUDED

#define NAVE_NOMBRE_LARGO 1024

typedef struct _Nave {
    int vida;
    char nombre[NAVE_NOMBRE_LARGO];
} Nave;

/**
*/
void nave_init(Nave* this, const char* nombre);
void nave_daniar(Nave* this, int danio);
void nave_print(Nave* this);

#endif // NAVE_H_INCLUDED
