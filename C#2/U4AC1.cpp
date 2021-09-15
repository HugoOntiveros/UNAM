/* Programa para realizar el ordenamiento de 20 números generados aleatoriamente. 
Los números aleatorios son ordenados utilizando los métodos burbuja, inserción directa y selección.
Autor: Hugo Eduardo Ontiveros Ledezma
Universidad Nacional Autónoma de México
Facultad de Contaduría y Administración
Lic en informática semestre 3
Materia: Programación II: Estructura de datos
Asesor: Ramón Arcos González
06 de mayo del 2021 */

#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;

// void burbuja (int n1, int n2, int n3, int n4, int n5, int n6, int n7, int n8, int n9, int n10) {
  void burbuja (int r[20]) {
  cout << "Inicio de ordenamiento mediante método burbuja" <<endl;
  int b[20];
  for (int i = 0; i < 20; i++) {
    b[i] = r[i];
  }
  int memoria = -1;
  do {
    memoria = -1;
    for (int i = 0; i<19; i++) {
      if (b[i] > b[i+1]) {
        memoria = b[i+1];
        b[i+1] = b[i];
        b[i] = memoria;
      }
    }
  }
  while ( memoria != -1);
  for (int i=0; i<20; i++) {
    cout << "Número ya ordenado posicion " << i+1 << " es " << b[i] << endl;
  }
}

void insercion (int r[20]) {
  cout << "Inicio de ordenamiento mediante método de inserción directa" <<endl;
  int s[20];
  for (int i=0; i<20; i++) {
    s[i] = r[i];
  }
  for (int i = 1; i <20; i++) {
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
  for (int i=0; i<20; i++) {
    cout << "Número ya ordenado posicion " << i+1 << " es " << s[i] << endl;
  }
}

void seleccion(int r[20]) {
	int p[20];
	cout << "Inicio de ordenamiento mediante método de selección" <<endl;
	for (int i=0; i<20; i++) {
		p[i] = r[i];
	}
	for (int i=0; i<20; i++) {
		int min = p[i];
		int m = i;
		for (int j=i+1; j<20; j++) {
			if (min > p[j]) {
				min = p[j];
				m = j;
			}
		}
		p[m] = p[i];
		p[i] = min;
	}
	for (int i=1; i<=20; i++) {
		cout << "Número ya ordenado posición " << i << " es " << p[i-1] << endl;
	}
}


int main() {
  srand(time(0));
  int r[20];
	int opc = 0, con = 1;
 	while (con) {
		cout <<"Ordenamientos:\n"
		<<"1) Llenar arreglo con números aleatorios.\n"
		<<"2) Mostrar arreglo.\n"
		<<"3) Ordenamiento por intercambio (bubblesort).\n"
		<<"4) Ordenamiento por inserción directa.\n"
		<<"5) Ordenamiento por selección.\n"
		<<"6) Terminar.\n";
		cin>>opc;
		switch (opc) {

			case 1:
				cout << "Generando arreglo aleatorio..." << endl;
				for (int i=0; i<20; i++) {
    				r[i] = rand() % 20 + 1;
  				}
  				cout << "Arreglo generado." << endl;
				break;

			case 2:
				for (int i=1; i<=20; i++) {
					cout << "Elemento con posición " << i << " es " << r[i-1] << endl;
				}
				
				break;

			case 3:
				burbuja(r);
				break;

			case 4:
				insercion(r);
				break;

			case 5:
				seleccion(r);
				break;

			case 6:
				cout <<"Programa finzalizado.";
				con = 0;
				break;

			default:
				cout <<"No ingresó una opción válida. Por favor, vuelva a intentar ingresar una de las siguientes opciones:\n";
				cin.clear();
				cin.ignore(1000, '\n');
		}
	}
}
