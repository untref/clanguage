**UNTREF**

**Algoritmos y programación 3**

*Trabajo práctico Final: TDA generación de archivos JSON*

2do cuatrimestre, 2015

(Trabajo Grupal)

Alumnos:

  ----- --------------- -------- ------------------------
  Nro   Nombre          Legajo   Mail
  1     Klemenc Marco   29914    marcoklemenc@gmail.com
  2     Gaspari Waldo   29840    waldogaspari@gmail.com
  3                              
                                 
  ----- --------------- -------- ------------------------

***Fecha de entrega final***: Sábado 14/11/2015

***Nota Final***:

Introducción
============

Objetivo del trabajo
====================

Aplicar los conceptos enseñados en la materia a la resolución de un
problema así como también la aplicación de buenas prácticas, trabajando
en forma grupal y utilizando un lenguaje de tipado estático de bajo
nivel (Lenguaje C)

Consigna general
----------------

Desarrollar un conjunto de TDAs que permitan operar con un conjunto de
JSON (JavaScript object notation). Una vez creado este conjunto de datos
utilizarlo en la generación de un archivo JSON. La aplicación deberá ser
acompañada con la apropiada documentación de diseño. En la siguiente
sección se describe la aplicación a desarrollar.

Descripción de la aplicación a desarrollar
==========================================

Definir un conjunto de TDAs que permitan generar el siguiente archivo
JSON:

{

"size": "0 bytes",

"hash": "37eb1ba1849d4b0fb0b28caf7ef3af52",

"bytes": 0,

"thumb\_exists": false,

"rev": "714f029684fe",

"modified": "Wed, 27 Apr 2011 22:18:51 +0000",

"path": "/Photos",

"is\_dir": true,

"icon": "folder",

"root": "dropbox",

"contents": \[

{

"size": "2.3 MB",

"rev": "38af1b183490",

"thumb\_exists": true,

"bytes": 2453963,

"modified": "Mon, 07 Apr 2014 23:13:16 +0000",

"client\_mtime": "Thu, 29 Aug 2013 01:12:02 +0000",

"path": "/Photos/flower.jpg",

"photo\_info": {

"lat\_long": \[

37.77256666666666,

-122.45934166666667

\],

"time\_taken": "Wed, 28 Aug 2013 18:12:02 +0000"

},

"is\_dir": false,

"icon": "page\_white\_picture",

"root": "dropbox",

"mime\_type": "image/jpeg",

"revision": 14511

}

\],

"revision": 29007

}

**Consignas para el programa principal:**

Luego de definir apropiadamente las estructuras crear el programa
principal que generará este archivo. Dicho programa podrá recibir como
parámetro:

-   **Ningún parámetro:** En cuyo caso el JSON se imprimirá en la
    consola (standard output)

<!-- -->

-   **Parámetro: -f &lt;archivo\_destino&gt;:** En cuyo caso el JSON
    generado deberá escribirse en un archivo llamado *archivo\_destino*.

**La API para manejar JSON deberá proveer funcionalidad para realizar
las siguientes tareas:**

1.  Crear un nuevo *nodo JSON (en adelante nJson)*

    a.  Asignarle nombre al nJson y contenido al mismo tiempo

<!-- -->

1.  Cambiarle el contenido\* al nJson

2.  Agregar nuevo nJson a un nJson existente

*\*Respecto a los contenidos posibles:*

1.  nJson

<!-- -->

1.  Cualquier tipo de dato punto flotante

2.  Cualquier tipo de dato entero

3.  Strings

4.  Arrays

    a.  De cualquier tipo entre 1-4 (solo un ùnico tipo por vez).

NOTA:

Los contenidos del nJson en ocasiones pueden ser Números enteros /
Flotantes / Booleanos / Strings /etc. En estos casos el usuario de la
API deberá poder operar con los tipos de datos nativos provistos por C
que mejor se adapten al dato en cuestión.

**Pautas de calidad al momento de resolver el TP**

-   Los atributos del TDA deberán accederse mediante funciones provistas
    por la API ***exclusivamente*** (Application Programming Interface).

<!-- -->

-   Dentro de las funciones que operan sobre el TDA/s evitar los
    llamados a funciones que impriman en las salidas estándar de errores
    o en la salida estándar (printf, fprintf, etc.)

-   Cada uno de los TDAs definidos deberán estar apropiadamente
    documentas, tanto sus campos como todas sus primitivas.

-   Elegir un standard de codificación y seguirlo a lo largo
    del proyecto.

-   Toda la memoria reservada dentro del TDA será responsabilidad de la
    API, es decir, si el TDA reserva memoria deberá proveer las
    herramientas necesarias para liberarla apropiadamente.

-   Si necesita utilizar números mágicos, utilice \#define y
    documéntelos apropiadamente.

-   Los arrays utilizados dentro del TP deberán poder ser de una
    longitud indefinida (sin restricciones en su cantidad de elementos).

