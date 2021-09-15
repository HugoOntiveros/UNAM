/* Programa para realizar el ordenamiento alfab�tico de 20 cadenas. 
Los m�todos de ordenamiento utilizados son Shell y Quicksort.
Autor: Hugo Eduardo Ontiveros Ledezma
Universidad Nacional Aut�noma de M�xico
Facultad de Contadur�a y Administraci�n
Lic en inform�tica semestre 3
Materia: Programaci�n II: Estructura de datos
Asesor: Ram�n Arcos Gonz�lez
13 de mayo del 2021 */

#include <iostream>
#include <stdlib.h>
#include <string.h>
using namespace std;

void shell (char r[20][20]) {
  cout << "Ordenamiento mediante m�todo Shell.\n" << endl;
  char temp[20];
  int a;
  for(int inter=20/2; inter>=1; inter = inter/2) {
  	for(int i = inter; i<20; i++) {
  		strcpy(temp, r[i]);
  		a = i;
  		while(a-inter>=0 && strcmp(temp, r[a-inter])<0){
  			strcpy(r[a], r[a-inter]);
  			a = a - inter;
		  }
		  if(a != i){
		  	strcpy(r[a], temp);
		  }
	  }
  }
}

void insercion (int r[20]) {
  cout << "Inicio de ordenamiento mediante m�todo de inserci�n directa" <<endl;
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
    cout << "N�mero ya ordenado posicion " << i+1 << " es " << s[i] << endl;
  }
}


void quicksort (char r[20][20], int min, int max) {
  if (min < max) {
    // Definir� al pivote como el valor m�s cercano a la media aritm�tica de los n�meros aleatorios.
    int piv = max;
    char pivote[20];
	strcpy(pivote, r[piv]);
	strcpy(r[piv], r[max]);
	strcpy(r[max], pivote);	
    //cout << "Valor de pivote " << pivote << endl;
    int iPiv = min;
    for (int i = min; i < max; i++) {
      if(strcmp(pivote, r[i]) >0){
        char memoria[20];
		strcpy(memoria, r[i]);
		strcpy(r[i], r[iPiv]);
		strcpy(r[iPiv], memoria);
        iPiv++;                  
      }
    }
    strcpy(r[max], r[iPiv]);
    strcpy(r[iPiv], pivote);
    //cout << "Indice del pivote despu�s de ordenaci�n es " << iPiv << endl;
    /*for (int i = min; i <= max; i++) {
      cout << "El n�mero ya ordenado con �ndice " << i << " es " << r[i] << endl; 
    }*/
    quicksort(r, min, iPiv-1);
    quicksort(r, iPiv+1, max);
  }
}


int main() {
  char r[20][20] = {
  	"Mexico",
  	"Espana",
  	"Inglaterra",
  	"Croacia",
  	"Francia",
  	"Belgica",
  	"Serbia",
  	"Japon",
  	"Brasil",
  	"Filipinas",
  	"Canada",
  	"Rumania",
  	"China",
  	"Jamaica",
  	"Suriname",
  	"Holanda",
  	"Marruecos",
  	"Sudafrica",
  	"Fiji",
  	"Montenegro"
  };
	int opc = 0, con = 1;
 	while (con) {
		cout <<"Ordenamientos:\n"
		<<"1) Mostrar arreglo.\n"
		<<"2) Ordenamiento por Shell.\n"
		<<"3) Ordenamiento por Quicksort.\n"
		<<"4) Terminar.\n";
		cin>>opc;
		switch (opc) {

			case 1:
				cout << "Arreglo de pa�ses:\n";
				for (int i=0; i<20; i++) {
  					cout << r[i] << "\n";
  				}
  				cout << endl;
				break;

			case 2:
				shell(r);
				break;

			case 3:
				cout << "Ordenamiento Quicksort\n\n";
				quicksort(r, 0, 19);
				break;

			case 4:
				cout <<"Programa finzalizado.";
				con = 0;
				break;

			default:
				cout <<"No ingres� una opci�n v�lida. Por favor, vuelva a intentar ingresar una de las siguientes opciones:\n";
				cin.clear();
				cin.ignore(1000, '\n');
		}
	}
}
