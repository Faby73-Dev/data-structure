#include <iostream>
#include <conio.h>

using namespace std;

void cargarArreglo(int arreglo[], int);
int sumarVector(int arreglo[], int, int);
void clearPantalla();

int main(){

	int indice = 50;
	int arreglo[indice];
	int resultadoSuma = 0;

	cargarArreglo(arreglo,indice);

	clearPantalla();

	cout << "el resultdo es: " << sumarVector(arreglo,indice,resultadoSuma) << endl;

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

//devuelve el resultado de la suma de los elemetos del vector
int sumarVector(int arreglo[], int i,int resultadoSuma){
	if (i != 0){
		resultadoSuma = sumarVector(arreglo,i - 1,arreglo[i] + resultadoSuma);

	}else{
		resultadoSuma = resultadoSuma + arreglo[0];
	}

	return resultadoSuma;
}

//limpia pantalla
void clearPantalla(){
	system("cls");

}