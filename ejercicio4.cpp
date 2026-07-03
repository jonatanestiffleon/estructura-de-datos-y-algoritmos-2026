#include <iostream>
#include <stack>
using namespace std;

int main() {
    stack<string> paginas;
    string pagina;
    int op;

    do {
        cout << "\n--- PAGINAS VISITADAS ---" << endl;
        cout << "1. Visitar pagina" << endl;
        cout << "2. Retroceder" << endl;
        cout << "3. Mostrar pagina actual" << endl;
        cout << "4. Salir" << endl;
        cout << "Ingrese opcion: ";
        cin >> op;

        switch (op) {
            case 1:
                cout << "Ingrese pagina: ";
                cin >> pagina;
                paginas.push(pagina);
                cout << "Pagina guardada." << endl;
                break;

            case 2:
                if (!paginas.empty()) {
                    paginas.pop();

                    if (!paginas.empty()) {
                        cout << "Pagina actual: " << paginas.top() << endl;
                    } else {
                        cout << "No hay pagina anterior." << endl;
                    }
                } else {
                    cout << "No hay paginas visitadas." << endl;
                }
                break;

            case 3:
                if (!paginas.empty()) {
                    cout << "Pagina actual: " << paginas.top() << endl;
                } else {
                    cout << "No hay pagina actual." << endl;
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

