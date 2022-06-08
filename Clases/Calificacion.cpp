#include <string>

#include "Calificacion.h"
#include "../Tipos/tipos.h"
#include "Estadia.h"
#include "RespuestaCalificacion.h"

Calificacion::Calificacion(){};

Calificacion::Calificacion(int valor,string comentario,DTFecha fecha,int hab){
    this->valor = valor;
    this->comentario = comentario;
    this->fecha = fecha;
    this->habitacion = hab;
    this->estadia = NULL;
    this->respuesta =NULL;
}

Calificacion::~Calificacion(){}

void Calificacion::setEstadia(Estadia* estadia){
    this->estadia = estadia;
}

void Calificacion::setValor(int valor){
    this->valor = valor;
}

void Calificacion::setComentario(string comentario){
    this->comentario = comentario;
}

void Calificacion::setFecha(DTFecha fecha){
    this->fecha = fecha;
}

void Calificacion::setHabitacion(int habitacion){
    this->habitacion = habitacion;
}

DTCalificacion Calificacion::getDT(){
    int _valor = this->valor;
    string _comentario = this->comentario;
    DTFecha _fecha = this->fecha;
    int _habitacion = this->habitacion;
    string _estadia = getEstadia()->getCodigo(); 
    DTCalificacion resu( _valor, _comentario, _fecha, _habitacion, _estadia);
    return resu;
}

int Calificacion::getValor(){
    return this->valor;
}

string Calificacion::getComentario(){
    return this->comentario;
}

DTFecha Calificacion::getFecha(){
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

DTRespuestaCalificacion Calificacion::obtenerRespuestaCalificacion(){
    return respuesta->getDTRespuestaCalificacion();
}

//void Calificacion::setEstadia(string _codigo){};

//void setHostal(string nombre){}; no existe asociacion clasificacion hostal





