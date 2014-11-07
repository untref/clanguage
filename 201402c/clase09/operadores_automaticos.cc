#include <typeinfo>
#include <cstring>
#include <cstdlib>
#include <iostream>

// Declaración de una clase
class Atributo
{
public:
	Atributo(const char* nombre) {
		std::cout << "Constructor" << std::endl;
		this->nombre = 0;
		setNombre( nombre);
	}

	~Atributo() {
		std::cout << "Destructor" << std::endl;
		if (nombre)
		{
			free( nombre);
		}

		nombre = 0;
	};

	Atributo& operator=(const Atributo& otro ) {
		std::cout << "Operador de asignación" << std::endl;		
		if ( this == &otro )
			return *this;

		setNombre( otro.nombre );
	};

	const char* getNombre() {
		return nombre;
	}

private:
	void setNombre(const char* nombre) {
		if ( this->nombre)
		{
			free( this->nombre);
		}

		this->nombre = (char*)malloc( (strlen(nombre) + 1) * sizeof(char) );

		strcpy( this->nombre, nombre);
	};


private:
	char* nombre; 
};

int main(int argc, char const *argv[])
{
	Atributo contenido("contenido");
	Atributo unidades("bytes");

	contenido = unidades;



	return 0;
}