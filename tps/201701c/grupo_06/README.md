# Grupo 06

## Integrantes

* PIRRO LUCIANO ANDRES
* FIORITO HERNAN DARIO
* SANDE BERTUZZI FERNANDO HERNAN

## Entregas

### Cuarta entrega

**Aprobado (10)**

### Tercera entrega

**Aprobado**

```
main.c:9:39: warning: illegal character encoding in string literal [-Winvalid-source-encoding]
                printf("Test inicializacion/liberaci<F3>n de una Coleccion\n");
                                                    ^~~~
main.c:15:37: warning: illegal character encoding in string literal [-Winvalid-source-encoding]
                printf("Test iteracion con impresi<F3>n de una Colecci<F3>n de enteros:\n");
                                                  ^~~~                ~~~~
main.c:23:37: warning: illegal character encoding in string literal [-Winvalid-source-encoding]
                printf("Test iteracion con impresi<F3>n de una Colecci<F3>n de flotantes:\n");
                                                  ^~~~                ~~~~
main.c:31:37: warning: illegal character encoding in string literal [-Winvalid-source-encoding]
                printf("Test iteracion con impresi<F3>n de una Colecci<F3>n de caracteres:\n");
                                                  ^~~~                ~~~~
main.c:39:54: warning: illegal character encoding in string literal [-Winvalid-source-encoding]
                printf("Test agregar un elemento (15) a una Colecci<F3>n:\n");
                                                                   ^~~~
main.c:49:53: warning: illegal character encoding in string literal [-Winvalid-source-encoding]
                printf("Test buscar un elemento (6) en una Colecci<F3>n\n");
                                                                  ^~~~
main.c:57:52: warning: illegal character encoding in string literal [-Winvalid-source-encoding]
                printf("Test quitar un elemento (6) a una Colecci<F3>n:\n");
                                                                 ^~~~
main.c:80:49: warning: illegal character encoding in string literal [-Winvalid-source-encoding]
                printf("Test colectar elementos en una colecci<F3>n (elevar al cuadrado):\n");
                                                              ^~~~
main.c:102:45: warning: illegal character encoding in string literal [-Winvalid-source-encoding]
                printf("Test reducir a derecha una colecci<F3>n:\n");
                                                          ^~~~
main.c:111:47: warning: illegal character encoding in string literal [-Winvalid-source-encoding]
                printf("Test reducir a izquierda una colecci<F3>n (con valor inicial previo):\n");
                                                            ^~~~
10 warnings generated.
```

Prestar atencion a los warnings y corregirlos.

### Segunda entrega

**Desaprobada**

#### corrida

Al ejecutar el código obtengo la siguiente salida:

```
:src dsanchez$ ./a.out

Agregar elemento en colecci�n:
a.out(54797,0x7fff70f3f000) malloc: *** error for object 0x7fff591887c0: pointer being freed was not allocated
*** set a breakpoint in malloc_error_break to debug
1 2 3 5 6 1 Abort trap: 6
:src dsanchez$
```

La causa del error es el free del this:

```c

void colection_free(Coleccion* this){
	if(this->elementos){
		free(this->elementos);
	}
	free(this);
}

```
#### Acerca del código

##### main

```c
#include "Coleccion.h"

void colection_init(Coleccion* this, void* lista_valores, unsigned tamanio_dato, unsigned cantidad_elementos);
void colection_free(Coleccion* this);
Coleccion* colection_add(Coleccion* this, void* elemento);
Coleccion* colection_remove(Coleccion* this, void* elemento);
void* colection_find(Coleccion* this, void* elemento);

void colection_select(Coleccion* this, Coleccion* dst, int (*criterio_seleccion)(void*));

void colection_iterate(Coleccion* this, void (*funcion_imprimir)(void*));
void imprimir_char(void* valor);
void imprimir_enteros(void* valor);
void imprimir_decimales(void* valor);


void colection_colect(Coleccion* this, Coleccion* dst, void (*funcion)(void*));

int main(int argc, char** argv) {
```

Quitar estas declaraciones del main.  No tienen sentido aquí.

```c 
	int entero_quitar_N = 9;
/*
	printf("Crear colección: \n");
	{
    	Coleccion c;
    	colection_init(&c, &enteros1 ,sizeof(int), sizeof(enteros1)/sizeof(int));
    	colection_free(&c);
	}
*/
```
Código comentado, va a no va? Si no va, eliminarlo.

```c 
    printf("\nEncontrar elemento NO existente de la coleccion: \n");
    {
    Coleccion c;
    colection_init(&c, &enteros1, sizeof(int), sizeof(enteros1)/ sizeof(int));
    int* resultado = colection_find(&c, &entero_quitar_N);
    printf("%p \n", resultado);
    colection_free(&c);
    }

```
Para imprimir el valor de un puntero utilizar `%p` en lugar de `%d`.


##### collection.c

Eliminar código comentado.





### Primera entrega

**Aprobado**

### array de void
No es necesario crear un array de ```void*```. Porqué no un array de datos tamaño ```tamanio_elemento```.

### coleccion_quitar hace dos cosas

Esta primitiva búsca el elemento y luego lo quita de la colección. Esto no está bueno. Generar una primitiva para encontrar y otra para remover.

### Respectar los nombres de las primitivas

El TDA tienen nombres de primitivas específicas que están en el enunciado.  Respetar.
