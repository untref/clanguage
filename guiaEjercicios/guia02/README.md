## Guia 02 - Arrays

### Ejercicio 1

Dado la siguiente porción de código, hacer un esquema del stack y un seguimiento (en este esquema) de como se van modificando las variables locales al main 

        ```
        int main()
        {
            float decimales[] = { 1.1, 2.2, 3.3 };
            int indice;

            for(indice = 0; indice < 3; ++indice) {
                printf("decimales[%d] = %f\n", indice, decimales[indice]);
            }
        
            return 0;
        }
        ```

### Ejercicio 2

1. Predecir el/los valores que imprimirá ```printf```. 
2. Porqué el valor del sizeof es tal?
3. Cuantos elementos tiene el array *decimales*?
4. Cuantos elementos tiene el array *enteros*?
5. Cuál es el tamaño de un *float*?
6. Cuál es el tamaño de un *int*?
7. Qué relación existe entre el tamaño del array y el tamaño del tipo de dato?

        ```
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

### Ejercicio 3

1. Predecir el/los valores que imprimirá ```printf```. 
2. Cuantos elementos contiene el array?
3. Que estamos haciendo cuando cambiamos el valor del elemento 6?
4. Podemos hacer lo que estamos haciendo en el punto 3? Porqué?

        ```
        int main()
        {
            int enteros[] = { 2, 8, 16, 32, 64};

            printf( enteros[0]);
            printf( enteros[4]);

            enteros[5] = 128;
        
            return 0;
        }
        ```


### Ejercicio 4

1. Predecir el/los valores que imprimirá ```printf```. 
2. Porqué el sizeof de params es  tal?
3. Hacer procedimiento para imprimir el array
4. Se modifica el array en alguna de las funciones? Porque?
5. Que es pasaje por valor y por referencia?

```

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

### Ejercicio 5

1. Generar una función que copie el contenido de un array de enteros a  otro.
2. Que debemos tener en cuenta al momento de realizar la copia?
3. Generar una función que copie el contenido de un array de flotantes a  otro.
4. Puedo realizar una copia desde el array de enteros al de flotantes (utilizando estas funciones)?
5. Que desventajas tiene este código? Se puede mejorar? Cómo (no es necesario hacerlo)?
```
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

### Ejercicio 6

Crear un procedimiento que perminta revertir los elementos de un array.

