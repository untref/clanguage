#include "circulo.h"

#include <string.h>

void circulo_inicializar( Circulo* this ) {
  this->radio = 1;
  memset(this->etiqueta, 0x0, TAM);
};

double circulo_perimetro( Circulo* this ) {
  return 2.0 * PI * this->radio;
}
