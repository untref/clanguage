#include <stdio.h>

/***
 * Intercambiar a y b siendo arrays
 * */

void intercambiar(void* pa, void* pb, unsigned tam) {
    unsigned char t;
    unsigned char* _pa = pa;
    unsigned char* _pb = pb;

    while (tam--) {
        t = *_pa;
        *_pa = *_pb;
        *_pb = t;
        ++_pa;
        ++_pb;
    }
}

int main(int argc, char** argv) {
  int a = 1,
      b = 2;

  double d1 = 1,
      d2 = 2;

  intercambiar(&a, &b, sizeof(a));
  intercambiar(&d1, &d2, sizeof(double));

  printf("a: %d, b: %d\n", a, b);
  printf("d1: %lf, d2: %lf\n", d1, d2);

  double decimales[] = {1.1,2.2,3.3};
  double* base;

  double* pd = decimales + 2;
  double* pdd = pd;
  base = decimales;

  base = base + 1;
  *base = 7.5; 
  *pd = 9.0;

  printf("%lf, %lf, %lf\n", *base, *pd, *pdd);
}
