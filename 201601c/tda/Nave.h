#ifndef __NAVE_H__
#define __NAVE_H__

typedef struct _Nave {
  int vida;
  char* nombre;
} Nave;

void nave_init(Nave* this, char* nombre) ;
void nave_clonar(Nave* this, Nave* otra);
void nave_limpiar(Nave* this);
void nave_print(Nave* this) ;

#endif // __NAVE_H__
