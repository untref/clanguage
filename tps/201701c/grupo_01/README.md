# Grupo 01

## Integrantes

* ROCHA JORGE ANDRES
* ABADIE IGNACIO JULIAN

## Entregas

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
