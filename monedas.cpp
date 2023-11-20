#include <iostream>
#include <vector>
#include "monedas.h"

int cambio(std::vector<int> v, int n, int cant){
  int num = 0, dev = cant;
  if(cant == 0){
    return 0;
  }else{
    num = cant/v[n];
    if(dev > (num * v[n])){
      return num + 1;
    }else{
      return num;
    }
  }
}
  
