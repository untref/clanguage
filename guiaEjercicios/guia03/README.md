## Guia 02 - Punteros

### Ejercicio 1

1. Predecir el/los valores que imprimirá ```printf```. 
2. Intercambiar valores de i y j

    ```
        int main()
        {
            int i = 29;
            int j = 50;
            int* direccionI = 0;
            int* direccionJ = 0;

            printf("*direccionJ: %d\n"), *direccionJ);
            printf("*direccionI: %d\n"), *direccionI);


            // Sin asignar nuevos valores a i o j ni
            // utilizar constantes literales;
            // intercambiar los valores de i y j

            // codigo aqui ...

            printf("i: %d\n"), i);
            printf("j: %d\n"), j);
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




