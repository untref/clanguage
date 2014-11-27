#include <typeinfo>
#include <cstring>
#include <cstdlib>
#include <iostream>

// Declaración de una clase
class Atributo
{
public:
	Atributo(const char* nombre) {
		std::cout << "Constructor: " << nombre << std::endl;
		this->nombre = 0;
		setNombre( nombre);
	}

	Atributo(const Atributo& other) {
		std::cout << "Constructor de copia: " << other.nombre << std::endl;		
		this->nombre = 0;
		setNombre( other.nombre);
	}

  Atributo& operator=(const Atributo&  o) {
    if ( &o == this ) {
      return *this;

    }
		std::cout << "Operador igual " << o.nombre << std::endl;		
    
    setNombre(o.nombre);


    return *this;
  }

	~Atributo() {
		std::cout << "Destructor: " << nombre << std::endl;
		if (nombre)
		{
			free( nombre);
		}

		nombre = 0;
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

void functionConReferencia( Atributo& a ) {
	std::cout << "Atributo: " << a.getNombre() << std::endl;
}

void functionSinReferencia( Atributo a ) {
	std::cout << "Atributo: " << a.getNombre() << std::endl;
}

int main(int argc, char const *argv[])
{
	Atributo contenido("contenido");
	Atributo unidades("bytes");

  unidades = unidades;
  unidades = contenido = unidades;


	return 0;
}
