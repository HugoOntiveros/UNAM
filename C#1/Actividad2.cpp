/* Programa GAP generar 80 n�meros aleatorios del 1 al 100. 
Despu�s, genera una lista con los 20 n�meros faltantes.
Autor: Hugo Eduardo Ontiveros Ledezma
Universidad Nacional Aut�noma de M�xico
Facultad de Contadur�a y Administraci�n
Lic. en inform�tica semestre 2
Materia: Introducci�n a la programaci�n
Asesor: RAUL OJEDA VILLAGOMEZ
11 de octubre del 2020 */

#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

int main() {
  int numero[100] = {};
  int count = 0;
  srand(time(0));  
  while (count < 80) {
    int random = rand() % 100;
    if (numero[random] == 0) {
      numero[random] = random+1;
      count++;
    }
  }
  cout << "Listado de 80 n�meros aleatorios del 1 al 100" << endl;
    for (int i = 0; i<100; i++) {
      if (numero[i] != 0) {
      cout << numero[i] << endl;
      }
  }
  cout << "Lista de los 20 n�meros faltantes" << endl;
  for (int i = 0; i < 100; i++) {
    if (numero[i] == 0) {
      cout << i + 1 << endl;
    }
  }
}
