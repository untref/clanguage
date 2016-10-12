## Guia Lógica - Guia Prolog

### Ejercicio 1 - Apellidos

Dada la siguiente base de datos de conocimentos:

```prolog
    padre(guillermo, rossi, walter).
    madre(beatriz, capusotto, walter).
    padre(guillermo, rossi, lucia).
    madre(beatriz, capusotto, lucia).
```

Responder (true):

```prolog
apellido(guillermo, rossi).
apellido(beatriz, capusotto).
apellido(walter, rossi).
apellido(lucia, rossi).
```

### Ejercicio 2 - Dada la siguiente base de conocimiento:

```prolog
    palabra(abalone,a,b,a,l,o,n,e).
    palabra(abandon,a,b,a,n,d,o,n).
    palabra(enhance,e,n,h,a,n,c,e).
    palabra(anagram,a,n,a,g,r,a,m).
    palabra(connect,c,o,n,n,e,c,t).
    palabra(elegant,e,l,e,g,a,n,t).
```

Se busca resolver el siguiente problema: Colocar las palabras de modo tal que se puedan ubicarlas en el siguiente tablero.
```
    |----+---+----+---+----+---+----+---|
    |    |   | V1 |   | V2 |   | V3 |   |
    |----+---+----+---+----+---+----+---|
    |    |   |    |   |    |   |    |   | 
    |----+---+----+---+----+---+----+---|
    | H1 |   |    |   |    |   |    |   |
    |----+---+----+---+----+---+----+---|
    |    |   |    |   |    |   |    |   |
    |----+---+----+---+----+---+----+---|
    | H2 |   |    |   |    |   |    |   |
    |----+---+----+---+----+---+----+---|
    |    |   |    |   |    |   |    |   |
    |----+---+----+---+----+---+----+---|
    | H3 |   |    |   |    |   |    |   |
    |----+---+----+---+----+---+----+---|
    |    |   |    |   |    |   |    |   | 
    |----+---+----+---+----+---+----+---|
```

* Ejercicio extraido desde "Learn Prolog Now! By: Patrick Blackburn, Johan Bos and Kristian Striegnitz"

### Ejercicio 3 - Hernamos

**NOTA**: Dos personas son hermanos si tienen un padre o madre en común
Dada la siguiente base de datos de conocimentos:

```prolog
    padre(guillermo, rossi, walter).
    padre(guillermo, rossi, lucia).
    padre(guillermo, rossi, camilla).

    madre(beatriz, capusotto, lucia).
    madre(beatriz, capusotto, walter).
    madre(beatriz, capusotto, rodolfo).
    madre(jimena, kaplan, camilla).
    madre(irma, jusid, raquel).
```

Responder:

1. ```hermanos(walter, lucia)``` (*true*)
2. ```hermanos(camilla, lucia)``` (*true*)
3. ```hermanos(raquel, camila)``` (*false*)

### Ejercicio 4 - Viajeros

Dada la siguiente base de datos de conocimentos:

```prolog
    enAuto(auckland,hamilton).
    enAuto(hamilton,raglan).
    enAuto(valmont,saarbruecken).
    enAuto(valmont,metz).

    enTren(metz,frankfurt).
    enTren(saarbruecken,frankfurt).
    enTren(metz,paris).
    enTren(saarbruecken,paris).

    enAvion(frankfurt,bangkok).
    enAvion(frankfurt,singapore).
    enAvion(paris,losAngeles).
    enAvion(bangkok,auckland).
    enAvion(singapore,auckland).
    enAvion(losAngeles,auckland).
```

Se necesita: Construir una regla llamada viajar/2 (recibe desde hasta) que responda si es posible llegar desde un lugar hacia otro, cualquiera sea el método de trasporte que utilicemos. Considerar combinaciones.

Responder:

1. ```viajar(valmont, auckland)``` (*true*)
2. ```viajar(auckland, raglan)``` (*true*)
3. ```viajar(valmont, metz)``` (*true*)
4. ```viajar(valmont, bsas)``` (*false*)


* Ejercicio extraido desde [swi-prolog](http://lpn.swi-prolog.org/lpnpage.php?pagetype=html&pageid=lpn-htmlse12)

### Ejercicio 5 - Miembro de Listas

Construir un predicado que devuelva *true* cuando un elemento está dentro de la lista.

### Ejercicio 6 - Reverso de lista

Construir un predicado que devuelva el reverso de la lista. [1,2,3] -> [3,2,1].

### Ejercicio 7 - Concatenar listas

Construir un predicado que devuelva la concatenación de dos listas.

### Ejercicio 8 - Palindromo

Tomando como definido el predicado revert/2 (que invierte el orden de los elementos de una lista), crear un predicado que sea verdad cuando la palabra parametro es un palindromo.

### Ejercicio 9 - 8 Reinas

Dado un tablero de ajedrez con 8 reinas ya ubicadas necesitamos saber si las 8 reinas estan posicionadas de manera que ninguna ataque a otra.

La siguiente configuración de tablero es válida:
```
    1   2   3   4   5   6   7   8
    |---+---+---+---+---+---+---+---|
  1 |   |   |   |   |   |   |   | R | 
    |---+---+---+---+---+---+---+---|
  2 |   |   |   | R |   |   |   |   | 
    |---+---+---+---+---+---+---+---|
  3 | R |   |   |   |   |   |   |   | 
    |---+---+---+---+---+---+---+---|
  4 |   |   | R |   |   |   |   |   |
    |---+---+---+---+---+---+---+---|
  5 |   |   |   |   |   | R |   |   |
    |---+---+---+---+---+---+---+---|
  6 |   | R |   |   |   |   |   |   |
    |---+---+---+---+---+---+---+---|
  7 |   |   |   |   |   |   | R |   |
    |---+---+---+---+---+---+---+---|
  8 |   |   |   |   | R |   |   |   |
    |---+---+---+---+---+---+---+---|
```

La siguiente configuración de tablero es **inválida**:

```
    1   2   3   4   5   6   7   8
    |---+---+---+---+---+---+---+---|
  1 | R |   |   |   |   |   |   |   | 
    |---+---+---+---+---+---+---+---|
  2 |   |   |   | R |   |   |   |   | 
    |---+---+---+---+---+---+---+---|
  3 | R |   |   |   |   |   |   |   | 
    |---+---+---+---+---+---+---+---|
  4 |   |   | R |   |   |   |   |   |
    |---+---+---+---+---+---+---+---|
  5 |   |   |   |   |   | R |   |   |
    |---+---+---+---+---+---+---+---|
  6 |   | R |   |   |   |   |   |   |
    |---+---+---+---+---+---+---+---|
  7 |   |   |   |   |   |   | R |   |
    |---+---+---+---+---+---+---+---|
  8 |   |   |   |   | R |   |   |   |
    |---+---+---+---+---+---+---+---|
```

La base de conocimiento que tenemos inicialmente es (tablero válido):

```prolog
    tablero([q(3,1), q(6,2), q(4,3), q(2,4), q(8,5), q(5,6), q(7,7), q(1,8)]).
```
