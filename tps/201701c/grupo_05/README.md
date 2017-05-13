# Grupo 05

## Integrantes

* Guido Contreras
* Teresa Alberto

## Entregas

### Primera entrega

**Desaprobado**

1. No corre completamente.
2. Definir un TDA que sea lista enlazada.
3. El ```collection_eliminar``` es un complejo.  Hace muchas cosas, encontrar y eliminar. Devidir estas tareas en varias primitivas.

Esto es lo que me ocurre cuando lo ejecuto:

```
$ ./g5
Dato de Nodo: 1
Dato de Nodo: 2
Segmentation fault: 11
$
```

Respecto a definir un TDA, parece que la collección utiliza una lista doblemente enlazada. Esto implica que desde colección no podes acceder a los miembros del TDA NODO esto debe quedar oculto (algo similar al encapsulamiento).

Fijensé que en eliminar: 

```c
Coleccion* coleccion_eliminar(Coleccion* coleccion, void* elemento){
	Nodo* aEliminar = coleccion_localizar(coleccion, elemento);

	if (aEliminar !=NULL){

		//Eliminar Nodo inicial
		if (memcmp(aEliminar, coleccion->inicio, coleccion->tam_elemento)==0){
			Nodo* nuevo_inicio = aEliminar->sig;
			coleccion->inicio=nuevo_inicio;

			nodo_liberar_dato(aEliminar);
			free(aEliminar);
		}
```

Porqué comparan el ```aEliminar```, ```coleccion->inicio``` con memcmp? Son punteros! Utilicen ```==```.
