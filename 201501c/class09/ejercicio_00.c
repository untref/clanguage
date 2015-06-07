#include <iostream>

/**
 * Declaracion de la clase Complejo
 */
class Complejo {
 public:
    // Construye un complejo igual a 0 + 0i
    Complejo();

    // Construye un complejo com parte entera
    Complejo(double x);

    // Construye un complejo con parte compleja y entera
    Complejo(double x, double y);

    // Suma el complejo pasado como parametro a this
    void sumar(const Complejo& otroComplejo);

    // Resta
    void restar(const Complejo& otroComplejo);

    // Imprimir numero complejo
    void print() ;

 private:
    double x, y;
    
};

// Definicio de la clase
Complejo::Complejo() {
    // Completar
};

Complejo::Complejo(double x) {
    // Completar
};

Complejo::Complejo(double x, double y) {
    // Completar
};

void Complejo::sumar(const Complejo& otroComplejo) {
    // Completar
};

void Complejo::restar(const Complejo& otroComplejo) {
    // Completar
};

void Complejo::print() {
    std::cout << this->x << " + " << (*this).y << " i" << std::endl;
}

int main( int argc, char** argv) {
    // Ejercicio 1
    // Crear dos numeros complejos y sumar uno con otro
    // Verificar resultados con el metodo print
    // 
    // Ejercicio 2
    // Crear dos numeros complejos y restar uno con otro
    // Verificar resultados con el metodo print
    // 
    // Ejercicio 3
    // Crear un array de 5 numeros complejos (que no sean 0 + 0i).
    // Intercambiar el 0 por el 3. (definiendo una funcion q utilice referencias)
    // Escribir la funcion iteracion para q esta imprima el array.

}
