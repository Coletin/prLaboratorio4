#include <iostream>
#include <string>
#include <set>

#include "Estadia.h"
#include "Calificacion.h"
#include "../Tipos/tipos.h"
#include "ColeccionesHandler.h"
#include "Hostal.h"
#include "Usuario.h"


int Estadia::contador = 0;

Estadia::Estadia(){
    this->checkIn = nullptr;
    this->checkOut = nullptr;
}

Estadia::Estadia(DTFecha* _cIn){
    Estadia::contador++;
    this->codigo = Estadia::contador + 1;
    this->checkIn = _cIn;
    this->checkOut = nullptr;
}

Estadia::~Estadia(){
    delete(this->calificacion);
    ColeccionesHandler * col = ColeccionesHandler::getInstancia();
    col->eliminarEstadia(this);
    this->huesped->eliminarEstadia(this);
}

int Estadia::getCodigo(){
    return this->codigo;
}

string Estadia::getPromo(){
    return this->promo;
}

DTFecha* Estadia::getCheckIn(){
    return this->checkIn;
}

DTFecha* Estadia::getCheckOut(){
    return this->checkOut;
}

void Estadia::setPromo(string _promo){
    this->promo = _promo;
}

void Estadia::setCheckIn(DTFecha* _cIn){
    this->checkIn = _cIn;
}

void Estadia::setCheckOut(DTFecha* _cOut){
    this->checkOut = _cOut;
}

void Estadia::setHuesped(Huesped* _huesped){
    this->huesped = _huesped;
}

Huesped* Estadia::getHuesped(){
    return this->huesped;
}

DTRespuestaCalificacion* Estadia::obtenerDatosRespuestaCalificacion(){
    return calificacion->obtenerRespuestaCalificacion();
}

DTCalificacion* Estadia::getDatosCalificacion(){
    return calificacion->getDT();
}

void Estadia::setCalificacion(Calificacion* c){
    this->calificacion = c;
}

void Estadia::elimCalHostal(string hostal){
    ColeccionesHandler * col = ColeccionesHandler::getInstancia();
    Hostal* h = col->getHostal(hostal);
    h->eliminarCalificacion(this->calificacion);
}

/* 
void Estadia::setReserva(Reserva* _reserva){
    this->reserva = _reserva;
}

DTReserva Estadia::obtenerDatosReserva(){
    return reserva->getDT()
}
*/

DTEstadia* Estadia::getDTEstadia(){ //no tenemos un DTEstadia en el diagrama
    string promo = this->promo;
    // int codigo = this->codigo; //falta agregar codigo al dt
    DTFecha* checkin = new DTFecha(this->checkIn->getDia(), this->checkIn->getMes(), this->checkIn->getAnio(), this->checkIn->getHora());
    DTFecha* checkout = new DTFecha(this->checkOut->getDia(), this->checkOut->getMes(), this->checkOut->getAnio(), this->checkOut->getHora());
    DTEstadia* dt = new DTEstadia(promo, *checkin, *checkout,this->codigo);
    return dt;
}
bool Estadia::existeEstadiaActiva(){
    return this->checkOut != NULL; //se usa en el diagrama 8.2, duda de si deberia llevar como parametro el email del usted o eso se hace en la operacion que esta en reserva
}