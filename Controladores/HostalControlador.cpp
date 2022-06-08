#include <cstdio>
#include "EstadiaControlador.h"
#include "HostalControlador.h"
#include "RelojControlador.h"
#include "ReservaControlador.h"
#include "UsuarioControlador.h"

#include "../Clases/Hostal.h"
#include "../Clases/Fabrica.h"




HostalControlador *HostalControlador::instancia = NULL;

HostalControlador::HostalControlador(){

// aca van definiciones del controlador

}

HostalControlador * HostalControlador::getInstancia(){
	if(instancia == NULL)
		instancia = new HostalControlador;

	return instancia;
}




void HostalControlador::agregarHostal(string nombre, string direccion, string telefono){

}



void HostalControlador::asignarEmpleado(string nomN, string emailN, CargoEmpleado cargoN){

}


void HostalControlador::cancelarAsignacion(){

}



void HostalControlador::confirmarAsigncacion(){

}



void HostalControlador::finalizar(){

}



set<DTHostal*> HostalControlador::listarHostales(){
    set<DTHostal*> setListarHostales;
    return setListarHostales;    
}





DTEmpleado HostalControlador::seleccionarHostal(string nom){
    DTEmpleado EmpleadoHostal;


    return EmpleadoHostal;
}






void HostalControlador::seleccionarHostalVar(string nombre){

}






DTHabitacion HostalControlador::ingresarHabitacion(int numero, float precio, int capacidad){
    DTHabitacion HabitacionIngresada;

    return HabitacionIngresada; 

}




void HostalControlador::persistirHabitacion(){

}




set<DTReserva*> HostalControlador::listarReservas(){
    set<DTReserva*> setListaReservas;

    return setListaReservas;    
}



void HostalControlador::cancelarCreacionHabitacion(){

}






set<DTHostal*> HostalControlador::topTres(){
    set<DTHostal*> setTopTres;

    return setTopTres;
}




set<DTCalificacion*> calificacionesHostal(string nom){
   set<DTCalificacion*> setCalificacionesHostal;

    return setCalificacionesHostal;
}