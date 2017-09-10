#ifndef __PALABRA_H__
#define __PALABRA_H__

typedef struct _palabra {
    char* texto;
} Palabra;

void palabra_inicializar(Palabra* this, const char* texto);
void palabra_liberar(Palabra* this);

void palabra_mostrar(const Palabra* this);
void palabra_cambiar(Palabra* this, const char* nuevoValor);

void palabra_reemplazar_si_coincide(Palabra* this, 
        const char* palabra, 
        const char* otraPalabra
);

#endif
