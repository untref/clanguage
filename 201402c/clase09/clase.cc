// Declaración de una clase
class Atributo
{
public:
	Atributo( /* No require argumentos*/);
	~Atributo();

};

// DEFINICIÓN de una clase
Atributo::Atributo() {

}

Atributo::~Atributo() {

}

int main(int argc, char const *argv[])
{
	// Declaro una instancia de Atributo
	Atributo variable;

	// Instancia almacenada en stacks
	Atributo* pVariable = new Atributo();


	// No olvidar liberar memoria
	delete pVariable;

	return 0;
}