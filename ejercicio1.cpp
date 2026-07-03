#include <iostream>
#include <stack>
using namespace std;

int main() {
    stack<int> numeros;
    int num;

    cout << "Ingrese numeros (-1 para terminar): " << endl;

    do {
        cout << "Numero: ";
        cin >> num;

        if (num != -1) {
            numeros.push(num);
        }

    } while (num != -1);

    cout << "\nCantidad de elementos en la pila: " << numeros.size() << endl;

    if (!numeros.empty()) {
        cout << "Ultimo elemento ingresado: " << numeros.top() << endl;
    } else {
        cout << "No se ingresaron numeros." << endl;
    }

    return 0;
}

