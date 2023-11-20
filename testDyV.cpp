#include <iostream>
#include <vector>
#include <chrono>

#include "DyV.h"

int main(){
        std::vector<int> v1{1, 3, 5, 7, 8};
        int tam1 = v1.size();

	std::vector<int> v2{9, 7, 5, 3, 1};
	int tam2 = v2.size();

	std::vector<int> v3{5, 3, 9, 1, 7};
	int tam3 = v3.size();

        int x, pos1, pos2;
        std::cout << "Inserta el elemento a buscar: " << std::endl << "- ";
        std::cin >> x;

        pos1 = busquedaBinaria(x, v1, 0, tam1);
	std::cout << "Posición: " << pos1 << std::endl;

	pos2 = busquedaBinaria_Inv(x, v2, 0, tam2);
        std::cout << "Posición invertida: " << pos2 << std::endl;

	for(int i=0; i<=tam3; i++){
	  std::cout << v3[i] << " ";
	}
	std::cout << std::endl;

	auto start = std::chrono::system_clock::now();
	quickSortInicial(v3, 0, tam3);
	auto end = std::chrono::system_clock::now();
	std::chrono::duration<float, std::milli> duration = end - start;
	std::cout << "Tiempo: " << duration.count() << "s" << std::endl;

	for(int i=0; i<=tam3; i++){
	  std::cout << v3[i] << " ";
	}
	std::cout << std::endl;

	for(int i=0; i<=tam3; i++){
	  std::cout << v3[i] << " ";
	}
	std::cout << std::endl;

	auto start = std::chrono::system_clock::now();
	quickSortFinal(v3, 0, tam3);
	auto end = std::chrono::system_clock::now();
	std::chrono::duration<float, std::milli> duration = end - start;
	std::cout << "Tiempo: " << duration.count() << "s" << std::endl;

	for(int i=0; i<=tam3; i++){
	  std::cout << v3[i] << " ";
	}
	std::cout << std::endl;

        return 0;
}
