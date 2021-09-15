/* Programa para definir un TDA
Autor: Hugo Eduardo Ontiveros Ledezma
Universidad Nacional Autónoma de México
Facultad de Contaduría y Administración
Lic. en informática semestre 3
Materia: Programación II: Estructura de datos
Asesor: Ramón Arcos González
09 de marzo del 2021 */

#include <iostream>

using namespace std;

class Calificacion {
private:
	float calif;
	
public:
	float evaluacion;
	int valor;
	int fecha;
	int fechaLimite;
	char c[200];
	
	void calcularCalificacion() {
		this->calif = this->evaluacion * this->valor / 100;
	}
	
	void imprimirCalificacion() {
		cout << this->calif;
	}
};

int main() {
	cout << "Programa para calcular una calificación, como operación de un TDA Calificación. Por favor ingrese la evaluación de la calificación.\n";
	Calificacion act1;
	while (1) {
		if (cin>>act1.evaluacion && act1.evaluacion>0.0 && act1.evaluacion<=10.0 ) {
			break;
		} else {
			cout << "Error al ingresar la evaluación de la calificación, por favor, intente de nuevo.\n";
			cin.clear();
			cin.ignore(1000, '\n');
		}
	}
	cout << "Por favor, el valor de la actividad expresado como entero (porcentaje).\n";
	while (1) {
		if (cin>>act1.valor && act1.valor>0 && act1.valor<101) {
			break;
		} else {
			cout << "Error al ingresar el valor de la actividad. Vuelva a ingresarla como un entero.\n";
			cin.clear();
			cin.ignore(1000, '\n');
		}
	}

	act1.calcularCalificacion();
	act1.imprimirCalificacion();
}
