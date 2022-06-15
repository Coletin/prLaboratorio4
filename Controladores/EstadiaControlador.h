#include <iostream>
#include <string>
#include <set>
#include "../Tipos/tipos.h"
#include "../Interfaces/IEstadia.h"

class EstadiaControlador:public IEstadia{
    private:
        static EstadiaControlador * instancia;
    public:
        EstadiaControlador();
        static EstadiaControlador * getInstancia();
        set<DTHostal*> listarHostales();
        set<DTReserva*> listarReservas(string email, string hostal);
        void registrarEstadia(string email, int codigo);
        bool existenEstadiasActivas(string email, string hostal);
        void finalizarEstadia(string codigo);
        set<DTEstadia*> obtenerEstadiasFinalizadas(string email, string hostal);
        void crearCalificacion(string email, string hostal, string comentario, int valor);
};