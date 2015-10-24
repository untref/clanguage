#ifndef CIRCULO_HH_INCLUDED
#define CIRCULO_HH_INCLUDED

#include <cstdlib>

class Circulo {
public:
    Circulo();
    Circulo(float radio);

    float area() const;

    float diametro() const;

    const Circulo& operator=(const Circulo& otro);
    virtual ~Circulo();

private:
    float* radio;
};

#endif // CIRCULO_HH_INCLUDED
