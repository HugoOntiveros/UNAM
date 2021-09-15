/* Programa que presenta al usuario un menú:
1. Ingresar un número.
2. Sumarle una unidad al número.
3. Restarle una unidad al número.
Cada opción llama a una función que hace lo indicado.
El menú y las opciones persisten después de cada operación.
Restricciones: Usar variables globales.
Autor: Hugo Eduardo Ontiveros Ledezma
Universidad Nacional Autónoma de México
Facultad de Contaduría y Administración
Lic. en informática semestre 2
Materia: Introducción a la programación
Asesor: RAUL OJEDA VILLAGOMEZ
11 de noviembre del 2020 */

#include <iostream>

using namespace std;

int opc=0, ent=10;

int entero() {
	while (1) {
		if (cin >> ent) {
			break;
		}
		cout << "No ingresó un número válido. Por favor introduzca un número entero.\n";
		cin.clear();
		cin.ignore(1000,  '\n');
	}
	return ent;
}

int incrementar(int num) {
	num++;
	return num;
}

int decrementar(int num) {
	num--;
	return num;
}

int main() {
	while (1) {
		cout << "\nBienvenido. Por favor, seleccione una de las siguientes opciones:\n"
		<< "\t1. Ingresa un número entero; sino se ocupa esta opción, se iniciará con el número 10\n"
		<< "\t2. Incrementa en una unidad entero\n"
		<< "\t3. Decrementa en una unidad entero\n";
		do {
      		cin >> opc;
      		switch (opc) {
        	case 1:
          		cout << "Por favor, ingrese un número entero.\n";
          		ent = entero();
          		cout << "Usted ingresó el número " << ent << ".\n";
          		break;
        	case 2:
        		cout << "El número " << ent << " se ha incrementado en una unidad. ";
         		ent = incrementar(ent);
         		cout << "Su valor actual es " << ent << ".\n";
          		break;
          	case 3:
          		cout << "El número " << ent << " se ha decrementado en una unidad. ";
         		ent = decrementar(ent);
         		cout << "Su valor actual es " << ent << ".\n";
          		break;
        	default:
          		cout << "No ha escogido una opción válida, por favor, escoja una opción válida.\n";
          		cin.clear();
         		cin.ignore(1000000, '\n');
      		}
   	 	} while (opc != 1 && opc != 2 && opc != 3);
	}
}
