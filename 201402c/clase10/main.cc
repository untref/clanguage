#include <iostream>

class Numero {
  public:
   Numero(int i ) {
     this->i = i;
   } 

   int valor() {
     return i;
   }

   int& refValor() {
     return i;
   }

   int* pValor() {
     return &i;
   }

  private:
   int i;
};

int main(int argc, char** argv) {
  Numero a(2);

  int& b = a.refValor();

  int* pb = a.pValor();

  b = 4;

  *pb = 19;
  pb = 0 = NULL; 

  std::cout << a.valor() << std::endl;


  return 0;
}
