#ifndef __GARBAGE_COLLECTOR_HH__
#define __GARBAGE_COLLECTOR_HH__ 

class Puntero {
public:
  void setValor( unsigned v );
  unsigned getValor() ;

public:
  Puntero();
  Puntero(void * ptr);
  Puntero(const Puntero& o );
  Puntero& operator=(const Puntero& );
  ~Puntero();

private:
  unsigned incRef();
  unsigned decRef();
  void     liberar();

private:
 void*      ptr; 
 unsigned*  referencias;
};

#endif
