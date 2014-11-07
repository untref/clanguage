#include <typeinfo>
#include <cstring>
#include <cstdlib>
#include <iostream>

// Declaración de una clase
class Atributo
{
public:
	Atributo(const char* nombre);
	~Atributo();

	void setNombre(const char* nombre);

	const char* getNombre();

private:
	char* nombre; 
};

// DEFINICIÓN de una clase
Atributo::Atributo(const char* nombre) : nombre(0) {
	setNombre( nombre );
}

Atributo::~Atributo() {
	// Este método se invoca automáticamente cuando la instancia se destruye
	if ( nombre )
		free( nombre);

	nombre = 0;
}

void Atributo::setNombre(const char* nombre) {
	if ( this->nombre)
	{
		free( this->nombre);
	}

	this->nombre = (char*)malloc( (strlen(nombre) + 1) * sizeof(char) );

	strcpy( this->nombre, nombre);
};

const char* Atributo::getNombre() {
	return nombre; 
}


int main(int argc, char const *argv[])
{
	// Declaro una instancia de Atributo
	Atributo variable( "Un atributo" /*es mandatorio*/);

	Atributo& referencia = variable; 		// NOOOO : &variable

	std::cout << "Nobre atributo: " << variable.getNombre() << std::endl;
	std::cout << "Nobre referencia: " << referencia.getNombre() << std::endl;

	variable.setNombre( "otro nombre");

	std::cout << "Nobre atributo: " << variable.getNombre() << std::endl;
	std::cout << "Nobre referencia: " << referencia.getNombre() << std::endl;


	return 0;
}