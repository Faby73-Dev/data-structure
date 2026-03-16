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

  //retirar final
  int retirarFinal(nodo **lista)
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