## Guia Arrays en detalles

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
6. Observa alguna relación entre estos valores?

### Ejercicio 2

Dado el siguiente código:

```c
    int main()
    {
        int vector[] = { 0x1, 0x2, 0x3 };
    }
```

1. Cuál es el resultado de la siguiente operación: ```vector + 1```? Es la suma algebraica?
2. Cuál es el resultado de la siguiente operación: ```vector - 1```? Es la resta algebraica?
2. Cuál es el resultado de la siguiente operación: ```vector + 200```? Puedo hacer esta operación? Porqué?
3. Cuál es el resultado de la siguiente operación: ```&vector[2] - &vector[0]```? Puedo hacer esta operación? Porqué?

### Ejercicio 3

1. Predecir el/los valores que imprimirá ```printf```. 
2. Porqué el valor del sizeof es tal?
3. Cuantos elementos tiene el array **decimales**?
4. Cuantos elementos tiene el array **enteros**?
5. Cuál es el tamaño de un **float**?
6. Cuál es el tamaño de un **int**?
7. Qué relación existe entre el tamaño del array y el tamaño del tipo de dato?

```c
int main()
{
    double decimales[] = { 1.1, 2.2, 3.3 };
    int enteros[] = { 2, 8, 16, 32, 64};

    printf("sizeof(decimales): %d\n", sizeof(decimales)); 
    printf("sizeof(enteros): %d\n", sizeof(enteros)); 

    printf("sizeof(double): %d\n", sizeof(double)); 
    printf("sizeof(int): %d\n", sizeof(int)); 

    return 0;
}

```

### Ejercicio 4

1. Predecir el/los valores que imprimirá ```printf```. 
2. Cuantos elementos contiene el array?
3. Que estamos haciendo cuando cambiamos el valor del elemento 6?
4. Podemos hacer lo que estamos haciendo en el punto 3? Porqué?

```c
int main()
{
    int enteros[] = { 2, 8, 16, 32, 64};

    printf( enteros[0] );
    printf( enteros[4] );
    printf( enteros[5] );
    enteros[5] = 9; 

    return 0;
}

```

### Ejercicio 5

1. Predecir el/los valores que imprimirá ```printf```. 
2. Porqué el sizeof de params es  tal?
3. Hacer procedimiento para imprimir el array
4. Se modifica el array en alguna de las funciones? Porque?
5. Que es pasaje por valor y por referencia?

```c

void f(int param[]) {
    printf("sizeof(param): %d\n", sizeof(param) );
    param[3] = 6;
};

void g(int* param) {
    printf("sizeof(param): %d\n", sizeof(param) );
    param[6] = 6;
};


int main()
{
    int array[] = { 1,2,3,4,5,6,7,8 };

    f(array);
    g(array);
    
    // Imprimir 
}

```

### Ejercicio 6

Definir un array origen y un array destino y copiar el contenido de uno en otro (el siguiente código tiene una trampa). 

```c
int main()
{
    float origen[] = { 1.1, 2.2, 3.3 };
    float destino[];

    // Codigo aquí

    // Imprima el contenido de ambos arrays aquí

    return 0;
}
```

1. Escribir el código para solucionar este problema.
2. Confeccionar el gráfico de memoria
3. Funcionó? 
4. Que fué lo que hicimos?


### Ejercicio 7

1. Generar una función que copie el contenido de un array de enteros a  otro.
2. Que debemos tener en cuenta al momento de realizar la copia?
3. Generar una función que copie el contenido de un array de flotantes a  otro.
4. Puedo realizar una copia desde el array de enteros al de flotantes (utilizando estas funciones)?
5. Que desventajas tiene este código? Se puede mejorar? Cómo (no es necesario hacerlo)?
```c
#define TAMANO_DESTINO  1 /* modificar de ser necesario */
int main()
{
    int origen[] = { 1,2,3,4,5,6,7,8 };
    int destino[TAMANO_DESTINO];
    int origenf[] = { 1.1, 2.2, 3.3, 4.4, 5.5, 6.6, 7.7, 8.8 };
    int destinof[TAMANO_DESTINO];
    
    copiar_enteros(destino, origen, /* ... */);
    copiar_flotantes(destinof, origenf, /* ... */);
}

```

### Ejercicio 8

Crear un procedimiento que perminta revertir los elementos de un array.

### Ejercicio 9

Crear una función que encuentre un elemento en un array y si existe devuelva el subíndice dentro del array, de lo contrario -1. Debemos probar nuestra función utilizando arrays de enteros y de flotantes. Hay código duplicado? Lo podemos reducir? Cómo?

## Ejercicio 10

Crear un procedimiento para copiar el contenido de un array a otro. Es importante el tipo?

```c
int main(int argc, char** argv) {
    int enteros_src[1024];
    // int enteros_dst
    copiar(enteros_dst, enteros_src, ...);
}
```
## Ejercicio 11

Crear un procedimiento para copiar el contenido de un array (origen) entre las posiciones 'desde' - 'hasta' a otro array (destino). Es importante el tipo?

```c
int main(int argc, char** argv) {
    int enteros_src[1024];
    // int enteros_dst
    copiar(enteros_dst, enteros_src, desde, hasta, ...);
}
```

## Ejercicio 12

Crear un procedimiento para concatenar dos arrays (de cualquier tipo).

```c
int main(int argc, char** argv) {
    int a[1024];
    int b[1024];
    // int destino;
    concatenar(destino, a, b, ...);
}
```

## Ejercicio 13

Crear una función que dado un parrafó de texto devuelva las ocurrencias (punteros a char) de una palabra.

```c
int main(int argc, char** argv) {
    char* parrafo = "este es un parrafo donde buscamos esta palabra a ver si aparece o no la palabra palabra";
    // ...
}
```

## Ejercicio 14

Crear un procedimiento que reemplace una palabra por otra en un párrafo.

```c
int main(int argc, char** argv) {
    char* parrafo = "este es un parrafo donde buscamos esta palabra a ver si aparece o no la palabra palabra";
    // ...
}
```
