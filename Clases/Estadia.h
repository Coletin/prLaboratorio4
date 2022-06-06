#include <iostream>
#include <string>
#include <set>
#include "tipos.h"

class Huesped;
class Calificacion;

class Estadia{
    private:
        string promo;
        string codigo;//Identificador
        DTFecha checkIn;
        DTFecha checkOut;
        Huesped* huesped;
        Calificacion* calificacion;
    public:
        Estadia(string,DTFecha checkIn, DTFecha checkOut);
        Estadia();
        ~Estadia();
        string getPromo();
        DTFecha getCheckIn();
        DTFecha getCheckOut();
        void setPromo(string);
        void setCheckIn(DTFecha);
        void setCheckOut(DTFecha);
        DTEstadia getDTEstadia();
        bool existeEstadiaActiva();
        void setReserva(int codigo);
        void setHuesped(string email);
        DTReserva obtenerDatosReserva();
        DTRespuestaCalificacion obtenerDatosRespuestaCalificacion();
        DTCalificacion getDatosCalificacion();
        void setCalificacion(Calificacion c);
};