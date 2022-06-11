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
#include "../Clases/ColeccionesHandler.h"


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
    ColeccionesHandler * col = ColeccionesHandler.getInstancia();
    return col->getHostalCol();
}

set<DTReserva*> EstadiaControlador::listarReservas(string email, string hostal){
    ColeccionesHandler * col = ColeccionesHandler.getInstancia();
    Hostal * h = col->getHostal(hostal);
    set<DTReserva*> setListaReservas;

    for(set<Habitacion*>::iterator it = h->habitaciones.begin(); it != h->habitaciones.end();++it){ // el primer for equivale getReservasAsociadas de hostal, pero le tengo que pasar como parametro el hostal y string email
        Habitacion* habActual = *it;
        for(set<Reserva*>::iterator it2 = habActual->reservas.begin(); it2 != habActual->reservas.end();++it){ // el segundo for equivale getReservasAsociadas de habitacion, pero le tengo que pasar como parametro solo el string email
            Reserva* actual = *it2;
            set<Huesped*>::iterator it3 = actual->huespedes.begin();
            bool encontre = false;
            while (it3 != actual->huespedes.end() && !encontre){
                Huesped* hue = *it3;
                encontre = hue->getEmail() == email;
                if(!encontre) ++it;
            };
            if(encontre){
                DTReserva* dt = actual->getDT();
                setListaReservas.insert(dt);
            }
        }
    }   

    return setListaReservas;
}



void EstadiaControlador::registrarEstadia(string email, int codigo){
    ColeccionesHandler * col = ColeccionesHandler.getInstancia();
    RelojControlador * reloj = RelojControlador.getInstancia();
    DTFecha* fecha = reloj->getFecha();
    Reserva* reserva = col->getReserva();
    Estadia est = new Estadia();
    est.setCheckIn(fecha);
    col->agregarEstadia(est);
    reserva->agregarEstadia(est);
    Huesped* huesped = col->getHuesped(email);
    huesped->agregarEstadia(est);  
}


bool EstadiaControlador::existenEstadiasActivas(string email, string hostal){
    bool existe = false;
    ColeccionesHandler * col = ColeccionesHandler.getInstancia();
    Hostal * h = col->getHostal(hostal);

//estos 3 while anidados equivalen a existeEstadiasActivas de hostal, habitacion, reserva cambiandole los parametros cambiando el string por Hostal*, Habitacion* y Reserva* respectivamente, siempre mateniendo string email
    set<Habitacion*>::iterator it = h->habitaciones.begin(); 
    while (it != h->habitaciones.end() && !existe){
        Habitacion* hab = *it;
        set<Reserva*>::iterator it2 = hab->reservas.begin(); 
        while (it2 != hab->reservas.end() && !existe){
            Reserva* rev = *it2;
            set<Estadia*>::iterator it3 = rev->estadias.begin();
            while (it3 != rev->estadias.end() && !existe){
                Estadia* est = *it3;
                if(est->checkOut == nullptr){
                    Huesped* hue = est->huesped;
                    if(hue.getEmail == email) 
                        existe = true;
                }
                it3++;                
            };
            it2++;
        };
        it++;
    };

    return existe;
}




/* Se busca la estadia para setearle hora de checkOut*/
void EstadiaControlador::finalizarEstadia(string codigo){
    bool existe = false;
    ColeccionesHandler * col = ColeccionesHandler.getInstancia();
    RelojControlador * reloj = RelojControlador.getInstancia();
    Estadia* est = col->getEstadia(codigo);
    est->setCheckOut(reloj->getFecha());
}




set<DTEstadia*> EstadiaControlador::obtenerEstadiasFinalizadas(string email, string hostal){
    set<DTEstadia*> setEstadiasFinalizadas;
    ColeccionesHandler * col = ColeccionesHandler.getInstancia();
    Hostal * h = col->getHostal(hostal);

//estos 3 while anidados equivalen a existeEstadiasActivas de hostal, habitacion, reserva cambiandole los parametros cambiando el string por Hostal*, Habitacion* y Reserva* respectivamente, siempre mateniendo string email
    set<Habitacion*>::iterator it = h->habitaciones.begin(); 
    while (it != h->habitaciones.end() && !existe){
        Habitacion* hab = *it;
        set<Reserva*>::iterator it2 = hab->reservas.begin(); 
        while (it2 != hab->reservas.end() && !existe){
            Reserva* rev = *it2;
            set<Estadia*>::iterator it3 = rev->estadias.begin();
            while (it3 != rev->estadias.end() && !existe){
                Estadia* est = *it3;
                if(est->checkOut != nullptr){
                    Huesped* hue = est->huesped;
                    if(hue.getEmail == email)
                        DTEstadia* dt = est->getDTEstadia();
                        setListaReservas.insert(dt);
                }
                it3++;                
            };
            it2++;
        };
        it++;
    };
   
    return setEstadiasFinalizadas;
}



void EstadiaControlador::crearCalificacion(string email, string hostal, string comentario, int valor){
    RelojControlador * reloj = RelojControlador.getInstancia();
    DTFecha * fecha = reloj->getFecha();
    Calificacion cal = new Calificacion();
    cal.setComentario(comentario);
    cal.setValor(valor);
    cal.setFecha(fecha);

    ColeccionesHandler * col = ColeccionesHandler.getInstancia();
    Huesped* huesped = col->getHuesped(email);
    Hostal* hostal = col->getHostal(hostal);

    String nombre = huesped->getNombre();
    Estadia* est = huesped->getEstadia();
    hostal->agregarCalificacion(cal);
    int numHab = hostal->getHabEstadia(est);
    est->setCalificacion(cal);
    Notificacion n = new Notificacion(nombre, valor, comentario);
    // donde esta el notificador?
}
