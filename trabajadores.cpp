#include <iostream>
#include <fstream>
#include <string>
#include <limits>
#include <iomanip>
using namespace std;

// =====================================================
// CONSTANTES GENERALES
// =====================================================

const int MAX = 10;
const int MAX_PLANTA = 7;
const int MAX_HORAS = 3;

const float PORCENTAJE_AFP = 0.1237;
const float DESCUENTO_SALUD = 90.00;
const float BONO_PUNTUALIDAD = 150.00;
const float BONO_METAS = 200.00;

// =====================================================
// CLASE EMPLEADO
// =====================================================

class Empleado {
private:
    string nombre;
    string tipoEmpleado;
    string cargoPrincipal;
    string puestoReal;

    int aniosEmpresa;
    int horasPorDia;
    int diasPorSemana;
    int horasSemana;

    float pagoHora;
    float sueldoBrutoMensual;
    float descuentoAFP;
    float descuentoSalud;
    float bonoPuntualidad;
    float bonoMetas;
    float sueldoNetoMensual;

public:
    Empleado() {
        nombre = "";
        tipoEmpleado = "";
        cargoPrincipal = "";
        puestoReal = "";

        aniosEmpresa = 0;
        horasPorDia = 0;
        diasPorSemana = 0;
        horasSemana = 0;

        pagoHora = 0;
        sueldoBrutoMensual = 0;
        descuentoAFP = 0;
        descuentoSalud = 0;
        bonoPuntualidad = 0;
        bonoMetas = 0;
        sueldoNetoMensual = 0;
    }

    // Metodos SET
    void setNombre(string n) {
        nombre = n;
    }

    void setTipoEmpleado(string t) {
        tipoEmpleado = t;
    }

    void setCargoPrincipal(string c) {
        cargoPrincipal = c;
    }

    void setPuestoReal(string p) {
        puestoReal = p;
    }

    void setAniosEmpresa(int a) {
        aniosEmpresa = a;
    }

    void setHorasPorDia(int h) {
        horasPorDia = h;
    }

    void setDiasPorSemana(int d) {
        diasPorSemana = d;
    }

    void setHorasSemana(int h) {
        horasSemana = h;
    }

    void setPagoHora(float p) {
        pagoHora = p;
    }

    // Metodos GET
    string getNombre() {
        return nombre;
    }

    string getTipoEmpleado() {
        return tipoEmpleado;
    }

    string getCargoPrincipal() {
        return cargoPrincipal;
    }

    string getPuestoReal() {
        return puestoReal;
    }

    int getAniosEmpresa() {
        return aniosEmpresa;
    }

    int getHorasPorDia() {
        return horasPorDia;
    }

    int getDiasPorSemana() {
        return diasPorSemana;
    }

    int getHorasSemana() {
        return horasSemana;
    }

    float getPagoHora() {
        return pagoHora;
    }

    float getSueldoBrutoMensual() {
        return sueldoBrutoMensual;
    }

    float getDescuentoAFP() {
        return descuentoAFP;
    }

    float getDescuentoSalud() {
        return descuentoSalud;
    }

    float getBonoPuntualidad() {
        return bonoPuntualidad;
    }

    float getBonoMetas() {
        return bonoMetas;
    }

    float getSueldoNetoMensual() {
        return sueldoNetoMensual;
    }

    // =====================================================
    // CALCULO DEL SUELDO MENSUAL
    // =====================================================

    void calcularSueldoMensual() {
        sueldoBrutoMensual = horasSemana * pagoHora * 4;

        if (tipoEmpleado == "Empleado de planta") {
            descuentoAFP = sueldoBrutoMensual * PORCENTAJE_AFP;
            descuentoSalud = DESCUENTO_SALUD;
            bonoPuntualidad = BONO_PUNTUALIDAD;
            bonoMetas = BONO_METAS;

            sueldoNetoMensual = sueldoBrutoMensual
                                - descuentoAFP
                                - descuentoSalud
                                + bonoPuntualidad
                                + bonoMetas;
        } else {
            descuentoAFP = 0;
            descuentoSalud = 0;
            bonoPuntualidad = 0;
            bonoMetas = 0;

            sueldoNetoMensual = sueldoBrutoMensual;
        }
    }

