#include <iostream>
#include <conio.h>

using namespace std;

void cargarArreglo(char arreglo[], int);
int sumaArregloCaracter(char arreglo[],int,int);
void clearPantalla();

int main(){
	
	int indice = 50;
	int resultado = 0;
	char arreglo[indice];

	cargarArreglo(arreglo,indice);
	
	//pantalla en espera
	system("pause");

	clearPantalla();

	cout << "el resultado es: " << sumaArregloCaracter(arreglo,indice,resultado) << endl;

	return 0;
}

//agrega elementos al vector
void cargarArreglo(char arreglo[], int i){
	for(int j = 0;j <= i; j++){
		cout << "ingrese caracter: ";	
		cin >> arreglo[j];
		cout << "el valor del caracter es: " << int (arreglo[j]) << endl; 
	}

}

//devuelve el resultado de sumar el valor ASCII de cada elemetos del vector
int sumaArregloCaracter(char arreglo[], int i,int resultado){
	if (i >= 0){

		resultado = sumaArregloCaracter(arreglo,i - 1,resultado + int (arreglo[i]));
	}

	return resultado;
}

//limpia pantalla
void clearPantalla(){
	system("cls");

}