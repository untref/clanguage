#include <iostream>

#include "Atributo.hh"
#include "Contenido.hh"

int main(int argc, char const *argv[])
{
	Contenido unContenido( "tamañon", 9);
	Contenido otroContenido( "comentario", 124);

	unContenido.toOutput();
	std::cout << std::endl; 
	otroContenido.toOutput();
	std::cout << std::endl; 

	return 0;
}