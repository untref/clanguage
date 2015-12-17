## Guia 04 - TDA

### Ejercicio 1

Definir el TDA Nave con la siguiente declaración:

```
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

Definir el TDA Nave con la siguiente declaración:

```
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
void cadena_modificar(Cadena* this, const char* dato);

/***
* Concatenar un contenido a una cadena
*
* @param cadena: El TDA cadena que voy a modificar
* @param data:   La cadena datos que utilizo para cambiar el valor
*                del TDA
*
* @return  cadena modificada (la misma que recibe)
*/
void cadena_concatenar(Cadena* this, const char* dato);

void cadena_print(Cadena* this);
#endif // CADENA_H_INCLUDED
```
