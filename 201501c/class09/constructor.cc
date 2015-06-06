
#include <string>
#include <iostream>

class Redis {
  public:
   Redis(int a) {
     std::cout << "const:" << a << std::endl;
     p =a;
     this->p = a;
     (*this).p = a;
   }

   Redis() {
     std::cout << "const" << std::endl;
   }

   virtual ~Redis() {
     std::cout << "dest" << std::endl;
   }

  private:
    int p;

    std::string s;
};


int main(int argc, char**) {
  {

    Redis v1(2);
  }

  Redis v;

  std::cout << "Codigo main" << std::endl;
}
