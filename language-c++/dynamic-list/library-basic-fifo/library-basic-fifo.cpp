#include <iostream>
using namespace std;

//estructura
struct nodo{
       int num;
       nodo *sgte;
};

namespace methodfifo
{
	//crear nodo
	nodo *crearNodo(int num)
	{
    	nodo *nod = new nodo;
    	nod->num = num;
    	nod->sgte = NULL;
         
    	return nod;
	}

	//insertar final FIFO
	void insertarfifo(nodo **lista,nodo *nuevo)
	{
    	if(*lista == NULL)
        	*lista = nuevo;
      	else
      	{
            nodo *aux = *lista;
            while(aux->sgte != NULL)
            {
              aux = aux->sgte;
            }
          	aux->sgte = *nuevo;
      	}
	}

  //retirar final FIFO
  int retirarfifo(nodo **lista)
  {
     nodo *elim;
     if(*lista == NULL)
         return -1;
     else
     {
         nodo *aux = *inicio;
         if(aux->sgte == NULL)
         {
             elim = aux;
             *lista = elim->sgte;
         }
         else
         {
             while(aux->sgte->sgte != NULL)
             {
                 aux = aux->sgte;
             }
             elim = aux->sgte;
             aux->sgte = aux->sgte->sgte;
         }
         delete(elim);
     }
     return 0;
  }

}