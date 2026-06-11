#include <iostream>
#include <string>
#include <iomanip>
#include <cstdlib>
using namespace std;

// ======================================================
// PROGRAMA: Gestion de salario de empleado
// EMPRESA: Licoreria Leon
// TRABAJADOR: Jonatan Estiff Leon Santa Maria
// ======================================================

// Limpia la pantalla para que el resultado no se mezcle con el menu
void limpiarPantalla() {
    system("cls");
}

// Funcion para saber si un anio es bisiesto
bool esBisiesto(int anio) {
    if ((anio % 4 == 0 && anio % 100 != 0) || (anio % 400 == 0)) {
        return true;
    } else {
        return false;
    }
}

// Funcion que devuelve la cantidad de dias que tiene un mes
int diasDelMes(int mes, int anio) {
    if (mes == 1 || mes == 3 || mes == 5 || mes == 7 ||
        mes == 8 || mes == 10 || mes == 12) {
        return 31;
    } else if (mes == 4 || mes == 6 || mes == 9 || mes == 11) {
        return 30;
    } else if (mes == 2) {
        if (esBisiesto(anio)) {
            return 29;
        } else {
            return 28;
        }
    } else {
        return 0;
    }
}

// Funcion que devuelve el nombre del mes
string nombreMes(int mes) {
    switch (mes) {
        case 1: return "Enero";
        case 2: return "Febrero";
        case 3: return "Marzo";
        case 4: return "Abril";
        case 5: return "Mayo";
        case 6: return "Junio";
        case 7: return "Julio";
        case 8: return "Agosto";
        case 9: return "Septiembre";
        case 10: return "Octubre";
        case 11: return "Noviembre";
        case 12: return "Diciembre";
        default: return "Mes no valido";
    }
}

// Funcion para calcular el dia de la semana
// Devuelve: 0 = domingo, 1 = lunes, 2 = martes, ..., 6 = sabado
int diaSemana(int dia, int mes, int anio) {
    if (mes < 3) {
        mes += 12;
        anio--;
    }

    int k = anio % 100;
    int j = anio / 100;

    int h = (dia + (13 * (mes + 1)) / 5 + k + (k / 4) + (j / 4) + (5 * j)) % 7;

    // Conversion para que 0 sea domingo
    int d = (h + 6) % 7;

    return d;
}

// Funcion para contar los dias trabajados
// El trabajador labora de lunes a sabado y descansa domingo
int contarDiasTrabajados(int mes, int anio) {
    int totalDias = diasDelMes(mes, anio);
    int diasTrabajados = 0;

    for (int dia = 1; dia <= totalDias; dia++) {
        if (diaSemana(dia, mes, anio) != 0) {
            diasTrabajados++;
        }
    }

    return diasTrabajados;
}

// Funcion para validar si el mes ya se cumplio
bool mesCumplido(int mes, int anio) {
    // Fecha actual considerada:
    // Hoy estamos 11 de junio del 2026.
    // Por eso, junio 2026 todavia no se puede reportar como mes culminado.
    int mesActual = 6;
    int anioActual = 2026;

    if (anio < anioActual) {
        return true;
    } else if (anio == anioActual && mes < mesActual) {
        return true;
    } else {
        return false;
    }
}

// Funcion que calcula el sueldo bruto
double calcularSueldoBruto(int horasTrabajadas, double pagoPorHora) {
    return horasTrabajadas * pagoPorHora;
}

// Funcion que calcula el total de descuentos
double calcularTotalDescuentos(double seguro, double afp) {
    return seguro + afp;
}

// Funcion que calcula el total de beneficios
double calcularTotalBeneficios(double puntualidad, double clientes) {
    return puntualidad + clientes;
}

// Funcion que calcula el sueldo neto
double calcularSueldoNeto(double sueldoBruto, double descuentos, double beneficios) {
    return sueldoBruto - descuentos + beneficios;
}

