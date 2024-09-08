// Diego García González
// A01198976
// ITC
// 12/08/24

#include <iostream>
using namespace std;

int main() {

     int arreglo[5]; 
     int n = 5;

    // Pedir al usuario los números
    cout << "Ingresa 5 números:" << endl;
    for (int index = 0; index < n; index++) {
        cin >> arreglo[index];
    }
   
    // Algoritmo  Primer for es para hacer cada corrida del algoritmo
    for (int index = 0; index < n-1; index++) {
        // Segundo for para checar si el número es mayor en cada caso.
        for (int j = 0; j < n-1 - index; j++) {
            if (arreglo[j] > arreglo[j + 1]) {
                // Intercambiar los números
                int pos = arreglo[j];
                arreglo[j] = arreglo[j + 1];
                arreglo[j + 1] = pos;
            }
        }
    }
    // Despliega la secuencia
    for (int index = 0; index < 5; index++) {
        cout << arreglo[index] << " ";
    }
    return 0;
}


  














