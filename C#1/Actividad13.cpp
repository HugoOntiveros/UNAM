/* Programa para imprimir el tríangulo de 
Pascal utilizando un arreglo de 1 dimensión.
Autor: Hugo Eduardo Ontiveros Ledezma
Universidad Nacional Autónoma de México
Facultad de Contaduría y Administración
Lic. en informática semestre 2
Materia: Introducción a la programación
Asesor: RAUL OJEDA VILLAGOMEZ
25 de noviembre del 2020 */

#include <iostream>

using namespace std;

int n = 0;

int main() {
	cout << "Ingrese el número de filas a imprimir del triángulo de Pascal:\n";
	while (1) {
		if (cin>>n && n > 0) {
			break;
		} else {
			cout << "No ha ingresado un número válido. Por favor, ingrese el número de filas a imprimir.\n";
			cin.clear();
			cin.ignore(1000, '\n');
		}
	}
	cout << "El número ingresado es " << n << ". triángulo de Pascal de " << n << " filas.\n";
	
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
