/* Programa para generar cuadrados m�gicos de 
orden n cuando n impar mayor a 3 y menor a 10.
Autor: Hugo Eduardo Ontiveros Ledezma
Universidad Nacional Aut�noma de M�xico
Facultad de Contadur�a y Administraci�n
Lic. en inform�tica semestre 2
Materia: Introducci�n a la programaci�n
Asesor: RAUL OJEDA VILLAGOMEZ
18 de noviembre del 2020 */

#include <iostream>
#include <math.h>

using namespace std;

int opc = 0, n = 0;

int main() {
	cout << "Ingrese un n�mero impar n mayor a 3 y menor a 10 para calcular un cuadrado m�gico de orden n:\n";
	while (1) {
		if (cin>>n && n > 3 && n < 10 && n % 2 == 1) {
			break;
		} else {
			cout << "No ha ingresado un n�mero v�lido. Por favor, ingrese un n�mero impar mayor a 3 y menor a 10.\n";
			cin.clear();
			cin.ignore(1000, '\n');
		}
	}
	cout << "El n�mero ingresado es " << n << ". Generando cuadrado m�gico de orden " << n << ".\n";
	
	int cuadradoM[n][n] = {0};
	// No se porq qu� hay valores que no se me asignan a 0 a pesar de la l�nea de arriba, as� que:
	for (int c = 0; c < n; c++) {
		for (int f =0; f < n; f++) {
			cuadradoM[c][f] = 0;
		}
	}
	
	/*for (int c = 0; c < n; c++) {
		for (int f =0; f < n; f++) {
			cout << " " << cuadradoM[c][f];
		}
		cout << "\n";
	}*/	
	
	int c = n/2, f = n-1;
	
	for (int i=1; i <= n*n; i++) {
		if (c == -1 && f == n) {
			c = 0;
			f = n - 2;
		}
		else {
			if (c < 0) {
				c = n-1;
			}
			if (f == n) {
				f = 0;
			}
		}
		if (cuadradoM[c][f] != 0) {
			c++;
			f -= 2;
			i--;
		}
		else {
			cuadradoM[c][f] = i;
			c--;
			f++;
		}
	}
	
	for (c = 0; c < n; c++) {
		for (f = 0; f < n; f++) {
			cout << "  " << cuadradoM[c][f];
		}
		cout << "\n";
	}
}
