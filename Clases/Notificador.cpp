#include "Notificador.h"
#include "Notificacion.h"
#include "../Interfaces/IObserver.h"


Notificador *Notificador::instancia = nullptr;

Notificador* Notificador::getInstancia(){
    if(instancia == NULL)
		instancia = new Notificador;

	return instancia;
}


void Notificador::agregar(IObserver* o){
    this->observers.insert(o);
}


void Notificador::eliminar(IObserver* o){
    this->observers.erase(o);
}


void Notificador::modificar(Notificacion* n){
    for(set<IObserver*>::iterator it = observers.begin(); it != observers.end();++it){
        IObserver* actual = *it;
        actual->notificar(n);
    }
}