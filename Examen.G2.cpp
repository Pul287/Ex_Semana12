struct Nodo {
    int Proceso;
    Nodo* siguiente;

    Nodo(int numero) {
        Proceso = numero;
        siguiente = NULL;
    }
};

