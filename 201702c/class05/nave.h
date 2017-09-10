#ifndef __NAVE_H__
#define __NAVE_H__

typedef struct _nave {
    unsigned vidas;
    char* nombre;
} Nave;


void nave_init(Nave* this, char* nombre);
void nave_release(Nave* this);

#endif
