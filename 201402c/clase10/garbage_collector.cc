#include "garbage_collector.hh"

#include <iostream>
#include <cstring>


void Puntero::setValor( unsigned v ) {
    memcpy( this->ptr, &v, sizeof(v) );

  }

unsigned Puntero::getValor() {
    return *((unsigned*)this->ptr);
}

Puntero::Puntero() : ptr(0), referencias(0){ 
  incRef();
}

Puntero::Puntero(void * ptr) : ptr(ptr), referencias(0){
  incRef();
 }

Puntero::Puntero(const Puntero& o ) {
  this->ptr = o.ptr;
  this->referencias = o.referencias;

  incRef();

  std::cout << "Constructor de copia: " << (*this->referencias) << std::endl;
}

Puntero::~Puntero() {
  if ( decRef() == 0 && this->ptr ) {
    liberar();
  }
}

Puntero& Puntero::operator=(const Puntero& o ) {
  if ( this == &o )
    return *this;

  // El puntero this no tiene otra referencia que lo esté 
  // apuntando
  if ( decRef() == 0 ) {
    liberar();
  }

  this->ptr = o.ptr;
  this->referencias = o.referencias;
  incRef();

  return *this;

}

void Puntero::liberar() {
  if ( this->ptr == 0)
    return;

  std::cout << "free " << std::endl;
  free( this->ptr );
  this->ptr = 0;
}

unsigned Puntero::incRef() {
  if ( this->referencias == 0 ) {
    std::cout << "creo entero" << std::endl;
    this->referencias = (unsigned*)malloc(sizeof(unsigned));
    (*this->referencias) = 0;
  }

  return ++(*this->referencias);
}

unsigned Puntero::decRef() {
  unsigned result = --(*this->referencias);

  // El puntero this no tiene otra referencia que lo esté 
  // apuntando
  if ( result == 0) {
    std::cout << "Destruyo entero" << std::endl;
    free(this->referencias);
    this->referencias = 0;
  }

  return result;
}