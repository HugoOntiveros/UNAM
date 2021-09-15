/* Programa para implementar una estructura
de datos tipo lista enlazada simple.
Autor: Hugo Eduardo Ontiveros Ledezma
Universidad Nacional Autónoma de México
Facultad de Contaduría y Administración
Lic. en informática semestre 3
Materia: Programación II: Estructura de datos
Asesor: Ramón Arcos González
25 de marzo del 2021 */

#include <iostream>
#include <string.h>

using namespace std;

class ListaEnlazadaSimple {
	class Nodo {
	public:
		int Clave;
    char Descripcion[35];
    float Precio;
		Nodo *siguiente;

		Nodo(int c, float p) : 
      Clave(c), 
      Descripcion{}, 
      Precio(p), 
      siguiente(NULL)
    {};
	};
	
	Nodo *inicio, *fin;
	int tamano;

public:
	ListaEnlazadaSimple() : 
    tamano(0),
    inicio(NULL),
    fin(NULL) 
  {};

void imprimirNodo(Nodo *nodo){
    cout << "Clave: " << nodo->Clave
  << "\nDescripcion: ";
   for(int i=0; i<35; i++) {
    cout << nodo->Descripcion[i];
  }
  cout << "\nPrecio: " << nodo->Precio << "\n";
} 

void crearNodo(int c, char d[35], float p) {
  Nodo *nodo = new Nodo(c, p);
  //copy(d, d+35, nodo->Descripcion);
  strcpy(nodo->Descripcion, d);
  if(inicio == NULL) {
    inicio = nodo;
    fin = nodo;
  } else {
    fin->siguiente = nodo;
    fin = nodo;
  }
  tamano++;

  imprimirNodo(nodo);
  cout << "Tamaño actual de la lista: " << tamano << "\n\n";
} 

void eliminarNodo(int clave) {
  Nodo *actual = inicio;

  if (actual->Clave == clave) {
    inicio = inicio->siguiente;
    delete actual;
    cout << "\nSe eliminó el elemento con Clave: " << clave << "\n";
    tamano--;
    return;
  }

  Nodo *prev = inicio;
  
  for(int i=0; i<tamano; i++) {
    if (actual->Clave == clave) {
      prev->siguiente = actual->siguiente;
      delete actual;
      cout << "Se eliminó el elemento con Clave: " << clave << "\n";
      tamano--;
      return;
    } else {
      prev = actual;
      actual = actual->siguiente;
    }
  }
  cout << "No se encontró ningún producto con Clave: " << clave << "\n";
}

void imprimirLista() {
  if (inicio == NULL) {
    cout << "La lista está vacía.\n";
  } else {
    Nodo *temp = inicio;
    while(temp != NULL) {
      imprimirNodo(temp);
      temp = temp->siguiente;
    }
    cout << "Tamaño de la lista: " << tamano << "\n\n";
  }
}

};

int main() {
	ListaEnlazadaSimple l;
	int opc = 0, con = 1, cla;
  char cad[35];
  float pre;

	while (con) {
		cout <<"Operaciones de Lista Enlazada Simple:\n"
		<<"1) Insertar elemento.\n"
		<<"2) Extraer elemento.\n"
		<<"3) Mostrar todos los elementos de la lista\n"
		<<"4) Terminar.\n";
		cin>>opc;
		switch (opc) {

			case 1:
				cout <<"Por favor, ingrese la Clave (entero) del producto.\n";
				while (1) {
					if(cin>>cla) {
						break;
					} else {
						cout << "Clave inválida. Por favor, ingrese una clave como entero.\n";
						cin.clear();
						cin.ignore(1000, '\n');
					}	
				}
				cout <<"Por favor, ingrese la Descripción del producto (cadena, máximo 34 caracteres).\n";
        cin.ignore();        
        cin.getline (cad, 35);
				cout <<"Por favor, ingrese el precio del producto (float).\n";
				while (1) {
					if(cin>>pre) {
						break;
					} else {
						cout << "Precio no válido. Vuelva a ingresar el precio como un número con decimales.\n";
						cin.clear();
						cin.ignore(1000, '\n');
					}	
				}
        l.crearNodo(cla, cad, pre);
				break;

			case 2:
				cout <<"Por favor, ingrese el número de clave del producto a extraer.\n";
				while (1) {
					if(cin>>cla) {
						l.eliminarNodo(cla);
						break;
					} else {
						cout << "Clave incorrecta. Vuelva a ingresar la clave del producto como entero.\n";
						cin.clear();
						cin.ignore(1000, '\n');
					}	
				}       
				break;

			case 3:
        l.imprimirLista();
				break;

			case 4:
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
