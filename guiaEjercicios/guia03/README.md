## Guia 02 - Punteros

### Ejercicio 1

Sin modificar los assert, modificar el código de forma tal que los tests pasen:

    ```
        int main()
        {
            int i = 29;
            int j = 50;
            int* direccionI = 0;
            int* direccionJ = 0;

            assert( *direccionJ, j);
            assert( *direccionI, i);

            assert( 29, j);
            assert( 50, i);

            // Sin asignar nuevos valores a i o j ni
            // utilizar constantes literales;
            // intercambiar los valores de i y j

            // codigo aqui ...

            assert( i, 50 );
            assert( j, 29 );
        }
    ```

### Ejercicio 2

**NOTA**: Este ejercicio está pensado para que lo hagan utilizando papel y lapiz

Dado la siguiente porción de código, hacer un esquema del stack y un seguimiento (en este esquema) de como se van modificando las variables locales al main 

```
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

### Ejercicio 3

**NOTA**: Este ejercicio está pensado para que lo hagan utilizando papel y lapiz

1. Dado la siguiente porción de código, hacer un esquema del stack y un seguimiento (en este esquema) de como se van modificando las variables locales al main 

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

2. Dado la siguiente porción de código, hacer un esquema del stack y un seguimiento (en este esquema) de como se van modificando las variables locales al main 

```
int main()
{
    float decimales[] = { 1.1, 2.2, 3.3 };
    float* direccion = decimales;

    while ( direccion - decimales < 3 ) {
        printf("decimales[%d] = %f\n", direccion - decimales, *direccion);
        ++direccion;
    }
    
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
    assert( *(array+1), 2 );

    assert( array[5], 9);
    assert( array[6], 10 );

    // codigo (no utilizar corchetes)

    assert( *(array+5), 10);
    assert( *(array+6), 9 );
    
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




