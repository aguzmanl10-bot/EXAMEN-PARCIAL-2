#include <iostream>
#include <fstream>
using namespace std;

// Función para mostrar menú
void menu() {
    cout << "\n===== SISTEMA DE VENTAS =====" << endl;
    cout << "1. Registrar venta" << endl;
    cout << "2. Mostrar ventas" << endl;
    cout << "3. Salir" << endl;
    cout << "Seleccione una opcion: ";
}

// Función para registrar venta
void registrarVenta() {
    ofstream archivo("ventas.txt", ios::app); // guardar al final

    string producto;
    int cantidad;
    float precio, total;

    cout << "\nNombre del producto: ";
    cin >> producto;

    cout << "Cantidad: ";
    cin >> cantidad;

    cout << "Precio: ";
    cin >> precio;

    total = cantidad * precio;

    // Guardar en archivo
    archivo << producto << " " << cantidad << " " << precio << " " << total << endl;

    archivo.close();

    cout << "Venta registrada con exito!\n";
}

// Función para mostrar ventas
void mostrarVentas() {
    ifstream archivo("ventas.txt");

    string producto;
    int cantidad;
    float precio, total;

    cout << "\n===== REPORTE DE VENTAS =====\n";

    while (archivo >> producto >> cantidad >> precio >> total) {
        cout << "Producto: " << producto << endl;
        cout << "Cantidad: " << cantidad << endl;
        cout << "Precio: " << precio << endl;
        cout << "Total: " << total << endl;
        cout << "----------------------" << endl;
    }

    archivo.close();
}

// Función principal
int main() {
    int opcion;

    do {
        menu();
        cin >> opcion;

        switch (opcion) {
            case 1:
                registrarVenta();
                break;
            case 2:
                mostrarVentas();
                break;
            case 3:
                cout << "Saliendo del sistema..." << endl;
                break;
            default:
                cout << "Opcion invalida!" << endl;
        }

    } while (opcion != 3);

    return 0;
}