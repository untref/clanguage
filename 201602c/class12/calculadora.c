#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void usage() {
  printf(" <cmd> <n1> <n2> <op>\n");
  printf("\n");
  printf(" Ex.:\n");
  printf("  <cmd> 5.0 4.0 sum\n");
  printf("\n");
}

int find_function( char** funcNames, const char* funcName, unsigned size ) {
  int index;

  for( index = 0; index < size; ++index) {
    if ( strcmp(funcName, funcNames[index]) == 0 ) {
      return index;
    }
  }

  return -1;
}

double sum(double a, double b) {
  return a + b;
}

double rest(double a, double b) {
  return a - b;
}

/***
 * <cmd> <n1> <n2> <op>
 *
 * Ex.:
 *   <cmd> 5.0 4.0 sum
 *
 */
int main(int argc, char** argv) {
  const char* operand_0 = argv[1];
  const char* operand_1 = argv[2];
  const char* funcName = argv[3];

  double result;

  char*                         funcNames[] = { "sum", "rest" };
  double (*functionArray[])(double, double) = { &sum,  &rest  };

  if  ( argc != 4 ) {
    usage();
    return 1;
  }

  int index = find_function( funcNames, funcName, sizeof(funcNames) / sizeof(char*) );
  double (*f)(double, double) = functionArray[index];


  if ( index == -1 ) {
    printf("Unknown <op>: %s\n", funcName);
    return 1;
  }


  result = (*f)( atof(operand_0), atof(operand_1) );
  
#if 0
  if ( strcmp( funcName, "sum") == 0 ) {
    result = sum( atof(operand_0), atof(operand_1) );
  }
  else if ( strcmp( funcName, "rest") == 0 ) {
    result = rest( atof(operand_0), atof(operand_1) );
  }
#endif


  printf(" %s %s %s: %lf\n", operand_0, funcName, operand_1, result); 



}

