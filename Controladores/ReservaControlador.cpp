#include "HostalControlador.h"
#include "ReservaControlador.h"


#include "../Clases/Reserva.h"
#include "../Clases/ReservaIndividual.h"
#include "../Clases/ReservaGrupal.h"

#include "../Clases/Fabrica.h"


ReservaControlador *ReservaControlador::instancia = NULL;


ReservaControlador::ReservaControlador() {
}

ReservaControlador * ReservaControlador::getInstancia(){
	if(instancia == NULL)
		instancia = new ReservaControlador;

	return instancia;
}








set<DTHostal*> listarHostales(){

}




void ingresarDatosReserva(DataR data){

}




set<DTHabitacion*> obtenerHabitacionesDisponiblesEnFecha(){

}



void agregarHabitacionAReserva(int numeroHab){

}




set<DTHuesped*> listarHuespedes(){


}




void agregarHuespedAReserva(string email){


}



void confirmarReserva(){

}




void cancelarReserva(){


}




set<DTReserva*> listarReservasHostal(string hostal){

}



void seleccionarReserva(int reserva){

}




void confirmarBajaReserva(){


}





void cancelarBajaReserva(){


}



void seleccionarHostal(string hostal){


}




set<DTReserva*> listarReservasMem(){



}