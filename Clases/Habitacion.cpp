#include "Habitacion.h"
#include "Reserva.h"
#include "Hostal.h"
#include "../Tipos/tipos.h"
#include "Estadia.h"

void Habitacion::setNumero(int _numero){ numero = _numero; }

int Habitacion::getNumero(){ return numero; }

void Habitacion::setPrecio(float _precio){ precio = _precio; }

float Habitacion::getPrecio(){ return precio; }

void Habitacion::setCapacidad(int _capacidad){ capacidad = _capacidad; }

int Habitacion::getCapacidad(){ return capacidad; }


Habitacion::Habitacion(){
    numero = 0;
    precio = 0.0;
    capacidad = 0;
    hostal = nullptr;
}

Habitacion::Habitacion(int _numero, float _precio, int _capacidad){
    numero = _numero;
    precio = _precio;
    capacidad = _capacidad;
}

bool Habitacion::esDeHostal(string Nomh){
    return hostal != nullptr && Nomh.compare(hostal->getNombre()) == 0;
}

bool Habitacion::estaLibre(DataR* data){
bool libre = true;
    set<Reserva*>::iterator it =  reservas.begin();
    while (it != reservas.end() && libre){
        Reserva* actual = *it;
        libre = actual->resNoSeSuperpone(data);
        ++it;
    }
    return libre;
}

DTHabitacion* Habitacion::getDT(){
    DTHabitacion* respuesta = new DTHabitacion(numero,precio,capacidad);
    return respuesta;
}

void Habitacion::asociarRevHab(Reserva *r){ 
    reservas.insert(r);
}

set<DTEstadia*> Habitacion::getEstadiasDT(){
    set<DTEstadia*> respuesta;
    set<DTEstadia*> aux;
    for(set<Reserva*>::iterator i = reservas.begin();i != reservas.end();++i){
        Reserva* actual = *i; 
        aux = actual->getEstadiasDT();
        for(set<DTEstadia*>::iterator it = aux.begin();it != aux.end();++it){
            DTEstadia* est = *it;
            respuesta.insert(est);
        }
    }
    return respuesta;
}

void Habitacion::setHostal(Hostal* h){
    hostal = h;
}

set<DTEstadia*> Habitacion::getReservasFinalizadasAsociadas(string email){  
    set<DTEstadia*> respuesta;
    set<DTEstadia*> aux;
    for(set<Reserva*>::iterator i = reservas.begin();i != reservas.end();++i){
        Reserva* actual = *i; 
        aux = actual->getReservasFinalizadasAsociadas(email);
        for(set<DTEstadia*>::iterator it = aux.begin();it != aux.end();++it){
           DTEstadia* est = *it;
           respuesta.insert(est);  
        }
    }
    return respuesta;
}

bool Habitacion::existeEstadiasActivas(string email){
    bool existe = false;
    set<Reserva*>::iterator it =  reservas.begin();
    while (it != reservas.end() && !existe){
        Reserva* actual = *it;
        existe = existe||actual->existeEstadiasActivas(email);
        ++it;
    }    
    return existe;
}

//agregar en reserva un funciaon para comprobar si huesped con email "email" pertencea a la reserva
set<DTReserva*> Habitacion::getReservasAsociadas(string email){
    set<DTReserva*> respuesta;
    for(set<Reserva*>::iterator i = reservas.begin();i != reservas.end();++i){
        Reserva* actual = *i;
        if(actual->huespedPertenece(email))
            respuesta.insert(actual->getDT());
    }
    return respuesta;
}

//si est no pertence a estadia devuelve -1 
int Habitacion::getHabEstadia(Estadia* est){
    set<DTEstadia*> aux;
    bool existe = false;
    int resu = -1;
    set<Reserva*>::iterator it =  reservas.begin();
    while (it != reservas.end() && !existe){
        Reserva* actual = *it;
        existe = actual->estEsta(est);
        ++it;
    }    
    if(existe)resu = this->numero;
    return resu;
}

string Habitacion::getNomHostal(){
    return this->hostal->getNombre();
}

void Habitacion::eliminarReserva(Reserva* r){
    reservas.erase(r);
}