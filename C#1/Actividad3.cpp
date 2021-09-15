/* Programa que genera 100 n�meros aleatorios en el intervalo del 1 al 20. 
Despu�s, genera una lista con la frecuencia de aparici�n de cada n�mero.
Autor: Hugo Eduardo Ontiveros Ledezma
Universidad Nacional Aut�noma de M�xico
Facultad de Contadur�a y Administraci�n
Lic. en inform�tica semestre 2
Materia: Introducci�n a la programaci�n
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
    cout << "N�mero aleatorio es " << random + 1 << ", su frecuencia antes de actualizarse era " << frec[random];
    frec[random]++;
    cout << " y su frecuencia actualizada es " << frec[random] << endl;
  }
  int suma = 0;
  for (int i=0; i<20; i++) {
    cout <<"Frecuencia del n�mero " << i+1 << " es " << frec[i] << endl;
    suma += frec[i];
  }
  cout << "Frecuencia acumulada " << suma << endl;
}
