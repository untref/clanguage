#include <iostream>

#include "Circulo.hh"

using namespace std;

void f(Circulo*  c3) {

};


int main()
{
    Circulo c1(4);
    Circulo c2;

    c2 = c1;

    f(&c2);
    cout << "Diametro c2 " << c2.diametro() << endl;
    cout << "Diametro c1 " << c1.diametro() << endl;
    return 0;
}
