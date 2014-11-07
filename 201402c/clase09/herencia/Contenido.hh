#ifndef __CONTENIDO_HH__
#define __CONTENIDO_HH__ 

#include "Atributo.hh"

class Contenido : public Atributo
{
public:
	Contenido(const char* nombre, unsigned valor);
	virtual ~Contenido();

	unsigned getValor();

	virtual void toOutput();

private:
	unsigned valor; 
};

#endif
