#include "../Clases/Reserva.h"
#include "../Tipos/tipos.h"
#include "Habitacion.h"
#include "Usuario.h"
#include "Estadia.h"
#include "ColeccionesHandler.h"

int Reserva::contador = 0;

void Reserva::setCheckIn(DTFecha* _checkIn){ checkIn = _checkIn; }
void Reserva::setCheckOut(DTFecha* _checkOut){ checkOut = _checkOut; }
void Reserva::setEstado(EstadoReserva _estado){ estado = _estado; }
void Reserva::setHabitacion(Habitacion* _habitacion){ habitacion = _habitacion; }
int Reserva::getCodigo(){ return codigo; }
DTFecha* Reserva::getCheckIn(){ return checkIn; }
DTFecha* Reserva::getCheckOut(){ return checkOut; }
EstadoReserva Reserva::getEstado(){ return estado; }
Habitacion* Reserva::getHabitacion(){ return habitacion; }

Reserva::~Reserva(){
    string hostal = this->habitacion->getNomHostal();
    this->habitacion->eliminarReserva(this);
    for(set<Estadia*>::iterator it = estadias.begin(); it != estadias.end();++it){
        Estadia *actual = *it;
        actual->elimCalHostal(hostal);
        estadias.erase(it);
        delete(actual);
    }
    ColeccionesHandler * col = ColeccionesHandler::getInstancia();
    col->eliminarReserva(this->getCodigo());
}

bool Reserva::esReservaHostal(string nom){
    return false;
}


Reserva::Reserva(){
    codigo = 0;
    DTFecha* fechaAgregar = new DTFecha(1,1,1,2000);
    checkIn = fechaAgregar;
    checkOut = fechaAgregar;
}

Reserva::Reserva(DTFecha* _checkIn, DTFecha* _checkOut, EstadoReserva _estado){
    this->contador++;
    codigo = this->contador;
    checkIn = _checkIn;
    checkOut = _checkOut;
    estado = _estado;
}

DTReserva* Reserva::getDT(){
    DTReserva* res;
    return res;
}


set<Huesped*> Reserva::getHuespedes(){
    return huespedes;
}


void Reserva::agregarEstadia(Estadia*){

}

void Reserva::asociarHabRev(Habitacion*){

}

void Reserva::asociarHuespedRev(Huesped*){
    
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




//GRUPAL



ReservaGrupal::ReservaGrupal(DTFecha* _checkIn,DTFecha* _checkOut,EstadoReserva _estado):Reserva(_checkIn, _checkOut, _estado){
};

float ReservaGrupal::calcularCosto(){
    int fing = 0;
    int i = 0;
    set<Huesped*>::iterator it;
    it = this->getHuespedes().begin();
    while (it != this->getHuespedes().end()){
        Huesped *current = *it;
        ++i;
        if(current->getEsFinger()) fing++;
        ++it;
    }
    float costo = (this->getHabitacion()->getPrecio() * diasEntre(this->getCheckIn(),this->getCheckOut())) * (i);
    if(fing > 1)
        costo = costo - costo*0.3;
    return costo;
}


int ReservaGrupal::cantidadHuespedes(){
    int i = 0;
    set<Huesped*>::iterator it;
    it = this->getHuespedes().begin();
    while (it != this->getHuespedes().end()){
        Huesped *current = *it;
        ++i;
        ++it;
    }
    return i;
}





//INDIVIDUAL



ReservaIndividual::ReservaIndividual(DTFecha* _checkIn,DTFecha* _checkOut,EstadoReserva _estado):Reserva(_checkIn, _checkOut, _estado){
};

float ReservaIndividual::calcularCosto(){
    int i = 0;
    int fing = 0;
    float costo = 0;
    costo = (this->getHabitacion()->getPrecio() * diasEntre(this->getCheckIn(),this->getCheckOut()));
    if(fing > 1)
        costo = costo - costo*0.3;
    return costo;
}