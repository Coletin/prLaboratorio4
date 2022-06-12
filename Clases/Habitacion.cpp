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
    //preguntar como a partir de un datareserva se si estoy libre
    return true;
}

DTHabitacion* Habitacion::getDT(){
    DTHabitacion* respuesta = new DTHabitacion(numero,precio,capacidad);
    return respuesta;
}

void Habitacion::asociarRevHab(Reserva *r){ //tiene que ser un puntero porque no podemos tener instancias de reserva
    reservas.insert(r);
}

set<DTEstadia*> Habitacion::getEstadiasDT(){
    set<DTEstadia*> respuesta;
    return respuesta;
}

set<DTEstadia*> Habitacion::getReservasFinalizadasAsociadas(string email){
    set<DTEstadia*> respuesta;
    return respuesta;
}

bool Habitacion::existeEstadiasActivas(string email){
    return false;
}

set<DTReserva*> Habitacion::getReservasAsociadas(string email){
    set<DTReserva*> respuesta;
    return respuesta;
}

int Habitacion::getHabEstadia(Estadia* est){
    return 1;
}

string Habitacion::getNomHostal(){
    return this->hostal->getNombre();
}

void Habitacion::eliminarReserva(Reserva* r){
    
}