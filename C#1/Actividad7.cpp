/* Programa para calcular el máximo común divisor de 2 números.
Lo hará a través de una función recursiva.
Autor: Hugo Eduardo Ontiveros Ledezma
Universidad Nacional Autónoma de México
Facultad de Contaduría y Administración
Lic. en informática semestre 2
Materia: Introducción a la programación
Asesor: RAUL OJEDA VILLAGOMEZ
04 de noviembre del 2020 */

#include <iostream>
#include <stdlib.h>

using namespace std;

int mcd (int x, int y) {
	if (y == 0) {
		return x;
	} else {
		return mcd(y, x%y);
	}
}

int main() {
	int a = 0, b = 0;
	cout << "Introduzca dos números enteros de los cuales desea conocer su máximo común divisor:\n";
	while (1) {
		if (cin >> a) {
				break;
		}
		cout << "Por favor introduzca un entero para el primer valor.\n";
		cin.clear();
		cin.ignore(1000000,  '\n');
		}
	while (1) {
		if (cin >> b) {
				break;
		}
		cout << "Por favor introduzca un entero para el segundo valor.\n";
		cin.clear();
		cin.ignore(1000000,  '\n');
		}
	int res = mcd(a,b);
	cout <<"El máximo común divisor de " << a <<" y " << b << " es " << res;
}
