/* Programa para todos los subconjuntos no vacuos
del conjunto de los números naturales del 1 al n.
Debe hacerlo de forma recursiva.
Autor: Hugo Eduardo Ontiveros Ledezma
Universidad Nacional Autónoma de México
Facultad de Contaduría y Administración
Lic. en informática semestre 2
Materia: Introducción a la programación
Asesor: RAUL OJEDA VILLAGOMEZ
11 de noviembre del 2020 */

#include <iostream>
#include <math.h>

using namespace std;

void combinaciones(int *numeros, int n, int r, int y=0, int i=0, int *indices=NULL){
	if(indices==NULL) {
		indices = new int[r];
	}
	if(i<r){
		for(int x=y; x<n; x++){
			indices[i]=x;
			//cout << "\nindices[" <<i <<"]: " << indices[i];
			combinaciones(numeros, n, r, x+1, i+1, indices);
		}
	} else {
		for(int w=0; w<r; w++) {
			cout << numeros[indices[w]] << " ";			
		}
		cout << "\n";
	}
}

int main() {
	int n=0, c=0;
	
	cout << "Este programa calcula todos los subconjuntos no vacuos del conjunto de números naturales de 1 a n. Por favor, ingrese el valor de n:\n";
	while (1) {
		if (cin>>n && n!=0) {
			n = n < 0 ? n*(-1): n;
			break;
		} else {
			cout << "No ha ingresado un número natural. Por favor, ingrese uno.\n";
			cin.clear();
			cin.ignore(1000, '\n');
		}
	}
	c = pow(2,n) - 1;
	cout << "El valor de n ingresado es " << n << ". El número de combinaciones de 1 a " << n << " es " <<c << ":\n";
	int numeros[n] = {0};
	for(int i=0; i<n; i++) {
		numeros[i] = i+1;
	}
	for (int r=1; r<=n; r++) {
		combinaciones(numeros, n, r);		
	}
}
