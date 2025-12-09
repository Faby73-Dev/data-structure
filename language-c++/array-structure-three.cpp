#include <iostream>
#include <conio.h>

using namespace std;

void cargarArreglo(int arreglo[], int);
void mostrarImpar(int arreglo[],int);
void clearPantalla();

int main(){
	
	int indice = 100;
	int arreglo[indice];

	cargarArreglo(arreglo,indice);
	clearPantalla();

	cout << "elementos impares: ";
    mostrarImpar(arreglo,indice);
    cout << endl;
    cout << endl;

    //pantalla en espera
    system("pause");

	return 0;
}

//agrega elementos al vector
void cargarArreglo(int arreglo[], int i){
	for(int j = 0;j <= i; j++){
		cout << "ingrese valor entero: " << endl;	
		cin >> arreglo[j];
	}

}

//visualiza elementos impares del vector
void mostrarImpar(int arreglo[], int i){
	if (i >= 0){
		mostrarImpar(arreglo,i - 1);

		if( (arreglo[i] % 2) != 0 ){
			cout <<  arreglo[i] << " ";
			
		}

	}
}

//limpia pantalla
void clearPantalla(){
	system("cls");

}