/* Programa que presenta al usuario un men�:
1. Ingresar un n�mero.
2. Sumarle una unidad al n�mero.
3. Restarle una unidad al n�mero.
Cada opci�n llama a una funci�n que hace lo indicado.
El men� y las opciones persisten despu�s de cada operaci�n.
Restricciones: Usar variables globales.
Autor: Hugo Eduardo Ontiveros Ledezma
Universidad Nacional Aut�noma de M�xico
Facultad de Contadur�a y Administraci�n
Lic. en inform�tica semestre 2
Materia: Introducci�n a la programaci�n
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
		cout << "No ingres� un n�mero v�lido. Por favor introduzca un n�mero entero.\n";
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
		<< "\t1. Ingresa un n�mero entero; sino se ocupa esta opci�n, se iniciar� con el n�mero 10\n"
		<< "\t2. Incrementa en una unidad entero\n"
		<< "\t3. Decrementa en una unidad entero\n";
		do {
      		cin >> opc;
      		switch (opc) {
        	case 1:
          		cout << "Por favor, ingrese un n�mero entero.\n";
          		ent = entero();
          		cout << "Usted ingres� el n�mero " << ent << ".\n";
          		break;
        	case 2:
        		cout << "El n�mero " << ent << " se ha incrementado en una unidad. ";
         		ent = incrementar(ent);
         		cout << "Su valor actual es " << ent << ".\n";
          		break;
          	case 3:
          		cout << "El n�mero " << ent << " se ha decrementado en una unidad. ";
         		ent = decrementar(ent);
         		cout << "Su valor actual es " << ent << ".\n";
          		break;
        	default:
          		cout << "No ha escogido una opci�n v�lida, por favor, escoja una opci�n v�lida.\n";
          		cin.clear();
         		cin.ignore(1000000, '\n');
      		}
   	 	} while (opc != 1 && opc != 2 && opc != 3);
	}
}
