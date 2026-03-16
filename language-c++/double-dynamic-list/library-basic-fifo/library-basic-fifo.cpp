#include <iostream>
using namespace std;

//estructura
struct nodo{
       int num;
       nodo *sgte;
       nodo *ant;
};

namespace methodfifo
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
}