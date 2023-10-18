#include <iostream>
#include <vector>

#include "DyV.h"

int main(){
        std::vector<int> v{1, 3, 5, 7, 8};
        int tam = v.size();
	std::cout << tam << std::endl;

        int x, pos;
        std::cout << "Inserta el elemento a buscar: " << std::endl;
        std::cin >> x;

        pos = busquedaBinaria(x, v, 0, tam);
	std::cout << "Posición: " << pos << std::endl;
        return 0;
}
