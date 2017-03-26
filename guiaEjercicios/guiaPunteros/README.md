## Guia Punteros - Punteros

### Ejercicio 1

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

### Ejercicio 2

Realizar el esquema de memoria del stack de este programa:

```c
int main(int argc, char** argv) {
}
```

### Ejercicio 3

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

### Ejercicio 4

Definir y declarar una función que dado dos arrays realice a concatenación de ambos y devuelva la concatenación. Implementar esta función para dos tipos distintos al menos.  Se repite el código? Cómo podemos evitarlo?

### Ejercicio 5

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

### Ejercicio 6

Teniendo hecho el ejercicio anterior, utilizar como fuente de un párrafo un archivo TXT.  Sacar el resultado por pantalla.
