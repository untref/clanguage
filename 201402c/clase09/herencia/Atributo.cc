#include "Atributo.hh"

#include <cstring>
#include <cstdlib>
#include <iostream>

Atributo::Atributo(const char* nombre ) {
	// INICIALIZAR ATRIBUTOS 
	this->nombre = 0;

	// PRUEBEN COMENTAR LA LINEA ANTERIOR

	setNombre(nombre);
}

Atributo::~Atributo() {
	if ( nombre )
		free(nombre);

	nombre = 0;
}

const char* Atributo::getNombre() {
	return nombre;
}

void Atributo::setNombre(const char* nombre ) {
	if ( this->nombre )
		free(this->nombre);

	if (nombre != NULL) {
		this->nombre = (char*)malloc( (strlen(nombre) + 1) * sizeof(char) );
		strcpy(this->nombre, nombre);
	}
	else {
		this->nombre = NULL;
	}
}

void Atributo::toOutput() {
	std::cout << "Atributo (" << nombre << " )";
}