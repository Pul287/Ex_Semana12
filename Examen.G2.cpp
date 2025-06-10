#incube <iostream>
using namespace std;

//Estructura
struct Proceso{
    int Proceso;
    int TiempoEjecucion;
    Proceso* siguiente;

    Proceso(int id, int tiempo) {
        idProceso = id;
        TiempoEjecucion = tiempo;
        siguiente = NULL;
    }
};

