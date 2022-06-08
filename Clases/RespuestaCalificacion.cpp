#include <iostream>
#include <string>
#include "RespuestaCalificacion.h"
#include "../Tipos/tipos.h"

RespuestaCalificacion::RespuestaCalificacion(){
};

RespuestaCalificacion::RespuestaCalificacion(String _comentario){
    this->comentario = _comentario;
};

void RespuestaCalificacion::setComentario(String _comentario){
    this->comentario = _comentario;
}

String RespuestaCalificacion::getComentario(){
    return this->comentario;
};

DTRespuestaCalificacion RespuestaCalificacion::getDTRespuestaCalificacion(){
    String comentario = getComentario();
    DTRespuestaCalificacion dt = new DTRespuestaCalificacion(comentario);
    return dt;
}