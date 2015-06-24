#include <iostream>

// Crear un array de bits q soporte más de de 64 bits, definiendo todos los metodos
// necesarios para administrar correctamente los recursos

class ArrayBits {
public:
    ArrayBits() {
        // completar código
    };

    ArrayBits(const ArrayBits& otro) {
        // completar código
    }

    virtual ~ArrayBits() {
        // completar código
    }

    ArrayBits& operator=(const ArrayBits& otro) {
        // completar código
        return *this;
    };

    ArrayBits& And(const ArrayBits& otro) {
        // completar código
        return *this;
    };

    ArrayBits& Or(const ArrayBits& otro) {
        // completar código
        return *this;
    };

    bool isOn(const ArrayBits& otro) {
        // completar código
        return true;
    };

    bool isOff(const ArrayBits& otro) {
        return ! isOn(otro);
    };

private:
    // Cada elemento de este array representa un bit (con el fin de simplificar)
    char* bits;
};

int main(int argc, char** argv) {
    ArrayBits a;
};
