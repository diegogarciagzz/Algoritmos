// Diego García González
// A01198976
// ITC
// 12/08/24

#include <iostream>
#include <vector>

using namespace std;  // Usar el espacio de nombres std para simplificar el código

// Función de ordenamiento por Selección
void ordenaSeleccion(vector<int>& vector) {
    int n = vector.size();
    for (int index = 0; index < n - 1; index++) {
        int minIndex = index;
        for (int j = index + 1; j < n; j++) {
            if (vector[j] < vector[minIndex]) {
                minIndex = j;
            }
        }
        // Intercambio manual
        int temp = vector[minIndex];
        vector[minIndex] = vector[index];
        vector[index] = temp;
    }
}

// Función de ordenamiento por Burbuja
void ordenaBurbuja(vector<int>& vector) {
    int n = vector.size();
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (vector[j] > vector[j + 1]) {
                // Intercambio manual
                int temp = vector[j];
                vector[j] = vector[j + 1];
                vector[j + 1] = temp;
            }
        }
    }
}

// Función auxiliar para el ordenamiento por Merge
void merge(vector<int>& vector, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    // Crear los vectores temporales para la división
    vector<int> L(n1);  // Vector temporal L de tamaño n1
    vector<int> R(n2);  // Vector temporal R de tamaño n2

    // Copiar los datos a los vectores temporales
    for (int i = 0; i < n1; i++)
        L[i] = vector[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = vector[mid + 1 + j];

    // Mezclar los vectores temporales de vuelta al vector original
    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            vector[k++] = L[i++];
        } else {
            vector[k++] = R[j++];
        }
    }

    // Copiar los elementos restantes de L, si hay alguno
    while (i < n1) {
        vector[k++] = L[i++];
    }

    // Copiar los elementos restantes de R, si hay alguno
    while (j < n2) {
        vector[k++] = R[j++];
    }
}

// Función de ordenamiento por Merge
void ordenaMerge(vector<int>& vector, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        ordenaMerge(vector, left, mid);
        ordenaMerge(vector, mid + 1, right);
        merge(vector, left, mid, right);
    }
}

// Función de búsqueda Secuencial
int busqSecuencial(const vector<int>& vector, int key) {
    for (int i = 0; i < vector.size(); i++) {
        if (vector[i] == key) {
            return i;
        }
    }
    return -1;
}

// Función de búsqueda Binaria
int busqBinaria(const vector<int>& vector, int key) {
    int left = 0, right = vector.size() - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (vector[mid] == key) {
            return mid;
        } else if (vector[mid] < key) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return -1;
}

int main() {
    int n, numBusquedas, numBuscar;
    vector<int> vector;

    // Solicitar al usuario el número de elementos del vector
    cout << "Ingrese el número de elementos del vector: ";
    cin >> n;
    vector.resize(n);

    // Solicitar los elementos del vector
    cout << "Ingrese los elementos del vector:\n";
    for (int i = 0; i < n; i++) {
        cin >> vector[i];
    }

    // Ordenar el vector con el método de Selección
    vector<int> vectorSeleccion = vector;
    ordenaSeleccion(vectorSeleccion);
    cout << "Vector ordenado con Selección: ";
    for (int num : vectorSeleccion) {
        cout << num << " ";
    }
    cout << endl;

    // Ordenar el vector con el método de Burbuja
    vector<int> vectorBurbuja = vector;
    ordenaBurbuja(vectorBurbuja);
    cout << "Vector ordenado con Burbuja: ";
    for (int num : vectorBurbuja) {
        cout << num << " ";
    }
    cout << endl;

    // Ordenar el vector con el método de Merge
    vector<int> vectorMerge = vector;
    ordenaMerge(vectorMerge, 0, vectorMerge.size() - 1);
    cout << "Vector ordenado con Merge: ";
    for (int num : vectorMerge) {
        cout << num << " ";
    }
    cout << endl;

    // Solicitar la cantidad de búsquedas
    cout << "Ingrese la cantidad de búsquedas que desea realizar: ";
    cin >> numBusquedas;

    for (int i = 0; i < numBusquedas; i++) {
        cout << "Ingrese el número que desea buscar: ";
        cin >> numBuscar;

        // Búsqueda Secuencial
        int indiceSecuencial = busqSecuencial(vector, numBuscar);
        cout << "Búsqueda Secuencial: "
             << (indiceSecuencial != -1 ? "Encontrado en índice " + to_string(indiceSecuencial) : "No encontrado")
             << endl;

       
    }