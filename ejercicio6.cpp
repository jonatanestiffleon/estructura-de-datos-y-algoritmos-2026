#include <iostream>
#include <queue>
using namespace std;

int main() {
    queue<string> clientes;
    string nombre;
    int op;

    do {
        cout << "\n--- COLA DE CLIENTES ---" << endl;
        cout << "1. Registrar cliente" << endl;
        cout << "2. Atender cliente" << endl;
        cout << "3. Mostrar clientes pendientes" << endl;
        cout << "4. Salir" << endl;
        cout << "Ingrese opcion: ";
        cin >> op;

        switch (op) {
            case 1:
                cout << "Nombre del cliente: ";
                cin >> nombre;
                clientes.push(nombre);
                cout << "Cliente registrado." << endl;
                break;

            case 2:
                if (!clientes.empty()) {
                    cout << "Cliente atendido: " << clientes.front() << endl;
                    clientes.pop();
                } else {
                    cout << "No hay clientes en la cola." << endl;
                }
                break;

            case 3:
                cout << "Clientes pendientes: " << clientes.size() << endl;
                break;

            case 4:
                cout << "Programa finalizado." << endl;
                break;

            default:
                cout << "Opcion no valida." << endl;
        }

    } while (op != 4);

    return 0;
}
