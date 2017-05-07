## Guia Bits

### Ejercicio 1

Dado dos paquetes de bits (de un tipo a elección) se busca copiar un número arbitrario de bits del paquete ```src``` al paquete ```dst```

NOTA: Arbitrario siginifica que podría copiar ```[0, 2, 4]``` o ```[0, 2, 4, 5, 9]``` y el número de bits es arbitrario.


### Ejercicio 2

Dado el ```paqueteA``` y ```paqueteB``` (de un tipo a elección) buscamos apagar aquellos bits del paquete A que estén encendidos en el paquete B.


### Ejercicio 3

Dado el ```paquete``` rotar su contenido a izquierda ```n``` bits.

Ejemplo:

paquete: 1000100011110101

Si lo roto a la izquierda 5 bits obtendré:

paquete: 0001111010110001

NOTA: Esto no es equivalente hacer un shift. 


### Ejercicio 4

Dado un paquete de 32 bits definir y declarar una función para invertir el orden de sus bytes (la función debe utilizar operaciones con bits).  

Ejemplo:

Dado el siguiente paquete:

paquete = [b0, b1, b2, b3];

Luego de invertir sus bytes debería quedar:

paquete = [b3, b2, b1, b0];




