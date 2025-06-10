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

