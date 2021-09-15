/* Programa para imprimir el tr�angulo de 
Pascal utilizando un arreglo de 1 dimensi�n.
Autor: Hugo Eduardo Ontiveros Ledezma
Universidad Nacional Aut�noma de M�xico
Facultad de Contadur�a y Administraci�n
Lic. en inform�tica semestre 2
Materia: Introducci�n a la programaci�n
Asesor: RAUL OJEDA VILLAGOMEZ
25 de noviembre del 2020 */

#include <iostream>

using namespace std;

int n = 0;

int main() {
	cout << "Ingrese el n�mero de filas a imprimir del tri�ngulo de Pascal:\n";
	while (1) {
		if (cin>>n && n > 0) {
			break;
		} else {
			cout << "No ha ingresado un n�mero v�lido. Por favor, ingrese el n�mero de filas a imprimir.\n";
			cin.clear();
			cin.ignore(1000, '\n');
		}
	}
	cout << "El n�mero ingresado es " << n << ". tri�ngulo de Pascal de " << n << " filas.\n";
	
	int num[n];
	int *p = num;
	
	for (int f=0; f<n; f++) {
		cout << "\n\t";
		for(int e=f; e<n; e++) {
			cout << " ";
		}
		for (int i=f; i>=0; i--) {
			if (i==0 || i==f) {
				*(p+i) = 1;
			} else {
				*(p+i) = *(p+i)+*(p+(i-1));
			}
			cout << *(p+i) <<" ";
		}
	}
}
