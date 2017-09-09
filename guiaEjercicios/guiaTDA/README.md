## Guia 04 - TDA

### Ejercicio 1

Definir el TDA Nave con la siguiente declaración:

```c
#ifndef NAVE_H_INCLUDED
#define NAVE_H_INCLUDED
    
#define NAVE_NOMBRE_LARGO 1024

typedef struct _Nave {
int vida;
char nombre[NAVE_NOMBRE_LARGO];
} Nave;

/**
*/
void nave_init(Nave* this, const char* nombre);
void nave_daniar(Nave* this, int danio);
void nave_print(Nave* this);

#endif // NAVE_H_INCLUDED
```

### Ejercicio 2

Definir el TDA Cadena con la siguiente declaración teniendo en cuenta los siguientes lineamientos:
1. Completar la definición del TDA según resulte necesario.
2. Definir las siguientes primitivas del TDA *sin modificar su firma* (ver debajo).
3. Liberar todos los recursos que se hayan alocado (antes de que el programa termine su ejecución).
4. Escriba un main en el cual se muestre como se utiliza el TDA, creando para esto un TDA cadena con caracteres no imprimibles.

```c
#ifndef CADENA_H_INCLUDED
#define CADENA_H_INCLUDED

typedef struct _Cadena {
char* datos;
unsigned cantidad;
} Cadena;

void cadena_init(Cadena* this, const char* dato, unsigned largo);
void cadena_liberar(Cadena* this);

/***
* Modifica la cadena de caracteres alacenada por la cadena
*
* @param cadena: El TDA cadena que voy a modificar
* @param data:   La cadena datos que utilizo para cambiar el valor
*                del TDA
*
* @return  cadena modificada (la misma que recibe)
*/
Cadena* cadena_modificar(Cadena* this, const char* dato);

/***
* Concatenar un contenido a una cadena
*
* @param cadena: El TDA cadena que voy a modificar
* @param data:   La cadena datos que utilizo para cambiar el valor
*                del TDA
*
* @return  cadena modificada (la misma que recibe)
*/
Cadena* cadena_concatenar(Cadena* this, const char* dato);

void cadena_print(Cadena* this);
#endif // CADENA_H_INCLUDED
```

### Ejercicio 3

Definir el TDA Dupla con la siguiente declaración teniendo en cuenta los siguientes lineamientos:
1. Completar la definición del TDA según resulte necesario.
2. Definir las siguientes primitivas del TDA *sin modificar su firma* (ver debajo).
3. Liberar todos los recursos que se hayan alocado (antes de que el programa termine su ejecución).
4. Escriba un main en el cual se muestre como se utiliza el TDA, creando para esto un TDA Dupla que almacene un entero y luego un double.

```c
#ifndef DUPLA_H_INCLUDED
#define DUPLA_H_INCLUDED

typedef struct _Dupla {
    char* clave;
    void* dato;
} Dupla;

void dupla_init(Dupla* this, const char* nombre, void* dato, unsigned longitud_dato);
void dupla_liberar(Dupla* this);

/***
* Modifica la clave de la dupla
*
* @param  this: Dupla
* @param clave: La nueva clave de la dupla
*
* @return 'this' modificada (la misma que recibe)
*/
Dupla* dupla_modificar(Dupla* this, const char* dato);

/***
* Almacena un dato en la tupla
*
* @param           this: Dupla
* @param          valor: Valor que quiero almacenar
* @param longitud_valor: Longitud del valor a almacenar
*
* @return 'this' modificada (la misma que recibe)
*/
Dupla* dupla_valor(Dupla* this, void* valor, unsigned longitud_valor);

#endif // DUPLA_H_INCLUDED
```


### Ejercicio 4

Definir el TDA Variant que permita almacenar cualquier tipo de dato dentro de sí mismo, proveyendo la siguiente funcionalidad:
1. Inicialización de estructura
2. Liberación de recursos alocados.
3. Almacenar un número float, double, unsigned, int, etc.
4. Almacenar un string.
5. Copiar datos entre variants.
6. Aplicar una función al variant y que esta función aplicada devuelva otro variant como valor. 

```c
#ifndef __VARIANT_H__
#define __VARIANT_H__

    typedef struct Variant {
      void* data;             // Datos contenidos por el variant
      unsigned count;         // Cantidad de elementos contenidos por el variant
      unsigned dataSize;      // Cantidad de de bytes apuntados por data
    } Variant;


    /****
     * Dado un puntero a variant inicializo la estructrua
     */
    void initialize(Variant* );

    /***
     * Dado un puntero a variant libero memoria (si es que está
     * utilizando)
     *
     * @precondicion  La estructura variant esta inicializada
     */
    void release(Variant*);

    /***
     * Set datos almacenados por el variant
     *
     * @param v       Variant que quiero configurar
     *
     * @precondicion  La estructura variant esta inicializada
     */
    void set( Variant*, ...);


    /***
     * Descargo un entero como si el variant tuviera almacenado 
     * un entero
     *
     * @param v       Variant que quiero configurar
     *
     * @precondicion  La estructura variant esta inicializada
     */
    int getInteger( Variant* );

    /***
     * Descargo un entero como si el variant tuviera almacenado 
     * un entero
     *
     * @param v       Variant que quiero configurar
     *
     * @precondicion  La estructura variant esta inicializada
     */
    double getDouble( Variant* );

    /***
     * Descargo un puntero a string como si el variant tuviera almacenado 
     * un entero
     *
     * @param v       Variant que quiero configurar
     *
     * @precondicion  La estructura variant esta inicializada
     */
    char* getString( Variant* );

    /***
     * Dado un variant origen, lo copio a un variant destino.
     *
     * El resultado de esta asignación va a ser un variant independiente
     * del que se uso como origen.  por tanto si modifico el nuevo
     * el viejo no se verá afectado.
     *
     * @param org     Variant origen
     * @param dst     Variant destino
     *
     * @precondicion  Ambos estructuras variants estan inicializadas
     */
    void assign(Variant* dst, Variant* org);

    /***
     * Crear un variant a partir de uno que ya existe
     *
     * El resultado de esto será una nueva variable
     * variant almacenada en el heap, quien solicito esto  deberá 
     * liberarla
     *
     * @param org     Variant origen
     *
     * @return        puntero a nuevo variant
     *
     * @precondicion  La estructura variant esta inicializada
     */
    Variant* duplicate(Variant* org);

#endif // __VARIANT_H__
```
