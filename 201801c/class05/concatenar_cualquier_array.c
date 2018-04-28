#include <stdio.h>

void concatena_arrays(void* dst, void* src, unsigned srcLen) {
    char* dstByte = (char*)dst;
    char* srcByte = (char*)src;

    for( unsigned i = 0; i < srcLen; ++i) {
        *dstByte = *srcByte;
        dstByte++;
        srcByte++;
    }
}

int main(int argc, char** argv) {
    float precios[100] = { 1.0, 2.0, 3.0 };
    float masPrecios[] = { 6.0, 7.0, 8.0 };

    concatena_arrays(precios + 3, masPrecios, sizeof(masPrecios));

    printf("%d. str(%s)\n", __LINE__, str);

}



































