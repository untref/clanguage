#include <iostream>
#include <cstring>
#include <cstdlib>
#include <sstream>

class StringB {
public:
 StringB() {
   this->data = 0;
   this->count = 0;
   std::cout << "Constructor StringB: " << this->print() << std::endl;
 };

 StringB(const StringB& other) {
   this->count = other.count;
   this->data = (char*)malloc(count);
   strcpy(this->data, other.data); 
   std::cout << "Constructor copia StringB: " << this->print() << std::endl;
 }

 StringB(const char* str) {
   count = strlen(str) + 1;
   data = (char*)malloc( count );

   strcpy(data, str);
   std::cout << "Constructor StringB: " << this->print() << std::endl;
 }

 const unsigned& xxx() { return this->count ; }


 StringB& operator=(const StringB& other) {
   std::cout << "operator =" << this->print() << std::endl;
   if ( this == &other ) {
     return *this;
   }

   this->count = other.count;

   if (this->data) {
     free(this->data);
   };

   this->data = (char*)malloc(count);
   strcpy(this->data, other.data); 

   return *this;
 }

 void str(const char* str) {
   if (this->data) {
     free(this->data);
   };

   this->data = (char*)malloc(strlen(str) + 1);
   strcpy(this->data, str); 
 }

 std::string print() const {
   std::stringstream s;

   
  if ( data ) {
    s << data;
  } else {
    s << "null";
  }

   return s.str();
 }

 virtual ~StringB() {
   std::cout << "Destructor StringB: " << this->print() << std::endl;
   if (data) {
     free(data);
   }
   data = 0;
   count = 0;
 }

private:
  char* data;
  unsigned count;

};

void f(StringB tmp) {
  std::cout << tmp.print() << std::endl;
}

int main(int, char**) {
  StringB nulo;
  StringB x("xxxxxx");

  f(x);

  nulo = x = StringB("jjjj");

  x = x;
  nulo.str("O");
  std::cout << nulo.print() << std::endl;
  std::cout << x.print() << std::endl;
  
}
