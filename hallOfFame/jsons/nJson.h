#ifndef NJSON_H_INCLUDED
#define NJSON_H_INCLUDED

// El tipo que se usará para las funciones de escritura.
typedef void* Write(FILE*, void*);

/*
Estructura que guarda un dato de un nJson.
@var name: nombre del dato.
@var value: valor del dato.
@var next: dato siguiente (símil lista enlazada).
@var isArray: si el dato es un array (!=0) o no (==0).
@var length: longitud del array del dato.
@var func: puntero a la función que se llamará para escribir el dato.
*/
typedef struct _data{
    char* name;
    void* value;
    struct _data* next;
    char isArray;
    unsigned length;
    Write* func;
}Data;

/*
Estructura que guarda todas las propiedades del JSON.
@var name: nombre del JSON.
@var data: puntero al primer dato del JSON.
*/
typedef struct _nJson{
    char* name;
    Data* data;
}nJson;

/*
Método auxiliar para buscar un dato con cierto nombre recursivamente
(si this->name == name lo devuelve, caso contrario, pasa al siguiente).
@param this: puntero al dato a comparar.
@param data: nombre del dato que se busca.
@return: puntero al dato o NULL si no lo encuentra.
*/
Data* data_hasData(Data* this, char* name);

/*
Método auxiliar para agregar un dato a la lista recursivamente
(si this está vacío, crea el dato, caso contrario, pasa al siguiente).
@param this: puntero al dato que se está evaluando.
@param name: nombre del dato a agregar.
@param value: valor del dato a agregar.
@param size: tamaño del dato a agregar.
@param isArray: si el dato es un array (!=0) o no (==0).
@param length: longitud del array del dato.
@param func: puntero a la función que imprimirá el dato.
@return: puntero al primer dato.
*/
Data* data_addData(Data* this, char* name, void* value, unsigned valueSize,
    char isArray, unsigned length, Write func);

/*
Método auxiliar para liberar un dato recursivamente
(se libera y llama a la misma función con su siguiente).
@param this: puntero al dato a liberar.
*/
void data_freeData(Data* this);

/*
Inicializa un nJson y fija un nombre y un primer dato.
@param this: puntero al nJson a inicializar.
@param name: nombre que tendrá el nJson.
@param dataName: nombre del primer dato.
@param value: valor del primer dato.
@param size: tamaño del primer dato.
@param isArray: si el dato es un array (!=0) o no (==0).
@param length: longitud del array del dato.
@param func: puntero a la función que imprimirá el dato.
@return: puntero al nJson inicializado.
*/
nJson* nJson_init(nJson* this, char* name, char* dataName, void* value,
    unsigned size, char isArray, unsigned length, Write func);

/*
Reemplaza el nombre de un nJson.
@param this: puntero al nJson.
@param name: nuevo nombre.
*/
void nJson_setName(nJson* this, char* name);

/*
Método para saber si el nJson tiene cierto dato.
@param this: nJson en cuestión.
@param name: nombre del dato.
@return: verdadero (1) o falso (0).
*/
char nJson_hasData(nJson* this, char* name);

/*
Agrega un dato al nJson.
@param this: puntero al nJson.
@param name: nombre del dato.
@param value: valor del dato.
@param size: tamaño del dato.
@param isArray: si el dato es un array (!=0) o no (==0).
@param length: longitud del array del dato.
@param func: puntero a la función que imprimirá el dato.
*/
void nJson_setData(nJson* this, char* name, void* value, unsigned size,
    char isArray, unsigned length, Write func);

/*
Escribe un dato del nJson.
@param this: puntero al nJson.
@param file: salida a la cual escribir.
@param name: nombre del dato.
*/
void nJson_writeData(FILE* file, nJson* this, char* name);

/*
Escribe un valor, interpretándolo como int.
@param file: salida a la cual escribir.
@param value: puntero al valor.
@return: puntero a la siguiente posición (para escribir arrays).
*/
void* nJson_writeInt(FILE* file, void* value);

