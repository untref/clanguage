#include <iostream>
#include <sstream>

/**
 * Declaracion de la clase Complejo
 */
class Complejo {
 public:
    // Constructor de copia
    Complejo(const Complejo& otro) {
      std::cout << "co" << std::endl;
      this->x = otro.x;
      this->y = otro.y;
    }

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

    Complejo& operator=(const Complejo& otro) {

      std::cout << "o =" << std::endl;
      this->x = otro.x;
      this->y = otro.y;
    }

    // Imprimir numero complejo
    std::string print() const ;

   ~Complejo() {
     std::cout << "de" << std::endl;
   } 
 private:
    double x, y;
    
};

// Definicio de la clase
Complejo::Complejo() {
      std::cout << "csp" << std::endl;
  x = y = 0;
};

Complejo::Complejo(double x) {
  this->x = x; 
};

Complejo::Complejo(double x, double y) {
  this->x = x;
  this->y = y;
};

void Complejo::sumar(const Complejo& otroComplejo) {
  this->x += otroComplejo.x;
  this->y += otroComplejo.y;
};

void Complejo::restar(const Complejo& otroComplejo) {
  this->x -= otroComplejo.x;
  this->y -= otroComplejo.y;
};

std::string Complejo::print() const {
    std::stringstream s;

    s << x << " + " << y << "i";

    return s.str();
}

void swap(Complejo& a, Complejo& b) {
  Complejo tmp(a);

  a = b;
  b = tmp;

}

void f(Complejo c) {

}

int main( int argc, char** argv) {
#if 0
    Complejo nulo;

    // Ejercicio 1
    // Crear dos numeros complejos y sumar uno con otro
    // Verificar resultados con el metodo print
    // 
{
    Complejo c0(7,1);
    Complejo c2(1,4);
    
    c2.sumar(c1);

    std::cout << "suma: " << c2.print() << std::endl;

}
    // Ejercicio 2
    // Crear dos numeros complejos y restar uno con otro
    // Verificar resultados con el metodo print
    // 
{
    Complejo c1(7,9);
    Complejo c2(1,4);
    
    c2.restar(c1);

    std::cout << "restar: " << c2.print() << std::endl;
}
    // Ejercicio 3
    // Crear un array de 5 numeros complejos (que no sean 0 + 0i).
    // Intercambiar el 0 por el 3. (definiendo una funcion q utilice referencias)
    // Escribir la funcion iteracion para q esta imprima el array.
#endif
    Complejo array[2];
    Complejo tmp(7,7);
    

    array[0] = tmp;

    std::cout << "0: " << array[0].print() << std::endl;
    std::cout << "1: " << array[1].print() << std::endl;
    
    swap(array[0], array[1]);

    std::cout << "0: " << array[0].print() << std::endl;
    std::cout << "1: " << array[1].print() << std::endl;

    f(tmp);








}
