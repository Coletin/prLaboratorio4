#include <cstdio>
#include <string>
#include <set>
#include "EstadiaControlador.h"
#include "../Interfaces/IReloj.h"
#include "../Interfaces/IUsuario.h"
#include "../Clases/Estadia.h"
#include "../Clases/Fabrica.h"
#include "../Clases/Hostal.h"
#include "../Clases/ColeccionesHandler.h"
#include "../Clases/Reserva.h"
#include "../Clases/Usuario.h"
#include "../Clases/Calificacion.h"
#include "../Clases/Notificacion.h"
#include "../Clases/Notificador.h"
#include "../Tipos/tipos.h"


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
    Fabrica* fabrica = new Fabrica();
    IReloj * reloj = fabrica->getIReloj();
    DTFecha* fecha = reloj->getFecha();
    Reserva* reserva = col->getReserva(codigo);
    Estadia* est = new Estadia(fecha);
    col->agregarEstadia(est);
    reserva->agregarEstadia(est);
    Huesped* huesped = col->getHuesped(email);
    est->setHuesped(huesped);
    huesped->agregarEstadia(est);
    delete fabrica;
}


bool EstadiaControlador::existenEstadiasActivas(string email, string hostal){
    ColeccionesHandler * col = ColeccionesHandler::getInstancia();
    Hostal * h = col->getHostal(hostal);
    bool existe = h->existeEstadiasActivas(email);

    return existe;
}

bool EstadiaControlador::existeHuesped(string email){
    Fabrica* fabrica = new Fabrica();
    IUsuario* controladorUsuario = fabrica->getIUsuario();
    return controladorUsuario->existeHuesped(email);
    delete fabrica;
}


bool EstadiaControlador::EstadiaCalificada(int codigo){
    ColeccionesHandler * col = ColeccionesHandler::getInstancia();
    Estadia* est = col->getEstadia(codigo);
    return(est->getCalificacion() != nullptr);
}



/* Se busca la estadia para setearle hora de checkOut*/
void EstadiaControlador::finalizarEstadia(string mail){
    bool existe = false;
    ColeccionesHandler * col = ColeccionesHandler::getInstancia();
    Fabrica* fabrica = new Fabrica();
    IReloj * reloj = fabrica->getIReloj();
    Huesped* huesped = col->getHuesped(mail);
    set<Estadia*> est = huesped->getEstadias();
    set<Estadia*>::iterator it = est.begin();
    while(it != est.end() && !existe){
        Estadia* actual = *it;
        if(actual->getCheckOut() == nullptr){
            actual->setCheckOut(reloj->getFecha());
            existe = true;
        }
        ++it;
    }
    delete fabrica;
}




set<DTEstadia*> EstadiaControlador::obtenerEstadiasFinalizadas(string email, string hostal){
    
    ColeccionesHandler * col = ColeccionesHandler::getInstancia();
    Hostal * h = col->getHostal(hostal);
    set<DTEstadia*> setEstadiasFinalizadas = h->getReservasFinalizadasAsociadas(email);
   
    return setEstadiasFinalizadas;
}



void EstadiaControlador::crearCalificacion(string email, string hostal_, string comentario, int valor, int codigo){
    Fabrica* fabrica = new Fabrica();
    IReloj * reloj = fabrica->getIReloj();
    ColeccionesHandler * col = ColeccionesHandler::getInstancia();
    Hostal* hostal = col->getHostal(hostal_);
    Huesped* huesped = col->getHuesped(email);
    string nombre = huesped->getNombre();
    DTFecha * fecha = reloj->getFecha();
    Estadia* est = huesped->getEstadia(codigo);
    int numHab = hostal->getHabEstadia(est);
    Calificacion* cal = new Calificacion(1,"a",fecha,1);
    cal->setComentario(comentario);
    cal->setValor(valor);
    cal->setFecha(fecha);
    cal->setHabitacion(numHab);
    hostal->agregarCalificacion(cal);
    
    est->setCalificacion(cal);
    cal->setEstadia(est);
    Notificacion* n = new Notificacion(false, nombre, valor, comentario);
    Notificador* notif = Notificador::getInstancia();
    notif->modificar(n);
    delete fabrica;
}

set<DTEstadia*> EstadiaControlador::listarEstadias(string hostal){
    ColeccionesHandler * col = ColeccionesHandler::getInstancia();
    Hostal* h = col->getHostal(hostal);
    set<DTEstadia*> res = h->getEstadiasDT();
    return res;
}

int EstadiaControlador::getHabitacionEstadia(int codigo){
    ColeccionesHandler * col = ColeccionesHandler::getInstancia();
    Reserva* r = col->getReservaEstadia(codigo);
    int h = r->getNumeroHabitacion();
    return h;
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