    // =====================================================
    // MOSTRAR DATOS DEL TRABAJADOR
    // =====================================================

    void mostrarDatos() {
        cout << "\n------------------------------------------------------------" << endl;
        cout << "INFORMACION DEL TRABAJADOR" << endl;
        cout << "------------------------------------------------------------" << endl;
        cout << "Nombre                 : " << nombre << endl;
        cout << "Tipo de empleado       : " << tipoEmpleado << endl;
        cout << "Cargo principal        : " << cargoPrincipal << endl;
        cout << "Puesto real            : " << puestoReal << endl;
        cout << "Anios en empresa       : " << aniosEmpresa << endl;
        cout << "Horas por dia          : " << horasPorDia << endl;
        cout << "Dias por semana        : " << diasPorSemana << endl;
        cout << "Horas por semana       : " << horasSemana << endl;
        cout << "Pago por hora          : S/ " << fixed << setprecision(2) << pagoHora << endl;
        cout << "Sueldo bruto mensual   : S/ " << fixed << setprecision(2) << sueldoBrutoMensual << endl;

        if (tipoEmpleado == "Empleado de planta") {
            cout << "Descuento AFP 12.37%   : S/ " << fixed << setprecision(2) << descuentoAFP << endl;
            cout << "Descuento salud        : S/ " << fixed << setprecision(2) << descuentoSalud << endl;
            cout << "Bono puntualidad       : S/ " << fixed << setprecision(2) << bonoPuntualidad << endl;
            cout << "Bono por metas         : S/ " << fixed << setprecision(2) << bonoMetas << endl;
        } else {
            cout << "Descuento AFP          : No aplica" << endl;
            cout << "Descuento salud        : No aplica" << endl;
            cout << "Bonificaciones         : No aplica" << endl;
        }

        cout << "Sueldo neto mensual    : S/ " << fixed << setprecision(2) << sueldoNetoMensual << endl;
        cout << "------------------------------------------------------------" << endl;
    }
};

// =====================================================
// FUNCIONES AUXILIARES
// =====================================================

