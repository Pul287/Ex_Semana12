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

<<<<<<< HEAD
=======
Proceso* frente = NULL;

void encolarProceso(int id, int tiempo, int prioridad) {
    Proceso* nuevo = new Proceso(id, tiempo, prioridad);

    if (frente == NULL || prioridad < frente->prioridad) {
        nuevo->siguiente = frente;
        frente = nuevo;
    } else {
        Proceso* actual = frente;
        while (actual->siguiente != NULL && actual->siguiente->prioridad <= prioridad) {
            actual = actual->siguiente;
        }
        nuevo->siguiente = actual->siguiente;
        actual->siguiente = nuevo;
    }

    cout << "Proceso numero" << id << " encolado - prioridad: " << prioridad << endl;
}

void ejecutarProceso() {
    if (frente == NULL) {
        cout << "No hay procesos en cola." << endl;
        return;
    }

    Proceso* temp = frente;
    frente = frente->siguiente;
    cout << "Ejecutando proceso #" << temp->id
         << " (tiempo: " << temp->tiempoEjecucion
         << ", prioridad: " << temp->prioridad << ")" << endl;
    delete temp;
}
>>>>>>> f065e008f80692bfb4b2593e6ee5f95f947a30de
