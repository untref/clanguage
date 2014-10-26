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
 * @param data    Puntero al comienzo del entero
 * @param length   Cantidad de bytes que ocupa un entero
 *
 * @precondicion  La estructura variant esta inicializada
 */
void set( Variant*, void* data, unsigned length, unsigned elements);


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
