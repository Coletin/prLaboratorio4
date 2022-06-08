#include <iostream>
#include <string>
#include <set>
#include "tipos.h"


class Usuario;
class Hostal;
class Reserva;
class Empleado;
class Calificacion;
class Estadia;
class IObserver;
class Huesped;

class ColeccionesHandler {
    private:
        static ColeccionesHandler * instancia;
        ColeccionesHandler();
        set<Usuario*> usuarios;
        set<Hostal*> hostales;
        set<Reserva*> reservas;
    public:
        static ColeccionesHandler * getInstancia();
        void addHostal(Hostal hostalN);
        //Empleado getUsuario(string email); Repetida
        Hostal getHostal(string nombre);
        set<DTHostal*> getHostalCol();
        set<DTEmpleado*> getEmpleadoNoAsigCol(string nom);
        set<DTUsuario*> getUsuarios();
        void agregarCalificacion(Calificacion c);
        Reserva reserva(string email, int codigo);
        void agregarEstadia(Estadia e);
        Empleado getEmpleado(string email);
        IObserver getEmpleadoObs(string email);
        Huesped getHuesped(string email);
        Hostal getReservasHostal(string nomH);
        void eliminarReserva(int codR);
        Reserva getReserva(int codR);
        set<DTHuesped*> getHuespedes();
        void agregarReserva(Reserva r);
        void agregarUsuario(Usuario u);
        bool existeUsuario(string email);
        Reserva devolverReserva(int codigo);
};