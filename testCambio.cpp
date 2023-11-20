#include <iostream>
#include <vector>
#include "monedas.h"

int main(){
  int** matriz;
  matriz = new int* [FILAS];
  for(int i=0; i<FILAS; i++){
    matriz[i] = new int [COLUMNAS];
  }

  std::vector<int> v = {1, 4, 6};
  v.resize(FILAS);

  for(int i=0; i<FILAS; i++){
    for(int j=0; j<COLUMNAS; j++){
      matriz[i][j] = cambio(v, i, j);
    }
  }
 
  std::cout << "Tabla de monedas utilizada: " << std::endl;
  
  for(int i=0; i<FILAS; i++){
    for(int j=0; j<COLUMNAS; j++){
      std::cout << matriz[i][j] << " ";
    }
    std::cout << std::endl;
  }
  std::cout << std::endl;  
}
