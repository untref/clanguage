#include "Contenido.hh"

#include <iostream>

Contenido::Contenido(const char* nombre, unsigned valor ) : Atributo(nombre) {
	this->valor = valor;
}

Contenido::~Contenido() {

}

unsigned Contenido::getValor() {
	return this->valor;
}

void Contenido::toOutput() {
	Atributo::toOutput() ;

	std::cout << " valor: " << this->valor << std::endl;
}