// Funcion para mostrar los meses disponibles
void mostrarMeses() {
    cout << "\nSeleccione el mes que desea consultar:\n";
    cout << "1. Enero\n";
    cout << "2. Febrero\n";
    cout << "3. Marzo\n";
    cout << "4. Abril\n";
    cout << "5. Mayo\n";
    cout << "6. Junio\n";
    cout << "7. Julio\n";
    cout << "8. Agosto\n";
    cout << "9. Septiembre\n";
    cout << "10. Octubre\n";
    cout << "11. Noviembre\n";
    cout << "12. Diciembre\n";
}

// Funcion para preguntar si desea volver al menu o salir
bool volverAlMenu() {
    int opcionContinuar;

    do {
        cout << "\n=============================================================\n";
        cout << "Que desea hacer ahora?\n";
        cout << "\n1. Volver al menu principal";
        cout << "\n2. Salir del programa";
        cout << "\nSeleccione una opcion: ";
        cin >> opcionContinuar;

        if (opcionContinuar == 1) {
            limpiarPantalla();
            return true;
        } else if (opcionContinuar == 2) {
            limpiarPantalla();
            return false;
        } else {
            cout << "\nOpcion no valida. Ingrese 1 o 2.\n";
        }

    } while (opcionContinuar != 1 && opcionContinuar != 2);

    return true;
}

// Funcion para mostrar salario actual resaltado
void mostrarSalarioActual(
    string nombre,
    int mes,
    int anio,
    int totalDiasMes,
    int diasTrabajados,
    int diasDescanso,
    int horasTrabajadas,
    int horasPorDia,
    double pagoPorHora,
    double descuentoSeguro,
    double descuentoAFP,
    double beneficioPuntualidad,
    double beneficioClientes
) {
    double sueldoBruto = calcularSueldoBruto(horasTrabajadas, pagoPorHora);
    double totalDescuentos = calcularTotalDescuentos(descuentoSeguro, descuentoAFP);
    double totalBeneficios = calcularTotalBeneficios(beneficioPuntualidad, beneficioClientes);
    double sueldoNeto = calcularSueldoNeto(sueldoBruto, totalDescuentos, totalBeneficios);

    cout << fixed << setprecision(2);

    cout << "\n\n";
    cout << "=============================================================\n";
    cout << "                    RESULTADO DEL CALCULO\n";
    cout << "=============================================================\n";
    cout << " Trabajador: " << nombre << endl;
    cout << " Mes evaluado: " << nombreMes(mes) << " del " << anio << endl;

    cout << "-------------------------------------------------------------\n";
    cout << " DETALLE DEL MES\n";
    cout << " El mes tiene: " << totalDiasMes << " dias" << endl;
    cout << " Dias trabajados: " << diasTrabajados << endl;
    cout << " Dias de descanso: " << diasDescanso << endl;
    cout << " Horas por dia: " << horasPorDia << endl;
    cout << " Total de horas trabajadas: " << horasTrabajadas << endl;

    cout << "-------------------------------------------------------------\n";
    cout << " INGRESOS\n";
    cout << " Pago por hora: $" << pagoPorHora << endl;
    cout << " Pago diario: $" << pagoPorHora * horasPorDia << endl;
    cout << " Sueldo bruto: $" << sueldoBruto << endl;

    cout << "-------------------------------------------------------------\n";
    cout << " DESCUENTOS MENSUALES\n";
    cout << " Seguro: $" << descuentoSeguro << endl;
    cout << " AFP: $" << descuentoAFP << endl;
    cout << " Total descuentos: $" << totalDescuentos << endl;

    cout << "-------------------------------------------------------------\n";
    cout << " BENEFICIOS MENSUALES\n";
    cout << " Puntualidad y metas logradas: $" << beneficioPuntualidad << endl;
    cout << " Captacion de nuevos clientes: $" << beneficioClientes << endl;
    cout << " Total beneficios: $" << totalBeneficios << endl;

    cout << "=============================================================\n";
    cout << "                 SUELDO NETO A COBRAR: $" << sueldoNeto << endl;
    cout << "=============================================================\n";
}

