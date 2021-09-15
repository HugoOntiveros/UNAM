/* Programa para implementar una estructura
de datos tipo grafo utilizando listas de 
adyacencia.
Autor: Hugo Eduardo Ontiveros Ledezma
Universidad Nacional Autónoma de México
Facultad de Contaduría y Administración
Lic. en informática semestre 3
Materia: Programación II: Estructura de datos
Asesor: Ramón Arcos González
22 de abril del 2021 */

#include <iostream>
#include <string.h>

using namespace std;

class Grafo {

  class ListaEnlazadaSimple {
  public:
	  class Nodo {
	  public:
		  int Clave;
      char Descripcion[15];
		  Nodo *siguiente;

	Nodo(int c) : 
        Clave(c),  
        Descripcion(),
        siguiente(NULL)
      {};
	  };
  
	  Nodo *inicio, *fin;
	  int tamano;

	ListaEnlazadaSimple() : 
    tamano(0),
    inicio(NULL),
    fin(NULL)
    {};

  void imprimirNodo(Nodo *nodo){
    //cout << "Clave: " << nodo->Clave;
    cout << "\n\t";
    for(int i=0; i<15; i++) {
      cout << nodo->Descripcion[i];
    }
  } 

  void crearNodo(int c, char d[15]) {
    Nodo *nodo = new Nodo(c);
    strcpy(nodo->Descripcion, d);
    if(inicio == NULL) {
      inicio = nodo;
      fin = nodo;
    } else {
      fin->siguiente = nodo;
      fin = nodo;
    }
    tamano++;

    //imprimirNodo(nodo);
    //cout << "Tamaño actual de la lista: " << tamano << "\n\n";
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
      cout << "\n\tSin vecinos.";
    } else {
      Nodo *temp = inicio;
      while(temp != NULL) {
        imprimirNodo(temp);
        temp = temp->siguiente;
      }
      //cout << "Tamaño de la lista: " << tamano << "\n\n";
    }
  }

  };

  class Vertice {
    public:
    char nombre[15];
    int num;
    ListaEnlazadaSimple *vecinos;
    Vertice *siguiente;

    Vertice(int num) :
      num(num),
      nombre(),
      vecinos(NULL),
      siguiente(NULL)
      {}
  };


  int estados;
  Vertice *inicio, *fin;

public:
Grafo() :
    estados(0),
    inicio(NULL),
    fin(NULL)
  {}; 

  void crearVertice(char e[15]){
    estados++;
    Vertice *vert = new Vertice(estados);
    strcpy(vert->nombre, e);
    vert->vecinos = new ListaEnlazadaSimple();
    
    if(inicio == NULL){
      inicio = vert;
      fin = vert;
    } else {
      fin->siguiente = vert;
      fin = vert;
    }
    cout << "Número de estados en el grafo: " <<estados<<"\n\n";
  }

  void imprimirVertice(Vertice *vert){
      cout << "Clave de estado: " << vert->num
    << "\n";
    for(int i=0; i<15; i++) {
      cout << vert->nombre[i];
    }
    vert->vecinos->imprimirLista();
    cout << "\n\n";
  } 

  void crearArista(int c1, int c2){
    if(estados <2) {
      cout <<"Error: debe haber por lo menos 2 estados para que sean vecions.\n";
      return;
    }
    if(c1 == c2) {
      cout <<"Error: las claves de estado deben ser distintas.\n";
    }
    Vertice *temp1 = inicio;
    Vertice *temp2 = inicio;
    for(int i=1; i<=estados; i++){
      if(temp1->num == c1) {
        for(int j=1; i<=estados; j++) {
          if(temp2->num == c2) {
            temp1->vecinos->crearNodo(c2, temp2->nombre);
            temp2->vecinos->crearNodo(c1, temp1->nombre);
            cout << "Los estados " << temp1->nombre << " y " << temp2->nombre << " se han registrado como adyacentes.\n\n";
            return;
          } else {
            temp2 = temp2->siguiente;
          }
        } cout << "No se encontró la clave del segundo estado.\n";
      } else {
        temp1 = temp1->siguiente;
      } 
    } cout << "No se encontró la clave del primer estado.\n"; 
  }

  void imprimirGrafo() {
    if (inicio == NULL) {
      cout << "La lista está vacía.\n";
    } else {
      Vertice *temp = inicio;
      while(temp != NULL) {
        imprimirVertice(temp);
        temp = temp->siguiente;
      }
    cout << "Número de estados en la lista: " <<estados <<"\n";
    }
  }

};

int main() {
	int opc = 0, con = 1, cla1, cla2;
  char cad[15];

  Grafo g;

 	while (con) {
		cout <<"Operaciones de grafo:\n"
		<<"1) Insertar estado.\n"
		<<"2) Establecer adyacencia.\n"
		<<"3) Mostrar todos los elementos del grafo\n"
		<<"4) Terminar.\n";
		cin>>opc;
		switch (opc) {

			case 1:
				cout <<"Por favor, ingrese el nombre del estado (cadena, máximo 14 caracteres).\n";
        cin.clear();
		cin.ignore(1000, '\n');        
        cin.getline (cad, 15);
        g.crearVertice(cad);
				break;

			case 2:
				cout <<"Por favor, ingrese la clave (entero) del estado.\n";
				while (1) {
					if(cin>>cla1) {
						break;
					} else {
						cout << "Clave inválida. Por favor, ingrese una clave como entero.\n";
						cin.clear();
						cin.ignore(1000, '\n');
					}	
				}
				cout <<"Por favor, ingrese la clave (entero) del estado vecino.\n";
				while (1) {
					if(cin>>cla2) {
						break;
					} else {
						cout << "Precio no válido. Vuelva a ingresar el precio como un número con decimales.\n";
						cin.clear();
						cin.ignore(1000, '\n');
					}	
				}
        g.crearArista(cla1, cla2);
				break;

			case 3:
        g.imprimirGrafo();
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
