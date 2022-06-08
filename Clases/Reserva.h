#include <iostream>
#include <string>
#include <set>
#include "../Tipos/tipos.h"
#include "../Clases/Estadia.h"
#include "../Clases/Habitacion.h"

class Estadia;
class Huesped;

class Reserva{
    private:
     int codigo;
     DTFecha checkIn;
     DTFecha checkOut;
     EstadoReserva estado;
     set<Estadia*> estadias;
     set<Huesped*> huespedes;
     Habitacion habitacion;
    public:
     Reserva(int,DTFecha,DTFecha,EstadoReserva); 
     Reserva();
     ~Reserva();
     virtual float calcularCosto() = 0;
     int getCodigo();
     DTFecha getCheckIn();
     DTFecha getCheckOut();
     EstadoReserva getEstado();
     Habitacion getHabtiacion();
     void setCodigo(int);
     void setCheckIn(DTFecha);
     void setCheckOut(DTFecha);
     void setEstado(EstadoReserva);
     void setHabitacion(Habitacion);
};