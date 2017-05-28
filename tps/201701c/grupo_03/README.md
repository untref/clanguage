# Grupo 03

## Integrantes

* Álvarez Felipe
* Bosio Gabriel
* ROMBOLA GUIDO IGNACIO

## Entregas

### Segunda entrega

**Aprobada**

```c
Collection* collection_remove(Collection* this, void* dato) {
    Node* encontrado = collection_find_node(this, dato);

    if (encontrado) {

		if (encontrado->anterior) {
			encontrado->anterior->siguiente = encontrado->siguiente;

			if (encontrado->siguiente) {
				encontrado->siguiente->anterior = encontrado->anterior;
			}

		} else {
			this->inicio = encontrado->siguiente;
		}

		if (this->final == encontrado) {
			this->final = encontrado->anterior;
		}

		node_liberar(encontrado);
		this->cantidadElementos--;
	}

    return this;
}

``` 

Si Uds. definieron un TDA Nodo, es responsabilidad de este manejar el siguiente y el anterior y **no** de la colección.
### Primera entrega

**Aprobado**

1. Falta el liberar memoria de la collección
2. El ```collection_remove``` es un complejo.  Hace muchas cosas, encontrar y eliminar. Devidir estas tareas en varias primitivas.

