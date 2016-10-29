#include <stdio.h>

int sum(int a, int b) {
  return a + b;
}

int rest(int a, int b) {
  return a - b;
}

int main(int argc, char* argv[]) {
  int (*f)(int, int) = 0;

  f = &sum;
  printf("suma: %d\n", (*f)(5, 9));

  f = &rest;
  printf("resta: %d\n", (*f)(5, 3));
}
