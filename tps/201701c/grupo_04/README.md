# Grupo 04

## Integrantes

* GHIO NAHUEL SEBASTIÁN
* NICOLLIER FEDERICO NUMAS

## Entregas

### Tercera Entrega

**Desaprobado**

No han implementado la reducción.

Redefinir reducir a (derecha)[https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/Array/ReduceRight?v=example] y a (izquierda)[https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/Array/reduce?v=example].

### Segunda entrega

**Desaprobado**

Para hacer la entrega, enviar un mail con un paquete (zip, tar, rar) que contenga todos los archivos de la entrega. 

```c
Collection* collection_remove(Collection* this, void* remove){
	void* i = collection_find(this,remove);

	if(i != 0x0){
		void* nuevo = malloc(this->elementos * this->volDato - this->volDato);
		char* n = nuevo;
		char* q = this->array;
		while(q != i){
			memcpy(n,q,this->volDato);
			n += this->volDato;
			q += this->volDato;
		}
		q += this->volDato;
		while(q != (this->array + (this->elementos * this->volDato))){
			memcpy(n,q,this->volDato);
			n += this->volDato;
			q += this->volDato;
		}
		free(this->array);
		this->elementos --;
		this->array = nuevo;
		return this->array;
	}else{
		printf("No se encontro el elemento para remover de la Coleccion\n");
		return 0;
	}
}

```

Cuando escribimos un código críptico como este lo acompañamos con comentarios.  Cuál es la intención dentrás de este código?

No encuentro el ```collect``` ni el ```select```.  Asegurarse de estar viendo la última versión del enunciado.


### Primera entrega

**Aprobado**

2. El ```collection_remove``` es un complejo.  Hace muchas cosas, encontrar y eliminar. Devidir estas tareas en varias primitivas.

