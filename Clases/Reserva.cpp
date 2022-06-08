#include "../Clases/Reserva.h"

void Reserva::setCodigo(int _codigo){ codigo = _codigo; }
void Reserva::setCheckIn(DTFecha _checkIn){ checkIn = _checkIn; }
void Reserva::setCheckOut(DTFecha _checkOut){ checkOut = _checkOut; }
void Reserva::setEstado(EstadoReserva _estado){ estado = _estado; }
void Reserva::setHabitacion(Habitacion _habitacion){ habitacion = &_habitacion; }
int Reserva::getCodigo(){ return codigo; }
DTFecha Reserva::getCheckIn(){ return checkIn; }
DTFecha Reserva::getCheckOut(){ return checkOut; }
EstadoReserva Reserva::getEstado(){ return estado; }
Habitacion* Reserva::getHabitacion(){ return habitacion; }

Reserva::Reserva(){
    codigo = 0;
    DTFecha fechaAgregar = DTFecha(1,1,1,2000);
    checkIn = fechaAgregar;
    checkOut = fechaAgregar;
}

Reserva::Reserva(int _codigo, DTFecha _checkIn, DTFecha _checkOut, EstadoReserva _estado){
    codigo = _codigo;
    checkIn = _checkIn;
    checkOut = _checkOut;
    estado = _estado;
}

/*
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
     ~Reserva();
     virtual float calcularCosto() = 0;
     int getCodigo();
     DTFecha getCheckIn();
     DTFecha getCheckOut();
     EstadoReserva getEstado();
     void setCodigo(int&);
     void setCheckIn(DTFecha&);
     void setCheckOut(DTFecha&);
     void setEstado(EstadoReserva&);
};
*/