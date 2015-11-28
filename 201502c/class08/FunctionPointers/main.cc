#include <iostream>

class MiClase {

public:
    typedef void (MiClase::*TipoMiembro1)(int);
    MiClase() {

    };

    void miembro_tipo_1(int i) {
        std::cout << "miembro_tipo_1 " << i << std::endl;
    }

    void miembro_tipo_2(double d) {
        std::cout << "miembro_tipo_2 " << d << std::endl;
    }

};
int main(int argc, char** argv) {
    MiClase m;
    
    // Puntero a un miembro de MiClase
    void (MiClase::*f1)(int) = &MiClase::miembro_tipo_1;  // donde f1 es el nombre de la variable
    void (MiClase::*f2)(double) = &MiClase::miembro_tipo_2;  // donde f2 es el nombre de la variable

    // Suele utilizarse esto
    MiClase::TipoMiembro1 f3 = &MiClase::miembro_tipo_1;

    // Luego tenes punteros a miembros estáticos (esto es otro tema)

    (m.*f1)(19);
    (m.*f2)(7.2);
    (m.*f3)(2);

    return 0;
}
