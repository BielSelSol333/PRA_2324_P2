#include "mochila.h"
#include <algorithm>
#include <iostream>

int obtener_valor_Max(int valor[], int peso[], int pos[]);
int obtener_peso_Min(int valor[], int peso[], int pos[], int valor_max, int peso_total, int peso_max);
int comprobar_eliminadas(int pos[], int posicion);

int valor_mochila(int valor[], int peso[], int peso_max){
  int pos[MAX_O] = {0};
  int i, j, k = 0;
  int valor_total = 0, peso_total = 0;
  int valor_max = 0, peso_min = 99;

  // Bucle que comprueba que no sobrepase el peso
  do{
    // Comprueba el valor más grande
    valor_max = obtener_valor_Max(valor, peso, pos);
    
    // Comprueba cual es el menor peso
    peso_min = obtener_peso_Min(valor, peso, pos, valor_max, peso_total, peso_max);

    // Una vez comprobado a,bos cosas se suma al total
    for(i=0; i<MAX_O; i++){
      comprobar_eliminadas(pos, i);
      if(peso[i] == peso_min){
	peso_total += peso[i];
	valor_total += valor[i];
	pos[k] = i;
	valor_max = 0; peso_min = 99;
      }
    }
    k++;
    for(int m=0; m<MAX_O; m++){
      std::cout << pos[m] << " ";
    }
    std::cout << std::endl;
  }while(peso_total <= peso_max);

  return valor_total;
}

int obtener_valor_Max(int valor[], int peso[], int pos[]){
  int valor_max = 0;
  
  for(int i=0; i<MAX_O; i++){
    comprobar_eliminadas(pos, i);
    if(valor_max <= valor[i]){
      valor_max = valor[i];
    }
  }

  return valor_max;
}

int obtener_peso_Min(int valor[], int peso[], int pos[], int valor_max, int peso_total, int peso_max){
  int peso_min = 99;
  
  for(int i=0; i<MAX_O; i++){
    comprobar_eliminadas(pos, i);
    if(valor[i] >= valor_max){
      if(peso_min >= peso[i]){
	peso_min = peso[i];
      }
    }
  }

  return peso_min;
}

int comprobar_eliminadas(int pos[], int posicion){
  for(int j=0; j<MAX_O; j++){
    if(pos[j] == posicion){
      pos[posicion] = 1;
      posicion++;
      return posicion;
    }
  }
  return posicion;
}
