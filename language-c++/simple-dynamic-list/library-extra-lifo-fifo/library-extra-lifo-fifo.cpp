#include <iostream>
//modificar ruta: "library-basic-lifo.cpp" o "library-basic-fifo.cpp"
#include "library-basic-lifo.cpp"
using namespace std;

namespace method
{
	//mostrar lista 
	void mostrar(nodo *lista)
	{
     	if(lista == NULL)
         	cout << "LISTA VACIA" << endl;
     	else
     	{
         	cout << "LISTA DE NUMEROS:";
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
    int retirarElemento(nodo **lista,int buscar)
    {
        if(*inicio != NULL)
        {
            nodo *prev = NULL,*elim;
            nodo *aux = *lista;
            while(aux != NULL)
            {
                if(aux->num == buscar)
                {
                    elim = aux;
                    if((aux->sgte == NULL)&(prev == NULL))
                    {
                        *lista = elim->sgte;
                    }
                    else
                    {
                        if(prev == NULL)
                            *lista = elim->sgte;
                        else
                            prev->sgte = elim->sgte;
                    }
                    delete(elim);
                    return 0;
                }
                else
                    prev = aux;
                aux = aux->sgte;
            }
        }
        return -1;
    }

    //retirar elemento iguales
    int retirarElementosIguales(nodo **lista,int buscar)
    {
        int bandera = -1;
        if(*inicio != NULL)
        {
            nodo *prev = NULL,*elim;
            nodo *aux = *lista;
            while(aux != NULL)
            {
                if(aux->num == buscar)
                {
                    if((aux->sgte == NULL)&(prev == NULL))
                    {
                        elim = aux;
                        *lista = elim->sgte;
                    }
                    else
                    {
                        elim = aux;
                        if(prev == NULL)
                            *lista = elim->sgte;
                        else
                            prev->sgte = elim->sgte;
                    }
                    delete(elim);
                    bandera = 0;
                }
                else
                    prev = aux;
                aux = aux->sgte;
            }
        }
        if(bandera == 0)
            return 0;
        else
            return -1;
    }

    //insertar final
    void insertarFinal(nodo **lista,nodo *nuevo)
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
}