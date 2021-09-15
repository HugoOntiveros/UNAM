/* Programa para implementar el método
de búsqueda lineal.
Autor: Hugo Eduardo Ontiveros Ledezma
Universidad Nacional Autónoma de México
Facultad de Contaduría y Administración
Lic. en informática semestre 3
Materia: Programación II: Estructura de datos
Asesor: Ramón Arcos González
15 de abril del 2021 */

#include <iostream>

using namespace std;

int a[10];
int c=0, e=0;

void insertar(int n) {
	if (c<10){
		a[c] = n;
		cout << "Número " << n << " insertado en la posición " << c << ".\n";
		c++;
	} else cout << "Ha excedido el número de elementos en el arreglo, ya no puede agregar más elementos.\n";
}

void mostrar() {
	if(c==0){
		cout <<"Arreglo vacío, inserte elemento.\n";
	} else {
		for(int i=0; i<c; i++){
			cout << "Posición del arreglo " << i << " contiene " << a[i] << " .\n ";
		}
	}
}

int buscar(int n) {
	e = 0;
	for (int i=0; i<c; i++){
		if(a[i] == n){
			e = 1;
			return i;
		}
	}
	cout <<"No se encontró el valor indicado, intente con otro valor.\n";
}

int main() {
	int opc = 0, con = 1, n, b;

	while (con) {
		cout <<"\nMenú de búsqueda lineal:\n"
		<<"1) Insertar elemento (máximo 10 elementos).\n"
		<<"2) Mostrar arreglo.\n"
		<<"3) Buscar elemento.\n"
		<<"4) Terminar.\n";
		cin>>opc;
		switch (opc) {

			case 1:
				cout <<"Por favor, ingrese el número entero a insertar.\n";
				while (1) {
					if(cin>>n) {
						break;
					} else {
						cout << "Valor inválido. Por favor, ingrese un número entero.\n";
						cin.clear();
						cin.ignore(1000, '\n');
					}	
				}
		        insertar(n);
				break;

 			case 2:
				mostrar();
				break;

			case 3:
				cout <<"Por favor, ingrese el número entero a insertar.\n";
				cin.clear();
				cin.ignore(1000, '\n');
				while (1) {
					if(cin>>n) {
						break;
					} else {
						cout << "Valor inválido. Por favor, ingrese un número entero.\n";
						cin.clear();
						cin.ignore(1000, '\n');
					}	
				}
				b = buscar(n);
				if(e == 1){
					cout <<"Valor " << a[b] <<" encontrado en la posición " << b << ".\n"; 
				}
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
