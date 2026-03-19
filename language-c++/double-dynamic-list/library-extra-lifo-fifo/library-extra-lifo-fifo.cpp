#include <iostream>
//modificar ruta: "library-basic-lifo.cpp" o "library-basic-fifo.cpp"
#include "library-basic-lifo.cpp"
using namespace std;

namespace method
{
	//mostrar lista
	void mostrar(producto *lista)
	{
     	if(lista == NULL)
         cout << "LISTA VACIA" << endl;
     	else
     	{
         	cout << "LISTA DE NUMEROS" << endl;
        	while(lista != NULL)
        	{
           		cout << " " << lista->num << " "; 
                lista = lista->sgte;
        	}
     	}
     	cout << endl;
	}

	//cargar datos 
	void cargarDatos(int &num)
	{
     	cout << "INGRESE NUMERO: "; 
     	cin >> num;  
	}

	//buscar elemento
    int buscarElemento(nodo *lista,int buscar)
    {
        while(lista != NULL)
            if(lista->num == buscar)
                return 0;
            else
                lista = lista->sgte;
        return -1;
    }


    //eleminar segun elemento
	int retirarElemento(nodo **inicio,int buscar)
	{
    	if(*inicio != NULL)
    	{
        	nodo *aux = *inicio;
        	while(aux != NULL)
        	{
            	if(aux->num == buscar)
            	{
                	if((aux->sgte == NULL)&(aux->ant == NULL))
                     	*inicio = aux->sgte;
                	else
                	{
                    	if(aux->ant == NULL)
                    	{
                        	aux->sgte->ant = aux->ant;
                        	*inicio = aux->sgte;
                        	aux->sgte = NULL;
                    	}
                    	else
                        	if(aux->sgte != NULL)
                        	{
                            	aux->sgte->ant = aux->ant;
                            	aux->ant->sgte = aux->sgte;
                            	aux->sgte = NULL;
                        	}
                        	else
                            	aux->ant->sgte = aux->sgte;
                    		aux->ant = NULL;
                	}
                	delete aux;
                	return 0;
            	}
            	else
                	aux = aux->sgte;
        	}
    	}
    	return -1;
	}

	//retirar elemento iguales
	int retirarElementosIguales(nodo **inicio,int buscar)
	{
    	int bandera = -1;
    	if(*inicio != NULL)
    	{
        	nodo *post = NULL;
        	nodo *aux = *inicio;
        	while(aux != NULL)
        	{
            	if(aux->num == buscar)
            	{
                	post = aux->sgte;
                	if((aux->sgte == NULL)&(aux->ant == NULL))
                	{
                     	*inicio = aux->sgte;
                	}
                	else
                	{
                    	if(aux->ant == NULL)
                    	{
                        	aux->sgte->ant = aux->ant;
                        	*inicio = aux->sgte;
                        	aux->sgte = NULL;
                    	}
                    	else
                        	if(aux->sgte != NULL)
                        	{
                            	aux->sgte->ant = aux->ant;
                            	aux->ant->sgte = aux->sgte;
                            	aux->sgte = NULL;
                        	}
                        	else
                            	aux->ant->sgte = aux->sgte;
                    		aux->ant = NULL;
                	}
                	delete aux;
                	bandera = 0;
                	aux = post;
            	}
            	else
                	aux = aux->sgte;
        	}
    	}
    	if(bandera == 0)
      		return 0;
    	else
      		return -1;
	}

	//retirar final
	int retirarFinal(nodo **inicio)
	{
     	if(*inicio == NULL)
         	return -1;
     	else
     	{
         	nodo *aux = *inicio;
         	if(aux->sgte == NULL)
         	{
             	*inicio = aux->sgte;
        	}
         	else
         	{
             	while(aux->sgte != NULL)
             	{
                 	aux = aux->sgte;
             	}
             	aux->ant->sgte = aux->sgte;
             	aux->ant = aux->sgte;
         	}
         	delete aux;
     	}
     	return 0;
	}

	//insertar lista ordenada de menor a mayor
	void insertarListaOrdenada(nodo **inicio,nodo *nuevo)
	{
    	if(*inicio == NULL)
        	*inicio = nuevo;
    	else
    	{
        	nodo *aux = *inicio;
        	while((aux->num < nuevo->num)&(aux->sgte != NULL))
             	aux = aux->sgte;
        	if((aux->ant == NULL)&(nuevo->num < aux->num))
        	{
             	aux->ant = nuevo;
             	nuevo->sgte = aux;
             	*inicio = nuevo;
        	}
        	else
        	{
            	if((aux->sgte == NULL)&(aux->num < nuevo->num))
            	{
                	aux->sgte = nuevo;
                	nuevo->ant = aux;
            	}
            	else
            	{
                	nuevo->sgte = aux;
                	nuevo->ant = aux->ant;
                	aux->ant->sgte = nuevo;
                	aux->ant = nuevo;
            	}
        	}
    	}
	}
}