#include <iostream>

#include "garbage_collector.hh"

void otraLlamada( Puntero p0 ) {
  std::cout << "otraLlamada" << std::endl;
  p0.setValor(75);
}

void llamarPuntero( Puntero p0 ) {
  std::cout << "llamarPuntero" << std::endl;
  otraLlamada( p0 );
}



int main(int argc, char** argv) {

  {
    Puntero r;
    Puntero q;
    Puntero p( malloc(sizeof(int)) );

    q = p;
    r = p;

    q.setValor( 35 );

    std::cout << "Valor puntero p: " << p.getValor() << std::endl;
    std::cout << "Valor puntero q: " << q.getValor() << std::endl;

    llamarPuntero( p );

    std::cout << q.getValor() << std::endl;
  }

  std::cout << "Otro scope" << std::endl;
  std::cout << "Otro scope" << std::endl;
  std::cout << std::endl;

  {
    std::cout << "creo s " << std::endl;
    Puntero s;

    std::cout << "creo t " << std::endl;
    Puntero t( malloc(sizeof(double)));

    std::cout << "creo u " << std::endl;
    Puntero u( malloc(sizeof(int)) );

    // No solo debe liberarse el entero, sino tambien el
    // dato apuntado por t
    std::cout << "asigno u a t" << std::endl;
    t = u;
    s = u;

    t.setValor( 95 );

    std::cout << "Valor puntero u: " << u.getValor() << std::endl;
    std::cout << "Valor puntero t: " << t.getValor() << std::endl;

    llamarPuntero( u );

    std::cout << t.getValor() << std::endl;
  }

}