/*
Escribe un valor, interpretándolo como unsigned.
@param file: salida a la cual escribir.
@param value: puntero al valor.
@return: puntero a la siguiente posición (para escribir arrays).
*/
void* nJson_writeUnsigned(FILE* file, void* value);

/*
Escribe un valor, interpretándolo como double.
@param file: salida a la cual escribir.
@param value: puntero al valor.
@return: puntero a la siguiente posición (para escribir arrays).
*/
void* nJson_writeDouble(FILE* file, void* value);

/*
Escribe un valor, interpretándolo como long.
@param file: salida a la cual escribir.
@param value: puntero al valor.
@return: puntero a la siguiente posición (para escribir arrays).
*/
void* nJson_writeLong(FILE* file, void* value);

/*
Escribe un valor, interpretándolo como float.
@param file: salida a la cual escribir.
@param value: puntero al valor.
@return: puntero a la siguiente posición (para escribir arrays).
*/
void* nJson_writeFloat(FILE* file, void* value);

/*
Escribe un valor, interpretándolo como short.
@param file: salida a la cual escribir.
@param value: puntero al valor.
@return: puntero a la siguiente posición (para escribir arrays).
*/
void* nJson_writeShort(FILE* file, void* value);

/*
Escribe un valor, interpretándolo como unsigned short.
@param file: salida a la cual escribir.
@param value: puntero al valor.
@return: puntero a la siguiente posición (para escribir arrays).
*/
void* nJson_writeUnsignedShort(FILE* file, void* value);

/*
Escribe un valor, interpretándolo como string.
@param file: salida a la cual escribir.
@param value: puntero al valor.
@return: puntero a la siguiente posición (para escribir arrays).
*/
void* nJson_writeString(FILE* file, void* value);

/*
Escribe un valor, interpretándolo como boolean (char).
@param file: salida a la cual escribir.
@param value: puntero al valor.
@return: puntero a la siguiente posición (para escribir arrays).
*/
void* nJson_writeBoolean(FILE* file, void* value);

/*
Escribe un valor, interpretándolo como nJson.
@param file: salida a la cual escribir.
@param value: puntero al valor.
@return: puntero a la siguiente posición (para escribir arrays).
*/
void* nJson_writenJson(FILE* file, void* value);

/*
Comprueba si un puntero a nJson es válido o no.
Si no es válido, corta la ejecución devolviendo 1.
@param this: puntero a comprobar.
*/
void nJson_checknJson(nJson* this);

/*
Comprueba si un puntero a dato es válido o no.
Si no es válido, corta la ejecución devolviendo 2.
@param this: puntero a comprobar.
*/
void nJson_checkData(Data* this);

/*
Comprueba si un puntero a archivo es válido o no.
Si no es válido, corta la ejecución devolviendo 3.
@param this: puntero a comprobar.
*/
void nJson_checkFile(FILE* this);

/*
Comprueba si un puntero a valor es válido o no.
Si no es válido, corta la ejecución devolviendo 4.
@param this: puntero a comprobar.
*/
void nJson_checkValue(void* this);

/*
Comprueba si la longitud de un array es válida o no.
Si no es válido, corta la ejecución devolviendo 5.
@param this: longitud a comprobar.
*/
void nJson_checkLength(unsigned this);

/*
Fija la posición de escritura al penúltimo caracter,
para que la próxima escritura sobrescriba el último.
@param file: salida a modificar.
*/
void nJson_eraseLastCharacter(FILE* file);

/*
Finaliza la escritura.
@param file: salida a finalizar.
*/
void nJson_endWrite(FILE* file);

/*
Devuelve el mensaje de error correspondiente a un id específico.
@param id: el id del error (código de retorno).
@return: el string correspondiente al id utilizado.
*/
char* nJson_getError(int id);

/*
Libera todos los recursos utilizados por el nJson.
@param this: puntero al nJson a liberar.
*/
void nJson_free(nJson* this);

#endif // NJSON_H_INCLUDED
