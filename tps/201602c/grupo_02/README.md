# Grupo 02

## Integrantes

* BISCARDI, MAXIMILIANO FERNANDO
* ECHEGARAY, SIERRA ROCIO LUJAN

## Entregas

### Aprobada  entrega 

**Aprobada** 

NOTA: 5

1. No puedo comprimir y descomprimir:

```sh
<host> <user>$ ./c -c "MAURICIO MACRI ES PRESIDENTE DE LOS ARGENTINOS" -o f.c
Comprimir a 'f.c'...

Caracter R. Codificacion: 0000
Caracter S. Codificacion: 0001
Caracter C. Codificacion: 00100
Caracter D. Codificacion: 00101
Caracter A. Codificacion: 0011
Caracter E. Codificacion: 010
Caracter  . Codificacion: 011
Caracter N. Codificacion: 1000
Caracter O. Codificacion: 1001
Caracter I. Codificacion: 101
Caracter U. Codificacion: 11000
Caracter L. Codificacion: 11001
Caracter G. Codificacion: 11010
Caracter P. Codificacion: 11011
Caracter M. Codificacion: 1110
Caracter T. Codificacion: 1111

 Resultado: 3   (distinto de 0 es exitoso)
<host> <user>$ ./c -d -f f.c
Descomprimiendo..

```

2. Al intentar comprimir el siguiente texto (error):

```sh
<host> <user>$ ./c -c 'Lorem ipsum dolor sit amet, consectetur adipiscing elit. In non libero ante. Curabitur ornare nibh arcu, in gravida felis ultricies vitae. Ut vitae sem ullamcorper nunc tincidunt cursus sit amet non ante. Duis convallis mauris ac dolor tempor, sed vehicula lacus viverra. Morbi ultricies rhoncus urna non condimentum. Maecenas egestas sit amet turpis a finibus. Aliquam et ultrices nunc, vitae molestie velit. Morbi congue sodales dui eu fermentum. Sed ornare ex at libero pellentesque, vel ornare eros efficitur. Phasellus in magna purus. Praesent iaculis molestie congue'
Comprimir:
Caracter b. Codificacion: 0000000
Caracter P. Codificacion: 000000100
Caracter q. Codificacion: 000000101
Caracter M. Codificacion: 00000011
Caracter .. Codificacion: 000001
Caracter c. Codificacion: 00001
Caracter i. Codificacion: 0001
Caracter  . Codificacion: 001
Caracter g. Codificacion: 0100000
Caracter f. Codificacion: 0100001
Caracter v. Codificacion: 010001
Caracter d. Codificacion: 010010
Caracter ,. Codificacion: 0100110
Caracter h. Codificacion: 0100111
Caracter a. Codificacion: 0101
Caracter r. Codificacion: 0110
Caracter n. Codificacion: 0111
Caracter s. Codificacion: 1000
Caracter u. Codificacion: 1001
Caracter t. Codificacion: 1010
Caracter m. Codificacion: 10110
Caracter x. Codificacion: 101110000
Caracter D. Codificacion: 101110001
Caracter C. Codificacion: 101110010
Caracter L. Codificacion: 101110011
Caracter I. Codificacion: 101110100
Caracter U. Codificacion: 101110101
Caracter A. Codificacion: 101110110
Caracter S. Codificacion: 101110111
Caracter p. Codificacion: 101111
Caracter e. Codificacion: 110
Caracter o. Codificacion: 1110
Caracter l. Codificacion: 1111
c(2144,0x7fff7b2f1300) malloc: *** error for object 0x7fba29c05e88: incorrect checksum for freed object - object was probably modified after being freed.
*** set a breakpoint in malloc_error_break to debug
Abort trap: 6
```
### Segunda entrega 

**Desaprobada**

1. Falta la primera entrega (lectura de parámetros).
2. CodigoHuffman.c:42. Vimos que para alocar un array de esta característica necesitamos utilizar ```malloc```.
3. Estan creando un node para cada uno de los caracteres del array (por más que estén duplicados)
4. No implementaron el árbol binario.

### Primera entrega

**Desaprobada**

Entiendo que Uds. son los integrantes que se separaron. Más allá de que el main está incompleto, las razones por la cuál la entrega está desaprobada son las siguientes:

[Ver link](https://github.com/untref/clanguage/tree/master/tps/201602c/grupo_01)
