#include <iostream>
#include <string>
#include <set>
#include "tipos.h"
#include "Empleado.h"
#include "Usuario.h"
#include "Huesped.h"
#include "Hostal.h"
#include "Reserva.h"



class Estadia;
class IObserver;

class ColeccionesHandler {
    private:
        static ColeccionesHandler * instancia;
        ColeccionesHandler();
        set<Usuario*> usuarios;
        set<Hostal*> hostales;
        set<Reserva*> reservas;
        set<Estadia*> estadias;
    public:
        static ColeccionesHandler * getInstancia();
        void addHostal(Hostal);
        Hostal getHostal(string);
        set<DTHostal*> getHostalCol();
        set<DTEmpleado*> getEmpleadoNoAsigCol(string);
        set<DTUsuario*> getUsuarios();
        void agregarEstadia(Estadia);
        Empleado getEmpleado(string);
        IObserver getEmpleadoObs(string);
        Huesped getHuesped(string);
        set<DTReserva*> getReservasHostal(string);
        void eliminarReserva(int);
        Reserva* getReserva(int);
        set<DTHuesped*> getHuespedes();
        void agregarReserva(Reserva *);
        void agregarUsuario(Usuario *);
        bool existeUsuario(string email);
};