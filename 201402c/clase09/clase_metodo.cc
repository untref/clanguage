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
	/* este código no se agrega a una clase lo hago para que se entiena el codigo */
	std::cout << "Construyendo: " << typeid(*this).name() 
		<< "con nombre: " << nombre << std::endl; 
	/* fin comentario */

	setNombre( nombre );
}

Atributo::~Atributo() {
	/* este código no se agrega a una clase lo hago para que se entiena el codigo */
	std::cout << "Destruyendo: " << typeid(*this).name() 
		<< "con nombre: " << this->nombre 
		<< std::endl; 

	/* fin comentario */

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

	// Instancia almacenada en stacks
	Atributo* pVariable = new Atributo("Otro Atributo" /*es mandatorio*/);


	// No olvidar liberar memoria
	delete pVariable;

	// Desabilitar el delete y ver que pasa 

	return 0;
}
