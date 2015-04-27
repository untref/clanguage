#ifndef __TDA_H__
#define __TDA_H__

#define PERSONA_NOMBRE_LONG 10
#define PERSONA_APELLIDO_LONG 10

typedef struct _Persona {
    char nombre[PERSONA_NOMBRE_LONG];
    char apellido[PERSONA_APELLIDO_LONG];
} Persona ;

void persona_init(Persona* p, const char* nombre, const char* apellido);

void persona_print(Persona* p);


#endif 
