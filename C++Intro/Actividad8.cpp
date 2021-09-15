/* Programa para calcular las variaciones posibles de
5 archivos en 3 carpetas distintas.
Lo hará a través de una función recursiva.
Además, se incluye un validador para comprobar que no
se repita ninguna variación.
Autor: Hugo Eduardo Ontiveros Ledezma
Universidad Nacional Autónoma de México
Facultad de Contaduría y Administración
Lic. en informática semestre 2
Materia: Introducción a la programación
Asesor: RAUL OJEDA VILLAGOMEZ
09 de noviembre del 2020 */

#include <iostream>
#include <string.h>
#include <math.h>

using namespace std;

int count = 0;
int vari[243] = {};

void variaciones(char *archivos, int i=0, int *indices=NULL){
	if(indices==NULL) {
		indices = new int[3];
	}
	if(i<5){
		for(int x=0; x<3; x++){
			indices[i]=x;
			//cout << "\nindices[" <<i <<"]: " << indices[i];
			variaciones(archivos, i+1, indices);
		}
	} else {
		count++;
		cout <<"\n" << count << "\t";
		char c1[6]="\0", c2[6]="\0", c3[6]="\0";
		for(int w=0; w<5; w++){
			switch (indices[w]){
				case 0:
					strncat(c1, &archivos[w],1);
					//cout << " c1 "<< c1;
					break;
				case 1:
					strncat(c2, &archivos[w],1);
					//cout << " c2 "<<c2;
					break;
				case 2:
					strncat(c3, &archivos[w],1);
					//cout << " c3 " << c3;
					break;
			}
      vari[count-1] += (indices[w]+1) * pow(10,4-w);
			//cout << archivos[indices[w]];
		}
		cout << c1 << "\t" << c2 << "\t" << c3 << "\t" << c1 << "/" << c2 << "/" << c3 << "\t " << vari[count-1] << "\n";
    for (int c=0; c<count-1; c++) {
      if (vari[count-1] == vari[c]){
        cout << "***********ERROR: variación " << count << " es igual a variación " << c+1 << "***********";
      }
    }
	}
}

int main() {
	char archivos[] = {'5', '4', '3', '2', '1'};
	// Incluyo mi propia representación como la carpeta a la que pertenece cada número en orden 54321.
	cout << "No.\tC1\tC2\tC3\tRepresentación";
	variaciones(archivos);
}
