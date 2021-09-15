/* Programa para jugar "Chicos y Grandes"
Es un juego de dados en el cual un jugador tira dos dados,
se suma el valor de las caras superiores (de 2 a 12).
El jugardor, antes de lanzar los dados, debe seleccionar Chicos o Grandes.
Si la suma es mayor a 7, y el jugador escogi� grandes, gana.
Si la suma es menor a 7, y el jugador escog�o chicos, gana.
Si la suma es igual a 7, la casa gana.
Autor: Hugo Eduardo Ontiveros Ledezma
Universidad Nacional Aut�noma de M�xico
Facultad de Contadur�a y Administraci�n
Lic. en inform�tica semestre 2
Materia: Introducci�n a la programaci�n
Asesor: RAUL OJEDA VILLAGOMEZ
25 de octubre del 2020 */

#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

int suma()
 {
  int d1 = 0, d2 = 0, sum=0;
  d1 = rand() % 6 + 1;
  d2 = rand() % 6 + 1;
  sum = d1 + d2;
  cout << "El dado 1 cay� con " << d1 << " y el dado 2 con " << d2 << ", la suma de estos es " << sum <<endl;
  return sum;
 }

int main() {
  int opc = 0, sum=0, sn=1;
  srand(time(0));
  while (sn == 1) {
    cout << "Chicos y Grandes\n" 
    "Para jugar, seleccione una de las siguientes opciones y presione enter:\n"
    "1. Chicos\n"
    "2. Grandes\n";
    do {
      cin >> opc;
      switch (opc) {
        case 1:
          cout << "Jugador apost� a Chicos\n";
          sum = suma();
          if (sum < 7) {
            cout << "�Felicidades, ganaste!\n";
          } else if (sum > 7) {
            cout << "Has perdido, �buuuu!\n";
          } else {
            cout << "La casa ha ganado, mala suerte.\n";
          }
          break;
        case 2:
          cout << "Jugador apost� a Grandes\n";
          sum = suma();
          if (sum > 7) {
            cout << "�Felicidades, ganaste!\n";
          } else if (sum < 7) {
            cout << "Has perdido, �buuuu!\n";
          } else {
            cout << "La casa ha ganado, mala suerte.\n";
          }
          break;
        default:
          cout << "No ha escogido una opci�n v�lida, por favor, escoja una opci�n v�lida.\n";
          cin.clear();
          cin.ignore(1000000, '\n');
      }
    } while (opc != 1 && opc != 2 );
    cout << "�Desea seguir jugando?\n"
    "Ingrese 1 para S�, cualquier otro valor para No:\n";
    cin >> sn;
  }
}
