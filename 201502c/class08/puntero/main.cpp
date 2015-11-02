#include <iostream>
#include <cstdlib>

class Puntero {
  public:
    Puntero() {
      std::cout << "constructor" << std::endl;
     this->p = 0;
     this->ref = 1;
    }

    Puntero(void* p) {
     this->p = p;
     this->ref = 1;
    }

    Puntero(const Puntero& otro) {
     this->p = otro.p;
     this->ref = otro.ref + 1;
    }

    virtual ~Puntero() {
      this->ref--;
      std::cout << "destructor" << std::endl;
      if ( p && !ref ) {
        std::cout << "free" << std::endl;
        free(p);
      }
      p = 0;
    }

    void* ptr() const {
      return p;
    }

  private:
    void* p;
    unsigned ref;
};

void f(Puntero p) {
}

int main() {
  Puntero p( malloc( sizeof(int) )  );
  Puntero null;

  *(int*)p.ptr() = 4;

  std::cout << "Puntero: " << *(int*)p.ptr() << std::endl;

  f(p);
}
