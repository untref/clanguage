#include <iostream>

class Attr {
  public:
   Attr(int i ) {
   } 
};

int main(int argc, char** argv) {
  Attr a(2);

  std::cout << argc << std::endl;

  std::cout << argv[0] << std::endl;
  std::cout << argv[1] << std::endl;
  std::cout << argv[2] << std::endl;

  return 0;
}
