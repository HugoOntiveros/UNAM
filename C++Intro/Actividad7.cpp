/* Programa para calcular el m�ximo com�n divisor de 2 n�meros.
Lo har� a trav�s de una funci�n recursiva.
Autor: Hugo Eduardo Ontiveros Ledezma
Universidad Nacional Aut�noma de M�xico
Facultad de Contadur�a y Administraci�n
Lic. en inform�tica semestre 2
Materia: Introducci�n a la programaci�n
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
	cout << "Introduzca dos n�meros enteros de los cuales desea conocer su m�ximo com�n divisor:\n";
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
	cout <<"El m�ximo com�n divisor de " << a <<" y " << b << " es " << res;
}
