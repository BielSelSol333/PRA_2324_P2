#include <iostream>
#include "mochila.h"

int main(){
  int valor[MAX_O] = {10, 20, 15, 20};
  int peso[MAX_O] = {1, 3, 2, 4};

  std::cout << "Valor de la mochila: " << valor_mochila(valor, peso, 5) << std::endl;

  return 0;
}
