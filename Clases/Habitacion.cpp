#include "Habitacion.h"

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

bool Habitacion::estaLibre(DataR data){
    //preguntar como a partir de un datareserva se si estoy libre
    return true;
}

DTHabitacion Habitacion::getDT(){
    DTHabitacion respuesta = DTHabitacion(numero,precio,capacidad);
    return respuesta;
}

void Habitacion::asociarRevHab(Reserva *r){ //tiene que ser un puntero porque no podemos tener instancias de reserva
    reservas.insert(r);
}

set<DTEstadia*> Habitacion::getEstadiasDT(){
    set<DTEstadia*> respuesta;
    return respuesta;
}

set<DTReserva*> Habitacion::getReservasFinalizadasAsociadas(){
    set<DTReserva*> respuesta;
    return respuesta;
}

bool Habitacion::existeEstadiasActivas(string email, string nombre){
    return false;
}

set<DTReserva*> Habitacion::getReservasAsociadas(string nombre, string email){
    set<DTReserva*> respuesta;
    return respuesta;
}

int Habitacion::getHabEstadia(Estadia* est){
    return 1;
}