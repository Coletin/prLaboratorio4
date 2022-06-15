#include <iostream>
#include <string>
#include <set>

#include "Calificacion.h"
#include "Estadia.h"
#include "RespuestaCalificacion.h"
#include "ColeccionesHandler.h"
#include "Hostal.h"
#include "Habitacion.h"
#include "../Tipos/tipos.h"

Calificacion::Calificacion(){};

Calificacion::Calificacion(int valor,string comentario,DTFecha* fecha,int hab){
    this->valor = valor;
    this->comentario = comentario;
    this->fecha = fecha;
    this->habitacion = hab;
    this->estadia = NULL;
    this->respuesta =NULL;
}

void Calificacion::setEstadia(Estadia* estadia){
    this->estadia = estadia;
}

void Calificacion::setValor(int valor){
    this->valor = valor;
}

void Calificacion::setComentario(string comentario){
    this->comentario = comentario;
}

void Calificacion::setFecha(DTFecha* fecha){
    this->fecha = fecha;
}

void Calificacion::setHabitacion(int habitacion){
    this->habitacion = habitacion;
}

DTCalificacion* Calificacion::getDT(){
    int _valor = this->valor;
    string _comentario = this->comentario;
    DTFecha* _fecha = new DTFecha(this->fecha->getDia(), this->fecha->getMes(), this->fecha->getAnio(), this->fecha->getHora());
    int _habitacion = this->habitacion;
    int _estadia = getEstadia()->getCodigo(); 
    DTCalificacion* resu = new DTCalificacion( _valor, _comentario, _fecha, _habitacion, _estadia);
    return resu;
}

int Calificacion::getValor(){
    return this->valor;
}

string Calificacion::getComentario(){
    return this->comentario;
}

DTFecha* Calificacion::getFecha(){
    return this->fecha;
}

int Calificacion::getHabitacion(){
    return this->habitacion;
}

Estadia* Calificacion::getEstadia(){
    return this->estadia;
}

RespuestaCalificacion* Calificacion::getRespuestaCalificacion(){
    return this->respuesta;
}

DTRespuestaCalificacion* Calificacion::obtenerRespuestaCalificacion(){
    return respuesta->getDTRespuestaCalificacion();
}

//void setHostal(string nombre){}; no existe asociacion clasificacion hostal

Calificacion::~Calificacion(){
    delete(this->respuesta);
    ColeccionesHandler * col = ColeccionesHandler::getInstancia();
    bool encontre;
    Hostal* hostal;

    // set<Hostal*>::iterator it = col->getHostales().begin(); //necesito un getHostales para buscar el hostal que pertenece esta calificacion
    // while (it != col->getHostales().end() && !encontre){
    //     Hostal* host = *it;
    //     set<Habitacion*>::iterator it2 = host->getHabitaciones().begin(); // necesito un getHabitaciones que devuelva un set<Habitaciones*>
    //     while (it2 != host->getHabitaciones().end() && !encontre){
    //         Habitacion* hab = *it2;
    //         if(hab->getNumero() == this->habitacion){
    //             encontre = true;
    //             hostal = host;
    //         }
    //         it2++;
    //     };
    //     it++;
    // };

    hostal->eliminarCalificacion(this);
}
