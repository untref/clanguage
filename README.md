# Algoritmos y programación III / Lenguajes de Programación III

## Recomendaciones

1. Concurrir a cada una de las clases teóricas
2. Si no concurre a la clase teórica, comuniquesé con **sus compañeros** para ver que se dió en la teórica.
3. Si no concurre a la clase teórica y no se pudo comunicar con sus compañeros, comuniquesé con el **docente** (los datos de contactos están en la página).
4. Para cada una de las teóricas se van a proponer una serie de ejercicios, hagalos! **NOTA**: si no se alcanza el resultado es porque algún concepto no lo conoce. Pregunte!
5. El TP Final es grupal. Si algún integrante del grupo abandona la materia, el grupo (reducido) deberá hacer las entregas según lo programado.
6. Esta no es una materia extensa pero involucra varios conceptos nuevos para el estudiante. Estudie semanalmente en lugar de unos pocos días muchas horas antes del exámen.
7. Todos los temas se evaluán excepto que se enuncio lo contrario.
8. Lenguaje de programación C:
  1. Programe el lenguaje C en horarios de lucidez (ni por las noches ni en medio de otras actividades)
  2. Entienda lo que escribe escribe y evite copiar y pegar código de Stackoverflow
9. Sea proactivo, Ud. es el responsable final de su educación. Si algunos de los los siguientes elementos no se le suministran **reclame** al docente¨
9.1. Código de la última clase.
9.2. Material defectuoso. 
9.3. Guía de ejercicios.
9.4. Lecturas adicionales.
9.5. Presentaciones (PPTs).

## Home page

Aquí encontraran noticias, encuestas y actividades que se llevan a cabo durante el cuatrimestre: [algo3untref][1]

## [Hall of Fame][2]
Inauguramos esta nueva sección con el fin de que los alumnos que se han esmerado en la construcción de su TP Final tengan un reconocimiento (más allá del triunfo que implica haber aprendido el contenido que se dicta en la materia)

## [Guias de ejercicios][3]

Guía de ejercicios para aplicar conceptos cubiertos en clase

## Errores comunes
### Punteros
1. Cuando paso un array por parámetro, este parámetro es un puntero al inicio del array
```
  void imprimir(char param[]) { // Esto es equivalente a 'void imprimir(char* param)'
    printf("sizeof de %s: ", sizeof(param));  // Es 4 u 8 (por ser puntero)
    printf("%s\n", param);
  }

  int main(int argc, char** argv) {
    char* buffer[] = "esto es un string";
    imprimir(buffer);
    printf("sizeof de %s: ", sizeof(buffer));  // Es 18
  }

```

2. Una función *NO* deber devolver punteros a variables definidas dentro del scope de la función.

```
char* worngCopy(char* orig) {
  char result[BUFFER_SIZE];
  char* dest = result;

  while( *orig != '\0' ) {
    *result = *orig;
    dest++;
    orig++;
  }
  *dest = '\0';

  return result;
};

```
*IMPORTANTE*: ```worngCopy``` devuelve un puntero a la variable ```result``` que se destruirá luego de que finalice la invoación de la función ```worngCopy```

[1]: https://sites.google.com/site/algo3untref
[2]: hallOfFame/
[3]: guiaEjercicios/
