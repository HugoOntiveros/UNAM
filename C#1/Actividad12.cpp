/* Programa para acceder a elementos de un
arreglo a trav�s de apuntadores.
Autor: Hugo Eduardo Ontiveros Ledezma
Universidad Nacional Aut�noma de M�xico
Facultad de Contadur�a y Administraci�n
Lic. en inform�tica semestre 2
Materia: Introducci�n a la programaci�n
Asesor: RAUL OJEDA VILLAGOMEZ
23 de noviembre del 2020 */

#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

int calif[10];

int main() {
  srand(time(0));
  // Utilizo dos apuntadores para inicializar cada uno de forma diferente para fines did�cticos, pues su valor es el mismo, &calif[0] es igual a calif.
  int *ap1 = &calif[0];
  int *ap2 = calif;

  for (int i=0; i<10; i++) {
    *(ap1+i) = rand()%10+1; 
  }

  for (int i = 0; i<10; i++) {
    cout << "Calificaci�n del alumno n�mero " << i+1 << " es " << *ap2++ << ".\n";
  }

  //cout << "ap1 apunta a " << ap1 << ", ap2 apunta a "<< ap2 << ", calif[9] apunta a " << &calif[9] << ", calif[10] apunta a " << &calif[10] << ", calif[11] apunta a " << &calif[11] <<" El valor de calif[10] es " <<calif[10];
  // De forma similar, se iter� de manera distinta, aunque con el mismo resultado, para yo poder comprender mejor los punteros. 
  // Sin embargo, al final, el ap1 apunta al inicio del arreglo calif (calif[0]), pero ap2 apunta al siguiente int fuera del arreglo, el cual es equivalente a &calif[10], a pesar de no estar definido.  
}
