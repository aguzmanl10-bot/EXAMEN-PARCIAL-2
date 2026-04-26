#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

double calcularSubtotal(int cantidad, double precio) {
    return cantidad * precio;
}

double calcularDescuento(double subtotal, int tipoPago) {
    double descuento = 0;

    if (subtotal >= 500) {
        descuento += subtotal * 0.05;
    }

    if (tipoPago == 1 && subtotal >= 300) {
        descuento += subtotal * 0.02;
    }

    return descuento;
}

double calcularTotal(double subtotal, double descuento) {
    return subtotal - descuento;
}

void mostrarMenu() {
    
    cout <<"Bienvenido al sistema de ventas de Ana Guzman\n";
    cout << "\n===== MENU =====\n";
    cout << "1. Registrar venta\n";
    cout << "2. Mostrar ventas\n";
    cout << "3. Reporte general\n";
    cout << "4. Buscar por monto\n";
    cout << "5. Salir\n";
    cout << "Opcion: ";
}

void registrarVenta() {
    ofstream archivo("ventas.txt", ios::app);

    string cliente, producto;
    int cantidad, tipoPago;
    double precio, subtotal, descuento, total;

    cin.ignore();
    cout << "\nNombre del cliente: ";
    getline(cin, cliente);

    cout << "Producto: ";
    getline(cin, producto);

    while (true) {
        cout << "Cantidad: ";
        cin >> cantidad;
        if (cantidad > 0) break;
        cout << "Cantidad invalida\n";
    }

    while (true) {
        cout << "Precio: ";
        cin >> precio;
        if (precio > 0) break;
        cout << "Precio invalido\n";
    }

    while (true) {
        cout << "Tipo de pago (1=Efectivo, 2=Tarjeta, 3=Transferencia): ";
        cin >> tipoPago;
        if (tipoPago >= 1 && tipoPago <= 3) break;
        cout << "Opcion invalida\n";
    }

    subtotal = calcularSubtotal(cantidad, precio);
    descuento = calcularDescuento(subtotal, tipoPago);
    total = calcularTotal(subtotal, descuento);

    string pagoTexto;
    if (tipoPago == 1) pagoTexto = "Efectivo";
    else if (tipoPago == 2) pagoTexto = "Tarjeta";
    else pagoTexto = "Transferencia";

    archivo << cliente << ","
            << producto << ","
            << cantidad << ","
            << fixed << setprecision(2)
            << precio << ","
            << subtotal << ","
            << descuento << ","
            << total << ","
            << pagoTexto << endl;

    archivo.close();

    cout << fixed << setprecision(2);
    cout << "\nSubtotal: Q" << subtotal << endl;
    cout << "Descuento: Q" << descuento << endl;
    cout << "Total: Q" << total << endl;

    cout << "Venta registrada correctamente!\n";
}

void mostrarVentas() {
    ifstream archivo("ventas.txt");
    string linea;

    cout << "\n===== VENTAS =====\n";

    while (getline(archivo, linea)) {
        cout << linea << endl;
    }

    archivo.close();
}

void reporteGeneral() {
    ifstream archivo("ventas.txt");

    string cliente, producto, pago;
    int cantidad;
    double precio, subtotal, descuento, total;

    int totalVentas = 0;
    int efectivo = 0, tarjeta = 0, transferencia = 0, conDescuento = 0;
    double sumaTotal = 0;

    while (getline(archivo, cliente, ',')) {
        getline(archivo, producto, ',');
        archivo >> cantidad; archivo.ignore();
        archivo >> precio; archivo.ignore();
        archivo >> subtotal; archivo.ignore();
        archivo >> descuento; archivo.ignore();
        archivo >> total; archivo.ignore();
        getline(archivo, pago);

        totalVentas++;
        sumaTotal += total;

        if (pago == "Efectivo") efectivo++;
        else if (pago == "Tarjeta") tarjeta++;
        else transferencia++;

        if (descuento > 0) conDescuento++;
    }

    cout << fixed << setprecision(2);
    cout << "\n===== REPORTE GENERAL =====\n";
    cout << "Total ventas: " << totalVentas << endl;
    cout << "Suma total: Q" << sumaTotal << endl;

    if (totalVentas > 0)
        cout << "Promedio: Q" << sumaTotal / totalVentas << endl;

    cout << "Efectivo: " << efectivo << endl;
    cout << "Tarjeta: " << tarjeta << endl;
    cout << "Transferencia: " << transferencia << endl;
    cout << "Con descuento: " << conDescuento << endl;

    archivo.close();
}

void buscarPorMonto() {
    ifstream archivo("ventas.txt");

    double monto;
    cout << "Ingrese monto minimo: ";
    cin >> monto;

    string linea;
    double total;

    cout << fixed << setprecision(2);
    cout << "\nVentas mayores o iguales a Q" << monto << ":\n";

    while (getline(archivo, linea)) {
        int pos = linea.rfind(',');
        int pos2 = linea.rfind(',', pos - 1);

        total = stod(linea.substr(pos2 + 1, pos - pos2 - 1));

        if (total >= monto) {
            cout << linea << endl;
        }
    }

    archivo.close();
}

int main() {
    int opcion = 0;

    do {
        mostrarMenu();
        cin >> opcion;

        switch (opcion) {
            case 1:
                registrarVenta();
                break;
            case 2:
                mostrarVentas();
                break;
            case 3:
                reporteGeneral();
                break;
            case 4:
                buscarPorMonto();
                break;
            case 5:
                cout << "Saliendo...\n";
                break;
            default:
                cout << "Opcion invalida\n";
                continue;
        }

    } while (opcion != 5);

    return 0;
}