## Guia Punteros - Punteros

> **NOTA:** Es importante realizar los diagramas de menoria para realizar estos ejercicios

### Ejercicio 1

Dado el siguiente código:

```c
    int main()
    {
        int i = 29;
        int j = 50;

        char vector[] = { 0x1, 0x2, 0x3 };
    }
```

1. Cuál es la dirección de ```i```?
2. Cuál es la dirección de ```j```?
3. Cuál es la dirección de ```vector```?
4. Cuál es la dirección de ```vector[0]```?
5. Cuál es la dirección de ```vector[1]```?

### Ejercicio 2

Dado el siguiente código:

```c
    int main()
    {
        int vector[] = { 0x1, 0x2, 0x3 };
    }
```

1. Cuál es el resultado de la siguiente operación: ```vector + 1```? Es la suma algebraica?
2. Cuál es el resultado de la siguiente operación: ```vector + 200```? Puedo hacer esta operación? Porqué?
3. Cuál es el resultado de la siguiente operación: ```&vector[2] - &vector[0]```? Puedo hacer esta operación? Porqué?

### Ejercicio 3

Dado el siguiente código:

```c
    int main()
    {
        float auro = 1.6180;
        int primo = 999631;
        float* pf;
        int* pi;
  
        void* pv = 0x0;

        pf = &auro;
        pi = &primo;

        pv = pf;
        pv = pi;
    }
```
1. Son válidos los punteros declarados? Cuáles?
2. Contienen valores numéricos los punteros? Cuáles son sus valores?
3. Que dato contiene ```pv``` en la linea 58? Puedo derreferenciarlo? Porqué?
4. Que dato contiene ```pv``` en la linea 59? Puedo derreferenciarlo? Porqué?
5. Puedo asignar ```primo = auro```? Cuanto valdrá primo? Y ```*pi```?
6. Puedo asignar ```auro = primo```? Cuanto valdrá primo? Y ```*pf```?

### Ejercicio 4

**NOTA**: Este ejercicio está pensado para que lo hagan utilizando papel y lapiz

Dado la siguiente porción de código, hacer un esquema del stack y un seguimiento (en este esquema) de como se van modificando las variables locales al main 

```c
void pasajePorValor(int parametro, int nuevoValor) {
    parametro = nuevoValor;
};

void pasajePorReferencia(int* parametro, int nuevoValor) {
    *parametro = nuevoValor;
};

int main()
{
    float pi = 3.14;
    int decimales = 2;

    int* direccionEntera = 0;
    float* direccionDecimal = &pi;

    printf("El valor de 'pi' %f, almacenado en la dirección 0x%x\n", pi, direccionDecimal);

    printf("El valor de 'decimales' %d almacenado en la dirección 0x%x\n", decimales, &decimales );
    pasajePorValor(decimales, 28);
    printf("El valor de 'decimales' %d almacenado en la dirección 0x%x - luego de invocar pasajePorValor\n", decimales, &decimales );
    direccionEntera = &decimales;
    pasajePorReferencia(direccionEntera, 15);
    printf("El valor de 'decimales' %d almacenado en la dirección 0x%x - luego de invocar pasajePorValor\n", decimales, &decimales );
}
```

### Ejercicio 5

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
11. Porqué la resta de los punteros de la linea 31 toma ese valor? Cuanto vale?


```
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

### Ejercicio 6

Dado el siguiente código:

```c
int suma(int a, int b) {
  return a + b;
}

int resta(int a, int b) {
  return a - b;
}

int main() {
  int (*f)(int, int) = 0;

  printf("producto: %d\n", (*f)(9, 9));
  
```

1. De que tipo es la variable ```f```?
2. Modificar el programa para que imprima el producto de 9 y 9.

### Ejercicio 7

Realizar el esquema de memoria del stack de este programa:

```c
int main(int argc, char** argv) {
}
```

### Ejercicio 8

Crear una función/es que permita iterar un array de cualquier tipo (sin repetir código) y elemento a elemento imprima cada uno de sus elementos.  

```c

int main(int argc, char** argv) {
  int      enteros[] = { 1, 2, 3};
  double decimales[] = { 1.1, 2.2, 3.3 };

  // Invoco  la función que itera
  iterador( enteros, .... );

  
  iterador( decimales, .... );
}
```

### Ejercicio 9

Definir y declarar una función que dado dos arrays realice a concatenación de ambos y devuelva la concatenación. Implementar esta función para dos tipos distintos al menos.  Se repite el código? Cómo podemos evitarlo?

### Ejercicio 10

**NOTA**: Hacer diagrama de la memoria.

Se busca implementar la funcionalidad "Replace All" de un editor. Para eso se tiene un vector de strings (párrafo), la palabra a reemplazar y la palabra reemplazo.  Confeccionar una función o procedimiento que dado el párrafo realice el reemplazo.
Liberar todos los recursos que se hayan alocado.

```c
int main() {
  char* parrafo[] = {
    "Diego Capusoto",
    "es",
    "es",
    "uno",
    "de",
    "los",
    "humoristas",
    "más",
    "grandes",
    "grandes",
    "de",
    "Arg"
  };
    
  // Reemplazar, 'es' por 'eeeeeeeeeeees' y 'grandes' por 'fenomeno'
  
}
```

### Ejercicio 11

Teniendo hecho el ejercicio anterior, utilizar como fuente de un párrafo un archivo TXT.  Sacar el resultado por pantalla.
