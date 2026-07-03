#include <iostream>
#include <queue>
using namespace std;

int main() {
    queue<string> banco;
    string cliente;
    int op;

    do {
        cout << "\n--- BANCO ---" << endl;
        cout << "1. Agregar cliente" << endl;
        cout << "2. Atender cliente" << endl;
        cout << "3. Mostrar siguiente cliente" << endl;
        cout << "4. Mostrar cantidad de clientes" << endl;
        cout << "5. Salir" << endl;
        cout << "Ingrese opcion: ";
        cin >> op;

        switch (op) {
            case 1:
                cout << "Nombre del cliente: ";
                cin >> cliente;
                banco.push(cliente);
                cout << "Cliente agregado." << endl;
                break;

            case 2:
                if (!banco.empty()) {
                    cout << "Cliente atendido: " << banco.front() << endl;
                    banco.pop();
                } else {
                    cout << "No hay clientes para atender." << endl;
                }
                break;

            case 3:
                if (!banco.empty()) {
                    cout << "Siguiente cliente: " << banco.front() << endl;
                } else {
                    cout << "No hay clientes en espera." << endl;
                }
                break;

            case 4:
                cout << "Cantidad de clientes: " << banco.size() << endl;
                break;

            case 5:
                cout << "Programa finalizado." << endl;
                break;

            default:
                cout << "Opcion no valida." << endl;
        }

    } while (op != 5);

    return 0;
}

