#include "Circulo.hh"

#include <cstring>

Circulo::Circulo(float radio) {
    this->radio = (float*)malloc(sizeof(float));
    *this->radio = radio;
};

Circulo::Circulo() {
    this->radio = (float*)malloc(sizeof(float));
    *this->radio = 1;
};

float Circulo::area() const {
    return 3.14 * *radio * *radio;
}

float Circulo::diametro() const {
    return 2 * *radio;
}

Circulo::~Circulo() {
    free(this->radio);
    this->radio = 0;
}

const Circulo& Circulo::operator=(const Circulo& otro) {
    memcpy(this->radio, otro.radio, sizeof(float));
}


