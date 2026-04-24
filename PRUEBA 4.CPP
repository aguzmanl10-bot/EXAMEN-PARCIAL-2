#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

// FUNCION CON RETORNO
double calcularTotal(int cantidad, double precio) {
    return cantidad * precio;
}

// PROCEDIMIENTO PARA REGISTRAR VENTAS
void registrarVenta() {
    ofstream archivo("ventas.txt", ios::app);

    string producto;
    int cantidad;
    double precio, total;

    cin.ignore(); // limpiar buffer
    cout << "\nNombre del producto: ";
    getline(cin, producto);

    cout << "Cantidad: ";
    cin >> cantidad;

    cout << "Precio: ";
    cin >> precio;

    total = calcularTotal(cantidad, precio);

    archivo << producto << "|" << cantidad << "|" << precio << "|" << total << endl;

    archivo.close();

    cout << "Venta guardada correctamente!\n";
}

// PROCEDIMIENTO PARA MOSTRAR REPORTE
void mostrarReporte() {
    ifstream archivo("ventas.txt");

    string producto;
    int cantidad;
    double precio, total;
    double totalGeneral = 0;

    cout << "\n===== REPORTE DE VENTAS =====\n";

    while (getline(archivo, producto, '|')) {
        archivo >> cantidad;
        archivo.ignore();
        archivo >> precio;
        archivo.ignore();
        archivo >> total;
        archivo.ignore();

        cout << "Producto: " << producto << endl;
        cout << "Cantidad: " << cantidad << endl;
        cout << "Precio: Q" << fixed << setprecision(2) << precio << endl;
        cout << "Total: Q" << total << endl;
        cout << "--------------------------\n";

        totalGeneral += total;
    }

    cout << "TOTAL GENERAL: Q" << totalGeneral << endl;

    archivo.close();
}

// MENU PRINCIPAL
int main() {
    int opcion;

    while (opcion != 3) {
        cout << "\n===== MENU =====\n";
        cout << "1. Registrar venta\n";
        cout << "2. Ver reporte\n";
        cout << "3. Salir\n";
        cout << "Seleccione: ";
        cin >> opcion;

        if (opcion == 1) {
            registrarVenta();
        } 
        else if (opcion == 2) {
            mostrarReporte();
        } 
        else if (opcion == 3) {
            cout << "Saliendo del sistema...\n";
        } 
        else {
            cout << "Opcion invalida\n";
        }
    }

    return 0;
}