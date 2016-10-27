#ifndef __CIRCULO_H__
#define __CIRCULO_H__

#define TAM 1024
#define PI  3.141519

typedef struct _Circulo {
  double radio;
  char   etiqueta[TAM];
} Circulo;

void circulo_inicializar( Circulo* this );
double circulo_perimetro( Circulo* this );

#endif 
