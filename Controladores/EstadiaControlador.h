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
        void finalizarEstadia(string mail);
        set<DTEstadia*> obtenerEstadiasFinalizadas(string email, string hostal);
        void crearCalificacion(string email, string hostal, string comentario, int valor, int codigo);
        set<DTEstadia*> listarEstadias(string);
        int getHabitacionEstadia(int);
        int getReservaEstadia(int);
        DTCalificacion* getCalificacion(int);
        DTRespuestaCalificacion* getRespuestaCalificacion(int);
        DTReserva* getReservaDT(int);
        bool EstadiaCalificada(int);
};