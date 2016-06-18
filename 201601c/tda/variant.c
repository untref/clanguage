#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _Variant {
  void* d;
  unsigned t;
} Variant;

void variant_inicializar_con_flotante(Variant* this, float v) {
  this->t = sizeof(v);

  if ( this-> d ) {
    free( this-> d );
  }

  this->d = malloc( this->t );
  memcpy( this->d, &v, this->t );
}

void variant_inicializar_con_entero(Variant* this, int v) {
  this->t = sizeof(v);

  if ( this-> d ) {
    free( this-> d );
  }

  this->d = malloc( this->t );
  memcpy( this->d, &v, this->t );
}

void variant_valor_flotante(Variant* this, float* v) {
  memcpy( v, this->d, this->t );
};

void variant_valor_entero(Variant* this, int* v) {
  memcpy( v, this->d, this->t );
};

void variant_init(Variant* this) {
  bzero(this, sizeof(Variant) );
}

void variant_limpiar(Variant* this) {
  if ( this-> d ) {
    free( this-> d );
  }

  this->d = 0;
}

int main(int argc, char* argv[] ) {
  Variant v;
  float f;
  int d;
  char str[1024];

  variant_inicializar_con_flotante(&v, 12.2);
  variant_valor_flotante(&v, &f);
  printf("Valor flotante: %f\n", f);

  variant_inicializar_con_entero(&v, 12);
  variant_valor_entero(&v, &d);
  printf("Valor entero: %d\n", d);

  variant_limpiar(&v);
#if 0
  variant_inicializar_con_str(&v, "hey!");
  variant_valor_str(&v, s);
  printf("Valor str: %s\n", s);
#endif

}
