// Diego García González y  Oliver Vazquez Lima
// A01198976                 A01738020
// ITC
// 19/08/24
#include <iostream>
using namespace std;

//Función intercambiar: Realiza el intercambio de dos elementos.
void intercambiar(int& a, int& b) {
    int vartemp = a;
    a = b;
    b = vartemp;
}

//Función que Divide el arreglo según un pivote.
int dividir(int arreglo[], int izquierdo, int derecho) {
    int pivote = arreglo[derecho];
    int index = izquierdo - 1;

    //Compara los elementos
    for (int j = izquierdo; j < derecho; j++) {
        if (arreglo[j] <= pivote) {
            index++;
            intercambiar(arreglo[index], arreglo[j]);
        }
    }

    intercambiar(arreglo[index + 1], arreglo[derecho]);
    return index + 1;
}

//Función quickSort: Llama recursivamente a sí misma para ordenar las subpartes del arreglo.
void quickSort(int arreglo[], int izquierdo, int derecho) {
    if (izquierdo < derecho) {
        int pivote = dividir(arreglo, izquierdo, derecho);
        quickSort(arreglo, izquierdo, pivote - 1);
        quickSort(arreglo, pivote + 1, derecho);
    }
}


int main() {
    int arreglo[] = {9, 7, 2, 5, 1, 4};
    int n = sizeof(arreglo) / sizeof(arreglo[0]);

    quickSort(arreglo, 0, n - 1);

    for (int index = 0; index < n; index++) {
        cout << arreglo[index] << " ";
    }
    cout << endl;

    return 0;
}
