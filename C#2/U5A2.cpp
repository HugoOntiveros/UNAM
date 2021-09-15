/* Programa para el método de 
búsqueda con árboles binarios
Autor: Hugo Eduardo Ontiveros Ledezma
Universidad Nacional Autónoma de México
Facultad de Contaduría y Administración
Lic. en informática semestre 3
Materia: Programación II: Estructura de datos
Asesor: Ramón Arcos González
01 de junio del 2021 */

#include <iostream>

using namespace std;

class Arbol {
	class Nodo {
	public:
		int Numero;
		Nodo *izq;
    Nodo *der;

		Nodo(int n) : 
      Numero(n),
      izq(NULL), 
      der(NULL)
    {};
	};

  Nodo *raiz;

  Nodo* insertar(int n, Nodo* hoja) {
    if(hoja == NULL){
      hoja = new Nodo(n);
    } else if(n < hoja->Numero) {
            hoja->izq = insertar(n, hoja->izq);
    } else if(n > hoja->Numero) {
            hoja->der = insertar(n, hoja->der);
    }
    return hoja;
  }

void preOrden(Nodo *raiz)
{
     if(raiz!=NULL)
     {
          cout << raiz->Numero <<" ";
          preOrden(raiz->izq);
          preOrden(raiz->der);
     }
}

void enOrden(Nodo *raiz)
{
     if(raiz!=NULL)
     {
          enOrden(raiz->izq);
          cout << raiz->Numero <<" ";
          enOrden(raiz->der);
     }
}

void postOrden(Nodo *raiz)
{
     if(raiz!=NULL)
     {
          postOrden(raiz->izq);
          postOrden(raiz->der);
          cout << raiz->Numero <<" ";
     }
}

int buscar(int n, Nodo *raiz){
	if(raiz != NULL){
		if(raiz->Numero > n){
			buscar(n, raiz->izq);
		} else if (raiz->Numero < n){
			buscar(n, raiz->der);
		} else {
			return raiz->Numero;
		}
	} else {
		return 0;
	}
}

  public:

  Arbol(){
    raiz = NULL;
  }

  void insertar(int n) {
    raiz = insertar(n, raiz);
  } 

  void imprimirPreOrden() {
    preOrden(raiz);
    cout << "\n";
  }

  void imprimirEnOrden() {
    enOrden(raiz);
    cout << "\n";
  }

  void imprimirPostOrden() {
    postOrden(raiz);
    cout << "\n";
  }
  
  void imprimirBuscar(int n) {
  	int res = buscar(n, raiz);
  	if (res==0){
  		cout <<"No se encontró el elemento " <<n <<" en el árbol binario, intente de nuevo.\n";
	  } else {
	  	cout <<"Se encontró el elemento " <<n <<" en el árbol binario.\n";
	  }
  }

};

int main() {
	Arbol a;
	int opc = 0, con = 1, n;

	while (con) {
		cout <<"\nOperaciones del árbol binario de búsqueda:\n"
		<<"1) Insertar elemento.\n"
		<<"2) Recorren en pre-orden.\n"
		<<"3) Recorren en orden.\n"
		<<"4) Recorren en post-orden.\n"
		<<"5) Buscar elemento.\n"
		<<"6) Terminar.\n";
		cin>>opc;
		switch (opc) {

			case 1:
				cout <<"Por favor, ingrese el número.\n";
				while (1) {
					if(cin>>n) {
						break;
					} else {
						cout << "Clave inválida. Por favor, ingrese una clave como entero.\n";
						cin.clear();
						cin.ignore(1000, '\n');
					}	
				}
        		a.insertar(n);
				break;

 			case 2:
				a.imprimirPreOrden();
				break;

			case 3:
				a.imprimirEnOrden();
				break;

			case 4:
				a.imprimirPostOrden();
				break;        

			case 5:
				cout <<"Por favor, ingrese el número.\n";
				while (1) {
					if(cin>>n) {
						break;
					} else {
						cout << "Clave inválida. Por favor, ingrese una clave como entero.\n";
						cin.clear();
						cin.ignore(1000, '\n');
					}	
				}
        		a.imprimirBuscar(n);
				break;



			case 6:
				cout <<"Programa finzalizado.";
				con = 0;
				break;
				
 
			default:
				cout <<"No ingresó una opción válida. Por favor, vuelva a intentar ingresar una de las siguientes opciones:\n";
				cin.clear();
				cin.ignore(1000, '\n');
		}
	}
}
