/* Programa para calcular el Valor Presente Neto
(VPN) a partir del n�mero de periodos, tasa de
descuento, inversi�n inicial y el flujo de efectivo
durante cada periodo.
Autor: Hugo Eduardo Ontiveros Ledezma
Universidad Nacional Aut�noma de M�xico
Facultad de Contadur�a y Administraci�n
Lic. en inform�tica semestre 2
Materia: Introducci�n a la programaci�n
Asesor: RAUL OJEDA VILLAGOMEZ
09 de diciembre del 2020 */

#include <iostream>
#include <math.h>
#include <iomanip>

using namespace std;

float i0 = 0, vpn = 0, k = 0;
int n = 0;

int main() {
	cout << "Programa para calcular el Valor Presente Neto (VPN) a partir de la inversi�n inicial, n�mero de periodos, tasa de descuento y flujos de efectivo de cada periodo. Por favor, ingrese el n�mero de periodos.\n";
	while (1) {
		if (cin>>n && n > 0) {
			break;
		} else {
			cout << "Error al ingresar al n�mero de periodos, por favor, ingrese un n�mero natural equivalente al n�mero de periodos a evaluar.\n";
			cin.clear();
			cin.ignore(1000, '\n');
		}
	}
	cout << "Por favor, ingrese la tasa de descuento expresada decimal.\n";
	while (1) {
		if (cin>>k) {
			break;
		} else {
			cout << "Error al ingresar la tasa de descuento, por favor, vuelva a ingresar la tasa de descuento estimada expresada como decimal.\n";
			cin.clear();
			cin.ignore(1000, '\n');
		}
	}
	cout << "Por favor, ingrese la inversi�n inicial del proyecto.\n";
	while (1) {
		if (cin>>i0) {
			break;
		} else {
			cout << "Error al ingresar la inversi�n inicial del proyecto, por favor, ingrese la inversi�n inicial.\n";
			cin.clear();
			cin.ignore(1000, '\n');
		}
	}
	float f[n] = {0};
	for (int i =0; i<n; i++) {
		cout << "Por favor, ingrese el flujo de efectivo para el periodo " << i+1 << ".\n";
		while (1) {
			if (cin>>f[i]) {
				break;
			} else {
				cout << "Error al ingresar el flujo de efectivo del periodo " << i+1 << ", por favor, vuelve a ingresar su apellido paterno.\n";
				cin.clear();
				cin.ignore(1000, '\n');
			}
		}
	}
	cout << fixed << setprecision(2) << "El n�mero de periodos es " << n << ", la inveris�n iniical es " << i0 << ", la tasa de descuento es " << k << ".\n";
	vpn =- i0;
	for (int i = 0; i<n; i++) {
		cout <<"Flujo de efectivo del periodo " << i+1 << " es " << f[i] << ".\n";
	}
	for (int i =0; i<n; i++) {
		vpn += f[i] / pow(k+1, i+1);
	}
	cout << "El VPN es " << vpn;
}
