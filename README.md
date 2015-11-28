# Algoritmos y programación III / Lenguajes de Programación III
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
