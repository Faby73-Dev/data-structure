#include <iostream>
using namespace std;

//estructura
struct nodo{
       int num;
       nodo *sgte;
       nodo *ant;
};

//prototipo
nodo *crearNodo(int numero);
void cargarDatos(int & numero);
void mostrar(nodo *inicio);
void insertarInicio(nodo **inicio,nodo *nuevo);
int retirarInicio(nodo **inicio);

//principal
int main()
{

	nodo *inicio = NULL;
	int numero = 0, op = 0;

    do
    {
        cout << "Menu" << endl;
        cout << "1-AGREGAR ELEMENTO AL INICIO" << endl;
        cout << "2-RETIRAR ELEMENTO AL INICIO" << endl;
        cout << "3-MOSTRAR LISTA" << endl;
        cout << "4-SALIR" << endl;
        cout << "SELECCIONE OPCION" << endl;
        cin >> op;    

        switch(op)
        {
            case 1:    
                 cargarDatos(numero);  
                 insertarInicio(&inicio,crearNodo(numero));
                 cout << "LA OPERACION SE REALIZO CON EXITO!!!" << endl;
                 break;
            case 2:
                 (retirarInicio(&inicio) == 0)? cout << "LA OPERACION SE REALIZO CON EXITO" << endl : cout << "NO EXISTE O LISTA VACIA" << endl;
                 break;
            case 3:
                 mostrar(inicio);
            	 break;
            case 4:
                 cout << "FIN DEL PROGRAMA " << endl;
            	 break;
            default:
                    cout<<"OPCION INCORRECTA"<<endl;
        }
        system("pause");
        system("cls");  
    }while(op != 6);

	return 0;
}

//crear nodo
nodo *crearNodo(int numero)
{
         nodo *inicio = new nodo;
         inicio->num = numero;
         inicio->sgte = NULL;
         inicio->ant = NULL;
         
         return inicio;
}

//cargar datos
void cargarDatos(int & numero)
{
     cout << "INGRESE NUMERO ENTERO: "; 
     cin >> numero;   
}

//mostrar datos
void mostrar(nodo *inicio)
{
     if(inicio == NULL)
         cout << "LISTA VACIA" << endl;
     else
     {
        cout << "LISTA: ";
        while(inicio != NULL)
        {
           cout << inicio->num << " "; 
           inicio = inicio->sgte;
        }
     }
     cout << endl;
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