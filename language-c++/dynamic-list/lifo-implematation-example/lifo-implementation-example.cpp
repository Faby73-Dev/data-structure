#include <iostream>
#include <string>
using namespace std;

//estructura
struct nodo{
       int num;
       nodo *sgte;
};

nodo *crearNodo(int num);
void cargarDatos(int &num);
void insertarLifo(nodo **lista, nodo *nuevo);
void mostrar(nodo *lista);
int retirarLifo(nodo **lista);


int main()
{
	nodo *lista = NULL;
	int n = 0, op = 0;
	
  do
  {
      cout << "MENU" << endl;
      cout << "1-MOSTRAR DATOS" << endl;
      cout << "2-AGREGAR DATOS (METODO LIFO)" << endl;
      cout << "3-ELIMINAR DATOS (METODO LIFO)" << endl;
      cout << "4-SALIR" << endl;
      cout << "SELECCIONE OPCION: ";
      cin >> op;
      switch (op)
      {
        case 1:
          mostrar(lista);
        break;
        case 2:
          cargarDatos(n);
          insertarLifo(&lista,crearNodo(n)); 
        break;
        case 3:
          if (retirarLifo(&lista) == -1)
              cout << "LISTA VACIA" << endl;
          else
              cout << "ELEMENTO ELIMINADO" << endl;
        break;
        case 4:
          cout << "FIN DEL PROGRAMA" << endl;
        break;
        default:
          cout << "OPCION INCORRECTA" << endl;
      }
      system("pause");  
      system("cls");  

  }while(op != 4);

	return 0;
}

//crear nodo
nodo *crearNodo(int num)
{
    nodo *nod = new nodo;
    nod->num = num;
    nod->sgte = NULL;
         
    return nod;
}

//cargar datos
void cargarDatos(int &num)
{
     cout << "INGRESE NUMERO: "; 
     cin >> num;  
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

//mostrar lista
void mostrar(nodo *lista)
{
     int indice = 0;
     if(lista == NULL)
         cout << "LISTA VACIA" << endl;
     else
     {
         cout << "LISTA DE NUMEROS:";
        while(lista != NULL)
        {
           cout << " " << lista->num << " "; 
           indice++;
           lista = lista->sgte;
        }
     }
     cout << endl;
}

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