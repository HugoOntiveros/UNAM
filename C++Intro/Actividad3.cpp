/* Programa que genera 100 números aleatorios en el intervalo del 1 al 20. 
Después, genera una lista con la frecuencia de aparición de cada número.
Autor: Hugo Eduardo Ontiveros Ledezma
Universidad Nacional Autónoma de México
Facultad de Contaduría y Administración
Lic. en informática semestre 2
Materia: Introducción a la programación
Asesor: RAUL OJEDA VILLAGOMEZ
14 de octubre del 2020 */

#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

int main() {
  srand(time(0));
  int frec[20] ={};
  for (int i=0; i<100; i++) {
    int random = rand() % 20;
    cout << "Número aleatorio es " << random + 1 << ", su frecuencia antes de actualizarse era " << frec[random];
    frec[random]++;
    cout << " y su frecuencia actualizada es " << frec[random] << endl;
  }
  int suma = 0;
  for (int i=0; i<20; i++) {
    cout <<"Frecuencia del número " << i+1 << " es " << frec[i] << endl;
    suma += frec[i];
  }
  cout << "Frecuencia acumulada " << suma << endl;
}
