/* Programa que resuelve una ecuaci�n cuadr�tica utilizando la ecuaci�n general de segundo grado. 
Se deben ingresar 3 valores a diferente de 0, b y c, y se debe devolver X1 y X2, en caso que existan soluciones.
Autor: Hugo Eduardo Ontiveros Ledezma
Universidad Nacional Aut�noma de M�xico
Facultad de Contadur�a y Administraci�n
Lic. en inform�tica semestre 2
Materia: Introducci�n a la programaci�n
Asesor: RAUL OJEDA VILLAGOMEZ
20 de octubre del 2020 */

#include <iostream>
#include <stdlib.h>
#include <math.h>

using namespace std;

int main() {
	double a=0, b=0, c=0;
	cout << "Por favor, introduzca el valor de a.\n";
	while (1) {
		if (cin >> a && a != 0) {
			break;
		}
		cout << "Por favor introduzca un valor v�lido para a.\n";
		cin.clear();
		cin.ignore(1000,  '\n');
	}
	cout << "Por favor, introduzca el valor de b.\n";
	while (1) {
		if (cin >> b) {
			break;
		}
		cout << "Por favor introduzca un valor v�lido para b.\n";
		cin.clear();
		cin.ignore(1000,  '\n');
	}
	cout << "Por favor, introduzca el valor de c.\n";
	while (1) {
		if (cin >> c) {
			break;
		}
		cout << "Por favor introduzca un valor v�lido para c.\n";
		cin.clear();
		cin.ignore(1000,  '\n');
	}
	cout << "El valor de a es " << a;
	cout << "\nEl valor de b es " << b;
	cout << "\nEl valor de c es " << c;
	// Calcular el discriminante de la f�rmula general para determinar si hay soluciones.
	double d = b * b - 4 * a * c;
	//cout << "\nEl discriminante es " << d;
	if (d > 0) {
		double r = sqrt(d);
		double X1 = (-b + r) / (2 * a);
		double X2 = (-b - r) / (2 * a);
		cout << "\nLas soluciones para esta ecuaci�n cuadr�tica son X1 = " << X1 << " y X2 = " << X2;
	} else if (d == 0) {
		double x = -b / 2 * a;
		cout << "\nEsta ecuaci�n cuadr�tica tiene solo una soluci�n con multiplicidad doble, por lo que X1 = X2 = " << x;
	} else {
		cout << "\nEsta ecuaci�n cuadr�tica no tiene soluciones en el conjunto de los n�meros reales";
	}
}
