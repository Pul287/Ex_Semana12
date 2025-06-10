#incube <iostream>
using namespace std;

//Estructura
struct Proceso{
    int Proceso;
    int TiempoEjecucion;
    int Nprioridad;
    Proceso* siguiente;

    Proceso(int id, int tiempo, int prioridad) {
        idProceso = id;
        TiempoEjecucion = tiempo;
        Nprioridad = prioridad
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
