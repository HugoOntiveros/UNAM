/* Programa para generar RFC sin homoclave
a partir de nombre completo y fecha utilizando
únicamente C-strings.
Autor: Hugo Eduardo Ontiveros Ledezma
Universidad Nacional Autónoma de México
Facultad de Contaduría y Administración
Lic. en informática semestre 2
Materia: Introducción a la programación
Asesor: RAUL OJEDA VILLAGOMEZ
02 de diciembre del 2020 */

#include <iostream>

using namespace std;

char apellido1[20] = "";
char apellido2[20] = "";
char nombre[20] = "";
char fecha[9] = "";

int main() {
	cout << "Programa para generar su RFC a partir de su fecha de nacimiento, nombre y apellidos.:\nPor favor, ingrese su apellido paterno en mayúsculas.\n";
	while (1) {
		if (cin>>apellido1) {
			break;
		} else {
			cout << "Error al ingresar su apellido, por favor, vuelva a ingresar su apellido paterno.\n";
			cin.clear();
			cin.ignore(1000, '\n');
		}
	}
	cout << "Por favor, ingrese su apellido materno en mayúsculas.\n";
	while (1) {
		if (cin>>apellido2) {
			break;
		} else {
			cout << "Error al ingresar su apellido, por favor, vuelva a ingresar su apellido materno.\n";
			cin.clear();
			cin.ignore(1000, '\n');
		}
	}
	cout << "Por favor, ingrese su primer nombre en mayúsculas.\n";
	while (1) {
		if (cin>>nombre) {
			break;
		} else {
			cout << "Error al ingresar su nombre, por favor, vuelva a ingresar su nombre.\n";
			cin.clear();
			cin.ignore(1000, '\n');
		}
	}
	cout << "Por favor, ingrese su fecha de nacimiento con formato dd/mm/aa.\n";
	while (1) {
		if (cin>>fecha) {
			break;
		} else {
			cout << "Error al ingresar su apellido, por favor, vuelve a ingresar su apellido paterno.\n";
			cin.clear();
			cin.ignore(1000, '\n');
		}
	}
	cout << "El nombre completo ingresado es " << nombre <<" " << apellido1 <<" " << apellido2 << " y la fecha es " << fecha <<"\n";
	
	char RFC[14] = "AAAA000000XXX";
	RFC[0] = *apellido1;
	for (int i = 1; i<21; i++) {
		if(apellido1[i]== 'A' || apellido1[i] == 'E' || apellido1[i] == 'I' || apellido1[i] == 'O' || apellido1[i] == 'U') {
			cout << "Coincidencia\n";
			RFC[1] = *(apellido1+i);
			break;
		}
	}
	RFC[2] = *apellido2;
	RFC[3] = *nombre;
	RFC[4] = fecha[6];
	RFC[5] = fecha[7];
	RFC[6] = fecha[3];
	RFC[7] = fecha[4];
	RFC[8] = *fecha;
	RFC[9] = fecha[1];
	cout << RFC;
}
