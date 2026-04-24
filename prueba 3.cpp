#include <iostream>
#include <fstream>
using namespace std;

// PROTOTIPOS
void menu();
void registrarVentas();
void reporteVentas();

int main() {
    int opcion = 0;

    while (opcion != 3) {
        menu();
        cin >> opcion;
        cin.ignore(); // LIMPIAR BUFFER

        if (opcion == 1) {
            registrarVentas();
        } 
        else if (opcion == 2) {
            reporteVentas();
        } 
        else if (opcion == 3) {
            cout << "Saliendo...\n";
        } 
        else {
            cout << "Opcion invalida\n";
        }
    }

    return 0;
}

// MENU
void menu() {
    cout << "\n===== MENU =====\n";
    cout << "1. Registrar ventas\n";
    cout << "2. Ver reporte\n";
    cout << "3. Salir\n";
    cout << "Opcion: ";
}

// REGISTRAR VENTAS
void registrarVentas() {
    ofstream archivo("ventas.txt", ios::app);

    char continuar = 's';

    while (continuar == 's' || continuar == 'S') {
        string producto;
        int cantidad;
        float precio, total;

        cout << "\nNombre del producto: ";
        getline(cin, producto); // permite espacios

        cout << "Cantidad: ";
        cin >> cantidad;

        cout << "Precio: ";
        cin >> precio;

        cin.ignore(); // limpiar antes del siguiente getline

        total = cantidad * precio;

        archivo << producto << "|"
                << cantidad << "|"
                << precio << "|"
                << total << endl;

        cout << "Venta guardada!\n";

        cout << "Desea ingresar otra venta? (s/n): ";
        cin >> continuar;
        cin.ignore();
    }

    archivo.close();
}

// REPORTE
void reporteVentas() {
    ifstream archivo("ventas.txt");

    string linea;

    cout << "\n===== REPORTE =====\n";

    while (getline(archivo, linea)) {
        cout << linea << endl;
    }

    archivo.close();
}