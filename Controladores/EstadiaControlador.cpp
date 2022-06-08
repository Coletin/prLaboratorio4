#include <cstdio>
#include "EstadiaControlador.h"
#include "HostalControlador.h"
#include "RelojControlador.h"
#include "ReservaControlador.h"
#include "UsuarioControlador.h"

#include "../Clases/Estadia.h"
#include "../Clases/Fabrica.h"


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

}



set<DTReserva*> EstadiaControlador::listarReservas(string email, string hostal){
   set<DTReserva*> setListaReservas;

return setListaReservas;
}



void EstadiaControlador::registrarEstadia(string email, int codigo){
    Estadia * nueva= new Estadia();
  
}


bool EstadiaControlador::existenEstadiasActivas(string email, string hostal){


return true;
}




/* Se busca la estadia para eliminarla*/
void EstadiaControlador::finalizarEstadia(string email){



}




set<DTEstadia*> EstadiaControlador::obtenerEstadiasFinalizadas(string email, string hostal){
   set<DTEstadia*> setEstadiasFinalizadas;
   
   
    return setEstadiasFinalizadas;
}



void EstadiaControlador::crearCalificacion(string email, string hostal, string comentario, int valor){
    
}
