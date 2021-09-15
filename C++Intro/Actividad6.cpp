/* Programa que ejecuta 3 diferentes opciones seg�n la elecci�n del usuario."
La primera funci�n pide que se introduzcan 10 enteros y los ordena.
La segunda funci�n encuentra los primeros 100 n�meros perfectos utilizando una funci�n anidada.
La tercera funci�n pide se ingrese un entero de 6 d�gitos, y devuelve el n�mero con los d�gitos invertidos.
Autor: Hugo Eduardo Ontiveros Ledezma
Universidad Nacional Aut�noma de M�xico
Facultad de Contadur�a y Administraci�n
Lic. en inform�tica semestre 2
Materia: Introducci�n a la programaci�n
Asesor: RAUL OJEDA VILLAGOMEZ
25 de octubre del 2020 */

#include <iostream>
#include <stdlib.h>

using namespace std;

void insercion() {
	int s[10];
	for (int o = 0; o < 10; o++) {
		cout << "Ingrese el entero " << o + 1 << " y presione enter.\n";
		while (1) {
			if (cin >> s[o]) {
				break;
			}
			cout << "Por favor introduzca un entero para el valor " << o + 1 << " .\n";
			cin.clear();
			cin.ignore(1000000,  '\n');
		}
	}

   for (int i = 1; i <10; i++) {
	    int memoria = s[i];
    	int d = i;
    	while (memoria < s[d-1] && d > 0) {
      		s[d] = s[d-1];
      		d--;
    	}
    	if (s[d] != memoria) {
      		s[d] = memoria;
    	}
  }
  for (int i = 0; i < 10; i++) {
    cout << "N�mero ya ordenado posicion " << i + 1 << " es " << s[i] << endl;
  }
}

bool perfecto(unsigned long num) {
	int suma = 1;
	for (unsigned long i = 2; i <= num/2; i++) {
		if (num % i == 0 ) {
			suma += i;
		}
	}
	if (suma == num) {
		return true;
	} else {
		return false;
	}
} 

void numerosPerfectos() {
	int cont = 0;
	unsigned long num = 1;
	// El valor es 4 para que el programa no se quede trabado, suponiendo que tuviera los recursos computacionales, este valor se modificar�a a 100.
	while (cont < 4) {
		num++;
		if (perfecto(num)) {
			cont++;
			cout << "N�mero perfecto " << cont << " es " << num << ".\n";
		}
	}	
}

int voltear(int numero) {
	int volteado = 0;
	while (numero > 0) {
		volteado = volteado * 10;
		volteado += numero % 10;
		numero = numero/10;
	}
	cout << "El n�mero con sus d�gitos invertidos es " << volteado << ".\n";
}

int main() {
	int opc = 0;
	int aVol = 0;
	cout << "Por favor seleccione una de las siguientes operaciones a realizar:\n"
	"1. Introduzca 10 n�meros enteros a ser ordenados.\n"
	"2. Encontrar los primeros 100 n�meros perfectos.\n"
	"3. Introduzca un entero de 6 d�gitos, para obtener un entero con los d�gitos invertidos.\n";
	do {
		cin >> opc;
		switch (opc) {
			case 1:
				insercion();
				break;
			case 2:
				cout << "N�meros perfectos.\n";
				numerosPerfectos();
				break;
			case 3:
				cout << "Introduzca un n�mero entero de 6 d�gitos a invertir.\n";
				cin >> aVol;
				while (99999 > aVol || aVol > 1000000) {
					cout << "No ha ingresado un n�mero de 6 d�gitos, por favor, ingrese un n�mero de 6 d�gitos.\n";
					cin.clear();
					cin.ignore(1000000, '\n');
					cin >> aVol;
				}
				voltear(aVol);
				break;
			default:
				cout << "No ha seleccionado una opci�n v�lida. Por favor, ingrese una opci�n v�lida.\n";
				cin.clear();
				cin.ignore(10000000, '\n');
		}
	} while (opc != 1 && opc != 2 && opc != 3);
}
