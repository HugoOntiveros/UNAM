/* Programa para calcular el m�ximo com�n divisor de 2 n�meros.
Lo har� a trav�s de una funci�n recursiva.
Autor: Hugo Eduardo Ontiveros Ledezma
Universidad Nacional Aut�noma de M�xico
Facultad de Contadur�a y Administraci�n
Lic. en inform�tica semestre 2
Materia: Introducci�n a la programaci�n
Asesor: RAUL OJEDA VILLAGOMEZ
09 de noviembre del 2020 */

#include <iostream>
#include <string.h>

using namespace std;


int main() {
	char c1[6] = "\0", c2[6] = "\0", c3[6] = "\0";
	int cont = 0, c1pos;
	cout << "No\tC1\tC2\tC3\tRepresentaci�n\n";
	for (int a5 = 1; a5<=3; a5++){
		char b5[2] = "5";
		switch (a5) {
			case 1:
				strcat(c1, b5);
				break;
			case 2:
				strcat(c2, b5);
				break;
			case 3:
				strcat(c3, b5);
				break;
		}
		for (int a4 = 1; a4<=3; a4++){
			char b4[2] = "4";
			switch (a4) {
				case 1:
					cont++;
					strcat(c1, b4);
					cout <<cont << "\t" << c1 << "\t" << c2 << "\t" << c3 <<"\n";
					break;
				case 2:
					cont++;
					strcat(c2, b4);
					cout <<cont << "\t" << c1 << "\t" << c2 << "\t" << c3 <<"\n";
					break;
				case 3:
					cont++;
					strcat(c3, b4);
					cout <<cont << "\t" << c1 << "\t" << c2 << "\t" << c3 <<"\n";
					break;
			}
		}
	}
}
