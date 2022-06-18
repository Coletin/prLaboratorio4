#include <iostream>
#include <string>
#include <set>
#include "../Tipos/EstadoReserva.h"


using namespace std;

class Estadia;
class DTFecha;
class Habitacion;
class Huesped;
class DTReserva;
class DataR;
class DTEstadia;


class Reserva{
    private:
     int codigo;
     DTFecha* checkIn;
     DTFecha* checkOut;
     EstadoReserva estado;
     set<Estadia*> estadias;
     set<Huesped*> huespedes;
     Habitacion* habitacion;
     static int contador;
    public:
     Reserva(DTFecha*,DTFecha*,EstadoReserva); 
     Reserva();
     ~Reserva();
     virtual float calcularCosto() = 0;
     int getCodigo();
     DTFecha* getCheckIn();
     DTFecha* getCheckOut();
     EstadoReserva getEstado();
     Habitacion* getHabitacion();
     set<Huesped*> getHuespedes();
     set<Estadia*> getEstadias();
     void setCheckIn(DTFecha*);
     void setCheckOut(DTFecha*);
     void setEstado(EstadoReserva);
     void setHabitacion(Habitacion*);
     bool esReservaHostal(string);
     virtual DTReserva* getDT() = 0;
     bool resNoSeSuperpone(DataR*);
     void asociarHabRev(Habitacion*);
     void asociarHuespedRev(Huesped*);
     set<DTEstadia*> getEstadiasDT();
     set<DTEstadia*> getReservasFinalizadasAsociadas(string);
     bool existeEstadiasActivas(string);
     bool estEsta(Estadia*);
     void agregarEstadia(Estadia*);
     bool huespedPertenece(string);
     int getNumeroHabitacion();
};


//GRUPAL


class ReservaGrupal : public Reserva{
    private:

    public:
     ReservaGrupal(DTFecha*,DTFecha*,EstadoReserva);
     ~ReservaGrupal(){};
     float calcularCosto();
     int cantidadHuespedes();
     DTReserva* getDT();
};



//INDIVIDUAL



class ReservaIndividual : public Reserva{
    private:

    public:
     ReservaIndividual(DTFecha*,DTFecha*,EstadoReserva);
     ~ReservaIndividual(){};
     float calcularCosto();
     DTReserva* getDT();
};