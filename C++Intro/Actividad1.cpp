/* Programa para realizar el ordenamiento de 10 números generados aleatoriamente. 
Los números aleatorios son ordenados utilizando los métodos burbuja, inserción directa y quicksort.
Autor: Hugo Eduardo Ontiveros Ledezma
Universidad Nacional Autónoma de México
Facultad de Contaduría y Administración
Lic en informática semestre 2
Materia: Introducción a la programación
Asesor: RAUL OJEDA VILLAGOMEZ
06 de octubre del 2020 */

#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;

// void burbuja (int n1, int n2, int n3, int n4, int n5, int n6, int n7, int n8, int n9, int n10) {
  void burbuja (int r[10]) {
  cout << "Inicio de ordenamiento mediante método burbuja" <<endl;
  int b[10];
  for (int i = 0; i < 10; i++) {
    b[i] = r[i];
  }
  int memoria = -1;
  do {
    memoria = -1;
    for (int i = 0; i<9; i++) {
      if (b[i] > b[i+1]) {
        memoria = b[i+1];
        b[i+1] = b[i];
        b[i] = memoria;
      }
    }
  }
  while ( memoria != -1);
  for (int i=0; i<10; i++) {
    cout << "Número ya ordenado posicion " << i+1 << " es " << b[i] << endl;
  }
}

void insercion (int r[10]) {
  cout << "Inicio de ordenamiento mediante método de inserción directa" <<endl;
  int s[10];
  for (int i=0; i<10; i++) {
    s[i] = r[i];
  }
  for (int i = 1; i <10; i++) {
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
  for (int i=0; i<10; i++) {
    cout << "Número ya ordenado posicion " << i+1 << " es " << s[i] << endl;
  }
}

void quicksort (int r[10], int min, int max) {
  if (min < max) {
    // Definiré al pivote como el valor más cercano a la media aritmética de los números aleatorios.
    long total = 0;
    int tamano = 0;
    for (int p=min; p <= max; p++) {
      total += r[p];
      tamano++;
    }
    int promedio = total/tamano;
    int md = -1;
    int piv = 0;
    for (int d=min; d <= max; d++) {
      int dif = abs(r[d] - promedio);
      if (md == -1 || dif < md) {
        md = dif;
        piv = d;
      }
    }
    int pivote = r[piv];
    r[piv] = r[max];
    r[max] = pivote;
    //cout << "Valor de pivote " << pivote << endl;
    int iPiv = min;
    for (int i = min; i < max; i++) {
      if (r[i] < pivote) {
        int memoria = r[i];            
        r[i] = r[iPiv];
        r[iPiv] = memoria;
        iPiv++;                  
      }
    }
    r[max] = r[iPiv];
    r[iPiv] = pivote;
    //cout << "Indice del pivote después de ordenación es " << iPiv << endl;
    for (int i = min; i <= max; i++) {
      //cout << "El número ya ordenado con índice " << i << " es " << r[i] << endl; 
    }
    quicksort(r, min, iPiv-1);
    quicksort(r, iPiv+1, max);
  }
}


int main() {
  srand(time(0));
  int r[10];
  for (int i=0; i<10; i++) {
    r[i] = rand();
    cout << "Número aleatorio " << i+1 << " es " << r[i] << endl;
  }
  burbuja(r);
  insercion(r);
  cout << "Inicio de ordenamiento mediante método quicksort" << endl;
  quicksort(r, 0, 9);
  for (int i=0; i<10; i++) {
    cout << "Número ya ordenado posicion " << i+1 << " es " << r[i] << endl;
  }    
}
