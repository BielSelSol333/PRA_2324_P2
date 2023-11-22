#include <iostream>

using namespace std;
#define MAX 5
#define TAMA 4
int arr[TAMA+1][MAX+1];

void printmatrix(){
        for(int i=0; i<TAMA+1; i++){
                for(int j=0; j<MAX+1; j++){
                        cout<<arr[i][j]<<" ";
                }
                cout<<endl;
        }
}

void printarr(int v[]){
        for(int i=0; i<TAMA; i++){
                cout<<v[i]<<" ";
        }
        cout<<endl;
}


void solucion(int x, int y, int pesos[], int* v){
	if(arr[y][x]==0){
		return;
	}
	if(arr[y][x]!=arr[y-1][x]){
		v[y-1]=v[y-1]+1;
		solucion(x-pesos[y-1],y-1, pesos, v);
	}
	else{
		solucion(x, y-1, pesos, v);
	}
}

int mochila(int v[], int p[], int capa, int ptr, bool ini){
    if(capa<0){
        return -9999;
    }
    if(capa==0){
        return 0;
    }
    if(ini==true){
        return arr[ptr][capa];
    }
    int a;
    for(int i=1; i<TAMA+1; i++){
	    for(int j=1; j<MAX+1; j++){
		a=v[i-1] + mochila(v, p, j-p[i-1], i-1, true);
		if(a<arr[i-1][j]){
			a=arr[i-1][j];
		}
		arr[i][j]=a;
	    }
    }
    return arr[TAMA][MAX];
}

int main()
{
    int pesos[TAMA] = {1,3,2,4};
    int valores[TAMA] = {10,20,15,20};
    int sol[TAMA]={0};
    cout<<mochila(valores, pesos, MAX, 1, false)<<endl;
    solucion(MAX, TAMA, pesos, sol);
    printarr(sol);
    printmatrix();

    
    return 0;
}

