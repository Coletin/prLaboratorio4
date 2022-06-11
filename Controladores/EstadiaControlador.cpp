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



    // set<Habitacion*>::iterator it = habs.begin(); 
    // while (it != habs.end() && !existe){
    //     Habitacion* hab = *it;
    //     set<Reserva*>::iterator it2 = hab->reservas.begin(); 
    //     while (it2 != hab->reservas.end() && !existe){
    //         Reserva* rev = *it2;
    //         set<Estadia*>::iterator it3 = rev->estadias.begin();
    //         while (it3 != rev->estadias.end() && !existe){
    //             Estadia* est = *it3;
    //             if(est->checkOut == nullptr){
    //                 Huesped* hue = est->huesped;
    //                 if(hue.getEmail == email) 
    //                     existe = true;
    //             }
    //             it3++;                
    //         };
    //         it2++;
    //     };
    //     it++;
    // };

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
    // set<Habitacion*>::iterator it = habs.begin(); 
    // while (it != habs.end() && !existe){
    //     Habitacion* hab = *it;
    //     set<Reserva*>::iterator it2 = hab->reservas.begin(); 
    //     while (it2 != hab->reservas.end() && !existe){
    //         Reserva* rev = *it2;
    //         set<Estadia*>::iterator it3 = rev->estadias.begin();
    //         while (it3 != rev->estadias.end() && !existe){
    //             Estadia* est = *it3;
    //             if(est->checkOut != nullptr){
    //                 Huesped* hue = est->huesped;
    //                 if(hue.getEmail == email)
    //                     DTEstadia* dt = est->getDTEstadia();
    //                     setListaReservas.insert(dt);
    //             }
    //             it3++;                
    //         };
    //         it2++;
    //     };
    //     it++;
    // };
   
    return setEstadiasFinalizadas;
}



void EstadiaControlador::crearCalificacion(string email, string hostal_, string comentario, int valor){
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
    Estadia* est = huesped->getEstadia();
    hostal->agregarCalificacion(cal);
    int numHab = hostal->getHabEstadia(est);
    est->setCalificacion(cal);
    Notificacion* n = new Notificacion(false, nombre, valor, comentario);
    Notificador* notif = Notificador::getInstancia();
    notif->modificar(n);
}
