#ifndef __ATRIBUTO_HH__
#define __ATRIBUTO_HH__

class Atributo
{
public:
	Atributo(const char* nombre);
	virtual ~Atributo();

	const char* getNombre();
	void setNombre(const char* nombre);

	virtual void toOutput();

private:
	char* nombre;
};

#endif