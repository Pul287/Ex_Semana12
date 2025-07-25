#include <iostream>
using namespace std;

// Erick Rodriguez
//Estructura dise�ada para listas
struct Proceso {
    int id;
    string nombre;
    int prioridad;
    string estado;
};

const int MAX_PROCESOS = 100; //Cantidad maxima aceptada por la lista

Proceso listaProcesos[MAX_PROCESOS];
int cantidadProcesos = 0; //Inicializacion
//Validacion para agregar procesos
void agregarProceso() {
    if (cantidadProcesos >= MAX_PROCESOS) {
        cout << "No se pueden agregar m�s procesos.\n";
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

void cambiarEstadoProceso() {
    int idBuscar;
    cout << "Ingrese el ID del proceso al que desea cambiar el estado: ";
    cin >> idBuscar;

    bool encontrado = false;
    for (int i = 0; i < cantidadProcesos; i++) {
        if (listaProcesos[i].id == idBuscar) {
            cout << "Estado actual: " << listaProcesos[i].estado << endl;
            cout << "Ingrese el nuevo estado (Listo, En ejecuci�n, Terminado): ";
            cin.ignore(); 
            getline(cin, listaProcesos[i].estado);
            cout << "Estado actualizado correctamente.\n";
            encontrado = true;
            break;
        }
    }

    if (!encontrado) {
        cout << "Proceso no encontrado.\n";
    }
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
//fin erick

//Inicio Pul

//Estructura para uso de colas

struct ProcesoQ {
    int idProceso;
    int TiempoEjecucion;
    int Nprioridad;
    string nombre;
    ProcesoQ* siguiente;

    ProcesoQ(int id, string nom, int tiempo, int prioridad) {
        idProceso = id;
        TiempoEjecucion = tiempo;
        Nprioridad = prioridad;
        nombre = nom;
        siguiente = NULL;
    }
};
//Inicializacion de inicio de la cola "Nula"
ProcesoQ* frente = NULL;

void encolarProceso(int id, string nom, int tiempo, int prioridad) {
    ProcesoQ* nuevo = new ProcesoQ(id, nom, tiempo, prioridad);
	//Validacion para agregar colas "Prioridad" - numero menos mas prioridad
    if (frente == NULL || prioridad < frente->Nprioridad) {
        nuevo->siguiente = frente;
        frente = nuevo;
    } else {
        ProcesoQ* actual = frente;
        while (actual->siguiente != NULL && actual->siguiente->Nprioridad <= prioridad) {
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
    ProcesoQ* temp = frente;
    frente = frente->siguiente;
    cout << "Ejecutando proceso ID: " << temp->idProceso <<"| Nombre: "<< temp->nombre << " | tiempo: " << temp->TiempoEjecucion << " | prioridad: " << temp->Nprioridad << endl;
    delete temp;
}

void mostrarCola() {
    if (frente == NULL) {
        cout << "La cola esta vacia." << endl;
        return;
    }

    cout << "Procesos en cola:" << endl;
    ProcesoQ* actual = frente;
    while (actual != NULL) {
        cout << "ID: " << actual->idProceso <<"| Nombre: "<< actual->nombre << " | Tiempo: " << actual->TiempoEjecucion << " | Prioridad: " << actual->Nprioridad << endl;
        actual = actual->siguiente;
    }
}
//fin pul

//Gabriela

//estructura para uso de pilas
struct NodoMemoria {
    int idProceso;
    NodoMemoria* siguiente;
};

class PilaMemoria {
private:
    NodoMemoria* cima;

public:
    PilaMemoria() {
        cima = NULL;
    }

    ~PilaMemoria() {
        while (cima != NULL) {
            liberarMemoria();
        }
    }

    void asignarMemoria(int idProceso) {
        NodoMemoria* nuevo = new NodoMemoria;
        if (nuevo == NULL) {
            cout << "Error al asignar memoria." << endl;
            return;
        }
        nuevo->idProceso = idProceso;
        nuevo->siguiente = cima;
        cima = nuevo;
        cout << "Memoria asignada al proceso " << idProceso<< endl;
    }

    void liberarMemoria() {
        if (cima == NULL) {
            cout << "No hay memoria para liberar." << endl;
            return;
        }
        NodoMemoria* temp = cima;
        cout << "Liberando memoria del proceso " << temp->idProceso << endl;
        cima = cima->siguiente;
        delete temp;
    }

    void mostrarEstado() {
        if (cima == NULL) {
            cout << "La pila de memoria esta vacia." << endl;
            return;
        }

        cout << "Estado actual de la memoria :" << endl;
        NodoMemoria* actual = cima;
        while (actual != NULL) {
            cout << "Proceso ID: " << actual->idProceso << endl;
            actual = actual->siguiente;
        }
    }
};
//Menu que simula el Gestor de procesos
void gestorprocesos(){
	int subopcion;
	do {
		cout << "\n--- MENU ---\n";
		cout << "1. Agregar proceso\n";
		cout << "2. Mostrar procesos\n";
		cout << "3. Eliminar proceso\n";
		cout << "4. Buscar proceso por ID\n";
		cout << "5. Modificar ID de un proceso\n";
		cout << "6. Cambiar el estado del proceso\n";
		cout << "7. Salir\n";
		cout << "Seleccione una opci�n: ";
		cin >> subopcion;
		switch (subopcion) {
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
			    cambiarEstadoProceso();
			    break;
			case 7:
			    cout << "Saliendo del programa realizado\n";
			    break;
			default:
			    cout << "Opci�n inv�lida. Intente nuevamente.\n";
			    break;
		}
	} while (subopcion != 7);
}
//Menu que simula Planificador de CPU
void planificador(){
	int tiempo, prioridad, subopcion;
	string nombre;
	int id = 1;
	do{
		cout << "--- Planificador de CPU ---" << endl;
		cout << "1. A�adir proceso" << endl;
		cout << "2. Ejecutar proceso" << endl;
		cout << "3. Mostrar cola" << endl;
		cout << "4. Salir" << endl;
		cout << "Selecciona una opcion: ";
		cin >> subopcion;
		switch(subopcion){
			case 1:
			    cout << "Ingrese nombre del proceso: ";
			    cin.ignore();
			    getline(cin, nombre);
			    cout << "Ingrese tiempo de ejecucion: ";
			    cin >> tiempo;
			    cout << "Ingrese su prioridad: ";
			    cin >> prioridad;
			    encolarProceso(id++, nombre, tiempo, prioridad);
			    break;
			        case 2:
			            ejecutarProceso();
			            break;
			        case 3:
			            mostrarCola();
			            break;
			        case 4:
			            cout << "Saliendo del planificador." << endl;
			            break;
			        default:
			            cout << "Opcion no valida." << endl;
			            break;
		}
	} while(subopcion != 4);
}
//Menu que simula el Gestor de memoria
void gestormemoria(){
	PilaMemoria memoria;
	int subopcion, id;
	
	do{
		cout << "--- GESTION DE MEMORIA ---" << endl;
		cout << "1. Asignar memoria a un proceso " << endl;
		cout << "2. Liberar memoria " << endl;
		cout << "3. Ver estado de la memoria " << endl;
		cout << "4. Salir " << endl; 
		cout << "Seleccione una opcion: ";
		cin >> subopcion;
		
		switch (subopcion) {
		case 1:
			cout << "Ingrese el ID del proceso: ";
			cin >> id;
			memoria.asignarMemoria(id);
			break;
		case 2:
			memoria.liberarMemoria();
			break;
		case 3:
			memoria.mostrarEstado();
			break;
		case 4:
			cout << "Saliendo del programa..." << endl;
			break;
		default:
			cout << "Opcion invalida. Intente nuevamente." << endl;
		}
    } while (subopcion != 4);
}

//Menu que simula el administrador de tareas de forma general
int main(){
    int opcion, subopcion, id;
    do{
        cout << "--- Administrador de Tareas ---" << endl;
        cout << "1. Gestor de procesos" << endl;
        cout << "2. Planificador de CPU" << endl;
        cout << "3. Gestor de memoria" << endl;
        cout << "4. Salir" << endl;
        cout << "Selecciona una opcion: ";
        cin >> opcion;
        
        switch(opcion){
            case 1:
			    gestorprocesos();//Uso de funciones adecuados para una mejor organizacion.
			    break;
            case 2:
            	planificador();
            	break;
			case 3: 
				gestormemoria();
				break;
            case 4:
                cout << "Cerrando administrador. " << endl;
                break;
            default:
                cout << "Opcion no valida." << endl;
        }
    } while(opcion != 4);
    return 0;
}

