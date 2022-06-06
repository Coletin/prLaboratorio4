#include <iostream>
#include <string>
#include <set>
#include "tipos.h"

class EstadiaControlador{
    private:
        static EstadiaControlador * instancia;
    public:
        static EstadiaControlador * getInstancia();
        set<DTHostal*> listarHostales();
        set<DTReserva*> listarReservas(string email, string hostal);
        void registrarEstadia(string email, int codigo);
        bool existenEstadiasActivas(string email, string hostal);
        void finalizarEstadia(string email);
        set<DTEstadia*> obtenerEstadiasFinalizadas(string email, string hostal);
        void crearCalificacion(string email, string hostal, string comentario, int valor);
};