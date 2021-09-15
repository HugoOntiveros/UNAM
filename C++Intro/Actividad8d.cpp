/* Programa para calcular el máximo común divisor de 2 números.
Lo hará a través de una función recursiva.
Autor: Hugo Eduardo Ontiveros Ledezma
Universidad Nacional Autónoma de México
Facultad de Contaduría y Administración
Lic. en informática semestre 2
Materia: Introducción a la programación
Asesor: RAUL OJEDA VILLAGOMEZ
09 de noviembre del 2020 */

#include <iostream>
#include <string.h>

using namespace std;


int main() {
	char c1[6] = "\0", c2[6] = "\0", c3[6] = "\0";
	int cont = 0, c1pos;
	cout << "No\tC1\tC2\tC3\tRepresentación\n";
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
