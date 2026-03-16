#include <iostream>
#include <string>
using namespace std;

//estructura
struct nodo{
       int num;
       nodo *sgte;
};

//prototipo
nodo *crearNodo(int num);
void cargarDatos(int &num);
void insertarInicio(nodo **lista, nodo *nuevo);
void mostrar(nodo *lista);
int retirarInicio(nodo **lista);


int main()
{
	nodo *lista = NULL;
	int n = 0, op = 0;
	
  do
  {
      cout << "MENU" << endl;
      cout << "1-MOSTRAR DATOS" << endl;
      cout << "2-AGREGAR DATOS INICIO" << endl;
      cout << "3-ELIMINAR DATOS INICIO" << endl;
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
          insertarInicio(&lista,crearNodo(n)); 
        break;
        case 3:
           (retirarInicio(&inicio) == 0)? cout << "LA OPERACION SE REALIZO CON EXITO" << endl : cout << "NO EXISTE O LISTA VACIA" << endl;
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

//retira inicio
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