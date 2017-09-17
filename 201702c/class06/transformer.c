#include <stdlib.h>
#include <string.h>

#include "transformer.h"

void transform_init(Transformer* this) {
    memset(this, 0x0, sizeof(Transformer));
};

void transform_release(Transformer* this) {
    if ( this->dst ) {
        free( this->dst );
    }

    if ( this->functores ) {
        free( this->functores );
    }

    this->functores = 0;
    this->dst = 0;
};

void transform_add_functor(Transformer* this, Functor f) {
    unsigned newCount = this->count + 1;
    this->functores = realloc(this->functores, newCount * sizeof(Functor) );
    this->functores[ newCount - 1 ] = f;
    this->count = newCount;
};

void transform_apply(Transformer* this, void* input, unsigned len, void** dst, unsigned* lenDst) {
    Functor* current = this->functores;

    while ( (current - this->functores) < this->count ) {
        Functor f = *current;

        (*f)(input, len, &this->dst, &this->lenDst);

        input = this->dst;
        len = this->lenDst;

        current++;
    }; 

    *dst = this->dst;
    *lenDst = this->lenDst;
};
