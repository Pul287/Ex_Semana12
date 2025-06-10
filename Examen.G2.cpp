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
        cout << "No se pueden agregar más procesos.\n";
        return;
    }

    Proceso nuevo;
    cout << "Ingrese ID del proceso: ";
    cin >> nuevo.id;
    cout << "Ingrese nombre del proceso: ";
    cin.ignore(); 
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

void eliminarProceso() {
    int idEliminar;
    cout << "Ingrese el ID del proceso a eliminar: ";
    cin >> idEliminar;

    int index = -1;
    for (int i = 0; i < cantidadProcesos; i++) {
        if (listaProcesos[i].id == idEliminar) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        cout << "Proceso no encontrado.\n";
        return;
    }

    for (int i = index; i < cantidadProcesos - 1; i++) {
        listaProcesos[i] = listaProcesos[i + 1];
    }

    cantidadProcesos--;
    cout << "Proceso eliminado correctamente.\n";
}

void buscarProcesoPorID() {
    int idBuscar;
    cout << "Ingrese el ID del proceso a buscar: ";
    cin >> idBuscar;

    bool encontrado = false;
    for (int i = 0; i < cantidadProcesos; i++) {
        if (listaProcesos[i].id == idBuscar) {
            cout << "Proceso encontrado:\n";
            cout << "ID: " << listaProcesos[i].id
                 << ", Nombre: " << listaProcesos[i].nombre
                 << ", Prioridad: " << listaProcesos[i].prioridad << endl;
            encontrado = true;
            break;
        }
    }

    if (!encontrado) {
        cout << "Proceso no encontrado.\n";
    }
}

void modificarID() {
    int idActual, nuevoID;
    cout << "Ingrese el ID del proceso a modificar: ";
    cin >> idActual;

    bool encontrado = false;
    for (int i = 0; i < cantidadProcesos; i++) {
        if (listaProcesos[i].id == idActual) {
            cout << "Ingrese el nuevo ID: ";
            cin >> nuevoID;
            listaProcesos[i].id = nuevoID;
            cout << "ID modificado correctamente.\n";
            encontrado = true;
            break;
        }
    }

    if (!encontrado) {
        cout << "Proceso no encontrado.\n";
    }
}

int main() {
    int opcion;

    do {
        cout << "\n--- MENU ---\n";
        cout << "1. Agregar proceso\n";
        cout << "2. Mostrar procesos\n";
        cout << "3. Eliminar proceso\n";
        cout << "4. Buscar proceso por ID\n";
        cout << "5. Modificar ID de un proceso\n";
        cout << "6. Salir\n";
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
                eliminarProceso();
                break;
            case 4:
                buscarProcesoPorID();
                break;
            case 5:
                modificarID();
                break;
            case 6:
                cout << "Saliendo del programa...\n";
                break;
            default:
                cout << "Opción inválida. Intente nuevamente.\n";
        }

    } while (opcion != 6);

    return 0;
}

//Pul
struct Proceso {
    int id;
    int tiempoEjecucion;
    int prioridad;
    Proceso* siguiente;

    Proceso(int id, int tiempo, int prioridad) {
        idProceso = id;
        TiempoEjecucion = tiempo;
        Nprioridad = prioridad;
        siguiente = NULL;
    }
};

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
    cout << "Ejecutando proceso numero" << temp->id << " (tiempo: " << temp->tiempoEjecucion << ", prioridad: " << temp->prioridad << ")" << endl;
    delete temp;
}

