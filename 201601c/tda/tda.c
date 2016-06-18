#include "Nave.h"
int main(int argc, char* argv[]) {
  int i = 9;
  Nave n;
  Nave m;

  nave_init(&n, "Otro nombre");
  nave_clonar(&n, &m);
  nave_print(&n);
  nave_limpiar(&m);
  nave_limpiar(&n);
}
