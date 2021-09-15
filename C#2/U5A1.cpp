/* Programa para implementar el m�todo
de b�squeda lineal.
Autor: Hugo Eduardo Ontiveros Ledezma
Universidad Nacional Aut�noma de M�xico
Facultad de Contadur�a y Administraci�n
Lic. en inform�tica semestre 3
Materia: Programaci�n II: Estructura de datos
Asesor: Ram�n Arcos Gonz�lez
15 de abril del 2021 */

#include <iostream>

using namespace std;

int a[10];
int c=0, e=0;

void insertar(int n) {
	if (c<10){
		a[c] = n;
		cout << "N�mero " << n << " insertado en la posici�n " << c << ".\n";
		c++;
	} else cout << "Ha excedido el n�mero de elementos en el arreglo, ya no puede agregar m�s elementos.\n";
}

void mostrar() {
	if(c==0){
		cout <<"Arreglo vac�o, inserte elemento.\n";
	} else {
		for(int i=0; i<c; i++){
			cout << "Posici�n del arreglo " << i << " contiene " << a[i] << " .\n ";
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
	cout <<"No se encontr� el valor indicado, intente con otro valor.\n";
}

int main() {
	int opc = 0, con = 1, n, b;

	while (con) {
		cout <<"\nMen� de b�squeda lineal:\n"
		<<"1) Insertar elemento (m�ximo 10 elementos).\n"
		<<"2) Mostrar arreglo.\n"
		<<"3) Buscar elemento.\n"
		<<"4) Terminar.\n";
		cin>>opc;
		switch (opc) {

			case 1:
				cout <<"Por favor, ingrese el n�mero entero a insertar.\n";
				while (1) {
					if(cin>>n) {
						break;
					} else {
						cout << "Valor inv�lido. Por favor, ingrese un n�mero entero.\n";
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
				cout <<"Por favor, ingrese el n�mero entero a insertar.\n";
				cin.clear();
				cin.ignore(1000, '\n');
				while (1) {
					if(cin>>n) {
						break;
					} else {
						cout << "Valor inv�lido. Por favor, ingrese un n�mero entero.\n";
						cin.clear();
						cin.ignore(1000, '\n');
					}	
				}
				b = buscar(n);
				if(e == 1){
					cout <<"Valor " << a[b] <<" encontrado en la posici�n " << b << ".\n"; 
				}
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
