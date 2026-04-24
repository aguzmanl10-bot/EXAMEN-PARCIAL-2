#include <iostream>
#include <fstream>
using namespace std;

// PROTOTIPOS
void mostrarMenu();
void registrarVentas();
void reporteVentas();

int main() {
    int opcion = 0;

    while (opcion != 3) {
        mostrarMenu();
        cin >> opcion;

        if (opcion == 1) {
            registrarVentas();
        } else if (opcion == 2) {
            reporteVentas();
        } else if (opcion == 3) {
            cout << "Saliendo del programa..." << endl;
        } else {
            cout << "Opcion incorrecta\n";
        }
    }

    return 0;
}

// MENU
void mostrarMenu() {
    cout << "\n===== MENU =====\n";
    cout << "1. Registrar ventas\n";
    cout << "2. Ver reporte\n";
    cout << "3. Salir\n";
    cout << "Opcion: ";
}

// REGISTRAR VARIAS VENTAS
void registrarVentas() {
    ofstream archivo("ventas.txt", ios::app);

    char continuar = 's';

    while (continuar == 's' || continuar == 'S') {
        string producto;
        int cantidad;
        float precio, total;

        cout << "\nProducto: ";
        cin >> producto;

        cout << "Cantidad: ";
        cin >> cantidad;

        cout << "Precio: ";
        cin >> precio;

        total = cantidad * precio;

        archivo << producto << " "
                << cantidad << " "
                << precio << " "
                << total << endl;

        cout << "Venta guardada!\n";

        cout << "Desea ingresar otra venta? (s/n): ";
        cin >> continuar;
    }

    archivo.close();
}

// REPORTE CON TOTAL GENERAL
void reporteVentas() {
    ifstream archivo("ventas.txt");

    string producto;
    int cantidad;
    float precio, total;
    float totalGeneral = 0;

    cout << "\n===== REPORTE =====\n";

    while (archivo >> producto >> cantidad >> precio >> total) {
        cout << "Producto: " << producto << endl;
        cout << "Cantidad: " << cantidad << endl;
        cout << "Total: " << total << endl;
        cout << "-------------------\n";

        totalGeneral += total;
    }

    cout << "TOTAL GENERAL: " << totalGeneral << endl;

    archivo.close();
}