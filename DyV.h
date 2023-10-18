#include <vector>

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