-   La estructura del proyecto deberá ser:

    -   Archivo main.c con el ejemplo de uso de el/los TDA/s

    -   Archivo &lt;declaración del tda&gt;.h

    -   Archivo &lt;definición del tda&gt;.c

-   El proyecto deberá ser implementado utilizando la
    interfase CodeBlock.

Formas de entrega

Habrá *4 entregas formales*. Las mismas tendrán una calificación de APROBADO o NO APROBADO en el momento de la entrega.
-----------------------------------------------------------------------------------------------------------------------

*1er Entrega*: *Mínimamente* (se aconseja avanzar todo lo posible):

-   Estructura completa del proyecto.

<!-- -->

-   Creación del main.c y la lectura de parámetros que provean la
    posibilidad de ejecutar la aplicación en los dos modos.

*2da Entrega*: Tener la posibilidad de:

1.  Crear un nJson

<!-- -->

1.  Poder asignarle cualquier contenido (salvo array) para todos los
    tipos primitivos de C.

2.  Agregar la posibilidad de poder imprimir el nJson.

NOTA: Si para esta entrega pueden implementar el contenido array,
adelante!

*3er Entrega*: Tener la posibilidad de:

1.  Cambiarle el contenido\* al nJson

<!-- -->

1.  Agregar nuevo nJson a un nJson existente

2.  Poder asignar como contenido de un njson un array

3.  Completar la salida por pantalla.

*4ta y última Entrega*: Trabajo Práctico completo, funcionando y
cumpliendo todas las normas de calidad.

IMPORTANTE:

Si el TP no se puede ejecutar por cualquier tipo de error (acceso
inválido de memoria, goteo de memoria, etc) el TP estará
***desaprobado*.**

Si la salida resultante del TP fuera un JSon inválido el TP estará
***desaprobado***.

Fechas de entrega programadas
-----------------------------

*1er Entrega*: *A definir*

*2da Entrega*: *A definir*

*3er Entrega*: *A definir*

*4ta y última Entrega*: *A definir*

Informe

*Supuestos*
-----------

Uno de los supuestos planteados es que nuestros TDAs usados son el de nJson y el de data, ambos se definen o declaran en un único archivo: en el primer caso en nJson.h y en el segundo caso en nJson.c. 
---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

*Modelo de dominio*
-------------------

Para la implementación del Json se utilizaron dos TDAs: uno es el nJson,
que guarda el Json, y el otro es data, que guarda cualquier dato propio
del Json.

Dentro del Json se guarda el nombre y todos los datos del Json, y en
data se guarda el nombre, las características del dato y su dato
siguiente, además del puntero a función de escritura, la longitud del
array y si es el dato es in array o no. También se presentan todas las
funciones que se van a utilizar para la creación, escritura y
finalización de un Json, además de funciones auxiliares para trabajar
con los datos del mismo.

*Detalles de implementación*
----------------------------

Uno de los puntos conflictivos a resolver fue la posibilidad de que se produzca un inconveniente durante la creación de un Json. Para ello se implementaron comprobaciones que cortarán la ejecución de la aplicación al detectar un error devolviendo un número de error. Luego, con ese número se puede obtener de qué tipo fue el error efectuado mediante la función nJson\_getError(). Los posibles valores de error son: 1, 2, 3, 4 y 5. Si se busca otro número de error tirará “Error desconocido”. 
------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

El 1 tirará error de tipo “JSON no válido”. Se efectuará para verificar si el Json dado es válido o no.
-------------------------------------------------------------------------------------------------------

El 2 tirará error de tipo “dato no válido”. Se efectuara para verificar si el dato dado es válido o no. 
--------------------------------------------------------------------------------------------------------

El 3 tirará error de tipo “archivo no válido”. Se efectuara para verificar si el archivo dado es válido no.
-----------------------------------------------------------------------------------------------------------

El 4 tirará error de tipo “valor no válido”. Se efectuara para verificar si el valor dado es válido o no.
---------------------------------------------------------------------------------------------------------

El 5 tirará error de tipo “longitud no válida”. Se efectuara para verificar si la longitud del array es válida o no.
--------------------------------------------------------------------------------------------------------------------

Checklist de corrección
=======================

Esta sección es para uso exclusivo de los docentes, por favor no
modificar.

Carpeta
-------

**Generalidades**

-   ¿Son correctos los supuestos y extensiones?

<!-- -->

-   ¿Es prolija la presentación? (hojas del mismo tamaño, numeradas y
    con tipografía uniforme)

**Modelo**

-   ¿Está completo? ¿Contempla la totalidad del problema?

<!-- -->

-   ¿Respeta encapsulamiento?

-   ¿Pierde memoria?

-   ¿Cumple con las buenas prácticas?

Código
======

**Generalidades**

-   ¿Respeta estándares de codificación?

<!-- -->

-   ¿Está correctamente documentado?

-   ¿Define magic numbers? ¿Están documentados?

-   ¿Respeta estructura del proyecto?
