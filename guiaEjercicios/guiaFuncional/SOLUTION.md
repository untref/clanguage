## Guia 00 - Implementación en JavaScript de Codificación - SOLUCIONES

### Ejercicio 2 - Pares

Expresión lambda que definen un par:

```
    (a,b) == lambda a b f. f a b
```

Primer elemento del par:

```
    (lambda a b f. f a b)(1 2 TRUE)

     beta transformación ->
     
    (lambda b f. f 1 b )(2 TRUE)
    
     beta transformación ->
     
    (lambda f. f 1 2 )(TRUE)

    beta transformación ->
     
    TRUE 1 2
```

Segundo elemento del par:

```
    (lambda a b f. f a b)(1 2 FALSE)

     beta transformación ->
     
    (lambda b f. f 1 b )(2 FALSE)
    
     beta transformación ->
     
    (lambda f. f 1 2 )(FALSE)

    beta transformación ->
     
     FALSE 1 2
```

### Ejercicio 4 - Algebra de Bool

[Soluciones](../../Funcional/logic_and_list.js)

### Ejercicio 5 - Implementación de Pares

[Soluciones](../../Funcional/logic_and_list.js)

### Ejercicio 6 - Listas

Creo un par con dos elementos
CONS(78)(9) == (78,9)

Creo otro para con dos elementos (uno de ellos es el par creado previamente):

CONS(24)( CONS(78)(9) ) == ( 24, (78, 9) )

Ahora q tengo la lista de puedo obtener sus elementos, puntualmente el segundo elemento (78). Primero otengo el segundo elemento de la lista (que es un par) y luego tomo el primer elemento del par.

    CONS(24)( CONS(78)(9) )(FALSE)        --> Devolverá CONS(78)(9)

    CONS(24)( CONS(78)(9) )(FALSE)(TRUE) --> 78 - CONS(78)(9)(TRUE) -

