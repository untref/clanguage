/*****
 * Definir y declarar una clase String tal como existe en java.
 *
 * Mínimamente deberá poder:
 * - Construirse un string vacío
 * - Construirse a partir de un string literal
 * - Poder asignarse
 * - Destruirse liberando todo los recursos reservados
 */

// Interfase posible
class String {
public:
  String();
  String(const char* str);
  String(const String& otra);
  virtual ~String();

  String& operator=(const String& otra);

private:
  // Atributo según corresponda 
};
