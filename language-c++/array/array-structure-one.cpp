#include <iostream>
#include <conio.h>

using namespace std;

//prototipo
void cargarArreglo(char arreglo[],int);
void mostrarArregloRecursivoDesendente(char arreglo[],int);
void mostrarArregloRecursivoAsendente(char arreglo[],int);
void clearPantalla();


int main(){
	clearPantalla();
	int indice = 30;
	char arreglo[indice];

	cout << "-----------Carga de valores enteros---------" << endl;	
	cargarArreglo(arreglo,indice);

	//limpia pantalla
	clearPantalla();

	
	cout << "-----Elementos del vector----" << endl;	
	mostrarArregloRecursivoAsendente(arreglo,indice);
	cout << endl;
	cout << endl;


	cout << "-----Elementos del vector de manera inversa----" << endl;	
	mostrarArregloRecursivoDesendente(arreglo,indice);
	cout << endl;
	cout << endl;

	//pantalla en espera
	system("pause");

	return 0;
}

//definicion de funcion
void cargarArreglo(char arreglo[], int i){
	for(int j = 0;j <= i; j++){
		cout << "ingrese caracter: " << endl;	
		cin >> arreglo[j];
	}

}

void mostrarArregloRecursivoDesendente(char arreglo[],int i){
	if( i == 0){
		cout << arreglo[i] << " ";
	}else{
		cout << arreglo[i] << " ";
		i = i - 1;
		//llamada de funcion recursiva
		mostrarArregloRecursivoDesendente(arreglo,i);
		
	}

}

void mostrarArregloRecursivoAsendente(char arreglo[],int i){
	if(i == 0){
		cout << arreglo[i] << " ";
	}else{
		i = i - 1;
		mostrarArregloRecursivoAsendente(arreglo,i);
		cout << arreglo[i+1] << " ";
		
	}

}

//limpia pantalla
void clearPantalla(){
	system("cls");

}
