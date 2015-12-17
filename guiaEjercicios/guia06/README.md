## Guia 06 - C++

### Ejercicio 1

Implementar un numero complejo con el siguiente contrato:

1. Dos instancias se pueden sumar
2. Dos instancias se pueden restar
3. Una instancia puede multiplicarse por un escalar
4. Una instancias puede normalizarse
5. Dos instancias pueden multiplicarse y el resultado es el producto escalar
6. Debe responder al mensaje ```toString``` el cual recibirá como parámetro un ```const char*``` donde se va a almacenar el str.

### Ejercicio 2

Se necesita definir una clase Variant que permitirá almacenar cualquier dato primitivo del lenguaje C++ (bool, unisgned, int, float, double, long long, etc) uno por vez, es decir, o almacena un int o un float o un double o etc.. Esta clase debe brindar como mínimo la siguiente funcionalidad:

1. Proveer un constructor para cada uno de los tipos nativos en C++.
2. Método mediante el cual pueda obtenerse el valor almacenado en formato primitivo, es decir, un método para devolver el valor int o double o etc. Aclaración: No necesitan validar que el dato almacenado sea el que el usuario espera recuperar. Si el usuario almacenó un entero y luego recupera un float, problema del usuario.
3. Ḿétodo para cambiar el valor del dato almacenado.
4. Tener en cuenta que los variants se pueden asignar entre si.
5. Que se pueda pasar por parámetro de una función o método por valor o referencia.
6. Que se puedan asignar dos instancias manteniendo la independencia entre ambos.
7. Evitando duplicar código.
8. La clase debe administrar la memoria de forma tal que no hay goteo de memoria.

### Ejercicio 3

Se necesita definir una clase Vector (colección de n numeros) que brinde la siguiente funcionalidad:

1. Que se pueda sumar un vector con otro
2. Que se pueda restar un vector con otro
3. Que se pueda multiplicar por un escalar
4. Que se pueda normalizar
5. Que se puedan asignar dos instancias manteniendo la independencia entre ambos.
6. Que se pueda pasar como parámetro por valor y por referencia a otra función.
7. Que se pueda hacer producto escalar
8. Evitando duplicar código.
9. La clase debe administrar la memoria de forma tal que no hay goteo de memoria.
10. NO utilizar el operador [ ].

### Ejercicio 4

Se necesita definir una clase PaqueteBits (conjunto de n bits) que brinde la siguiente funcionalidad:

1. Poder negar el paquete de bits.
2. Poder encender un bit en particular del paquete de bits.
3. Poder apagar un bit en particular del paquete de bits.
4. Hacer un shift a izquierda o derecha del paquete de bits.
5. Poder invertir un bit del paquete de bits.
6. Que responda true o false si un conjunto de bits dados como parámetro (mascara) están todos encendidos.
7. Que se pueda pasar por parámetro de una función o método por valor o referencia.
8. Que se puedan asignar dos instancias manteniendo la independencia entre ambos.
9. Evitando duplicar código.
10. La clase debe administrar la memoria de forma tal que no hay goteo de memoria.
