## Guia Funcional

### Ejercicio 1 - Implicación

Teniendo en cuenta la codificación Church, definir una expresión lambda que defina una implicación lógica del tipo *p entonces q*.

### Ejercicio 2 - Ley de morgan

Definir una función lamba que transforme una expresión morgan a su equivalente. 

Recibimos como argumentos: (-p) AND (-q)
Y buscamos obtener: -(p OR Q).

Definir una función lamba que transforme una expresión morgan a su equivalente. 

Recibimos como argumentos: (-p) OR (-q)
Y buscamos obtener: -(p AND Q).

Podemos definir una funcion lambda que dado un operador logico OR devuelve AND y viceversa?

### Ejercicio 3 - Pares

Dada la definición de pares (según la codificacón Church) escribir las expresiones lambdas que permiten obtener el primer
elemento y el segundo elemento del par.

### Ejercicio 4 - Listas

Basandonos en la definición de Pares del punto anterior, definir las expresiones lambdas que nos permitan construir una lista. Una vez definidas estas expresiones construir:

1. Definir una lista vacía.
2. Una lista con un único elemento. 
3. Definir una lista con 3 elementos.

### Ejercicio 5 - Lista de funciones lambdas

Se tiene una lista de dos operaciones aritméticas lambdas y se busca evaluarlas en un valor x.  Obtener la función lambda que realiza esta tarea.

Esta es la lista: ( +1, (+2, NIL ) ).
Al aplicarle el conjunto de expresiones a un parámetro x sería:
- x + 1
- x + 1 + 2


