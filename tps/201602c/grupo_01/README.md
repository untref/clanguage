# Grupo 00

## Integrantes

* PREMAT, DARIO PABLO
* UMIRI, PEDRO

## Entregas

### Segunda entrega

**Pendiente**

### Segunda entrega

**Aprobada**

1. Cuando tiene un cuyo cuerpo es muy largo, cambien la condición para que este (el cuerpo) contenga menos lineas.  Huffman.c:72.
2. TDA y variables
    1. La variable no puede llamarse auxiliar! Dar nombres claros a las variables.
    2. Tanto ``auxiliar``` como su cantidad deberían ser parte de un TDA.
    3. Las primitivas que permiten encontrar un elemento auxiliar por el caracter que almacena debería ser una primitiva del TDA.
    4. El flujo puede mejorarse de la siguiente manera:
        1. (Siempre busco un nodo para el caracter) Si no lo encontre, lo creo.
        2. Sea que lo haya encontrado o creado, siempre voy a tener un nodoe.
        3. Incremento frecuencia.
3. En limpiar, primero borran node a la izquierda, borran la raiz y por último nodo a la derecha. Raiz debería borrarse al final.
4. Corregir estilo de codificación
5. Colocar toda la funcionalidad dentro de TDAs
6. No hay necesidad de que ```auxiliares``` tenga una longitud fija. Hacerla variable.

### Primera entrega

**Desaprobada**

1. No existe el informe donde ver los integrantes del grupo
2. Al ejecutar la applicación arroja un error.
3. No existe el proyecto de ecplise
4. Falta lectura de parámetro '-f'
5. Falta lectura de parámetro '-o'
6. El ```Segmentation Fault: 11``` se produce en la inicialización del nodo.  Hagan el diagrama de memoria y verán donde está el error.
7. El nombre del TDA va en [cammelcase](https://en.wikipedia.org/wiki/Camel_case).
8. Las primitivas del TDA comienzan con un prefijo igual al nombre del TDA, en su caso **nodo_**.
