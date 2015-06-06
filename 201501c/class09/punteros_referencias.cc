
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

   void dump() {
     std::cout << "dump: " << this->p << std::endl;
   }
  private:
    int p;

    std::string s;
};


int main(int argc, char**) {
  // Redis v[2];

  Redis v1(9);

  Redis* pRedis = new Redis(27);

  pRedis->dump();

  delete pRedis;
  std::cout << "Codigo main" << std::endl;
}

























