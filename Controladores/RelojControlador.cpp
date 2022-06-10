#include <cstdio>
#include "RelojControlador.h"



RelojControlador *RelojControlador::instancia = NULL;

RelojControlador * RelojControlador::getInstancia(){
	if(instancia == NULL)
		instancia = new RelojControlador;

	return instancia;
}

void RelojControlador::setFecha(DTFecha* fecha){
	this->fecha = fecha;
}



DTFecha* RelojControlador::getFecha(){
	return this->fecha;
}