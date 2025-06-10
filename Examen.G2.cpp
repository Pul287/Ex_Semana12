struct Nodo {
    int Proceso;
    Nodo* siguiente;

    Nodo(int numero) {
        Proceso = numero;
        siguiente = NULL;
        123
    }
};
// Erick Rodriguez
#include <iostream>
using namespace std;

struct Proceso {
    int id;
    string nombre;
    int prioridad;
};

const int MAX_PROCESOS = 100;

Proceso listaProcesos[MAX_PROCESOS];
int cantidadProcesos = 0;

void agregarProceso() {
    if (cantidadProcesos >= MAX_PROCESOS) {
        cout << "No se pueden agregar más procesos (límite alcanzado).\n";
        return;
    }

    Proceso nuevo;
    cout << "Ingrese ID del proceso: ";
    cin >> nuevo.id;
    cout << "Ingrese nombre del proceso: ";
    cin.ignore(); // Limpiar buffer
    getline(cin, nuevo.nombre);
    cout << "Ingrese prioridad del proceso (1-10): ";
    cin >> nuevo.prioridad;

    listaProcesos[cantidadProcesos] = nuevo;
    cantidadProcesos++;

    cout << "Proceso agregado correctamente.\n";
}

void mostrarProcesos() {
    cout << "\nLista de procesos:\n";
    for (int i = 0; i < cantidadProcesos; i++) {
        cout << "ID: " << listaProcesos[i].id
             << ", Nombre: " << listaProcesos[i].nombre
             << ", Prioridad: " << listaProcesos[i].prioridad << endl;
    }
    cout << endl;
}

int main() {
    int opcion;

    do {
        cout << "\n--- MENU ---\n";
        cout << "1. Agregar proceso\n";
        cout << "2. Mostrar procesos\n";
        cout << "3. Salir\n";
        cout << "Seleccione una opción: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                agregarProceso();
                break;
            case 2:
                mostrarProcesos();
                break;
            case 3:
                cout << "Saliendo del programa...\n";
                break;
            default:
                cout << "Opción inválida. Intente nuevamente.\n";
        }

    } while (opcion != 3);

    return 0;
}

