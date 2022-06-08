#include <cstdio>
#include "EstadiaControlador.h"
#include "HostalControlador.h"
#include "RelojControlador.h"
#include "ReservaControlador.h"
#include "UsuarioControlador.h"


RelojControlador *RelojControlador::instancia = NULL;

RelojControlador::RelojControlador(){

// aca van definiciones del controlador

}

RelojControlador * RelojControlador::getInstancia(){
	if(instancia == NULL)
		instancia = new RelojControlador;

	return instancia;
}

void RelojControlador::setFecha(DTFecha){


}



DTFecha RelojControlador::getFecha(){
DTFecha retornoFecha;

return retornoFecha;
}