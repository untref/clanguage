#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _Variant {
    void* data;
    unsigned size;
} Variant;

Variant* variant_init(Variant* this) {
    this->data = 0x0;
    this->size = 0x0;
    return this;
}

void variant_release(Variant* this) {
    if ( this->data ) {
        free( this->data );
    }
    this->data = 0x0;
    this->size = 0x0;
}

Variant* variant_store_data(Variant* this, void* value, unsigned size) {
    this->data = malloc( size );
    this->size = size;
    memcpy(this->data, value, size);

    return this;
}

Variant* variant_set_float(Variant* this, float value) {
    variant_release(this);

    variant_store_data(this, &value, sizeof(float));

    return this;
}

Variant* variant_set_array(Variant* this, void* array, unsigned sizeOfarray) {
    variant_release(this);

    variant_store_data(this, array, sizeOfarray);

    return this;
}

Variant* variant_set_double(Variant* this, double value) {
    variant_release(this);

    variant_store_data(this, &value, sizeof(double));

    return this;
}

Variant* variant_print(Variant* this, void (*print)(void*)) {
    (*print)(this->data);
    return this;
}


#if 0
// No devolvemos this->data porque el usuario puedo romperlo (free(data))
void* variant_get_data(Variant* this, void* result) {
    return this->data;
};
#endif

Variant* variant_get_data(Variant* this, void* result) {
    memcpy(result, this->data, this->size);
    return this;
};

void print_double(void* value) {
    printf("%f\n", *(double*)value);
}

int main(int argc, char** argv) {
    int enteros[] = { 1,2,3,4,54,5,56,6,66,6};
    Variant v;

    variant_init(&v);

    variant_set_float(&v, 29.0f);
    variant_set_double(&v, 29.0L);

    /*
    variant_set_array(&v, enteros, sizeof(enteros));
    double stored;
    variant_get_data(&v, &stored);
    */

    variant_print(&v, &print_double);


    variant_release(&v);

}

