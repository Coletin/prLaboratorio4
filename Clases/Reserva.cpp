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
set<Estadia*> Reserva::getEstadias(){ return estadias; }
set<Huesped*> Reserva::getHuespedes(){ return huespedes; }

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
    return this->habitacion->esDeHostal(nom);
}


bool Reserva::huespedPertenece(string email){
    set<Huesped*>::iterator it;
    it = this->getHuespedes().begin();
    Huesped *current = *it;
    while (current->getEmail() != email){
        current = *it;
        ++it;
    }
    return it != this->getHuespedes().end();
}

Reserva::Reserva(){
    this->contador++;
    codigo = this->contador;
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

bool Reserva::resNoSeSuperpone(DataR* r){
    return (*this->getCheckOut() < r->getCheckIn())||(r->getCheckOut() < *this->getCheckIn());
}


void Reserva::agregarEstadia(Estadia* est){
    this->estadias.insert(est);
}

void Reserva::asociarHabRev(Habitacion* hab){
    this->habitacion = hab;
}

void Reserva::asociarHuespedRev(Huesped* h){
    this->huespedes.insert(h);
}

set<DTEstadia*> Reserva::getEstadiasDT(){
    set<DTEstadia*> resu;
    for(set<Estadia*>::iterator it = estadias.begin(); it != estadias.end();++it){
        Estadia actual = **it;
        DTEstadia* agregar = actual.getDTEstadia();
        resu.insert(agregar);
    }
    return resu;
}

set<DTEstadia*> Reserva::getReservasFinalizadasAsociadas(string email){
    set<DTEstadia*> resu;
    for(set<Estadia*>::iterator it = estadias.begin(); it != estadias.end();++it){
        Estadia actual = **it;
        if((actual.getHuesped()->getEmail() == email)&&(actual.getCheckOut()!=nullptr)){
            DTEstadia* agregar = actual.getDTEstadia();
            resu.insert(agregar);
        };
    }
    return resu;
}

bool Reserva::existeEstadiasActivas(string email){
    bool resu = false;
    for(set<Estadia*>::iterator it = estadias.begin(); it != estadias.end();++it){
        Estadia actual = **it;
        if((actual.getHuesped()->getEmail() == email)){
            resu = resu || actual.existeEstadiaActiva();
        };
    }
    return resu;
}

bool Reserva::estEsta(Estadia* est){
    return this->estadias.find(est)!=estadias.end();
}



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

DTReserva* ReservaGrupal::getDT(){
    set<DTHuesped*> huespedesDT;
    for(set<Huesped*>::iterator it = this->getHuespedes().begin(); it != this->getHuespedes().end();++it){
        Huesped actual = **it;
        DTHuesped* agregar = actual.getDTHuesped(); 
        huespedesDT.insert(agregar);
    }
    DTFecha* in = new DTFecha(this->getCheckIn()->getDia(),this->getCheckIn()->getMes(),this->getCheckIn()->getAnio(),this->getCheckIn()->getHora());
	DTFecha* out = new DTFecha(this->getCheckOut()->getDia(),this->getCheckOut()->getMes(),this->getCheckOut()->getAnio(),this->getCheckOut()->getHora());
    DTReserva* res = new DTReservaGrupal(this->getCodigo(), *in, *out, this->getEstado(), this->calcularCosto(), this->getHabitacion()->getNumero(),huespedesDT);
    return res;
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

DTReserva* ReservaIndividual::getDT(){
    DTFecha* in = new DTFecha(this->getCheckIn()->getDia(),this->getCheckIn()->getMes(),this->getCheckIn()->getAnio(),this->getCheckIn()->getHora());
	DTFecha* out = new DTFecha(this->getCheckOut()->getDia(),this->getCheckOut()->getMes(),this->getCheckOut()->getAnio(),this->getCheckOut()->getHora());
    DTReservaIndividual* res = new DTReservaIndividual(this->getCodigo(),*in,*out,this->getEstado(),this->calcularCosto(),this->getHabitacion()->getNumero());
    return res;
}