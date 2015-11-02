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
  A& d = b;

  d = a;

  f(a);

  b = a;
  return 0;
}
