#include <iostream>
#include <string>
#include "RespuestaCalificacion.h"
#include "../Tipos/tipos.h"

RespuestaCalificacion::RespuestaCalificacion(){
};

RespuestaCalificacion::RespuestaCalificacion(string _comentario){
    this->comentario = _comentario;
};

void RespuestaCalificacion::setComentario(string _comentario){
    this->comentario = _comentario;
}

string RespuestaCalificacion::getComentario(){
    return this->comentario;
};

DTRespuestaCalificacion RespuestaCalificacion::getDTRespuestaCalificacion(){
    string comentario = getComentario();
    DTRespuestaCalificacion dt(comentario);
    return dt;
}