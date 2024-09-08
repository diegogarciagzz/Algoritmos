// Diego García González OlIver Vazquez lima
// A01198976
// ITC
// 12/08/24


#include <iostream>
using namespace std;

void insertionSort(int arreglo[], int n) {
    for (int index = 1; index < n; index++) {
        int clave = arreglo[index];
        int j = index - 1;

        // Mover los elementos del arreglo que son mayores que la clave
        // a una posición adelante de su posición actual
        while (j >= 0 && arreglo[j] > clave) {
            arreglo[j + 1] = arreglo[j];
            j = j - 1;
        }
        arreglo[j + 1] = clave;
    }
}

int main() {
    int arreglo[] = {20, 13, 10, 6, 3};
    int n = sizeof(arreglo) / sizeof(arreglo[0]);

    insertionSort(arreglo, n);
    
    for (int index = 0; index < n; index++)
        cout << arreglo[index] << " ";
    cout << endl;

    return 0;
}
