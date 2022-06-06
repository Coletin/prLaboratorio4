#include <set>
#include "../Tipos/tipos.h"

class ReservaControlador{
    private:
        DataR data;
        int numeroHab;
        set<string> emailHue;
        int codR;
        static ReservaControlador * instancia;
    public:
        static ReservaControlador * getInstancia();
        set<DTHostal*> listarHostales();
        void ingresarDatosReserva(DataR data);
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