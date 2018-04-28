#ifndef __NAVE_H__
#define __NAVE_H__

typedef struct _Nave {
    int vida;
    char* nombre;
} Nave;


Nave* nave_init(Nave* this, const char* nombre) ;
void nave_release(Nave* this) ;
void nave_imprimir(void* this) ;

#endif  // __NAVE_H__
