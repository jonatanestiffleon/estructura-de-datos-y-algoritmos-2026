#include <iostream>
#include <vector>
using namespace std;

class Contacto {
public:
    string nombre;
    string telefono;
    string correo;

    void registrar() {
        cout << "Nombre: ";
        cin >> nombre;

        cout << "Telefono: ";
        cin >> telefono;

        cout << "Correo: ";
        cin >> correo;
    }

    void mostrar() {
        cout << "\nNombre: " << nombre << endl;
        cout << "Telefono: " << telefono << endl;
        cout << "Correo: " << correo << endl;
    }
};

int main() {
    vector<Contacto> contactos;
    Contacto c;
    string nombreBuscar;
    int op;
    bool encontrado;

    do {
        cout << "\n--- CONTACTOS ---" << endl;
        cout << "1. Agregar contacto" << endl;
        cout << "2. Buscar por nombre" << endl;
        cout << "3. Eliminar contacto" << endl;
        cout << "4. Mostrar contactos" << endl;
        cout << "5. Salir" << endl;
        cout << "Ingrese opcion: ";
        cin >> op;

        switch (op) {
            case 1:
                c.registrar();
                contactos.push_back(c);
                cout << "Contacto agregado." << endl;
                break;

            case 2:
                cout << "Ingrese nombre a buscar: ";
                cin >> nombreBuscar;

                encontrado = false;

                for (int i = 0; i < contactos.size(); i++) {
                    if (contactos[i].nombre == nombreBuscar) {
                        cout << "\nContacto encontrado:" << endl;
                        contactos[i].mostrar();
                        encontrado = true;
                    }
                }

                if (!encontrado) {
                    cout << "No se encontro el contacto." << endl;
                }
                break;

            case 3:
                cout << "Ingrese nombre a eliminar: ";
                cin >> nombreBuscar;

                encontrado = false;

                for (int i = 0; i < contactos.size(); i++) {
                    if (contactos[i].nombre == nombreBuscar) {
                        contactos.erase(contactos.begin() + i);
                        cout << "Contacto eliminado." << endl;
                        encontrado = true;
                        break;
                    }
                }

                if (!encontrado) {
                    cout << "No se encontro el contacto." << endl;
                }
                break;

            case 4:
                if (contactos.size() > 0) {
                    for (int i = 0; i < contactos.size(); i++) {
                        cout << "\nContacto " << i + 1 << endl;
                        contactos[i].mostrar();
                    }
                } else {
                    cout << "No hay contactos registrados." << endl;
                }
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

