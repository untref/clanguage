#include <string.h>
#include <stdlib.h>

typedef _string {
  char* data;
  unsigned l;
} string;

void string_init(string* this, char* data, unsigned len) {
  memcpy(this->data, data, len);
  this->l = len;
}

unsigned string_len(string* this) {
  return this->l;
}

int main( int argc, char** argv) {
  string s;
  // char data[] = { 0x0, 0x0,  0x1, 0x3, 0x5, 'U'};
  char data[] = "UNTREF";

  string_init( &s, data, sizeof(data) );

  string_len( &s );
}

