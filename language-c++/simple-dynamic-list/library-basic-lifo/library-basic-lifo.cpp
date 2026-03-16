#include <iostream>
using namespace std;

//estructura
struct nodo{
       int num;
       nodo *sgte;
};

namespace methodlifo
{
	//crear nodo
	nodo *crearNodo(int num)
	{
    	nodo *nod = new nodo;
    	nod->num = num;
    	nod->sgte = NULL;
         
    	return nod;
	}

	//insertar inicio
	void insertarInicio(nodo **lista,nodo *nuevo)
	{
    	if(*lista == NULL)
        	*lista = nuevo;
      	else
      	{
          	nuevo->sgte = *lista;
          	*lista = nuevo;
      	}
	}

	//retirar inicio
	int retirarInicio(nodo **lista)
	{
  		if (*lista == NULL)
    		return -1;
  		else
  		{
    		nodo *aux = *lista;
    		*lista = aux->sgte;
    		delete(aux);
  		}
      return 0;
	}

}