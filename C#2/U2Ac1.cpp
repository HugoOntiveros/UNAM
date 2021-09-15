/* Programa para implementar una estructura
de datos tipo pila.
Autor: Hugo Eduardo Ontiveros Ledezma
Universidad Nacional Aut�noma de M�xico
Facultad de Contadur�a y Administraci�n
Lic. en inform�tica semestre 3
Materia: Programaci�n II: Estructura de datos
Asesor: Ram�n Arcos Gonz�lez
18 de marzo del 2021 */

#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

class Pila {
	class Nodo {
	public:
		int contenido;
		Nodo *siguiente;
		Nodo(int n) : contenido(n), siguiente(NULL) {};
	};
	
	Nodo *tope;
	int tamano;

public:
	Pila() : tamano(0) {};
	
	void insertar(int n) {
		Nodo *nodo = new Nodo(n);
		nodo->siguiente = tope;
		tope = nodo;
		this->tamano++;
		cout <<"Elemento a�adido a pila: " <<n <<", tama�o actual: " <<this->tamano <<".\n";
	}
	
	void extraer() {
		Nodo *nodo;
		if (tamano>0) {
			nodo=this->tope;
			this->tope = this->tope->siguiente;
			cout << "Se elimin� el elemento al topo de la lista: " << nodo->contenido << "\n";
			delete nodo;
			tamano--;
		} else{
			cout <<"La pila est� vac�a.\n";
		}
	}
	
	void imprimir(){
		Nodo *temp = this->tope;
		for(int i=tamano; i>0; i--) {
			cout <<"Elemento n�mero " << i << " es " << temp->contenido << ".\n";
			temp = temp->siguiente;
		}
	}
};

int main() {
	srand(time(NULL));
	int a[10];
	for (int i=0; i<10; i++) {
		a[i] = rand();
		cout <<"Posici�n de arreglo " << i << " contiene: " <<a[i] <<".\n";
	}
	
	Pila p;
	for (int i=0; i<10; i++) {
		p.insertar(a[i]);
	}
	
	int opc = 0, con = 1, ent;
	while (con) {
		cout <<"Operaciones de pila:\n"
		<<"1) Insertar elemento.\n"
			<<"2) Extraer elemento.\n"
		<<"3) Mostrar todos los elementos de la pila\n"
		<<"4) Terminar.\n";
		cin>>opc;
		switch (opc) {
			case 1:
				cout <<"Por favor, ingrese el n�mero entero a insertar en el topo de la pila.\n";
				while (1) {
					if(cin>>ent) {
						p.insertar(ent);
						break;
					} else {
						cout << "Valor incorrecto. Vuelva a ingresar un entero a insertar.\n";
						cin.clear();
						cin.ignore(1000, '\n');
					}	
				} 
				break;
			case 2:
				p.extraer();
				break;
			case 3:
				p.imprimir();
				break;
			case 4:
				cout <<"Programa finzalizado.";
				con = 0;
				break;
			default:
				cout <<"No ingres� una opci�n v�lida. Por favor, vuelva a intentar ingresar una de las siguientes opciones:\n";
				cin.clear();
				cin.ignore(1000, '\n');
		}
	}
	
}
