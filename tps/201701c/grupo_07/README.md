# Grupo 07

## Integrantes

* MARTINEZ SERVENTI DELFINA
* NEVADO LUCAS
## Entregas

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

