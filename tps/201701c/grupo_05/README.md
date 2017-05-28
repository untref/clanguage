# Grupo 05

## Integrantes

* Guido Contreras
* Teresa Alberto

## Entregas

### Segunda entrega

**Aprobado**

Modificar los nombres de las primitivas para que coincidan con las del enunciado del TP.

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

### No funciona (es correcta la corrección)

Luego de varias horas de debug :( creo haber encontrado el problema:

```c
Coleccion* coleccion_inicializar(Coleccion* coleccion, void* elementos, unsigned cantidadElem, unsigned tamElem){
	coleccion_inicializar_vacia(coleccion, tamElem);

	coleccion->tam_coleccion=cantidadElem;
	coleccion->tam_elemento=tamElem;
	void* actual= elementos;

	//Crea primer nodo
	Nodo* nodo = nodo_crear(actual, tamElem);
	coleccion->inicio=nodo;
	nodo->ant=PRIMER_NODO;
	cantidadElem--;

	while((cantidadElem)){
		actual+=tamElem;

		if (cantidadElem!=1){
			//No es último Nodo
			nodo->sig = nodo_crear(actual, tamElem);
			nodo->sig->ant=nodo;
		}else{
			//Es último nodo
			nodo->sig = nodo_crear(actual, tamElem);
			nodo->sig->ant=nodo;
			coleccion->fin=nodo->sig;
		}
		cantidadElem--;
		nodo = nodo->sig;
	}
	return coleccion;
}
```

Nunca configuran el siguiente del último nodo!  Esto se ve fácil para una collección con un único elemento.

