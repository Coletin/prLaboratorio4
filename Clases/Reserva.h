#include <iostream>
#include <string>
#include <set>
#include "../Tipos/tipos.h"
#include "../Clases/Estadia.h"

class Reserva{
    private:
     int codigo;
     DTFecha checkIn;
     DTFecha checkOut;
     EstadoReserva estado;
     set<Estadia*> estadias;
     set<Huesped*> huespedes;
    public:
     Reserva(int,DTFecha,DTFecha,EstadoReserva); 
     Reserva();
     ~Reserva();
     virtual float calcularCosto() = 0;
     int getCodigo();
     DTFecha getCheckIn();
     DTFecha getCheckOut();
     EstadoReserva getEstado();
     void setCodigo(int);
     void setCheckIn(DTFecha);
     void setCheckOut(DTFecha);
     void setEstado(EstadoReserva);
};