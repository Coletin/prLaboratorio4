#include <set>

using namespace std;

class DTHostal;
class DTHabitacion;
class DTHuesped;
class DTReserva;
class DataR;

class IReserva{
    public:
        virtual set<DTHostal*> listarHostales() = 0;
        virtual void ingresarDatosReserva(DataR* data){};
        virtual set<DTHabitacion*> obtenerHabitacionesDisponiblesEnFecha() = 0;
        virtual void agregarHabitacionAReserva(int numeroHab){};
        virtual set<DTHuesped*> listarHuespedes() = 0;
        virtual void agregarHuespedAReserva(string email){};
        virtual void confirmarReserva(){};
        virtual void cancelarReserva(){};
        virtual set<DTReserva*> listarReservasHostal(string hostal) = 0;
        virtual void seleccionarReserva(int reserva){};
        virtual void confirmarBajaReserva(){};
        virtual void cancelarBajaReserva(){};
        virtual void seleccionarHostal(string hostal){};
        virtual set<DTReserva*> listarReservasMem() = 0;
};