/* Programa para generar cuadrados mágicos de 
orden n cuando n impar mayor a 3 y menor a 10.
Autor: Hugo Eduardo Ontiveros Ledezma
Universidad Nacional Autónoma de México
Facultad de Contaduría y Administración
Lic. en informática semestre 2
Materia: Introducción a la programación
Asesor: RAUL OJEDA VILLAGOMEZ
18 de noviembre del 2020 */

#include <iostream>
#include <math.h>

using namespace std;

int opc = 0, n = 0;

int main() {
	cout << "Ingrese un número impar n mayor a 3 y menor a 10 para calcular un cuadrado mágico de orden n:\n";
	while (1) {
		if (cin>>n && n > 3 && n < 10 && n % 2 == 1) {
			break;
		} else {
			cout << "No ha ingresado un número válido. Por favor, ingrese un número impar mayor a 3 y menor a 10.\n";
			cin.clear();
			cin.ignore(1000, '\n');
		}
	}
	cout << "El número ingresado es " << n << ". Generando cuadrado mágico de orden " << n << ".\n";
	
	int cuadradoM[n][n] = {0};
	// No se porq qué hay valores que no se me asignan a 0 a pesar de la línea de arriba, así que:
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
