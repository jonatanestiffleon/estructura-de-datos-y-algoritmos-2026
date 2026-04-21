#include <iostream>
using namespace std;

int main() {
    double num1, num2;
    int opcion;
    int repetir = 1;

    while (repetir == 1) {

        cout << "===== CALCULADORA LEON =====" << endl;

        cout << "Ingrese el primer numero: ";
        cin >> num1;

        cout << "Ingrese el segundo numero: ";
        cin >> num2;

        cout << "Seleccione la operacion:" << endl;
        cout << "1. Suma" << endl;
        cout << "2. Resta" << endl;
        cout << "3. Multiplicacion" << endl;
        cout << "4. Division" << endl;
        cout << "Opcion: ";
        cin >> opcion;

        if (opcion == 1) {
            cout << "Resultado: " << num1 + num2 << endl;
        }
        else if (opcion == 2) {
            cout << "Resultado: " << num1 - num2 << endl;
        }
        else if (opcion == 3) {
            cout << "Resultado: " << num1 * num2 << endl;
        }
        else if (opcion == 4) {
            if (num2 == 0) {
                cout << "Error: No se puede dividir entre 0." << endl;
            } else {
                cout << "Resultado: " << num1 / num2 << endl;
            }
        }
        else {
            cout << "Opcion no valida." << endl;
        }

        cout << "\nDesea realizar otra operacion?" << endl;
        cout << "1. Si" << endl;
        cout << "2. No" << endl;
        cout << "Opcion: ";
        cin >> repetir;

        cout << endl;
    }

    cout << "Gracias por usar la calculadora LEON." << endl;

    return 0;
}
