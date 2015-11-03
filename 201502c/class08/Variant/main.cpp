#include <iostream>

using namespace std;

/****
* Implementar una clase que permita guardar cualquier dato primitivo de C++.
*
* Se pide:
* 1.- Proveer un constructor para cada uno de los tipos nativos en C++
* 2.- Método mediante el cual pueda obtenerse el valor almacenado.
* 3.- Ḿétodo para cambiar el valor del dato almacenado.
* 4.- Los variants se pueden asignar entre si.
*
* Restricciones:
*  - No se puede utilizar la palabra reservada switch.
*
* En todos los casos debe manejarse la memoria de manera apropiada según los critérios que
* vimos durante la cursada.
*/


int main()
{
    //  Pequeñon ejempo
    Variant unEntero(2);
    Variant unString("12345");

    unString.valor(2.1);    // Ahora tiene un flotante

    float f;
    unString.obtenerValor(f);   // Luego de esto f tiene el valor 2.1

    unString = unEntero;
    int i;
    unString.obtenerValor(i);   //  Ahora i tiene valor 2

    return 0;
}
