#include <cstdio>
#include <string>
#include <set>
#include "EstadiaControlador.h"
#include "HostalControlador.h"
#include "RelojControlador.h"
#include "ReservaControlador.h"
#include "UsuarioControlador.h"

#include "../Clases/Estadia.h"
#include "../Clases/Fabrica.h"
#include "../Clases/Hostal.h"
#include "../Clases/ColeccionesHandler.h"
#include "../Clases/Reserva.h"
#include "../Clases/Usuario.h"
#include "../Clases/Calificacion.h"
#include "../Clases/Notificacion.h"
#include "../Clases/Notificador.h"


EstadiaControlador * EstadiaControlador::instancia = NULL;

EstadiaControlador::EstadiaControlador(){
// aca van definiciones del controlador

}

EstadiaControlador * EstadiaControlador::getInstancia(){
	if(instancia == NULL)
		instancia = new EstadiaControlador;

	return instancia;
}

set<DTHostal*> EstadiaControlador::listarHostales(){
    ColeccionesHandler * col = ColeccionesHandler::getInstancia();
    return col->getHostalCol();
}

set<DTReserva*> EstadiaControlador::listarReservas(string email, string hostal){
    ColeccionesHandler * col = ColeccionesHandler::getInstancia();
    Hostal * h = col->getHostal(hostal);
    set<DTReserva*> setListaReservas = h->getReservasAsociadas(email);
    return setListaReservas;
}



void EstadiaControlador::registrarEstadia(string email, int codigo){
    ColeccionesHandler * col = ColeccionesHandler::getInstancia();
    RelojControlador * reloj = RelojControlador::getInstancia();
    DTFecha* fecha = reloj->getFecha();
    Reserva* reserva = col->getReserva(codigo);
    Estadia* est = new Estadia();
    est->setCheckIn(fecha);
    col->agregarEstadia(est);
    reserva->agregarEstadia(est);
    Huesped* huesped = col->getHuesped(email);
    huesped->agregarEstadia(est);  
}


bool EstadiaControlador::existenEstadiasActivas(string email, string hostal){
    ColeccionesHandler * col = ColeccionesHandler::getInstancia();
    Hostal * h = col->getHostal(hostal);
    bool existe = h->existeEstadiasActivas(email);

    return existe;
}




/* Se busca la estadia para setearle hora de checkOut*/
void EstadiaControlador::finalizarEstadia(int codigo){
    bool existe = false;
    ColeccionesHandler * col = ColeccionesHandler::getInstancia();
    RelojControlador * reloj = RelojControlador::getInstancia();
    Estadia* est = col->getEstadia(codigo);
    est->setCheckOut(reloj->getFecha());
}




set<DTEstadia*> EstadiaControlador::obtenerEstadiasFinalizadas(string email, string hostal){
    
    ColeccionesHandler * col = ColeccionesHandler::getInstancia();
    Hostal * h = col->getHostal(hostal);
    set<DTEstadia*> setEstadiasFinalizadas = h->getReservasFinalizadasAsociadas(email);
   
    return setEstadiasFinalizadas;
}



void EstadiaControlador::crearCalificacion(string email, string hostal_, string comentario, int valor, int codigo){
    RelojControlador * reloj = RelojControlador::getInstancia();
    DTFecha * fecha = reloj->getFecha();
    Calificacion* cal = new Calificacion();
    cal->setComentario(comentario);
    cal->setValor(valor);
    cal->setFecha(fecha);

    ColeccionesHandler * col = ColeccionesHandler::getInstancia();
    Huesped* huesped = col->getHuesped(email);
    Hostal* hostal = col->getHostal(hostal_);

    string nombre = huesped->getNombre();
    Estadia* est = huesped->getEstadia(codigo);
    hostal->agregarCalificacion(cal);
    int numHab = hostal->getHabEstadia(est);
    est->setCalificacion(cal);
    Notificacion* n = new Notificacion(false, nombre, valor, comentario);
    Notificador* notif = Notificador::getInstancia();
    notif->modificar(n);
}

set<DTEstadia*> EstadiaControlador::listarEstadias(string hostal){
    ColeccionesHandler * col = ColeccionesHandler::getInstancia();
    Hostal* h = col->getHostal(hostal);
    set<DTEstadia*> res = h->getEstadiasDT();
    return res;
}

int EstadiaControlador::getHabitacionEstadia(int codigo){
    ColeccionesHandler * col = ColeccionesHandler::getInstancia();
    Estadia* e = col->getEstadia(codigo);
    return e->getCalificacion()->getHabitacion();
}


int EstadiaControlador::getReservaEstadia(int codigo){
    ColeccionesHandler * col = ColeccionesHandler::getInstancia();
    Reserva* reserva = col->getReservaEstadia(codigo);
    return reserva->getCodigo();
}

DTCalificacion* EstadiaControlador::getCalificacion(int codigo){
    ColeccionesHandler * col = ColeccionesHandler::getInstancia();
    Estadia* e = col->getEstadia(codigo);
    DTCalificacion* res = e->getDatosCalificacion();
    return res;
}

DTRespuestaCalificacion* EstadiaControlador::getRespuestaCalificacion(int codigo){
    ColeccionesHandler * col = ColeccionesHandler::getInstancia();
    Estadia* e = col->getEstadia(codigo);
    DTRespuestaCalificacion* res = e->getCalificacion()->obtenerRespuestaCalificacion();
    return res;
}

DTReserva* EstadiaControlador::getReservaDT(int codigo){
    ColeccionesHandler * col = ColeccionesHandler::getInstancia();
    DTReserva * res = col->getReserva(codigo)->getDT();
    return res;
}