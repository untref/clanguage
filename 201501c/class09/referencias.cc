
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

    Redis(const Redis& other) {
        std::cout << "const de copia" << std::endl;
    }

    virtual ~Redis() {
        std::cout << "dest" << std::endl;
    }

    void dump() {
        std::cout << "value:" << this->p << std::endl;
    }

    Redis& operator=(const Redis& o) {
        std::cout << "Operator =" << std::endl;
    }

private:
    int p;

    std::string s;
};


void swapR(int& a, int& b){
    int tmp = a;
    a = b;
    b = tmp;
}


void swapR(Redis& a, Redis& b){
    std::cout << "Swap Redis" << std::endl;
    Redis tmp = a;
    a = b;
    b = tmp;
}

int main(int argc, char**) {
    Redis v1(8);
    Redis v2(6);
  
    std::cout << "v1 " << std::endl;
    v1.dump();

    std::cout << "v2 " << std::endl;
    v2.dump();

    swapR(v1, v2);

    std::cout << "v1 " << std::endl;
    v1.dump();

    std::cout << "v2 " << std::endl;
    v2.dump();

/*
  int a(12);
  int b(24);


  std::cout << "a: " << a << " b:" << b << std::endl;
  swap(&a, &b);
  std::cout << "a: " << a << " b:" << b << std::endl;
  swapR(a,b);
  std::cout << "a: " << a << " b:" << b << std::endl;

  int* pInt = &a;

  *pInt = 7;


  int& rInt = a;

  std::cout << "rInt: " << rInt << " a:" << a << std::endl;
  rInt = 12;

  std::cout << "rInt: " << rInt << " a:" << a << std::endl;

  rInt = b;

  std::cout << "rInt: " << rInt << " a:" << a << std::endl;







*/

}
