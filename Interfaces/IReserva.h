#include <set>
#include "../Tipos/tipos.h"

class IReserva{
    public:
        virtual set<DTHostal*> listarHostales();
        virtual void ingresarDatosReserva(DataR data);
        virtual set<DTHabitacion*> obtenerHabitacionesDisponiblesEnFecha();
        virtual void agregarHabitacionAReserva(int numeroHab);
        virtual set<DTHuesped*> listarHuespedes();
        virtual void agregarHuespedAReserva(string email);
        virtual void confirmarReserva();
        virtual void cancelarReserva();
        virtual set<DTReserva*> listarReservasHostal(string hostal);
        virtual void seleccionarReserva(int reserva);
        virtual void confirmarBajaReserva();
        virtual void cancelarBajaReserva();
        virtual void seleccionarHostal(string hostal);
        virtual set<DTReserva*> listarReservasMem();
};