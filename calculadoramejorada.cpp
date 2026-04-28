#include <iostream> // Permite usar cout y cin
using namespace std; // Permite escribir cout y cin sin std::

int main() { // Inicio del programa

    int opcion; // Guarda la operación que el usuario elige
    double num1, num2, resultado; // Guarda los números y el resultado
    int repetir = 1; // Sirve para repetir la calculadora

    cout << "==============================" << endl; // Línea decorativa
    cout << "       CALCULADORA LEON       " << endl; // Título
    cout << "==============================" << endl; // Línea decorativa

    while (repetir == 1) { // Repite mientras el usuario quiera continuar

        cout << endl; // Salto de línea
        cout << "Seleccione una operacion:" << endl; // Mensaje para elegir operación
        cout << "1. Suma" << endl; // Opción suma
        cout << "2. Resta" << endl; // Opción resta
        cout << "3. Multiplicacion" << endl; // Opción multiplicación
        cout << "4. Division" << endl; // Opción división
        cout << "5. Potencia al cuadrado" << endl; // Operación agregada sencilla
        cout << "Ingrese una opcion: "; // Pide opción
        cin >> opcion; // Lee la opción

        cout << "Ingrese el primer numero: "; // Pide primer número
        cin >> num1; // Lee primer número

        if (opcion != 5) { // Si no es potencia al cuadrado, pide segundo número
            cout << "Ingrese el segundo numero: "; // Pide segundo número
            cin >> num2; // Lee segundo número
        }

        if (opcion == 1) { // Si eligió suma
            resultado = num1 + num2; // Calcula suma
            cout << "El resultado es: " << resultado << endl; // Muestra resultado
        }
        else if (opcion == 2) { // Si eligió resta
            resultado = num1 - num2; // Calcula resta
            cout << "El resultado es: " << resultado << endl; // Muestra resultado
        }
        else if (opcion == 3) { // Si eligió multiplicación
            resultado = num1 * num2; // Calcula multiplicación
            cout << "El resultado es: " << resultado << endl; // Muestra resultado
        }
        else if (opcion == 4) { // Si eligió división
            if (num2 != 0) { // Verifica que no se divida entre cero
                resultado = num1 / num2; // Calcula división
                cout << "El resultado es: " << resultado << endl; // Muestra resultado
            }
            else { // Si el segundo número es cero
                cout << "Error: no se puede dividir entre cero." << endl; // Mensaje de error
            }
        }
        else if (opcion == 5) { // Si eligió potencia al cuadrado
            resultado = num1 * num1; // Calcula el cuadrado
            cout << "El resultado es: " << resultado << endl; // Muestra resultado
        }
        else { // Si escribe una opción incorrecta
            cout << "Opcion no valida." << endl; // Mensaje de error
        }

        cout << endl; // Salto de línea
        cout << "Desea realizar otra operacion? Escriba 1 para SI o 0 para NO: "; // Pregunta si desea repetir
        cin >> repetir; // Lee la respuesta
    }

    cout << endl; // Salto de línea
    cout << "Gracias por usar Calculadora Leon." << endl; // Mensaje final

    return 0; // Fin del programa
}