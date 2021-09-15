/* Programa que resuelve una ecuación cuadrática utilizando la ecuación general de segundo grado. 
Se deben ingresar 3 valores a diferente de 0, b y c, y se debe devolver X1 y X2, en caso que existan soluciones.
Autor: Hugo Eduardo Ontiveros Ledezma
Universidad Nacional Autónoma de México
Facultad de Contaduría y Administración
Lic. en informática semestre 2
Materia: Introducción a la programación
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
		cout << "Por favor introduzca un valor válido para a.\n";
		cin.clear();
		cin.ignore(1000,  '\n');
	}
	cout << "Por favor, introduzca el valor de b.\n";
	while (1) {
		if (cin >> b) {
			break;
		}
		cout << "Por favor introduzca un valor válido para b.\n";
		cin.clear();
		cin.ignore(1000,  '\n');
	}
	cout << "Por favor, introduzca el valor de c.\n";
	while (1) {
		if (cin >> c) {
			break;
		}
		cout << "Por favor introduzca un valor válido para c.\n";
		cin.clear();
		cin.ignore(1000,  '\n');
	}
	cout << "El valor de a es " << a;
	cout << "\nEl valor de b es " << b;
	cout << "\nEl valor de c es " << c;
	// Calcular el discriminante de la fórmula general para determinar si hay soluciones.
	double d = b * b - 4 * a * c;
	//cout << "\nEl discriminante es " << d;
	if (d > 0) {
		double r = sqrt(d);
		double X1 = (-b + r) / (2 * a);
		double X2 = (-b - r) / (2 * a);
		cout << "\nLas soluciones para esta ecuación cuadrática son X1 = " << X1 << " y X2 = " << X2;
	} else if (d == 0) {
		double x = -b / 2 * a;
		cout << "\nEsta ecuación cuadrática tiene solo una solución con multiplicidad doble, por lo que X1 = X2 = " << x;
	} else {
		cout << "\nEsta ecuación cuadrática no tiene soluciones en el conjunto de los números reales";
	}
}
