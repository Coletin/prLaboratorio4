#include <iostream>
#include <string>
#include <set>
#include "../Interfaces/IEstadia.h"

using namespace std;

class DTHostal;
class DTReserva;
class DTEstadia;

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
        void finalizarEstadia(int codigo);
        set<DTEstadia*> obtenerEstadiasFinalizadas(string email, string hostal);
        void crearCalificacion(string email, string hostal, string comentario, int valor);
};