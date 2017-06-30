# ~~Grupo 01~~

## Integrantes

* ROCHA JORGE ANDRES
* ABADIE IGNACIO JULIAN
* PEÑA LUCIANO FACUNDO MANUEL

## Entregas

### Cuarta entrega

**Aprobado (9)** 

- Hay ejemplos que no cuentan con el collection_free.


### Tercera entrega

**Desaprobado** 

Tiene problemas de memoria.

```
8.800000
11.000000
---------------
Test collection_filter :
Segmentation fault: 11
``` 

Redefinir reducir a [derecha](https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/Array/ReduceRight?v=example) y a [izquierda](https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/Array/reduce?v=example).

### Segunda entrega

**Aprobado** 

No lo pude compilar!

```
main.c:81:33: error: function definition is not allowed here
                void duplicate(void* pointer) {
                                              ^
main.c:90:36: error: use of undeclared identifier 'duplicate'
                collection_iterate(&collection, &duplicate);
                                                 ^
main.c:119:28: error: function definition is not allowed here
                int filter(void* pointer){
                                         ^
main.c:134:49: error: use of undeclared identifier 'filter'
                collection_select(&collection, &collection2, &filter);
                                                              ^
main.c:146:37: error: function definition is not allowed here
                void applyFunction(void* pointer) {
                                                  ^
main.c:155:50: error: use of undeclared identifier 'applyFunction'
                collection_collect(&collection, &collection2, &applyFunction);
```

> NOTA: Atender a los warnings de la compilación.

```c 
unsigned conditionalMemCpy(void* pointer1, void* pointer2, unsigned elementCount, unsigned size, int (*filter)(void*)){
	unsigned count = 0;
	while(elementCount--) {
		if((*filter)(pointer1) == 1){
			memcpy(pointer2, pointer1, size);
			pointer1+= size;
			pointer2+= size;
			count++;
		}else {
			pointer1+= size;
		}
	}
	return count;
}

``` 

Agregar comentarios a este código.

En pos de la simplicidad, que pasa si la primitiva select lo que haces es inicializar la colección ```dst``` y si el filtro le da ok agrega elemento utilizando la primitiva add? 

```c
Collection* collection_collect(Collection* this, Collection* dst, void (*function)(void*)) {
	void* memPointer = (char*)malloc(this->size);
	memcpy(memPointer, this->list, this->size);
	collection_init(dst, memPointer, this->size, this->typeSize);
	collection_iterate(dst, function);
	free(memPointer);
	return dst;
}
```

Es necesario hacer este malloc? Porqué?

### Primera entrega

**Aprobado**

1. No se podía compilar el programa

```
main.c:38:31: warning: incompatible pointer types passing 'double *' to parameter of type 'char *' [-Wincompatible-pointer-types]
                collection_add(&collection, pointerElement);
                                            ^~~~~~~~~~~~~~
./Collection.h:15:52: note: passing argument to parameter 'element' here
Collection* collection_add(Collection* this, char* element);
                                                   ^
main.c:52:34: warning: incompatible pointer types passing 'double *' to parameter of type 'char *' [-Wincompatible-pointer-types]
                collection_remove(&collection, removePointerElement);
                                               ^~~~~~~~~~~~~~~~~~~~
./Collection.h:17:55: note: passing argument to parameter 'element' here
Collection* collection_remove(Collection* this, char* element);
                                                      ^
main.c:61:35: error: function definition is not allowed here
                void showElement(void* pointer) {
                                                ^
main.c:66:33: error: function definition is not allowed here
                void duplicate(void* pointer) {
                                              ^
main.c:74:36: error: use of undeclared identifier 'duplicate'
                collection_iterate(&collection, &duplicate);
```
2. La primitiva ```collection_free``` hace el free siempre.  Hacerlo solo sí el puntero ```this->list``` es no nulo.
3. Este código es defícil! ```collection_remove```. Simplificarlo! Esta primitiva hace más de una cosa, busca y remueve.  Hacete una primitiva para buscar, una vez que encontraste el elemento solo tenes que hacer el shift a izq (o desplazamiento a la izquierda) de todos los elementos para pisar este valor.  Y por último reducir el tamaño del vector. 
