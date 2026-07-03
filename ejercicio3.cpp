#include <iostream>
#include <stack>
using namespace std;

int main() {
    stack<char> letras;
    string palabra, invertida = "";

    cout << "Ingrese una palabra: ";
    cin >> palabra;

    for (int i = 0; i < palabra.length(); i++) {
        letras.push(palabra[i]);
    }

    while (!letras.empty()) {
        invertida = invertida + letras.top();
        letras.pop();
    }

    cout << "Palabra original: " << palabra << endl;
    cout << "Palabra invertida: " << invertida << endl;

    if (palabra == invertida) {
        cout << "La palabra es palindromo." << endl;
    } else {
        cout << "La palabra no es palindromo." << endl;
    }

    return 0;
}
