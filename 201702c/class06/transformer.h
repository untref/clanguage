#ifndef __TRANSFORMER_H__
#define __TRANSFORMER_H__

typedef void (*Functor)(void*, unsigned, void**, unsigned*);

typedef struct _Transformer {
    Functor* functores;
    unsigned count;
    void* dst;
    unsigned lenDst;
} Transformer;

void transform_init(Transformer* this) ;
void transform_release(Transformer* this);
void transform_add_functor(Transformer* this, Functor f) ;
void transform_apply(Transformer* this, void* input, unsigned len, void** dst, unsigned* lenDst);

#endif
