#ifndef __CADENA_H__
#define __CADENA_H__

typedef struct _cadena {
  char* data;
  unsigned length;
} Cadena;

/***
 * Esta funcion inicializa la estructura para que tenga datos consistentes
 *
 * @param cadena: El TDA cadena que debo inicializar
 *
 * @return  cadena inicializada (la misma que recibe)
 */
Cadena* inicializar( Cadena* cadena);

void liberar(Cadena* cadena);

const char* devolverStr(Cadena* c);

/***
 * Modifica la cadena de caracteres alacenada por la cadena
 *
 * @param cadena: El TDA cadena que voy a modificar
 * @param data:   La cadena datos que utilizo para cambiar el valor
 *                del TDA
 *
 * @return  cadena modificada (la misma que recibe)
 */
Cadena* modificar(Cadena* c, const char* dato);

/***
 * Revierte la cadena 
 *
 * @param cadena: El TDA cadena que voy a revertir
 *
 * @return  cadena modificada (la misma que recibe)
 */
// Cadena* revertir(Cadena* c);

/***
 * Coloca la cadena en mayusculas
 *
 * @param cadena: El TDA cadena que voy a poner en mayusculas
 *
 * @return  cadena modificada (la misma que recibe)
 *
 */
// Cadena* mayusculas(Cadena* c);

/***
 * Devuelve 1 si la cadena es un palindromo, sino 0
 *
 * @param cadena: El TDA cadena que voy comprobar
 *
 * @return  0: La cadena no es un palindromo
 *          1: La cadena es un palindromo
 *
 */
// char esPalindromo(Cadena* c);

/***
 * Concatena dato en cadena 
 *
 * @param cadena: El TDA cadena que contendra los datos concatenados
 * @param dato:   String a concatenar
 *
 * @return  cadena modificada (la misma que recibe)
 */
Cadena* concatenarStr(Cadena* c, const char* dato);

/***
 * Concatena otra cadena en cadena 
 *
 * @param cadena: El TDA cadena que contendra los datos concatenados
 * @param dato:   String a concatenar
 *
 * @return  cadena modificada (la misma que recibe)
 */
Cadena* concatenarCadena(Cadena* dest, Cadena* origen);

/***
 * Duplicar cadena
 *
 * @precondicion    La cadena destino TIENE que estar inicializada 
 *
 * @param origen:   Cadena que voy a duplicar
 * @param destino:  Donde voy a guardar los datos duplicados
 *
 * @return          cadena duplicada
 *
 */
// Cadena* duplicar(Cadena* origen, Cadena* destino);

/***
 * Asignar cadenas
 *
 * @precondicion    Ambas cadenas deben estar inicializadas
 *
 * @param origen:   
 * @param destino:  
 *
 * @return          cadena destino
 *
 */
// Cadena* asignar(Cadena* origen, Cadena* destino);


#endif
