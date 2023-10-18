#include <iostream>

#include "DyV.h"

int busquedaBinaria(int x, std::vector<int> v, int ini, int fin){
	if(ini > fin){
                return -1;
        }
        int medio = (ini + fin) / 2;
        if(v[medio] == x){
                return medio;
        }else if(v[medio] > x){
                return busquedaBinaria(x, v, ini, medio - 1);
        }else{
                return busquedaBinaria(x, v, medio + 1, fin);
        }

}

