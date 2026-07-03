#include <iostream>
#include <stack>
using namespace std;

int main() {
    stack<char> letras;
    string palabra;

    cout << "Ingrese una palabra: ";
    cin >> palabra;

    for (int i = 0; i < palabra.length(); i++) {
        letras.push(palabra[i]);
    }

    cout << "Palabra invertida: ";

    while (!letras.empty()) {
        cout << letras.top();
        letras.pop();
    }

    cout << endl;

    return 0;
}

