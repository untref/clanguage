## Lenguaje C

**Objetivos**: Poder definir vectores 

### Ejercicio 1 - Tipos en C

```c
int main(int argc, char** argv) {
  int entero;
  unsigned enteroSinSigno;
  long int enteroLargo;
  long unsigned enteroLargoSinSigno;
  float decimalSimple;
  double decimalDoblePrecision;

  printf("Tamañano de un entero con sign:               %lu\n", sizeof(entero) );
  printf("Tamañano de un entero con sin sign:           %lu\n", sizeof(enteroSinSigno) );
  printf("Tamañano de un entero largo con sign:         %lu\n", sizeof(enteroLargo) );
  printf("Tamañano de un entero largo sin sign:         %lu\n", sizeof(enteroLargoSinSigno ) );
  printf("Tamañano de un flotante:                      %lu\n", sizeof(decimalSimple) );
  printf("Tamañano de un double:                        %lu\n", sizeof(decimalDoblePrecision) );
}
```

1. Qué salida producirán los printfs anteriros?
2. Cuanta memoria ocupará un conjunto  de 10 elementos para cada uno de los tipos anteriores?

## Ejercicio 2 - Arrays

Definir una array de tipo ```T``` e imprimir sus valores. Realizar los ejercicios con los siguientes tipos:

+ int
+ unsigned
+ double

1. Qué valores obtuvo?
2. Los valores son los que esperaba?
3. Como resolvemos el problema?
4. Imprimir el sizeof para cada uno de los arrays. Cuanto da? Puede inferirlo antes de ejecutar el código?
5. Como hacemos para inicializar el array con valores?

### Ejercicio 3 - Punteros y sus posibles valores

```c
int main(int argc, char** argv) {
  char vector[] = { 0x9, 32, 25, 010 /* octal */, 200, 09 };

  char* p = 0;
  char* q = 0x0;

  if ( p == q ) {
    printf("q y p son iguales\n");
  }

  p = vector + 0x6;
  q = vector;

  p = vector + 5;

  if ( p == q ) {
    printf("q y p son iguales\n");
  }

  char* r = vector + 10;
  printf("%\n", *r);

  return 0;
}
```

1. Cuál es la diferencia entre ```p``` y ```q```?
2. Se imprime la leyenda *q y p son iguales*?
3. Cuanto vale ```p``` luego de ejecutar la linea 66? Es válido el puntero?
4. Cuanto vale ```q``` luego de ejecutar la linea 68? Es válido el puntero?
5. Se imprime la leyenda * \*p es igual a \*q*?
6. Qué imprimirá la linea 75? Funciona?