void limpiarEntrada() {
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

void mostrarTitulo(string titulo) {
    cout << "\n============================================================" << endl;
    cout << titulo << endl;
    cout << "============================================================" << endl;
}

void mostrarResultado(string mensaje) {
    cout << "\n+----------------------------------------------------------+" << endl;
    cout << "| RESULTADO                                                |" << endl;
    cout << "+----------------------------------------------------------+" << endl;
    cout << mensaje << endl;
    cout << "+----------------------------------------------------------+" << endl;
}

bool volverAlMenuOSalir() {
    int opcion;

    do {
        cout << "\n------------------------------------------------------------" << endl;
        cout << "QUE DESEA HACER AHORA" << endl;
        cout << "1. Volver al menu principal" << endl;
        cout << "2. Salir del programa" << endl;
        cout << "------------------------------------------------------------" << endl;
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        if (opcion != 1 && opcion != 2) {
            cout << "Opcion incorrecta. Intente nuevamente." << endl;
        }

    } while (opcion != 1 && opcion != 2);

    return opcion == 1;
}

// =====================================================
// FUNCIONES DE LOGICA
// =====================================================

float obtenerPagoPorCargo(string cargo) {
    if (cargo == "Gerente") {
        return 100;
    } else if (cargo == "Supervisor") {
        return 80;
    } else {
        return 50;
    }
}

int valorCargo(string cargo) {
    if (cargo == "Gerente") {
        return 1;
    } else if (cargo == "Supervisor") {
        return 2;
    } else {
        return 3;
    }
}

// =====================================================
// PRESENTACION INICIAL
// =====================================================

void mostrarEstructuraInicial() {
    mostrarTitulo("SISTEMA DE TRABAJADORES - LICORERIA LEON");

    cout << "Empresa: Licoreria Leon 24 horas" << endl;
    cout << "Total de trabajadores: 10" << endl;
    cout << "Empleados de planta: 7" << endl;
    cout << "Empleados por horas: 3" << endl;
    cout << "Cargos principales: 1 gerente, 2 supervisores y 7 operarios" << endl;
    cout << "Calculo de sueldo: mensual" << endl;
    cout << "Archivo de respaldo: empleados.txt" << endl;
}

void mostrarCupos(int planta, int horas) {
    cout << "\nCUPOS DISPONIBLES" << endl;
    cout << "- Empleados de planta disponibles: " << MAX_PLANTA - planta << endl;
    cout << "- Empleados por horas disponibles: " << MAX_HORAS - horas << endl;
}

// =====================================================
// REGISTRAR TRABAJADORES
// =====================================================

void registrarEmpleados(Empleado empleados[]) {
    string nombre;
    int opcionTipo;
    int opcionPuesto;
    int anios;

    int horasPorDia;
    int diasPorSemana;
    int horasSemana;

    int cantidadPlanta = 0;
    int cantidadHoras = 0;

    bool gerenteOcupado = false;
    bool subgerenteOcupado = false;
    bool supervisorOcupado = false;
    bool cajeroMananaOcupado = false;
    bool cajeroTardeOcupado = false;
    bool cajeroNocheOcupado = false;
    bool cajeroVolanteOcupado = false;

    bool reponedorOcupado = false;
    bool deliveryOcupado = false;
    bool limpiezaOcupado = false;

    for (int i = 0; i < MAX; i++) {
        mostrarTitulo("REGISTRO DEL TRABAJADOR " + to_string(i + 1));

        mostrarCupos(cantidadPlanta, cantidadHoras);

        cout << "\nIngrese nombre del trabajador: ";
        limpiarEntrada();
        getline(cin, nombre);

        do {
            cout << "\nSeleccione tipo de empleado disponible:" << endl;

            if (cantidadPlanta < MAX_PLANTA) {
                cout << "1. Empleado de planta" << endl;
            }

            if (cantidadHoras < MAX_HORAS) {
                cout << "2. Empleado por horas" << endl;
            }

            cout << "Ingrese opcion: ";
            cin >> opcionTipo;

            if (opcionTipo == 1 && cantidadPlanta >= MAX_PLANTA) {
                cout << "Opcion no disponible. Ya se registraron los empleados de planta." << endl;
                opcionTipo = 0;
            } else if (opcionTipo == 2 && cantidadHoras >= MAX_HORAS) {
                cout << "Opcion no disponible. Ya se registraron los empleados por horas." << endl;
                opcionTipo = 0;
            } else if (opcionTipo < 1 || opcionTipo > 2) {
                cout << "Opcion incorrecta. Intente nuevamente." << endl;
            }

        } while (opcionTipo < 1 || opcionTipo > 2);

        string tipoEmpleado;
        string cargoPrincipal;
        string puestoReal;
        float pagoHora;

        // =====================================================
        // EMPLEADO DE PLANTA
        // =====================================================

        if (opcionTipo == 1) {
            tipoEmpleado = "Empleado de planta";

            do {
                cout << "\nSeleccione puesto de planta disponible:" << endl;

                if (!gerenteOcupado) {
                    cout << "1. Gerente general / propietario" << endl;
                }

                if (!subgerenteOcupado) {
                    cout << "2. Subgerente / administrador" << endl;
                }

                if (!supervisorOcupado) {
                    cout << "3. Supervisor operativo" << endl;
                }

                if (!cajeroMananaOcupado) {
                    cout << "4. Cajero turno manana" << endl;
                }

                if (!cajeroTardeOcupado) {
                    cout << "5. Cajero turno tarde" << endl;
                }

                if (!cajeroNocheOcupado) {
                    cout << "6. Cajero turno noche" << endl;
                }

                if (!cajeroVolanteOcupado) {
                    cout << "7. Cajero volante / reemplazo" << endl;
                }

                cout << "Ingrese opcion: ";
                cin >> opcionPuesto;

                if (opcionPuesto == 1 && gerenteOcupado) {
                    cout << "Ese puesto ya fue ocupado. Elija otro disponible." << endl;
                    opcionPuesto = 0;
                } else if (opcionPuesto == 2 && subgerenteOcupado) {
                    cout << "Ese puesto ya fue ocupado. Elija otro disponible." << endl;
                    opcionPuesto = 0;
                } else if (opcionPuesto == 3 && supervisorOcupado) {
                    cout << "Ese puesto ya fue ocupado. Elija otro disponible." << endl;
                    opcionPuesto = 0;
                } else if (opcionPuesto == 4 && cajeroMananaOcupado) {
                    cout << "Ese puesto ya fue ocupado. Elija otro disponible." << endl;
                    opcionPuesto = 0;
                } else if (opcionPuesto == 5 && cajeroTardeOcupado) {
                    cout << "Ese puesto ya fue ocupado. Elija otro disponible." << endl;
                    opcionPuesto = 0;
                } else if (opcionPuesto == 6 && cajeroNocheOcupado) {
                    cout << "Ese puesto ya fue ocupado. Elija otro disponible." << endl;
                    opcionPuesto = 0;
                } else if (opcionPuesto == 7 && cajeroVolanteOcupado) {
                    cout << "Ese puesto ya fue ocupado. Elija otro disponible." << endl;
                    opcionPuesto = 0;
                } else if (opcionPuesto < 1 || opcionPuesto > 7) {
                    cout << "Opcion incorrecta. Intente nuevamente." << endl;
                }

            } while (opcionPuesto < 1 || opcionPuesto > 7);

            if (opcionPuesto == 1) {
                cargoPrincipal = "Gerente";
                puestoReal = "Gerente general / propietario";
                horasPorDia = 5;
                diasPorSemana = 7;
                gerenteOcupado = true;
            } else if (opcionPuesto == 2) {
                cargoPrincipal = "Supervisor";
                puestoReal = "Subgerente / administrador";
                horasPorDia = 8;
                diasPorSemana = 6;
                subgerenteOcupado = true;
            } else if (opcionPuesto == 3) {
                cargoPrincipal = "Supervisor";
                puestoReal = "Supervisor operativo";
                horasPorDia = 8;
                diasPorSemana = 6;
                supervisorOcupado = true;
            } else if (opcionPuesto == 4) {
                cargoPrincipal = "Operario";
                puestoReal = "Cajero turno manana";
                horasPorDia = 8;
                diasPorSemana = 6;
                cajeroMananaOcupado = true;
            } else if (opcionPuesto == 5) {
                cargoPrincipal = "Operario";
                puestoReal = "Cajero turno tarde";
                horasPorDia = 8;
                diasPorSemana = 6;
                cajeroTardeOcupado = true;
            } else if (opcionPuesto == 6) {
                cargoPrincipal = "Operario";
                puestoReal = "Cajero turno noche";
                horasPorDia = 8;
                diasPorSemana = 6;
                cajeroNocheOcupado = true;
            } else {
                cargoPrincipal = "Operario";
                puestoReal = "Cajero volante / reemplazo";
                horasPorDia = 8;
                diasPorSemana = 6;
                cajeroVolanteOcupado = true;
            }

            horasSemana = horasPorDia * diasPorSemana;
            cantidadPlanta++;
        }

        // =====================================================
        // EMPLEADO POR HORAS
        // =====================================================

        else {
            tipoEmpleado = "Empleado por horas";
            cargoPrincipal = "Operario";

            do {
                cout << "\nSeleccione puesto por horas disponible:" << endl;

                if (!reponedorOcupado) {
                    cout << "1. Reponedor / almacenero" << endl;
                }

                if (!deliveryOcupado) {
                    cout << "2. Motorizado / delivery" << endl;
                }

                if (!limpiezaOcupado) {
                    cout << "3. Limpieza y apoyo operativo" << endl;
                }

                cout << "Ingrese opcion: ";
                cin >> opcionPuesto;

                if (opcionPuesto == 1 && reponedorOcupado) {
                    cout << "Ese puesto ya fue ocupado. Elija otro disponible." << endl;
                    opcionPuesto = 0;
                } else if (opcionPuesto == 2 && deliveryOcupado) {
                    cout << "Ese puesto ya fue ocupado. Elija otro disponible." << endl;
                    opcionPuesto = 0;
                } else if (opcionPuesto == 3 && limpiezaOcupado) {
                    cout << "Ese puesto ya fue ocupado. Elija otro disponible." << endl;
                    opcionPuesto = 0;
                } else if (opcionPuesto < 1 || opcionPuesto > 3) {
                    cout << "Opcion incorrecta. Intente nuevamente." << endl;
                }

            } while (opcionPuesto < 1 || opcionPuesto > 3);

            if (opcionPuesto == 1) {
                puestoReal = "Reponedor / almacenero";
                reponedorOcupado = true;
            } else if (opcionPuesto == 2) {
                puestoReal = "Motorizado / delivery";
                deliveryOcupado = true;
            } else {
                puestoReal = "Limpieza y apoyo operativo";
                limpiezaOcupado = true;
            }

            do {
                cout << "\nIngrese cuantas horas trabaja al dia, maximo 8: ";
                cin >> horasPorDia;

                if (horasPorDia < 1 || horasPorDia > 8) {
                    cout << "Las horas por dia deben estar entre 1 y 8." << endl;
                }

            } while (horasPorDia < 1 || horasPorDia > 8);

            do {
                cout << "Ingrese cuantos dias trabaja a la semana, maximo 7: ";
                cin >> diasPorSemana;

                if (diasPorSemana < 1 || diasPorSemana > 7) {
                    cout << "Los dias por semana deben estar entre 1 y 7." << endl;
                }

            } while (diasPorSemana < 1 || diasPorSemana > 7);

            horasSemana = horasPorDia * diasPorSemana;
            cantidadHoras++;
        }

        pagoHora = obtenerPagoPorCargo(cargoPrincipal);

        cout << "\nIngrese anios en la empresa: ";
        cin >> anios;

        empleados[i].setNombre(nombre);
        empleados[i].setTipoEmpleado(tipoEmpleado);
        empleados[i].setCargoPrincipal(cargoPrincipal);
        empleados[i].setPuestoReal(puestoReal);
        empleados[i].setAniosEmpresa(anios);
        empleados[i].setHorasPorDia(horasPorDia);
        empleados[i].setDiasPorSemana(diasPorSemana);
        empleados[i].setHorasSemana(horasSemana);
        empleados[i].setPagoHora(pagoHora);
        empleados[i].calcularSueldoMensual();

        mostrarResultado("Trabajador registrado correctamente.");
    }

    mostrarResultado("Se registraron correctamente los 10 puestos indispensables.");
}

// =====================================================
// MOSTRAR TRABAJADORES POR TIPO
// =====================================================

void mostrarEmpleados(Empleado empleados[]) {
    mostrarTitulo("TRABAJADORES DE LICORERIA LEON");

    cout << "\nEMPLEADOS DE PLANTA" << endl;
    cout << "------------------------------------------------------------" << endl;

    for (int i = 0; i < MAX; i++) {
        if (empleados[i].getTipoEmpleado() == "Empleado de planta") {
            cout << "- " << empleados[i].getNombre()
                 << " | " << empleados[i].getPuestoReal()
                 << " | " << empleados[i].getHorasPorDia() << " h/dia"
                 << " | " << empleados[i].getDiasPorSemana() << " dias/semana"
                 << " | Neto mensual: S/ " << fixed << setprecision(2) << empleados[i].getSueldoNetoMensual()
                 << endl;
        }
    }

    cout << "\nEMPLEADOS POR HORAS" << endl;
    cout << "------------------------------------------------------------" << endl;

    for (int i = 0; i < MAX; i++) {
        if (empleados[i].getTipoEmpleado() == "Empleado por horas") {
            cout << "- " << empleados[i].getNombre()
                 << " | " << empleados[i].getPuestoReal()
                 << " | " << empleados[i].getHorasPorDia() << " h/dia"
                 << " | " << empleados[i].getDiasPorSemana() << " dias/semana"
                 << " | Neto mensual: S/ " << fixed << setprecision(2) << empleados[i].getSueldoNetoMensual()
                 << endl;
        }
    }

    mostrarResultado("Se mostro la lista de trabajadores por tipo de contratacion.");
}

// =====================================================
// MOSTRAR TRABAJADORES DETALLADO
// =====================================================

void mostrarEmpleadosDetallado(Empleado empleados[]) {
    mostrarTitulo("LISTA DETALLADA DE TRABAJADORES");

    for (int i = 0; i < MAX; i++) {
        cout << "\nTrabajador " << i + 1 << endl;
        empleados[i].mostrarDatos();
    }

    mostrarResultado("Se mostro el detalle completo de los trabajadores.");
}

// =====================================================
// MAYOR SALARIO
// =====================================================

void mostrarMayorSalario(Empleado empleados[]) {
    int posicionMayor = 0;

    for (int i = 1; i < MAX; i++) {
        if (empleados[i].getSueldoNetoMensual() > empleados[posicionMayor].getSueldoNetoMensual()) {
            posicionMayor = i;
        }
    }

    mostrarTitulo("TRABAJADOR CON MAYOR SUELDO NETO MENSUAL");
    empleados[posicionMayor].mostrarDatos();
    mostrarResultado("El trabajador mostrado tiene el mayor sueldo neto mensual.");
}

// =====================================================
// TOP 3 MAYOR TIEMPO
// =====================================================

void mostrarTop3MayorTiempo(Empleado empleados[]) {
    Empleado copia[MAX];

    for (int i = 0; i < MAX; i++) {
        copia[i] = empleados[i];
    }

    for (int i = 0; i < MAX - 1; i++) {
        for (int j = 0; j < MAX - i - 1; j++) {
            if (copia[j].getAniosEmpresa() < copia[j + 1].getAniosEmpresa()) {
                Empleado aux = copia[j];
                copia[j] = copia[j + 1];
                copia[j + 1] = aux;
            }
        }
    }

    mostrarTitulo("3 TRABAJADORES CON MAYOR TIEMPO EN LA EMPRESA");

    for (int i = 0; i < 3; i++) {
        cout << "\nPOSICION " << i + 1 << endl;
        copia[i].mostrarDatos();
    }

    mostrarResultado("Se mostraron los 3 trabajadores con mayor antiguedad.");
}

// =====================================================
// ORDENAR POR CARGO
// =====================================================

void ordenarPorCargo(Empleado empleados[]) {
    for (int i = 0; i < MAX - 1; i++) {
        for (int j = 0; j < MAX - i - 1; j++) {
            if (valorCargo(empleados[j].getCargoPrincipal()) >
                valorCargo(empleados[j + 1].getCargoPrincipal())) {

                Empleado aux = empleados[j];
                empleados[j] = empleados[j + 1];
                empleados[j + 1] = aux;
            }
        }
    }

    mostrarResultado("Los trabajadores fueron ordenados por jerarquia.");
}

// =====================================================
// ORGANIGRAMA
// =====================================================

void mostrarOrganigrama(Empleado empleados[]) {
    mostrarTitulo("ORGANIGRAMA DE LICORERIA LEON");

    cout << "\nGerente general / propietario" << endl;
    cout << "   |" << endl;
    cout << "   |-- Subgerente / administrador" << endl;
    cout << "          |" << endl;
    cout << "          |-- Supervisor operativo" << endl;
    cout << "                 |" << endl;
    cout << "                 |-- Cajeros de planta" << endl;
    cout << "                 |      |-- Cajero turno manana" << endl;
    cout << "                 |      |-- Cajero turno tarde" << endl;
    cout << "                 |      |-- Cajero turno noche" << endl;
    cout << "                 |      |-- Cajero volante / reemplazo" << endl;
    cout << "                 |" << endl;
    cout << "                 |-- Operarios por horas" << endl;
    cout << "                        |-- Reponedor / almacenero" << endl;
    cout << "                        |-- Motorizado / delivery" << endl;
    cout << "                        |-- Limpieza y apoyo operativo" << endl;

    mostrarResultado("Se mostro el organigrama de Licoreria Leon.");
}

// =====================================================
// COBERTURA DE CAJA
// =====================================================

void mostrarCoberturaCaja() {
    mostrarTitulo("COBERTURA DE CAJA 24 HORAS");

    cout << "\nLicoreria Leon atiende 24 horas al dia y 7 dias a la semana." << endl;
    cout << "Por eso la caja debe cubrir: 24 x 7 = 168 horas semanales." << endl;

    cout << "\nTURNOS DE CAJA:" << endl;
    cout << "- Manana: 06:00 a.m. a 02:00 p.m." << endl;
    cout << "- Tarde : 02:00 p.m. a 10:00 p.m." << endl;
    cout << "- Noche : 10:00 p.m. a 06:00 a.m." << endl;

    cout << "\nDISTRIBUCION SEMANAL DE CAJA" << endl;
    cout << "Lunes:     Cajero volante / Cajero tarde / Cajero noche" << endl;
    cout << "Martes:    Cajero manana / Cajero volante / Cajero noche" << endl;
    cout << "Miercoles: Cajero manana / Cajero tarde / Cajero volante" << endl;
    cout << "Jueves:    Cajero manana / Cajero tarde / Cajero noche" << endl;
    cout << "Viernes:   Cajero manana / Cajero tarde / Cajero noche" << endl;
    cout << "Sabado:    Cajero manana / Cajero tarde / Cajero noche" << endl;
    cout << "Domingo:   Cajero manana / Cajero tarde / Cajero noche" << endl;

    cout << "\nCALCULO DE COBERTURA:" << endl;
    cout << "- Cajero manana : 6 turnos x 8 horas = 48 horas." << endl;
    cout << "- Cajero tarde  : 6 turnos x 8 horas = 48 horas." << endl;
    cout << "- Cajero noche  : 6 turnos x 8 horas = 48 horas." << endl;
    cout << "- Cajero volante: 3 turnos x 8 horas = 24 horas." << endl;
    cout << "Total: 48 + 48 + 48 + 24 = 168 horas." << endl;

    mostrarResultado("Se mostro la distribucion semanal de caja y reemplazos.");
}

// =====================================================
// GUARDAR ARCHIVO
// =====================================================

bool guardarArchivo(Empleado empleados[]) {
    ofstream archivo("empleados.txt");

    if (!archivo) {
        mostrarResultado("Error al crear el archivo empleados.txt.");
        return false;
    }

    for (int i = 0; i < MAX; i++) {
        archivo << empleados[i].getNombre() << endl;
        archivo << empleados[i].getTipoEmpleado() << endl;
        archivo << empleados[i].getCargoPrincipal() << endl;
        archivo << empleados[i].getPuestoReal() << endl;
        archivo << empleados[i].getAniosEmpresa() << endl;
        archivo << empleados[i].getHorasPorDia() << endl;
        archivo << empleados[i].getDiasPorSemana() << endl;
        archivo << empleados[i].getHorasSemana() << endl;
        archivo << empleados[i].getPagoHora() << endl;
    }

    archivo.close();

    mostrarResultado("Los datos se guardaron correctamente en empleados.txt.");
    return true;
}

// =====================================================
// RECUPERAR ARCHIVO
// =====================================================

bool recuperarArchivo(Empleado empleados[]) {
    ifstream archivo("empleados.txt");

    if (!archivo) {
        mostrarResultado("No se encontro el archivo empleados.txt.");
        return false;
    }

    string nombre, tipoEmpleado, cargoPrincipal, puestoReal;
    int anios, horasDia, diasSemana, horasSemana;
    float pago;

    for (int i = 0; i < MAX; i++) {
        getline(archivo, nombre);
        getline(archivo, tipoEmpleado);
        getline(archivo, cargoPrincipal);
        getline(archivo, puestoReal);
        archivo >> anios;
        archivo >> horasDia;
        archivo >> diasSemana;
        archivo >> horasSemana;
        archivo >> pago;
        archivo.ignore();

        empleados[i].setNombre(nombre);
        empleados[i].setTipoEmpleado(tipoEmpleado);
        empleados[i].setCargoPrincipal(cargoPrincipal);
        empleados[i].setPuestoReal(puestoReal);
        empleados[i].setAniosEmpresa(anios);
        empleados[i].setHorasPorDia(horasDia);
        empleados[i].setDiasPorSemana(diasSemana);
        empleados[i].setHorasSemana(horasSemana);
        empleados[i].setPagoHora(pago);
        empleados[i].calcularSueldoMensual();
    }

    archivo.close();

    mostrarResultado("Los datos fueron recuperados correctamente desde empleados.txt.");
    return true;
}

// =====================================================
// DESPEDIDA FINAL
// =====================================================

void mostrarDespedidaFinal() {
    cout << "\n============================================================" << endl;
    cout << "LICORERIA LEON - 24 HORAS" << endl;
    cout << "Gracias por usar el sistema de gestion." << endl;
    cout << "Calidad, garantia y atencion todos los dias." << endl;
    cout << "Esperamos su pronta visita." << endl;
    cout << "============================================================" << endl;
}

// =====================================================
// MENU PRINCIPAL
// =====================================================

void mostrarMenuPrincipal() {
    mostrarTitulo("MENU PRINCIPAL");

    cout << "1. Registrar 10 trabajadores" << endl;
    cout << "2. Mostrar trabajadores por tipo" << endl;
    cout << "3. Mostrar trabajador con mayor sueldo neto mensual" << endl;
    cout << "4. Mostrar 3 trabajadores con mayor tiempo en la empresa" << endl;
    cout << "5. Ordenar trabajadores por cargo y mostrar detalle" << endl;
    cout << "6. Mostrar organigrama de Licoreria Leon" << endl;
    cout << "7. Mostrar cobertura de caja y reemplazos" << endl;
    cout << "8. Guardar informacion en archivo TXT" << endl;
    cout << "9. Recuperar informacion desde archivo TXT" << endl;
    cout << "10. Salir" << endl;
    cout << "\nSeleccione una opcion: ";
}

// =====================================================
// FUNCION PRINCIPAL
// =====================================================

int main() {
    Empleado empleados[MAX];

    int opcion;
    bool hayDatos = false;
    bool continuarPrograma = true;

    cout << fixed << setprecision(2);

    mostrarEstructuraInicial();

    while (continuarPrograma) {
        mostrarMenuPrincipal();
        cin >> opcion;

        switch (opcion) {
            case 1:
                registrarEmpleados(empleados);
                hayDatos = true;
                continuarPrograma = volverAlMenuOSalir();
                break;

            case 2:
                if (hayDatos) {
                    mostrarEmpleados(empleados);
                } else {
                    mostrarResultado("Primero debe registrar o recuperar trabajadores.");
                }
                continuarPrograma = volverAlMenuOSalir();
                break;

            case 3:
                if (hayDatos) {
                    mostrarMayorSalario(empleados);
                } else {
                    mostrarResultado("Primero debe registrar o recuperar trabajadores.");
                }
                continuarPrograma = volverAlMenuOSalir();
                break;

            case 4:
                if (hayDatos) {
                    mostrarTop3MayorTiempo(empleados);
                } else {
                    mostrarResultado("Primero debe registrar o recuperar trabajadores.");
                }
                continuarPrograma = volverAlMenuOSalir();
                break;

            case 5:
                if (hayDatos) {
                    ordenarPorCargo(empleados);
                    mostrarEmpleadosDetallado(empleados);
                } else {
                    mostrarResultado("Primero debe registrar o recuperar trabajadores.");
                }
                continuarPrograma = volverAlMenuOSalir();
                break;

            case 6:
                if (hayDatos) {
                    mostrarOrganigrama(empleados);
                } else {
                    mostrarResultado("Primero debe registrar o recuperar trabajadores.");
                }
                continuarPrograma = volverAlMenuOSalir();
                break;

            case 7:
                mostrarCoberturaCaja();
                continuarPrograma = volverAlMenuOSalir();
                break;

            case 8:
                if (hayDatos) {
                    guardarArchivo(empleados);
                } else {
                    mostrarResultado("Primero debe registrar trabajadores.");
                }
                continuarPrograma = volverAlMenuOSalir();
                break;

            case 9:
                if (recuperarArchivo(empleados)) {
                    hayDatos = true;
                }
                continuarPrograma = volverAlMenuOSalir();
                break;

            case 10:
                mostrarDespedidaFinal();
                continuarPrograma = false;
                break;

            default:
                mostrarResultado("Opcion incorrecta. Intente nuevamente.");
                continuarPrograma = volverAlMenuOSalir();
                break;
        }
    }

    return 0;
}