// Funcion para imprimir boleta
void imprimirBoleta(
    string nombre,
    int edad,
    string direccion,
    string empresa,
    string ruc,
    string ciudad,
    int mes,
    int anio,
    int horasPorDia,
    double pagoPorHora,
    double descuentoSeguro,
    double descuentoAFP,
    double beneficioPuntualidad,
    double beneficioClientes
) {
    int totalDiasMes = diasDelMes(mes, anio);
    int diasTrabajados = contarDiasTrabajados(mes, anio);
    int diasDescanso = totalDiasMes - diasTrabajados;
    int horasTrabajadas = diasTrabajados * horasPorDia;

    double sueldoBruto = calcularSueldoBruto(horasTrabajadas, pagoPorHora);
    double totalDescuentos = calcularTotalDescuentos(descuentoSeguro, descuentoAFP);
    double totalBeneficios = calcularTotalBeneficios(beneficioPuntualidad, beneficioClientes);
    double sueldoNeto = calcularSueldoNeto(sueldoBruto, totalDescuentos, totalBeneficios);

    cout << fixed << setprecision(2);

    cout << "\n\n";
    cout << "=============================================================\n";
    cout << "                         BOLETA DE PAGO\n";
    cout << "=============================================================\n";
    cout << " Empresa: " << empresa << endl;
    cout << " RUC: " << ruc << endl;
    cout << " Ciudad: " << ciudad << endl;
    cout << " Trabajador: " << nombre << endl;
    cout << " Edad: " << edad << " anios" << endl;
    cout << " Direccion: " << direccion << endl;
    cout << " Mes seleccionado: " << nombreMes(mes) << " del " << anio << endl;

    cout << "-------------------------------------------------------------\n";
    cout << " DETALLE DEL MES\n";
    cout << " El mes de " << nombreMes(mes) << " tiene " << totalDiasMes << " dias." << endl;
    cout << " Dias trabajados: " << diasTrabajados << endl;
    cout << " Dias de descanso: " << diasDescanso << endl;

    cout << "-------------------------------------------------------------\n";
    cout << " DATOS LABORALES\n";
    cout << " Horario laboral: Lunes a sabado" << endl;
    cout << " Dia de descanso: Domingo" << endl;
    cout << " Pago por hora: $" << pagoPorHora << endl;
    cout << " Horas por dia: " << horasPorDia << endl;
    cout << " Total de horas trabajadas: " << horasTrabajadas << endl;

    cout << "-------------------------------------------------------------\n";
    cout << " INGRESOS\n";
    cout << " Sueldo bruto por horas trabajadas: $" << sueldoBruto << endl;

    cout << "-------------------------------------------------------------\n";
    cout << " DESCUENTOS MENSUALES\n";
    cout << " Descuento por seguro: $" << descuentoSeguro << endl;
    cout << " Descuento por AFP: $" << descuentoAFP << endl;
    cout << " Total descuentos: $" << totalDescuentos << endl;

    cout << "-------------------------------------------------------------\n";
    cout << " BENEFICIOS MENSUALES\n";
    cout << " Beneficio por puntualidad y metas logradas: $" << beneficioPuntualidad << endl;
    cout << " Beneficio por captacion de nuevos clientes: $" << beneficioClientes << endl;
    cout << " Total beneficios: $" << totalBeneficios << endl;

    cout << "=============================================================\n";
    cout << "                 SUELDO NETO A COBRAR: $" << sueldoNeto << endl;
    cout << "=============================================================\n";
    cout << " Licoreria Leon - 24 horas\n";
    cout << " Calidad y garantia\n";
    cout << "=============================================================\n";
}

