#include <set>
#include <iostream>
#include <string>
#include <set>
#include "../Interfaces/IReserva.h"


class DTHostal;
class DTHabitacion;
class DTHuesped;
class DTReserva;
class DataR;


class ReservaControlador:public IReserva{
    private:
        DataR* data;
        int numeroHab;
        set<string> emailHue;
        int codR;
        string nombre;
        static ReservaControlador * instancia;
        ReservaControlador();
    public:
        static ReservaControlador * getInstancia();
        set<DTHostal*> listarHostales();
        void ingresarDatosReserva(DataR* data);
        set<DTHabitacion*> obtenerHabitacionesDisponiblesEnFecha();
        void agregarHabitacionAReserva(int numeroHab);
        set<DTHuesped*> listarHuespedes();
        void agregarHuespedAReserva(string email);
        void confirmarReserva();
        void cancelarReserva();
        set<DTReserva*> listarReservasHostal(string hostal);
        void seleccionarReserva(int reserva);
        void confirmarBajaReserva();
        void cancelarBajaReserva();
        void seleccionarHostal(string hostal);
        set<DTReserva*> listarReservasMem();
};