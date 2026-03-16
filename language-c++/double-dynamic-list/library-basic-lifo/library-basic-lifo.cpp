#include <iostream>
using namespace std;

//estructura
struct nodo{
       int num;
       nodo *sgte;
       nodo *ant;
};

namespace methodlifo
{
	//crear nodo
	nodo *crearNodo(int numero)
	{
         nodo *inicio = new nodo;
         inicio->num = numero;
         inicio->sgte = NULL;
         inicio->ant = NULL;
         
         return inicio;
	}

	//insertar inicio
	void insertarInicio(nodo **inicio,nodo *nuevo)
	{
     	if(*inicio == NULL)
        	*inicio = nuevo;
     	else
      	{
        	nuevo->sgte = *inicio;
        	nuevo->sgte->ant = nuevo;
          	*inicio = nuevo;
      	}
	}

	//retirar inicio
	int retirarInicio(nodo **inicio)
	{
    	if(*inicio == NULL)
       		return -1;
    	else
     	{
        	nodo *aux = *inicio;
        	if(aux->sgte != NULL)
            	aux->sgte->ant = NULL;
        	*inicio = aux->sgte;
        	delete aux;
    	}

     	return 0;
	}

}