#include <iostream>
#include <string>
#include <set>

using namespace std;

class Estadia;
class IObserver;
class Hostal;
class Empleado;
class Huesped;
class Reserva;
class Habitacion;
class Usuario;
class DTHostal;
class DTReserva;
class DTEmpleado;
class DTUsuario;
class DTHuesped;

class ColeccionesHandler {
    private:
        static ColeccionesHandler * instancia;
        ColeccionesHandler(){};
        set<Usuario*> usuarios;
        set<Hostal*> hostales;
        set<Reserva*> reservas;
        set<Estadia*> estadias;
    public:
        static ColeccionesHandler * getInstancia();
        void addHostal(Hostal*);
        Hostal *getHostal(string);
        set<DTHostal*> getHostalCol();
        set<DTEmpleado*> getEmpleadoNoAsigCol(string);
        set<DTUsuario*> getUsuarios();
        void agregarEstadia(Estadia*);
        void eliminarEstadia(Estadia*);
        Empleado* getEmpleado(string);
        IObserver* getEmpleadoObs(string);
        Huesped* getHuesped(string);
        Estadia* getEstadia(int);
        set<DTReserva*> getReservasHostal(string);
        void eliminarReserva(int);
        Reserva* getReserva(int);
        set<DTHuesped*> getHuespedes();
        void agregarReserva(Reserva *);
        void agregarUsuario(Usuario *);
        bool existeUsuario(string email);
        set<Hostal*>getHostales();
};