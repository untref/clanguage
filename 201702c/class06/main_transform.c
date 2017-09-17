#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void duplicate(void* src, unsigned lenSrc, void** dst, unsigned* lenDst) {
    *lenDst = (2 * lenSrc) - 1;
    *dst = realloc( *dst, *lenDst );

    memcpy(*dst, src, lenSrc - 1);
    memcpy(*dst + lenSrc - 1, src, lenSrc);
};

typedef void (*Functor)(void*, unsigned, void**, unsigned*);

typedef struct _Transformer {
    Functor* functores;
    unsigned count;
    void* dst;
    unsigned lenDst;
} Transformer;

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


int main(int argc, char** argv) {
    {
        char* input = "A*";
        void* dup = 0x0;
        unsigned lenDup = 0x0;

        Transformer t;

        transform_init(&t);
        transform_add_functor( &t, &duplicate);
        transform_apply(&t, 
                input, 
                strlen(input) + 1,
                &dup, 
                &lenDup);

        printf("pointer dup: %p\n", dup);
        printf("len dup: %u\n", lenDup);
        printf("content dup: %s\n", (char*)dup);

        transform_release(&t);

    }
}

