#include <iostream>

class A {
  public:
    A() {
      std::cout << "constructor" << std::endl;
    }

    A(const A& otro) {
      std::cout << "constructor copy" << std::endl;
    }

    virtual ~A() {
      std::cout << "destructor" << std::endl;
    }

    A& operator=(const A& otro) {
      std::cout << "operator =" << std::endl;
    }



};

void f(A a) {
  std::cout << "call f" << std::endl;
};

int main(int argc, char** argv) {
    A a;
    A b;
    A c = b;

    // La referencia debe inicializarse con un valor y no se puede volver
    // a configurar
    A& d = b;

    d = a;

    // Cuando pasamos una instancia por valor se va a ejecutar el constructor  de copia
    f(a);

    // Si está definido se ejecuta el operador =, sino el por defecto
    b = a;
  return 0;
}
