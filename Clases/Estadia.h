#include <iostream>
#include <string>
#include <set>

using namespace std;

class DTFecha;
class DTEstadia;
class DTRespuestaCalificacion;
class DTCalificacion;

class Huesped;
class Calificacion;

class Estadia{
    private:
        string promo;
        int codigo;//Identificador
        DTFecha *checkIn;
        DTFecha *checkOut;
        Huesped* huesped;
        Calificacion* calificacion;
        static int contador;
    public:
        Estadia(DTFecha *checkIn);
        Estadia();
        ~Estadia();
        int getCodigo();
        string getPromo();
        DTFecha* getCheckIn();
        DTFecha* getCheckOut();
        void setPromo(string);
        void setCheckIn(DTFecha*);
        void setCheckOut(DTFecha*);
        DTEstadia* getDTEstadia();
        bool existeEstadiaActiva();
        void setHuesped(Huesped*);
        Huesped* getHuesped();
        //void setReserva(int codigo);
        //void setHuesped(string email);
        //DTReserva obtenerDatosReserva();
        DTRespuestaCalificacion* obtenerDatosRespuestaCalificacion();
        DTCalificacion* getDatosCalificacion();
        void setCalificacion(Calificacion*);
        void elimCalHostal(string);
};