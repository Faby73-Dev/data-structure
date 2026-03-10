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

	//insertar inicio LIFO
	void insertarLifo(nodo **lista,nodo *nuevo)
	{
    	if(*lista == NULL)
        	*lista = nuevo;
      	else
      	{
          	nuevo->sgte = *lista;
          	*lista = nuevo;
      	}
	}

	//retira inicio LIFO
	int retirarLifo(nodo **lista)
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