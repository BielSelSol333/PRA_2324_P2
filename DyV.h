#include <vector>
#include <iostream>

template <typename T> int busquedaBinaria(T x, std::vector<int> v, int ini, int fin){
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

template <typename T> int busquedaBinaria_Inv(T x, std::vector<int> v, int ini, int fin){
  	if(ini > fin){
                return -1;
        }
        int medio = (ini + fin) / 2;
        if(v[medio] == x){
                return medio;
        }else if(v[medio] > x){
                return busquedaBinaria_Inv(x, v, medio + 1, fin);
        }else{
                return busquedaBinaria_Inv(x, v, ini, medio - 1);
        }
}

template <typename T> int partition(std::vector<T> &v, int ini, int fin);

template <typename T> void quickSort(std::vector<T> &v, int ini, int fin){
	if(ini < fin){
	  int pivot = partition(v, ini, fin);
	  quickSort(v, ini, pivot - 1);
	  quickSort(v, pivot + 1, fin);
	}	
}

template <typename T> int partition(std::vector<T> &v, int ini, int fin){
	T x = v[fin];
	int i = ini;
	for(int j=ini; j<fin; j++){
	  if(v[j] <= x){
	    T aux = v[j];
	    v[j] = v[i];
	    v[i] = aux;
	    i++;
	  }
	}
	T aux = v[fin];
	v[fin] = v[i];
	v[i] = aux;

	return i;
} 
