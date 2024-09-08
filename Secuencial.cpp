// Diego García González 
// A01198976                 
// ITC
// 22/08/24

// Algoritmo de metodo de busqueda secuencial o Lineal

// Librerías
#include <iostream>
#include <vector>
using namespace std;


// Metodo 
void buscaSecuencial(vector <int> &arreglo, int datoAbuscar){

    //Variables locales 
    int i;

    for(i = 0; i < arreglo.size(); i++) {

        if (arreglo[i] == datoAbuscar){
            
            //Encontró el dato
            cout << endl << datoAbuscar<< " Pertenence al arreglo" << endl;
            cout << "Posición encntrada: " << i + 1 << endl;
            i = arreglo.size() + 1 ;
        }
        else if (i == arreglo.size() - 1){

            cout << "No se encontró " << datoAbuscar << " en el arreglo" << endl;

        }
    }

}

int main() {
    
    //Declarar variables Globales
    vector <int> arreglo[]= { 7, 5, 3, 21, 27, 30, 20};

    int datoABuscar;

    // Bienvenida
    cout << "Bienvenido a tu programa" << endl;

    //Pedir usuario
    cout << "Ingresa el dato entero a buscar: " << endl;
        cin >> datoABuscar;

    buscaSecuencial(*arreglo, datoABuscar);

    //Despedida
    cout << "Gracias por utilizar tu algoritmo" << endl;


    return 0;
}
