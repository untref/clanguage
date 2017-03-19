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
