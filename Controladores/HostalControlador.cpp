#include <cstdio>
#include "HostalControlador.h"

#include "../Clases/Hostal.h"
#include "../Clases/Fabrica.h"




HostalControlador *HostalControlador::instancia = nullptr;

HostalControlador::HostalControlador(){

};


HostalControlador * HostalControlador::getInstancia(){
	if(instancia == nullptr)
		instancia = new HostalControlador();

	return instancia;
}




void HostalControlador::agregarHostal(string nombre, string direccion, string telefono){

	Hostal *nuevoHostal = new Hostal(nombre,direccion,telefono);
	hostales.insert(*nuevoHostal);
    
}



void HostalControlador::asignarEmpleado(string nomN, string emailN, CargoEmpleado cargoN){
    //hostales.find()
    

}


void HostalControlador::cancelarAsignacion(){

}



void HostalControlador::confirmarAsigncacion(){

}



void HostalControlador::finalizar(){

}



set<DTHostal*> HostalControlador::listarHostales(){
    set<DTHostal*> setListarHostales;
    set<Hostal>::iterator itr;

	for(itr = hostales.begin(); itr != hostales.end(); itr++){
		Hostal& coso = const_cast<Hostal&>(*itr);
        //dynamic_cast<coso.getDireccion()>;
		DTHostal host(informacion,coso.getDireccion(),coso.getDireccion(),1,nullptr);
		setListarHostales.insert(host);
	}
 


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