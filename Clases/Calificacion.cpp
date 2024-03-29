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
    this->estadia = nullptr;
    this->respuesta =nullptr;
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
    DTCalificacion* resu = nullptr;
    if(this!=nullptr){
        int _valor = this->valor;
        string _comentario = this->comentario;
        DTFecha* _fecha = new DTFecha(this->fecha->getDia(), this->fecha->getMes(), this->fecha->getAnio(), this->fecha->getHora());
        int _habitacion = this->habitacion;
        int _estadia = this->estadia->getCodigo();
        resu = new DTCalificacion( _valor, _comentario, _fecha, _habitacion, _estadia);
    }
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
    if(this->respuesta != nullptr) return respuesta->getDTRespuestaCalificacion();
    else{
        DTRespuestaCalificacion* nueva = new DTRespuestaCalificacion("");
        return nueva;
    }
}

//void setHostal(string nombre){}; no existe asociacion clasificacion hostal

Calificacion::~Calificacion(){
    if(this->respuesta!=nullptr)delete(this->respuesta);
    ColeccionesHandler * col = ColeccionesHandler::getInstancia();
    set<Hostal*> hostales = col->getHostales();
    set<Hostal*>::iterator it = hostales.begin(); 
    while (it != hostales.end()){
        Hostal* host = *it;
        host->eliminarCalificacion(this);
        ++it;
    };
}

void Calificacion::responderCalificacion(string comentario){
    RespuestaCalificacion* resp = new RespuestaCalificacion(comentario);
    this->respuesta = resp;
}
