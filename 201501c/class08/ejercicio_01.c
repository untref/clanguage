#include <stdio.h>
#include <string.h>

int main(int argc, char** argv) {
    // Ejercicio 1
    // Convertir los siguientes numeros en formato
    // little endian -> big endian
    unsigned long long longLongInt = 0x0102030405060708;
    unsigned long longInt = 0x01020304;


    printf("Long value: 0x%lx \n", longInt ); 
    printf("Long Long value: 0x%llx \n", longLongInt ); 


    // Ejercicio 2
    // Como puedo saber si en la plataforma donde estoy
    // ejecutando este programa almacena enteros en
    // little or bitendian?

    // Ejercicio 3 - registro de estados de 16 bit intel 8086, 8088
    // El registro de estado de estos procesadores un un registro de
    // 16 bits estructurado de la siguiente manera:
    //
    //  b   b   b   b   b   b   b   b   b   b   b   b   b   b   b   b
    //  i   i   i   i   i   i   i   i   i   i   i   i   i   i   i   i
    //  t   t   t   t   t   t   t   t   t   t   t   t   t   t   t   t
    //                                                               
    //  1   1   1   1   1   1   0   0   0   0   0   0   0   0   0   0
    //  5   4   3   2   1   0   9   8   7   6   5   4   3   2   1   0
    //                                                               
    //  -   -   -   -   O   D   I   T   S   Z   -   A   -   P   -   C
    //                  F   F   F   F   F   F       F       F       F
    //
    // Aqui la descripcion de los campos:
    // http://es.wikipedia.org/wiki/Intel_8086_y_8088#Registros_de_Banderas
    //
    //
    // 1) Ver si esta prendido el registro de overflow (OF)
    // 
    // 2) Encender con una sola instruccion los registros birs DF & IF
    //
    // 3) Definir una mascara q nos permita saber si CF y PF estan encendidos (ambos)?
    //
    // 4) Con la mascara anterior encender ambos bits
    //
    // 5) Prender y apagar sucesivamente el bit ZF (toggle).
    // 
    // 6) Encender todos los bits del registro.
    
}
