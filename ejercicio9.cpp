#include <iostream>
using namespace std;

class Estudiante {
public:
    int codigo;
    string nombre;
    int edad;
    string carrera;

    void registrar() {
        cout << "Codigo: ";
        cin >> codigo;

        cout << "Nombre: ";
        cin >> nombre;

        cout << "Edad: ";
        cin >> edad;

        cout << "Carrera: ";
        cin >> carrera;
    }

    void mostrar() {
        cout << "\nCodigo: " << codigo << endl;
        cout << "Nombre: " << nombre << endl;
        cout << "Edad: " << edad << endl;
        cout << "Carrera: " << carrera << endl;
    }
};

int main() {
    Estudiante lista[50];
    int cantidad = 0;
    int op;
    int codigoBuscar;
    bool encontrado;

    do {
        cout << "\n--- ESTUDIANTES ---" << endl;
        cout << "1. Registrar estudiante" << endl;
        cout << "2. Mostrar estudiantes" << endl;
        cout << "3. Buscar por codigo" << endl;
        cout << "4. Salir" << endl;
        cout << "Ingrese opcion: ";
        cin >> op;

        switch (op) {
            case 1:
                if (cantidad < 50) {
                    lista[cantidad].registrar();
                    cantidad++;
                    cout << "Estudiante registrado." << endl;
                } else {
                    cout << "No se pueden registrar mas estudiantes." << endl;
                }
                break;

            case 2:
                if (cantidad > 0) {
                    for (int i = 0; i < cantidad; i++) {
                        cout << "\nEstudiante " << i + 1 << endl;
                        lista[i].mostrar();
                    }
                } else {
                    cout << "No hay estudiantes registrados." << endl;
                }
                break;

            case 3:
                cout << "Ingrese codigo a buscar: ";
                cin >> codigoBuscar;

                encontrado = false;

                for (int i = 0; i < cantidad; i++) {
                    if (lista[i].codigo == codigoBuscar) {
                        cout << "\nEstudiante encontrado:" << endl;
                        lista[i].mostrar();
                        encontrado = true;
                    }
                }

                if (!encontrado) {
                    cout << "No se encontro el estudiante." << endl;
                }
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

