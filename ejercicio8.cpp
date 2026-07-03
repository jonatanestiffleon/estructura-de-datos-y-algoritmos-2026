#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct Ticket {
    int codigo;
    string cliente;
    int prioridad;
};

struct Ordenar {
    bool operator()(Ticket a, Ticket b) {
        return a.prioridad < b.prioridad;
    }
};

int main() {
    priority_queue<Ticket, vector<Ticket>, Ordenar> tickets;
    Ticket t;
    int cantidad;

    cout << "Cantidad de tickets: ";
    cin >> cantidad;

    for (int i = 1; i <= cantidad; i++) {
        cout << "\nTicket " << i << endl;

        cout << "Codigo: ";
        cin >> t.codigo;

        cout << "Cliente: ";
        cin >> t.cliente;

        cout << "Prioridad: ";
        cin >> t.prioridad;

        tickets.push(t);
    }

    cout << "\n--- Orden de atencion ---" << endl;

    while (!tickets.empty()) {
        t = tickets.top();

        cout << "\nCodigo: " << t.codigo << endl;
        cout << "Cliente: " << t.cliente << endl;
        cout << "Prioridad: " << t.prioridad << endl;

        tickets.pop();
    }

    return 0;
}
