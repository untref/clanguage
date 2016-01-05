## Guia 02 - Arrays

### Ejercicio 1

**NOTA**: Este ejercicio está pensado para que lo hagan utilizando papel y lapiz

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

1. Modificar los assert de forma tal que los tests pasen. 
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

            assert( sizeof(decimales), 0);
            assert( sizeof(enteros), 0);
        
            assert( sizeof(double), 8);
            assert( sizeof(int), 4);
        
            return 0;
        }
        ```

### Ejercicio 3

1. Modificar los assert de forma tal que los tests pasen. 
2. Cuantos elementos contiene el array?
3. Que estamos haciendo cuando cambiamos el valor del elemento 6?
4. Podemos hacer lo que estamos haciendo en el punto 3? Porqué?

        ```
        int main()
        {
            int enteros[] = { 2, 8, 16, 32, 64};

            assert( enteros[0], 0);
            assert( enteros[4], 0);

            enteros[5] = 128;
        
            return 0;
        }
        ```


### Ejercicio 4

Sin modificar los assert, modificar el código de forma tal que los tests pasen:

```
int main()
{
    int array[] = { , , , , , , , };

    assert( array[1], 2 );

    assert( array[5], 9);
    assert( array[6], 10 );

    // codigo 

    assert( array[5], 10);
    assert( array[6], 9 );
    
}
```

### Ejercicio 5

Completar los asserts para que las pruebas pasen:

```

void f(int param[]) {
    assert( sizeof(param), ... );
};

void g(int* param) {
    assert( sizeof(param), ... );
};


int main()
{
    int array[] = { 1,2,3,4,5,6,7,8 };

    assert( sizeof(array), ... );
    assert( sizeof(int), ... );
    
}
```




