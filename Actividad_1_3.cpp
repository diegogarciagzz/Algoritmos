/*
Autores:
Alejandro Guajardo Caba - A01178375
Diego García González - A01198976 
Maximo Ramírez Valdespino - A00839731
Oliver Vázquez Lima - A01738020

Fecha de creación: 26 de agosto del 2024
Fecha de última modificación: 2 de septiembre del 2024
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Función que convierte la representación de tres letras de un mes a su entero correspondiente.
// Complejidad: O(1).
// Parámetros:
// - mes: un string con las tres letras que identifican al mes.
// Retorno: un string con la representación numérica de dos dígitos del mes.
string mesAEntero(string mes){
    // Vector donde el índice corresponde a la conversión para cada mes.
    vector<string> conversion = {" ", "Jan", "Feb", "Mar", "Apr", "May", "Jun", 
                                    "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};

    // Búsqueda Secuencial sobre el vector de conversión para encontrar la conversión correspondiente.
    for (int i = 1; i <= 12; i++){
        if (conversion[i] == mes){
            // Ajustar para mantener el 0 por la izquierda, para facilitar el ordenamiento.
            string mesString = to_string(i);
            if (mesString.length() == 1){
                mesString = "0" + mesString;
            }

            return mesString;
        }
    }

    // En caso de algún error, retornar -1 para indicar esto. Aunque esto no podría pasar si el archivo de texto es
    // válido.
    return to_string(-1);
}

// Función que convierte la representación numérica de un mes a su representación de tres letras.
// Complejidad: O(1).
// Parámetros:
// - mes: string con la representación numérica del mes.
// Retorno: string con la representación de tres letras del mes.
string enteroAMes(string mes){
    // Vector donde el índice corresponde a la conversión para cada mes.
    vector<string> conversion = {" ", "Jan", "Feb", "Mar", "Apr", "May", "Jun", 
                                "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};

    // Retornar la posición correspondiente en el vector, utilizando la ǘersión numértica del mes.
    return conversion[stoi(mes)];
}

// Función que retorna si una cadena ingresada resulta en una fecha válida.
// Complejidad: O(1).
// Parámetros:
// - fecha: string conteniendo la entrada del usuario a vertificar.
// Retorno: booleano; true si el string está en el formato válido, false si no.
bool validar(string fecha){
    // Inmediatamente, si la longitud de la cadena no es 14, no puede cumplir con las características de una fecha 
    // válida.
    if (fecha.length() != 14){
        return false;
    }

    // Si la cadena no cumple con los separadores establecidos, es inválida.
    if (fecha[2] != '/' || fecha[5] != '/' || fecha[8] != '/' || fecha[11] != '/'){
        return false;
    }

    // Partir la cadena en sus cinco datos: mes, día, hora, minuto y segundo, aprovechando la función stoi.
    int mes = stoi(fecha.substr(0, 2));
    int dia = stoi(fecha.substr(3, 2));
    int hora = stoi(fecha.substr(6, 2));
    int minuto = stoi(fecha.substr(9, 2));
    int segundo = stoi(fecha.substr(12, 2));

    // Vector que contiene los días en el mes correspondiente a su índice, asumiendo que no es año bisiesto.
    vector<int> diasPorMes = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    // Si alguno de los datos de la fecha rompe con su formato válido, la cadena es inválida.
    if (mes < 1 || mes > 12 || dia < 1 || dia > diasPorMes[mes] || hora > 23 || minuto > 59 || segundo > 59){
        return false;
    }

    // Si pasa todas las revisiones, entonces es válido.
    return true;
}

// Función que parte el arreglo para encontrar la posición real del pivote del rango proveído.
// Su complejidad está considerada en la función quickSort.
// Parámetros:
// - arr: el vector de vectores de cadenas a ordenar.
// - posI: la posición inicial del rango a ordenar.
// . posF: la posición final del rango a ordenar; también sirve como el dato a ser el pivote.
// Retorno: un entero conteniendo la posición del pivote.
int partir(vector<vector<string>>& arr, int posI, int posF){
    // Definir pivote (como el último elemento) y declarar posición inicial del pivote.
    vector<string> pivote = arr[posF];
    int posPiv = posI;

    for (int i = posI; i <= posF; i++){
        // Incrementar la posición del pivote si el elemento actual es menor al pivote. Mover el elemento a estar antes
        // del pivote y actualizar la posición del pivote, porque ahora hay más elementos antes del pivote.
        if (arr[i] < pivote){
            swap(arr[i], arr[posPiv]);
            posPiv++;
        }
    }
    
    // Colocar el pivote (arr[posF]) en su posición correcta, es decir, en arr[posPiv] y retornar la posición del pivote.
    swap(arr[posPiv], arr[posF]);
    return posPiv;
}

// Función que implementa el Método Quick Sort, adaptado para poder ordenar un vector de vectores de cadenas.
// Complejidad: O(n * log n).
// Parámetros: 
// - arr: el vector de vectores de cadenas a ordenar.
// - posI: la posición inicial del rango a ordenar.
// - posF: la posición final del rango a ordenar.
// Retorno: ninguno.
void quickSort(vector<vector<string>>& arr, int posI, int posF){
    if (posI < posF){
        int posPiv = partir(arr, posI, posF);

        quickSort(arr, posI, posPiv - 1);
        quickSort(arr, posPiv + 1, posF);
    }
}

// Función iterativa que implementa la Búsqueda Binaria de una fecha sobre el vector de fechas, modificada para 
// retornar la posición del elemento mínimo mayor o igual a la fecha de inicio o el máxmino menor o igual a la
// fecha de fin.
// Complejidad: O(log n).
// Parámetros:
// - arr: el vector de vectores de cadenas sobre el cual hacer la búsqueda.
// - fecha: el string que contiene la fecha de inicio o de fin proveída por el usuario.
// Retorno: la posición del elemento mínimo mayor o igual a la fecha de inicio o el máxmino menor o igual a la
// fecha de fin.
int busqBinaria(vector<vector<string>> arr, string fecha){
    // Declarar variables necesarias para la búsqueda.
    int bajo = 0;
    int alto = arr.size() - 1;
    int mitad;

    // Realizar el ciclo mientras que no se esté lo más cerca posible a la fecha proveída.
    while (bajo <= alto){
        mitad = (alto + bajo) / 2;

        // La fecha corresponde a los primeros cinco strings del vector de cadenas en cada índice del arreglo.
        string mes = arr[mitad][0];
        string dia = arr[mitad][1];
        string hora = arr[mitad][2];
        string minuto = arr[mitad][3];
        string segundo = arr[mitad][4];

        string fechaMitad = mes + "/" + dia + "/" + hora + "/" + minuto + "/" + segundo;

        // Se utiliza esta fecha como el elemento a comparar de la búsqueda, alterando el rango de búsqueda 
        // de acuerdo al resultado de la comparación.
        if (fecha == fechaMitad){
            return mitad;
        }
        else if (fecha < fechaMitad){
            alto = mitad - 1;
        }
        else{
            bajo = mitad + 1;
        }
    }

    // Si no se ha retornado nada, no hay un emparejamiento exacto, así que se retorna el elemento previo,
    // almacenado en mitad.
    return bajo;
}

int main(){
    // Variables para recibir un rango de fechas de búsqueda.
    string fechaInicio, fechaFin;
    bool fechaValida = false;
    
    // Pedir el rango de fechas mientras la fecha no sea válida.
    while (!fechaValida){
        cout << "Cual es la fecha de inicio de su rango deseado de busqueda? (MM/DD/HH/MM/SS): ";
        cin >> fechaInicio;
        cout << "\nCual es la fecha de fin de su rango deseado de busqueda? (MM/DD/HH/MM/SS): ";
        cin >> fechaFin;

        // Un conjunto de fechas solo es válido si cumple con el formato establecido por la función "validar" y
        // si la fecha de inicio es menor o igual a la fecha de fin; esta última condición se puede checar directamente
        // dado el formato numérico de las cadenas.
        if (validar(fechaInicio) && validar(fechaFin) && fechaInicio <= fechaFin){
            fechaValida = true;
            cout << "\n";
        }
        else{
            // Si no es válido, pedir al usuario que vuelva a intentarlo, y continuar el ciclo.
            cout << "\nAlguna de las fechas ingresadas es inválida, sigue el formato (MM/DD/HH/MM/SS).\n";
        }
    }

    // Se abre el archivo proveído con los datos.
    freopen("bitacora.txt", "r", stdin);

    // Este vector almacena todos los datos de cada entrada del archivo, y los strings de cada vector corresponden
    // a las distintas partes de la entrada; en orden, el mes, el día, la hora, el minuto, el segundo, la dirección 
    // IP proveniente y el mensaje de error. Entonces, por ejemplo, datos[7][3] guarda el minuto de la octava 
    // entrada del archivo de texto.
    vector<vector<string>> datos;

    // Mientras no se haya alcanzado el final del archivo de texto, seguir permitiendo entradas.
    while (!cin.eof()){
        // Crear variables para cada parte de las entradas: el mes, el día, la hora del día en formato HH:MM:SS, la 
        // dirección IP y la razón por la que no se pudo acceder.
        string mes;
        string dia;
        string horaDia;
        string IP;
        string razon;

        // Directamente, se hace la entrada de los primeros cuatro datos.
        cin >> mes >> dia >> horaDia >> IP;
        // Al tener espacios y ser de longitudes distintas, se usa getline para tomar el resto de la línea como la 
        // cadena de la razón.
        getline(cin, razon);

        // Convertir el mes a un entero y obtener cada parte de la hora del día.
        string mesEntero = mesAEntero(mes);
        string hora = horaDia.substr(0, 2);
        string minuto = horaDia.substr(3, 2);
        string segundo = horaDia.substr(6, 2);

        // Ajustar el día en caso de que sea de longitud 1. Esto permite un ordenamiento más facil.
        if (dia.length() == 1){
            dia = "0" + dia;
        }

        // Crear un vector de strings para la entrada de datos, e insertarla al vector de datos.
        vector<string> entradaLog = {mesEntero, dia, hora, minuto, segundo, IP, razon};

        datos.push_back(entradaLog);
    }

    // Aplicar Quick Sort para los datos (pendiente).
    quickSort(datos, 0, datos.size() - 1);

    // Abrir un archio de texto para guardar el resultado del ordenamiento.
    freopen("resultado.txt", "w", stdout);

    // Utilizando la Búsqueda Binaria, se encuentra la posición de inicio y de fin del recorrido del arreglo, a
    // partir de las fechas proveídas por el usuario.
    int posI = busqBinaria(datos, fechaInicio) + 1;
    int posF = busqBinaria(datos, fechaFin);

    // Se accede a cada uno de los datos de cada entrada  en el rango y se escriben en el archivo, asegurándose de que 
    // se haga la conversión del mes a su representación original de tres letras.
    for (int i = posI; i <= posF; i++){
        string mes = datos[i][0];
        string dia = datos[i][1];
        string hora = datos[i][2];
        string minuto = datos[i][3];
        string segundo = datos[i][4];
        string IP = datos[i][5];
        string razon = datos[i][6];

        string fecha = mes + "/" + dia + "/" + hora + "/" + minuto + "/" + segundo;

        // Reconvertir dia a su formato original.
        if (dia[0] == '0'){
            dia = dia[1];
        }

        // Imprimir la entrada en su formato original.
        cout << enteroAMes(mes) << " "<< dia << " " << hora << ":" << minuto;
        cout << ":" << segundo << " " << IP << " " << razon << "\n";
    }
    
}