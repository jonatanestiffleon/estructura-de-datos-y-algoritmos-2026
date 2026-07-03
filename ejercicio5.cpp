#include <iostream>
#include <queue>
using namespace std;

int main() {
    queue<string> personas;
    string nombre;

    cout << "--- Registro de 10 personas ---" << endl;

    for (int i = 1; i <= 10; i++) {
        cout << "Persona " << i << ": ";
        cin >> nombre;
        personas.push(nombre);
    }

    cout << "\n--- Atencion en orden FIFO ---" << endl;

    while (!personas.empty()) {
        cout << "Atendiendo a: " << personas.front() << endl;
        personas.pop();
    }

    return 0;
}
