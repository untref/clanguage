
int main(int argc, char** argv) {
  int cuanto = 10;
  char* nombre = malloc( cuanto );

  // @MAL 
  // Perdemos referencias
  //    nombre = "Alejandro";

  strcpy(nombre, "Alejandro");

  free(nombre);



}
