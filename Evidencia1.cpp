// Diego García González
// A01198976
// ITC
// 12/08/24

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <sstream>

using namespace std;

// Según investigué se puede hacer tambien con POO 
// con clases y atributos de clases 
// pero para que fuera un solo archivo decidí usar
// la función struct para almacenar los registros de la bitácora
struct Registro {
    string mes;
    int dia;
    string hora;
    string ip;
    string razon;

    // Método para obtener la fecha como una cadena para facilitar la comparación
    string obtenerFecha()  {
        return mes + " " + to_string(dia) + " " + hora;
    }

    // Sobrecarga del operador < para ordenar por fecha
    bool operator<( Registro& otro)  {
        // Comparación por mes, día y hora
        if (mes == otro.mes) {
            if (dia == otro.dia) {
                return hora < otro.hora;
            }
            return dia < otro.dia;
        }
        return mes < otro.mes;
    }
};

// Función para leer los registros desde el archivo
// Esta función si tuve que investigar porque no recordaba cómo era.
// pero lee el archivo y agarra la información dentro de el
vector<Registro> leerBitacora( string& nombreArchivo) {
    vector<Registro> registros;
    ifstream archivo(nombreArchivo);
    string linea;

    while (getline(archivo, linea)) {
        istringstream iss(linea);
        Registro registro;
        string ipConPuerto;
        
        iss >> registro.mes >> registro.dia >> registro.hora >> ipConPuerto;
        size_t pos = ipConPuerto.find(':');
        if (pos != string::npos) {
            registro.ip = ipConPuerto.substr(0, pos);
        }
        getline(iss, registro.razon);  // Resto de la línea es la razón
        registros.push_back(registro);
    }
    
    return registros;
}

// Función para mostrar los registros
void mostrarRegistros( vector<Registro>& registros) {
    for ( auto& registro : registros) {
        cout << registro.obtenerFecha() << " " << registro.ip << " " << registro.razon << std::endl;
    }
}

int main() {
    // Leer la bitácora desde el archivo
    vector<Registro> registros = leerBitacora("C:\\Users\\diego\\Downloads\\bitacora.txt");

    // Ordenar los registros por fecha
    sort(registros.begin(), registros.end());

    // Solicitar al usuario las fechas de inicio y fin
    string fechaInicio, fechaFin;
    cout << "Ingrese la fecha de inicio (Formato: Mes Día Hora): ";
    getline(cin, fechaInicio);
    cout << "Ingrese la fecha de fin (Formato: Mes Día Hora): ";
    getline(cin, fechaFin);

    // Filtrar y mostrar los registros en el rango de fechas
    for ( auto& registro : registros) {
        if (registro.obtenerFecha() >= fechaInicio && registro.obtenerFecha() <= fechaFin) {
            cout << registro.obtenerFecha() << " " << registro.ip << " " << registro.razon << std::endl;
        }
    }

    // Guardar registros ordenados en un archivo
    ofstream archivoOrdenado("C:\\Users\\diego\\Downloads\\bitacora_ordenada.txt"); // Se añade el nombre del archivo
    if (!archivoOrdenado) {  // Verifica si el archivo se abrió correctamente
        cerr << "Error al abrir el archivo para escribir." << endl;
        return 1;
    }

    for ( auto& registro : registros) {
        archivoOrdenado << registro.obtenerFecha() << " " << registro.ip << " " << registro.razon << std::endl;
    }

    archivoOrdenado.close();  // Asegúrate de cerrar el archivo después de escribir

    return 0;
}
