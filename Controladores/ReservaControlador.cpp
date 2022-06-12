#include "EstadiaControlador.h"
#include "HostalControlador.h"
#include "RelojControlador.h"
#include "ReservaControlador.h"
#include "UsuarioControlador.h"

#include "../Clases/Reserva.h"
#include "../Clases/ColeccionesHandler.h"
#include "../Clases/Fabrica.h"
#include "../Clases/Habitacion.h"
#include "../Clases/Hostal.h"
#include "../Tipos/tipos.h"

ReservaControlador *ReservaControlador::instancia = NULL;

ReservaControlador * ReservaControlador::getInstancia(){
	if(instancia == NULL)
		instancia = new ReservaControlador;

	return instancia;
}

ReservaControlador::ReservaControlador(){
	data = NULL;
	numeroHab = -1;
	codR = -1;
	nombre = "/0";
}

set<DTHostal*> ReservaControlador::listarHostales(){
	ColeccionesHandler* col;
	col = ColeccionesHandler::getInstancia();
	return col->getHostalCol();
}

void ReservaControlador::ingresarDatosReserva(DataR* data){
	this->data = data;
}

set<DTHabitacion*> ReservaControlador::obtenerHabitacionesDisponiblesEnFecha(){
	ColeccionesHandler* col;
	col = ColeccionesHandler::getInstancia();
	Hostal* h = col->getHostal(this->data->getHostal());
	return h->getHabDis(data);
}

void ReservaControlador::agregarHabitacionAReserva(int numeroHab){
	this->numeroHab = numeroHab;
}

set<DTHuesped*> ReservaControlador::listarHuespedes(){
	ColeccionesHandler* col;
	col = ColeccionesHandler::getInstancia();
	return col->getHuespedes();
}

void ReservaControlador::agregarHuespedAReserva(string email){
	this->emailHue.insert(email);
}

void ReservaControlador::confirmarReserva(){
	ColeccionesHandler* col;
	col = ColeccionesHandler::getInstancia();
	Reserva* r;
	DTFecha* in = new DTFecha(data->getCheckIn().getDia(),data->getCheckIn().getMes(),data->getCheckIn().getAnio(),data->getCheckIn().getHora());
	DTFecha* out = new DTFecha(data->getCheckOut().getDia(),data->getCheckOut().getMes(),data->getCheckOut().getAnio(),data->getCheckOut().getHora());
	if(this->data->getEsGrupal())
		r = new ReservaGrupal(in,out,Abierta);
	else
		r = new ReservaIndividual(in,out,Abierta);
	
	Hostal* h = col->getHostal(data->getHostal());
	Habitacion* hab = h->getHabNum(numeroHab);
	r->asociarHabRev(hab);
	for(set<string>::iterator it = emailHue.begin(); it != emailHue.end();++it){
		Reserva* r;
		Huesped* hue = col->getHuesped(*it);
		r->asociarHuespedRev(hue);
	}
	hab->asociarRevHab(r);
	col->agregarReserva(r);
	
	delete data;
	data = NULL;
	numeroHab = -1;
	emailHue.clear();
}

void ReservaControlador::cancelarReserva(){
	delete data;
	data = NULL;
	numeroHab = -1;
	emailHue.clear();
}

set<DTReserva*> ReservaControlador::listarReservasHostal(string hostal){
	ColeccionesHandler* col;
	col = ColeccionesHandler::getInstancia();
return col->getReservasHostal(hostal);
}

void ReservaControlador::seleccionarReserva(int reserva){
	this->codR = reserva;
}

void ReservaControlador::confirmarBajaReserva(){
	ColeccionesHandler* col;
	col = ColeccionesHandler::getInstancia();
	Reserva* r = col->getReserva(codR);
	col->eliminarReserva(codR);
	r->~Reserva();
}

void ReservaControlador::cancelarBajaReserva(){
	numeroHab = -1;
}

void ReservaControlador::seleccionarHostal(string hostal){
	nombre = hostal;
}

set<DTReserva*> ReservaControlador::listarReservasMem(){
	ColeccionesHandler* col;
	col = ColeccionesHandler::getInstancia();
	string nom = nombre;
	nombre = "/0";
	return col->getReservasHostal(nom);
}