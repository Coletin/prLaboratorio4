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
    public:
     Reserva(int,DTFecha*,DTFecha*,EstadoReserva); 
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
     void setCodigo(int);
     void setCheckIn(DTFecha*);
     void setCheckOut(DTFecha*);
     void setEstado(EstadoReserva);
     void setHabitacion(Habitacion*);
     bool esReservaHostal(string);
     DTReserva* getDT();
     bool resNoSeSuperpone(DataR*);
     void asociarHabRev(Habitacion*);
     void asociarHuespedRev(Huesped*);
     set<DTEstadia*> getEstadiasDT();
     set<DTReserva*> getReservasFinalizadasAsociadas(string, string);
     bool existeEstadiasActivas(string, string);
     bool estEsta(Estadia*);
     void agregarEstadia(Estadia*);
};


//GRUPAL


class ReservaGrupal : public Reserva{
    private:

    public:
     ReservaGrupal(int,DTFecha*,DTFecha*,EstadoReserva); 
     ~ReservaGrupal(); 
     virtual float calcularCosto();
     virtual int cantidadHuespedes();
};



//INDIVIDUAL



class ReservaIndividual : public Reserva{
    private:

    public:
     ReservaIndividual(int,DTFecha*,DTFecha*,EstadoReserva);
     ~ReservaIndividual();
     virtual float calcularCosto();
};