// Funcion para mostrar organigrama
void mostrarOrganigrama() {
    cout << "\n\n";
    cout << "=============================================================\n";
    cout << "              ORGANIGRAMA DE LICORERIA LEON\n";
    cout << "=============================================================\n";
    cout << "                       PROPIETARIO\n";
    cout << "                    Jonatan Estiff\n";
    cout << "                           |\n";
    cout << "                    GERENTE GENERAL\n";
    cout << "                           |\n";
    cout << "                       SUBGERENTE\n";
    cout << "                           |\n";
    cout << "          ---------------------------------\n";
    cout << "          |               |               |\n";
    cout << "        CAJERO        REPONEDOR      PERSONAL DE APOYO\n";
    cout << "          |               |               |\n";
    cout << "     Control de       Orden de       Apoyo en ventas,\n";
    cout << "     ventas y caja    productos      limpieza y atencion\n";
    cout << "=============================================================\n";
    cout << " Este organigrama muestra el orden basico de trabajo\n";
    cout << " y la responsabilidad principal de cada area.\n";
    cout << "=============================================================\n";
}

int main() {
    // Datos personales del trabajador
    string nombre = "Jonatan Estiff Leon Santa Maria";
    int edad = 31;
    string direccion = "Jr. San Alejandro 343 - Tingo Maria";

    // Datos de la empresa
    string empresa = "Licoreria Leon";
    string ruc = "20605586458";
    string ciudad = "Tingo Maria";

    // Datos del pago
    double pagoPorHora = 120.0;
    int horasPorDia = 8;

    // Valores establecidos por el Ing. Carlos
    double descuentoSeguroBase = 120.0;
    double descuentoAFPBase = 150.0;
    double beneficioPuntualidadBase = 500.0;
    double beneficioClientesBase = 1000.0;

    // Valores actuales que se usaran para el calculo
    double descuentoSeguroActual = descuentoSeguroBase;
    double descuentoAFPActual = descuentoAFPBase;
    double beneficioPuntualidadActual = beneficioPuntualidadBase;
    double beneficioClientesActual = beneficioClientesBase;

    // Mes inicial por defecto: Mayo 2026
    // Mayo ya se puede consultar porque la fecha actual considerada es 11/06/2026.
    int mes = 5;
    int anio = 2026;

    int totalDiasMes = diasDelMes(mes, anio);
    int diasTrabajados = contarDiasTrabajados(mes, anio);
    int diasDescanso = totalDiasMes - diasTrabajados;
    int horasTrabajadas = diasTrabajados * horasPorDia;

    int opcion;
    bool continuar = true;

    limpiarPantalla();

    do {
        cout << "\n=============================================================\n";
        cout << "            SISTEMA DE SALARIO - LICORERIA LEON\n";
        cout << "=============================================================\n";
        cout << " Trabajador actual: " << nombre << endl;
        cout << " Mes actual: " << nombreMes(mes) << " del " << anio << endl;
        cout << "=============================================================\n";
        cout << " 1. Seleccionar mes y calcular horas\n";
        cout << " 2. Mostrar salario actual\n";
        cout << " 3. Gestionar descuentos\n";
        cout << " 4. Gestionar beneficios\n";
        cout << " 5. Imprimir boleta de pago\n";
        cout << " 6. Ver organigrama de trabajadores\n";
        cout << " 7. Salir\n";
        cout << "=============================================================\n";
        cout << " Seleccione una opcion: ";
        cin >> opcion;

        switch (opcion) {

            case 1: {
                limpiarPantalla();

                cout << "\n=============================================================\n";
                cout << "                 SELECCIONAR MES DE TRABAJO\n";
                cout << "=============================================================\n";

                do {
                    cout << "\nIngrese el anio que desea consultar: ";
                    cin >> anio;

                    mostrarMeses();
                    cout << "Opcion: ";
                    cin >> mes;

                    if (mes < 1 || mes > 12) {
                        cout << "\nMes no valido. Elija una opcion del 1 al 12.\n";
                    } else if (!mesCumplido(mes, anio)) {
                        cout << "\nEl mes seleccionado aun no se cumple.\n";
                        cout << "No se puede saber con exactitud cuantos dias trabajara en ese mes.\n";
                        cout << "Por favor, ingrese otro mes que ya haya culminado.\n";
                    }

                } while (mes < 1 || mes > 12 || !mesCumplido(mes, anio));

                totalDiasMes = diasDelMes(mes, anio);
                diasTrabajados = contarDiasTrabajados(mes, anio);
                diasDescanso = totalDiasMes - diasTrabajados;
                horasTrabajadas = diasTrabajados * horasPorDia;

                limpiarPantalla();

                cout << "\n\n";
                cout << "=============================================================\n";
                cout << "                  RESULTADO DEL MES ELEGIDO\n";
                cout << "=============================================================\n";
                cout << " Mes seleccionado: " << nombreMes(mes) << " del " << anio << endl;
                cout << " El mes tiene: " << totalDiasMes << " dias" << endl;
                cout << " Dias trabajados: " << diasTrabajados << endl;
                cout << " Dias de descanso: " << diasDescanso << endl;
                cout << " Horas por dia: " << horasPorDia << endl;
                cout << " Total de horas trabajadas: " << horasTrabajadas << " horas" << endl;
                cout << "=============================================================\n";

                continuar = volverAlMenu();
                break;
            }

            case 2: {
                limpiarPantalla();

                mostrarSalarioActual(
                    nombre,
                    mes,
                    anio,
                    totalDiasMes,
                    diasTrabajados,
                    diasDescanso,
                    horasTrabajadas,
                    horasPorDia,
                    pagoPorHora,
                    descuentoSeguroActual,
                    descuentoAFPActual,
                    beneficioPuntualidadActual,
                    beneficioClientesActual
                );

                continuar = volverAlMenu();
                break;
            }

            case 3: {
                int opcionDescuento;

                limpiarPantalla();

                cout << "\n=============================================================\n";
                cout << "                    GESTIONAR DESCUENTOS\n";
                cout << "=============================================================\n";
                cout << " Los descuentos se aplican una sola vez al mes.\n";
                cout << " No se descuentan por dia ni por hora trabajada.\n\n";

                cout << " 1. Aplicar descuentos establecidos por el Ing. Carlos\n";
                cout << "    Seguro: $120.00 | AFP: $150.00\n\n";

                cout << " 2. Ingresar descuentos personalizados\n";
                cout << "    Esta opcion permite variar los descuentos y modifica el sueldo neto final.\n\n";

                cout << " 3. Ver descuentos que se estan usando actualmente\n";
                cout << "=============================================================\n";
                cout << " Seleccione una opcion: ";
                cin >> opcionDescuento;

                limpiarPantalla();

                if (opcionDescuento == 1) {
                    descuentoSeguroActual = descuentoSeguroBase;
                    descuentoAFPActual = descuentoAFPBase;

                    cout << "\n=============================================================\n";
                    cout << "                 DESCUENTOS APLICADOS\n";
                    cout << "=============================================================\n";
                    cout << " Se aplicaron los descuentos establecidos por el Ing. Carlos.\n";
                    cout << " Seguro: $" << descuentoSeguroActual << endl;
                    cout << " AFP: $" << descuentoAFPActual << endl;
                    cout << "=============================================================\n";

                    mostrarSalarioActual(
                        nombre,
                        mes,
                        anio,
                        totalDiasMes,
                        diasTrabajados,
                        diasDescanso,
                        horasTrabajadas,
                        horasPorDia,
                        pagoPorHora,
                        descuentoSeguroActual,
                        descuentoAFPActual,
                        beneficioPuntualidadActual,
                        beneficioClientesActual
                    );

                } else if (opcionDescuento == 2) {
                    cout << "\nIngrese nuevo descuento por seguro: $";
                    cin >> descuentoSeguroActual;

                    cout << "Ingrese nuevo descuento por AFP: $";
                    cin >> descuentoAFPActual;

                    limpiarPantalla();

                    cout << "\n=============================================================\n";
                    cout << "              DESCUENTOS PERSONALIZADOS REGISTRADOS\n";
                    cout << "=============================================================\n";
                    cout << " Importante: al modificar los descuentos, el sueldo neto final varia.\n";
                    cout << " Nuevo descuento por seguro: $" << descuentoSeguroActual << endl;
                    cout << " Nuevo descuento por AFP: $" << descuentoAFPActual << endl;
                    cout << "=============================================================\n";

                    mostrarSalarioActual(
                        nombre,
                        mes,
                        anio,
                        totalDiasMes,
                        diasTrabajados,
                        diasDescanso,
                        horasTrabajadas,
                        horasPorDia,
                        pagoPorHora,
                        descuentoSeguroActual,
                        descuentoAFPActual,
                        beneficioPuntualidadActual,
                        beneficioClientesActual
                    );

                } else if (opcionDescuento == 3) {
                    cout << fixed << setprecision(2);

                    cout << "\n=============================================================\n";
                    cout << "                  DESCUENTOS ACTUALES\n";
                    cout << "=============================================================\n";
                    cout << " Seguro: $" << descuentoSeguroActual << endl;
                    cout << " AFP: $" << descuentoAFPActual << endl;
                    cout << " Total descuentos: $" << descuentoSeguroActual + descuentoAFPActual << endl;
                    cout << "=============================================================\n";

                } else {
                    cout << "\nOpcion no valida.\n";
                }

                continuar = volverAlMenu();
                break;
            }

            case 4: {
                int opcionBeneficio;

                limpiarPantalla();

                cout << "\n=============================================================\n";
                cout << "                    GESTIONAR BENEFICIOS\n";
                cout << "=============================================================\n";
                cout << " Los beneficios se aplican una sola vez al mes.\n";
                cout << " No se pagan por dia ni por hora trabajada.\n\n";

                cout << " 1. Aplicar beneficios establecidos por el Ing. Carlos\n";
                cout << "    Puntualidad y metas: $500.00 | Captacion de clientes: $1000.00\n\n";

                cout << " 2. Ingresar beneficios personalizados\n";
                cout << "    Esta opcion permite variar los beneficios y modifica el sueldo neto final.\n\n";

                cout << " 3. Ver beneficios que se estan usando actualmente\n";
                cout << "=============================================================\n";
                cout << " Seleccione una opcion: ";
                cin >> opcionBeneficio;

                limpiarPantalla();

                if (opcionBeneficio == 1) {
                    beneficioPuntualidadActual = beneficioPuntualidadBase;
                    beneficioClientesActual = beneficioClientesBase;

                    cout << "\n=============================================================\n";
                    cout << "                 BENEFICIOS APLICADOS\n";
                    cout << "=============================================================\n";
                    cout << " Se aplicaron los beneficios establecidos por el Ing. Carlos.\n";
                    cout << " Puntualidad y metas logradas: $" << beneficioPuntualidadActual << endl;
                    cout << " Captacion de nuevos clientes: $" << beneficioClientesActual << endl;
                    cout << "=============================================================\n";

                    mostrarSalarioActual(
                        nombre,
                        mes,
                        anio,
                        totalDiasMes,
                        diasTrabajados,
                        diasDescanso,
                        horasTrabajadas,
                        horasPorDia,
                        pagoPorHora,
                        descuentoSeguroActual,
                        descuentoAFPActual,
                        beneficioPuntualidadActual,
                        beneficioClientesActual
                    );

                } else if (opcionBeneficio == 2) {
                    cout << "\nIngrese nuevo beneficio por puntualidad y metas logradas: $";
                    cin >> beneficioPuntualidadActual;

                    cout << "Ingrese nuevo beneficio por captacion de nuevos clientes: $";
                    cin >> beneficioClientesActual;

                    limpiarPantalla();

                    cout << "\n=============================================================\n";
                    cout << "              BENEFICIOS PERSONALIZADOS REGISTRADOS\n";
                    cout << "=============================================================\n";
                    cout << " Importante: al modificar los beneficios, el sueldo neto final varia.\n";
                    cout << " Nuevo beneficio por puntualidad y metas: $" << beneficioPuntualidadActual << endl;
                    cout << " Nuevo beneficio por captacion de clientes: $" << beneficioClientesActual << endl;
                    cout << "=============================================================\n";

                    mostrarSalarioActual(
                        nombre,
                        mes,
                        anio,
                        totalDiasMes,
                        diasTrabajados,
                        diasDescanso,
                        horasTrabajadas,
                        horasPorDia,
                        pagoPorHora,
                        descuentoSeguroActual,
                        descuentoAFPActual,
                        beneficioPuntualidadActual,
                        beneficioClientesActual
                    );

                } else if (opcionBeneficio == 3) {
                    cout << fixed << setprecision(2);

                    cout << "\n=============================================================\n";
                    cout << "                  BENEFICIOS ACTUALES\n";
                    cout << "=============================================================\n";
                    cout << " Puntualidad y metas logradas: $" << beneficioPuntualidadActual << endl;
                    cout << " Captacion de nuevos clientes: $" << beneficioClientesActual << endl;
                    cout << " Total beneficios: $" << beneficioPuntualidadActual + beneficioClientesActual << endl;
                    cout << "=============================================================\n";

                } else {
                    cout << "\nOpcion no valida.\n";
                }

                continuar = volverAlMenu();
                break;
            }

            case 5: {
                int tipoBoleta;

                limpiarPantalla();

                if (!mesCumplido(mes, anio)) {
                    cout << "\nNo se puede imprimir la boleta.\n";
                    cout << "El mes seleccionado todavia no ha culminado.\n";
                    cout << "Solo se imprimen boletas de meses cumplidos.\n";
                    continuar = volverAlMenu();
                    break;
                }

                cout << "\n=============================================================\n";
                cout << "                    IMPRIMIR BOLETA DE PAGO\n";
                cout << "=============================================================\n";
                cout << " 1. Imprimir boleta con valores actualmente seleccionados\n";
                cout << " 2. Imprimir boleta con valores establecidos por el Ing. Carlos\n";
                cout << "=============================================================\n";
                cout << " Seleccione una opcion: ";
                cin >> tipoBoleta;

                limpiarPantalla();

                if (tipoBoleta == 1) {
                    imprimirBoleta(
                        nombre,
                        edad,
                        direccion,
                        empresa,
                        ruc,
                        ciudad,
                        mes,
                        anio,
                        horasPorDia,
                        pagoPorHora,
                        descuentoSeguroActual,
                        descuentoAFPActual,
                        beneficioPuntualidadActual,
                        beneficioClientesActual
                    );

                } else if (tipoBoleta == 2) {
                    imprimirBoleta(
                        nombre,
                        edad,
                        direccion,
                        empresa,
                        ruc,
                        ciudad,
                        mes,
                        anio,
                        horasPorDia,
                        pagoPorHora,
                        descuentoSeguroBase,
                        descuentoAFPBase,
                        beneficioPuntualidadBase,
                        beneficioClientesBase
                    );

                } else {
                    cout << "\nOpcion no valida para imprimir boleta.\n";
                }

                continuar = volverAlMenu();
                break;
            }

            case 6: {
                limpiarPantalla();
                mostrarOrganigrama();
                continuar = volverAlMenu();
                break;
            }

            case 7: {
                limpiarPantalla();
                cout << "\nSaliendo del sistema de salario de Licoreria Leon...\n";
                cout << "Gracias por usar el programa.\n";
                continuar = false;
                break;
            }

            default: {
                limpiarPantalla();
                cout << "\nOpcion no valida. Intente nuevamente.\n";
                continuar = volverAlMenu();
                break;
            }
        }

    } while (continuar);

    return 0;
}



