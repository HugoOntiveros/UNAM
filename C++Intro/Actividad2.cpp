/* Programa GAP generar 80 números aleatorios del 1 al 100. 
Después, genera una lista con los 20 números faltantes.
Autor: Hugo Eduardo Ontiveros Ledezma
Universidad Nacional Autónoma de México
Facultad de Contaduría y Administración
Lic. en informática semestre 2
Materia: Introducción a la programación
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
  cout << "Listado de 80 números aleatorios del 1 al 100" << endl;
    for (int i = 0; i<100; i++) {
      if (numero[i] != 0) {
      cout << numero[i] << endl;
      }
  }
  cout << "Lista de los 20 números faltantes" << endl;
  for (int i = 0; i < 100; i++) {
    if (numero[i] == 0) {
      cout << i + 1 << endl;
    }
  }
}
