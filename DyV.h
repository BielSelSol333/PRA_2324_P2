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

template <typename T> void swamp(std::vector<T> &v, int a, int b){
  T aux = v[a];
  v[a] = v[b];
  v[b] = aux;
}

template <typename T> int partitionInicial(std::vector<T> &v, int ini, int fin){
	T x = v[fin];
	int i = ini;
	for(int j=ini; j<fin; j++){
	  if(v[j] <= x){
	    swamp(v, i, j);
	    i++;
	  }
	}
	swamp(v, i, fin);
	return i;
}

template <typename T> int partitionFinal(std::vector<T> &v, int ini, int fin){
	T x = v[ini];
	int i = fin;
	for(int j=fin; j<ini; j--){
	  if(v[j] <= x){
	    swamp(v, i, j);
	    i++;
	  }
	}
	swamp(v, i, ini);
	return i;
}

template <typename T> void quickSortInicial(std::vector<T> &v, int ini, int fin){
	if(ini < fin){
	  int pivot = partitionInicial(v, ini, fin);
	  quickSortInicial(v, ini, pivot - 1);
	  quickSortInicial(v, pivot + 1, fin);
	}	
}

template <typename T> void quickSortFinal(std::vector<T> &v, int ini, int fin){
	if(ini < fin){
	  int pivot = partitionFinal(v, ini, fin);
	  quickSortFinal(v, ini, pivot - 1);
	  quickSortFinal(v, pivot + 1, fin);
	}	
}

template <typename T> void quickSortCentral(std::vector<T> &V, int ini, int fin){
  int centro = (ini + fin)/2;
  T x = V[centro];
  // pivote central
  int i = ini;
  int j = fin;
  do{
    while(V[i] < x){
      i++;
    }
    while(V[j] > x){
      j--;
    }
    if(i<=j){
      swap(i, j, V);
      i++;
      j--;
    }
  }while(i<=j);

  if(ini < j){
    quickSortCentral(V, ini, j);
  }
  if(i < fin){
    quickSortCentral(V, i, fin);
  }
}
