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

### Ejercicio 2

Dado el siguiente código:

```c
01    int main()
02    {
03        float auro = 1.6180;
04        int primo = 999631;
05        float* pf;
06        int* pi;
07  
08        void* pv = 0x0;
09
10        pf = &auro;
11        pi = &primo;
12
13        pv = pf;
14        pv = pi;
15    }
```
1. Son válidos los punteros declarados? Cuáles? Porqué?
2. Contienen valores numéricos los punteros? Cuáles son sus valores?
3. Que dato contiene ```pv``` en la linea 09? Puedo derreferenciarlo? Porqué?
4. Que dato contiene ```pv``` en la linea 14 y 15? Puedo derreferenciarlo? Porqué?
5. Puedo asignar ```primo = auro```? Cuanto valdrá primo? Y ```*pi```?
6. Puedo asignar ```auro = primo```? Cuanto valdrá primo? Y ```*pf```?

### Ejercicio 3

**NOTA**: Este ejercicio está pensado para que lo hagan utilizando papel y lapiz

1. Hacer un esquema de memoria con el mayor detalle posible para realizar el seguiento del programa. Considerar que la primera dirección del proceso es 0xff00.
2. Cuál es el valor de p, q y r en la linea 5, 6 y 7?
3. Cuál es el valor de p, q y r en la linea 9, 10 y 11? Que significa?
4. Qué valor tiene 'simple' luego de que se ejecuto la linea 13?
5. Qué valor tiene *p y *q luego de que se ejecuto la linea 13?
6. Se modifico el array enteros luego de que se ejecutó la linea 17?
7. Se volvió a modificar el array enteros luego de que se ejecutaron las lineas hasta 20?
8. Algun elemento del array es 0 luego de ejecutar la linea 22?
9. Y luego de ejecutar la linea 25?
10. Porqué la suma de los punteros de la linea 25 toma ese valor?
11. Porqué la resta de los punteros de la linea 27 toma ese valor? Cuanto vale?
12. Porqué la resta de los punteros de la linea 31 toma ese valor? Cuanto vale?


```c
00 int main()
01 {
02    int enteros[] = { 1, 2, 3, 4, 7, 78, 174 };
03    int simple = 32;
04    int radio = 4;
05    int* p;
06    int* q;
07    int* r;
08    
09    p = enteros + 6;
10    q = &simple;
11    r = q;
12    
13    *r = 115;
14    
15    r = &radio;
16    
17    *p = radio;
18    
19    p = r;
20    q = enteros;
21    
22    *(q+ 4) = 0;
23    *p = 0;
24    
25    r = q + 1;
26    
27    q - r;
28  
29    p = enteros + 3;
30    
31    q - p;
32    return 0;
33}
```

### Ejercicio 4 - Arrays

Definir una array de tipo ```T``` e imprimir sus valores. Realizar los ejercicios con los siguientes tipos:

+ int
+ unsigned
+ double

1. Qué valores obtuvo?
2. Los valores son los que esperaba?
3. Como resolvemos el problema?
4. Imprimir el sizeof para cada uno de los arrays. Cuanto da? Puede inferirlo antes de ejecutar el código?
5. Como hacemos para inicializar el array con valores?

### Ejercicio 5 - Punteros y sus posibles valores

```c
01 int main(int argc, char** argv) {
02   char vector[] = { 0x9, 32, 25, 010 /* octal */, 200, 09 };
03
04   char* p = 0;
05   char* q = 0x0;
06 
07   if ( p == q ) {
08     printf("q y p son iguales\n");
09   }
10
11   p = vector + 0x6;
12   q = vector;
13
14   p = vector + 5;
15
16   if ( p == q ) {
17     printf("q y p son iguales\n");
18   }
19
20  char* r = vector + 10;
21  printf("%\n", *r);
22
23  return 0;
24 }
```

1. Cuál es la diferencia entre ```p``` y ```q```?
2. Se imprime la leyenda *q y p son iguales*?
3. Cuanto vale ```p``` luego de ejecutar la linea 11? Es válido el puntero?
4. Cuanto vale ```q``` luego de ejecutar la linea 12? Es válido el puntero?
5. Se imprime la leyenda * \*p es igual a \*q*?
6. Qué imprimirá la linea 21? Funciona?


### Ejercicio 6 - Procedimiento intercambio

Crear un procedimiento para dado dos valores del mismo tipo sus valores sean intercambien.

