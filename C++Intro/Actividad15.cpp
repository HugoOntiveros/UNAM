/* Programa para calcular el Valor Presente Neto
(VPN) a partir del número de periodos, tasa de
descuento, inversión inicial y el flujo de efectivo
durante cada periodo.
Autor: Hugo Eduardo Ontiveros Ledezma
Universidad Nacional Autónoma de México
Facultad de Contaduría y Administración
Lic. en informática semestre 2
Materia: Introducción a la programación
Asesor: RAUL OJEDA VILLAGOMEZ
09 de diciembre del 2020 */

#include <iostream>
#include <math.h>
#include <iomanip>

using namespace std;

float i0 = 0, vpn = 0, k = 0;
int n = 0;

int main() {
	cout << "Programa para calcular el Valor Presente Neto (VPN) a partir de la inversión inicial, número de periodos, tasa de descuento y flujos de efectivo de cada periodo. Por favor, ingrese el número de periodos.\n";
	while (1) {
		if (cin>>n && n > 0) {
			break;
		} else {
			cout << "Error al ingresar al número de periodos, por favor, ingrese un número natural equivalente al número de periodos a evaluar.\n";
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
	cout << "Por favor, ingrese la inversión inicial del proyecto.\n";
	while (1) {
		if (cin>>i0) {
			break;
		} else {
			cout << "Error al ingresar la inversión inicial del proyecto, por favor, ingrese la inversión inicial.\n";
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
	cout << fixed << setprecision(2) << "El número de periodos es " << n << ", la inverisón iniical es " << i0 << ", la tasa de descuento es " << k << ".\n";
	vpn =- i0;
	for (int i = 0; i<n; i++) {
		cout <<"Flujo de efectivo del periodo " << i+1 << " es " << f[i] << ".\n";
	}
	for (int i =0; i<n; i++) {
		vpn += f[i] / pow(k+1, i+1);
	}
	cout << "El VPN es " << vpn;
}
