#include <iostream>
#include <cstdio>
#include <string>
#include <set>
#include "RespuestaCalificacion.h"
#include "../Controladores/EstadiaControlador.h"
#include "../Tipos/tipos.h"
#include "Calificacion.h"
#include "Estadia.h"
#include "ColeccionesHandler.h"
#include "Usuario.h"


/*
El caso de uso comienza cuando un empleado desea comentar una calificacion realizada por un huesped.
Para ello , el usuario indica el email de un empleado y el sistema lista todos los comentarios sin 
responder para el hostal para el cual trabaja el empleado. El usuario elige de la lista que comentario 
desea responder e ingresa el comentario, ante el cual el sistema registra el comentario
*/

RespuestaCalificacion::RespuestaCalificacion(){
};

RespuestaCalificacion::RespuestaCalificacion(string _comentario){
    this->comentario = _comentario;
};


/*
Razonemos, me dan el EMAIL, con eso filtro las estadias finalizadas por
ese empleado, al  tener a la estadia tengo la coleccion de la calificacion

*/

void RespuestaCalificacion::setComentario(string _comentario){
  this->comentario=_comentario;


/*try{
        ColeccionesHandler * col = ColeccionesHandler::getInstancia();
        set<DTEstadia*> estadias = col->obtenerEstadiasFinalizadas(,"d");
        set<DTEstadia*>::iterator it = estadias.begin();
        bool detectado = false;
        while (it != estadias.end() && !detectado)
            {
                DTEstadia* actual = *it;
                detectado = (actual->getPromo()== "calificacion");
                if(!detectado)
                    ++it;
                else {
                    actual->getCodigo();
                }
            }


} catch(int myNum) {
      cout << "Dio Errpr la Respuesta Calificacion \n"<<endl;
}*/


}

string RespuestaCalificacion::getComentario(){
    return this->comentario;
};

DTRespuestaCalificacion* RespuestaCalificacion::getDTRespuestaCalificacion(){
    string comentario = getComentario();
    DTRespuestaCalificacion* dt = new DTRespuestaCalificacion(comentario);
    return dt;
}