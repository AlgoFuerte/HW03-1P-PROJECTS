#include <iostream>
#include <iomanip>
using namespace std;
int main(){
	int f1, c1, f2, c2;
	do{
		do{
			cout << "Ingrese las filas de la matriz 1: ";
			cin >> f1;
			cout << "Ingrese las columnas de la matriz 1: ";
			cin >> c1;
		}while(f1 <= 0 || c1 <= 0);
		do{
			cout << "Ingrese las filas de la matriz 2: ";
			cin >> f2;
			cout << "Ingrese las columnas de la matriz 2: ";
			cin >> c2;
		}while(f2 <= 0 || c2 <= 0);
	}while(c1 != f2);
	int v1[f1][c1], v2[f2][c2], vp[f1][c2];
	for (int i = 0; i < f1; i++){
		for (int j = 0; j < c1; j++){
			cout << "Ingrese el elemento (" << i+1 << ',' << j+1 << "): ";
			cin >> v1[i][j];
		}
	}	
	for (int i = 0; i < f2; i++){
		for (int j = 0; j < c2; j++){
			cout << "Ingrese el elemento (" << i+1 << ',' << j+1 << "): ";
			cin >> v2[i][j];
		}
	}
	
	//Mostrar Vectores originales
	cout << "Vector 1: " << endl;
	for (int i = 0; i < f1; i++){
		for (int j = 0; j < c1; j++){
			cout << setw(5) << v1[i][j]; 
		}
	cout << endl;
	}
	cout << endl << endl << "Vector 2: " << endl;
	for (int i = 0; i < f2; i++){
		for (int j = 0; j < c2; j++){
			cout << setw(5) << v2[i][j]; 
		}
	cout << endl;
	}
	
	// Vector Multiplicar UGA UGA UGA UGA
	//Inicializar todo el vector en 0
	for(int i = 0; i < f1; i++){
		for(int j = 0; j < c2; j++){
			vp[i][j] = 0;
		}
	}
	//Sacar la multiplicacion del vector
	for(int i = 0; i < f1; i++){
		for(int j = 0; j < c2; j++){
			for(int k = 0; k < c1; k++){
				vp[i][j] += v1[i][k] * v2[k][j];
			}
		}
	}
	cout << endl << endl;
	// Mostrar Mult
	cout << "Vector Multiplicado: " << endl;
	for(int i = 0; i < f1; i++){
		for(int j = 0; j < c2; j++){
			cout << setw(4) << vp[i][j];
		}
		cout << endl;
	}
	return 0;
}