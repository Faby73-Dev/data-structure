#include <iostream>
#include <conio.h>

using namespace std;

//prototipo
void cargarArreglo(int arreglo[],int);
void mostrarArregloRecursivoDesendente(int arreglo[],int);
void mostrarArregloRecursivoAsendente(int arreglo[],int);
void clearPantalla();


int main(){
	clearPantalla();
	int indice = 29;
	int arreglo[indice];

	cout << "-----------Carga de valores enteros---------" << endl;	
	cargarArreglo(arreglo,indice);
	clearPantalla();

	cout << "-----Datos mostrados de manera recursiva (posicion desendente)----" << endl;	
	mostrarArregloRecursivoDesendente(arreglo,indice);

	cout << "-----Datos mostrados de manera recursiva (posicion asendente)----" << endl;	
	mostrarArregloRecursivoAsendente(arreglo,indice);

	//pantalla en espera
	system("pause");

	return 0;
}

//definicion de funcion
void cargarArreglo(int arreglo[], int i){
	for(int j = 0;j <= i; j++){
		cout << "ingrese valor entero: " << endl;	
		cin >> arreglo[j];
	}

}

void mostrarArregloRecursivoDesendente(int arreglo[],int i){
	if( i == 0){
		cout << " pocision " << i << " el valor es : " << arreglo[i] << endl;
	}else{
		cout << " pocision " << i << " el valor es : " << arreglo[i] << endl;
		i = i - 1;
		//llamada de funcion recursiva
		mostrarArregloRecursivoDesendente(arreglo,i);
		
	}

}

void mostrarArregloRecursivoAsendente(int arreglo[],int i){
	if(i == 0){
		cout << " pocision " << i << " el valor es : " << arreglo[i] << endl;
	}else{
		i = i - 1;
		mostrarArregloRecursivoAsendente(arreglo,i);
		cout << " pocision " << i+1 << " el valor es : " << arreglo[i+1] << endl;
		
	}

}

//limpia pantalla
void clearPantalla(){
	system("cls");

}
