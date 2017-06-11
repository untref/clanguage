# Grupo 07

## Integrantes

* MARTINEZ SERVENTI DELFINA
* NEVADO LUCAS
## Entregas

### Tercer entrega

**Aprobado**

Tratando de compilar el TP aparecen varios warnings.  Entiendo que los están ignorando.  En vistas del problema que tienen debería eliminar los warnings.

```
Collection.c:8:2: warning: implicitly declaring library function 'memset' with type 'void *(void *, int, unsigned long)' [-Wimplicit-function-declaration]
        memset(this, 0x0, sizeof(Collection));
        ^
Collection.c:8:2: note: include the header <string.h> or explicitly provide a declaration for 'memset'
Collection.c:12:2: warning: implicitly declaring library function 'memcpy' with type 'void *(void *, const void *, unsigned long)'
      [-Wimplicit-function-declaration]
        memcpy(this->vector, valores, cantidad*tam_tipo);
        ^
Collection.c:12:2: note: include the header <string.h> or explicitly provide a declaration for 'memcpy'
Collection.c:63:7: warning: implicitly declaring library function 'memcmp' with type 'int (const void *, const void *, unsigned long)'
      [-Wimplicit-function-declaration]
                if(!memcmp(actual, valor, this->tam_tipo)){
                    ^
Collection.c:63:7: note: include the header <string.h> or explicitly provide a declaration for 'memcmp'
Collection.c:112:19: warning: format specifies type 'char *' but the argument has type 'char' [-Wformat]
    printf("%s ", *ps);
            ~~    ^~~
            %c
Collection.c:133:19: warning: incompatible pointer types passing 'char **' to parameter of type 'Collection *' (aka 'struct _collection *')
      [-Wincompatible-pointer-types]
                        collection_add(&dst->vector, actual);
                                       ^~~~~~~~~~~~
Collection.c:28:40: note: passing argument to parameter 'this' here
Collection* collection_add(Collection* this, void* valor){
                                       ^
Collection.c:147:19: warning: incompatible pointer types passing 'char **' to parameter of type 'Collection *' (aka 'struct _collection *')
      [-Wincompatible-pointer-types]
                        collection_add(&dst->vector, valor_aux);
                                       ^~~~~~~~~~~~
Collection.c:28:40: note: passing argument to parameter 'this' here
Collection* collection_add(Collection* this, void* valor){
                                       ^
6 warnings generated.
main_collection.c:35:46: warning: incompatible pointer types passing 'int *' to parameter of type 'char *' [-Wincompatible-pointer-types]
                int* encontrado = collection_find(&vector, &valor);
                                                           ^~~~~~
./Collection.h:69:47: note: passing argument to parameter 'valor' here
void* collection_find(Collection* this, char* valor);
                                              ^
main_collection.c:53:30: warning: incompatible pointer types passing 'int *' to parameter of type 'char *' [-Wincompatible-pointer-types]
                collection_remove(&vector, &valor);
                                           ^~~~~~
./Collection.h:51:55: note: passing argument to parameter 'valor' here
Collection* collection_remove(Collection* this, char* valor);
                                                      ^
main_collection.c:80:39: warning: incompatible pointer types passing 'int *(*)(void *)' to parameter of type 'void *(*)(void *)'
      [-Wincompatible-pointer-types]
                collection_collect(&vector,&destino,&multiplicarPor10);
                                                    ^~~~~~~~~~~~~~~~~
./Collection.h:89:68: note: passing argument to parameter 'doIt' here
void collection_collect(Collection* this, Collection* dst, void* (*doIt)(void*));
                                                                   ^
main_collection.c:105:32: warning: incompatible pointer types passing 'int *(*)(void *, void *)' to parameter of type 'void *(*)(void *, void *)'
      [-Wincompatible-pointer-types]
                collection_reduceL(&vector2, &sumar, resultado2);
                                             ^~~~~~
./Collection.h:118:51: note: passing argument to parameter 'doIt' here
void collection_reduceL(Collection* this, void* (*doIt)(void*, void*), void* result);
                                                  ^
4 warnings generated.

``` 

Viendo el código del main:

```c
		//ReducirL
		Collection vector2;
		int valores2[] = {1,1,2,5,3,4};
		collection_init(&vector2, valores2, sizeof(valores2)/sizeof(valores2[0]), sizeof(valores2[0]));
		char* resultado2;
		collection_reduceL(&vector2, &sumar, resultado2);
		printf("%d", *resultado2);
		printf("\n\n");
		collection_free(&vector2);
```

Están almacenando en ```resultado2``` un entero pero ```resultado2``` es un puntero inválido. Falta este detalle: 



```c
	{
		//ReducirL
		Collection vector2;
		int valores2[] = {1,1,2,5,3,4};
		collection_init(&vector2, valores2, sizeof(valores2)/sizeof(valores2[0]), sizeof(valores2[0]));
		int resultado2;
		collection_reduceL(&vector2, &sumar, &resultado2);
		printf("%d", *resultado2);
		printf("\n\n");
		collection_free(&vector2);
	}
```

### Segunda entrega

**Aprobado**

#### Select

```c
void collection_select(Collection* this, Collection* dst, int (*doIt)(void*)){

	char* actual = this->vector;
	unsigned cantidad = this->cantidad;
	dst->vector = malloc(this->tam_tipo*this->cantidad);
	dst->tam_tipo = this->tam_tipo;
	dst->cantidad = 0;

	int tamanio = 0;
	while(cantidad--){
		if((*doIt)(actual)){
			memcpy(dst->vector + tamanio,actual,this->tam_tipo);
			tamanio += this->tam_tipo;
			dst->cantidad++;
		}
		actual += this->tam_tipo;
	}

}

```

No acceder a los atributos de un TDA sino a través de sus primitivas! En lugar de hacer la manipulación que hacen de ```dst``` creen una primitiva que inicialice la colección sin elementos. Luego dentro del ```while``` si han encontrado un elemento utilicen la primitiva ```add``` en lugar de manipular los miembros del TDA.


Agregar la documentación de las primitivas en el ```.h```  en lugar de agregarla en el ```.c```.  Recuerden que lo que se distribuye en la librería ```.a``` o ```.so```  y los ```.h``` pero no los ```.c```.


### Primera entrega

**Aprobado**

