#include <cstdio>
#include "HostalControlador.h"

#include "../Clases/Hostal.h"
#include "../Clases/Fabrica.h"
#include "../Clases/ColeccionesHandler.h"
#include "../Clases/Usuario.h"
#include "../Tipos/tipos.h"




HostalControlador *HostalControlador::instancia = nullptr;

HostalControlador::HostalControlador(){

};


HostalControlador * HostalControlador::getInstancia(){
	if(instancia == nullptr)
		instancia = new HostalControlador();

	return instancia;
}




void HostalControlador::agregarHostal(string nombre, string direccion, string telefono){
    ColeccionesHandler* colecciones = ColeccionesHandler::getInstancia();
	Hostal *nuevoHostal = new Hostal(nombre,direccion,telefono);
	colecciones->addHostal(nuevoHostal);
    
}



void HostalControlador::asignarEmpleado(string emailN, CargoEmpleado cargoN){
    this->cargoN = cargoN;
    this->emailN = emailN;
}


void HostalControlador::cancelarAsignacion(){
}



void HostalControlador::confirmarAsigncacion(){
    ColeccionesHandler* colecciones = ColeccionesHandler::getInstancia();
    Empleado * e = colecciones->getEmpleado(emailN);
    Hostal * h = colecciones->getHostal(nom);
    e->setCargo(cargoN);
    e->setTrabajo(h);
}



void HostalControlador::finalizar(){
}



set<DTHostal*> HostalControlador::listarHostales(){
    set<DTHostal*> setListarHostales;
    ColeccionesHandler* colecciones = ColeccionesHandler::getInstancia();
    setListarHostales = colecciones->getHostalCol();
    return setListarHostales;    
}





set<DTEmpleado*> HostalControlador::seleccionarHostal(string nom){
    ColeccionesHandler* colecciones = ColeccionesHandler::getInstancia();
    set<DTEmpleado*> listEmpleados = colecciones->getEmpleadoNoAsigCol(nom);
    this->nom = nom;
    return listEmpleados;
}






void HostalControlador::seleccionarHostalVar(string nombre){
    this->nom = nombre;
}


bool HostalControlador::habitacionEnHostal(int num ,string hostal){
    ColeccionesHandler* colecciones = ColeccionesHandler::getInstancia();
    Hostal* h = colecciones->getHostal(hostal);
    return h->habPertenece(num);
}



void HostalControlador::ingresarHabitacion(int numero, float precio, int capacidad){
    this->numero = numero;
    this->precio = precio;
    this->capacidad = capacidad;
}


set<DTHabitacion*> HostalControlador::listarHabitacionesHostal(string hostal){
    ColeccionesHandler* colecciones = ColeccionesHandler::getInstancia();
    Hostal* h = colecciones->getHostal(hostal);
    return h->getHabitaciones();
}



void HostalControlador::persistirHabitacion(){
    ColeccionesHandler* colecciones = ColeccionesHandler::getInstancia();
    Hostal* h = colecciones->getHostal(nom);
    h->agregarHabitacion(numero, precio, capacidad);
}




set<DTReserva*> HostalControlador::listarReservas(){
    ColeccionesHandler* colecciones = ColeccionesHandler::getInstancia();
    set<DTReserva*> setListaReservas;
    setListaReservas = colecciones->getReservasHostal(nom);
    return setListaReservas;
}



void HostalControlador::cancelarCreacionHabitacion(){
}






set<DTHostal*> HostalControlador::topTres(){
    ColeccionesHandler* colecciones = ColeccionesHandler::getInstancia();
    set<DTHostal*> hh = colecciones->getHostalCol();
    set<DTHostal*>::iterator it;
    int h1 =0;
    int h2 = 0;
    int h3 = 0;
    DTHostal* hp1, *hp2, *hp3;
    for(set<DTHostal*>::iterator it = hh.begin(); it != hh.end(); ++it){
        DTHostal * actual = *it;
        int prom = actual->getPromedioClasi();
        if(prom >= h1){
            h3 = h2;
            hp3 = hp2;
            h2 = h1;
            hp2 = hp1;
            h1 = prom;
            hp1 = actual;
        }
        else if(prom >= h2){
            h3 = h2;
            hp3 = hp2;
            h2 = prom;
            hp2 = actual;
        }
        else if(prom >= h3){
            h3 = prom;
            hp3 = actual;
        }
    };
    this->t3.insert(hp1);
    this->t3.insert(hp2);
    this->t3.insert(hp3);

    return t3;
}




set<DTCalificacion*> HostalControlador::calificacionesHostal(string nom){
   set<DTCalificacion*> resu;
    for(set<DTHostal*>::iterator it = this->t3.begin(); it != this->t3.end();++it){
        DTHostal* actual = *it;
        if(actual->getNombre() == nom){
            resu = actual->getCaliHabi();
        }
    }
    return resu;
}




void HostalControlador::liberarMemoriaTop3(){
    for(set<DTHostal*>::iterator it = this->t3.begin(); it != this->t3.end();++it){
        DTHostal* actual = *it;
        delete(actual);
    }
    t3.clear();
}

bool HostalControlador::existeHostal(string _nombre){
    bool encontre = false;
    ColeccionesHandler* colecciones = ColeccionesHandler::getInstancia();
    set<DTHostal*> listaHostales = colecciones->getHostalCol();
    for(set<DTHostal*>::iterator actual = listaHostales.begin(); actual != listaHostales.end() && !encontre; actual ++){
        DTHostal *elemento = *actual;
        encontre = _nombre.compare(elemento->getNombre()) == 0;
    }
    /*
    for(set<DTUsuario*>::iterator actual = listaUsuarios.begin(); actual != listaUsuarios.end() && !encontre; ++actual){
        DTUsuario *elemento = *actual;
        encontre = email.compare(elemento->getEmail()) == 0;
    }
    */
    return encontre;
}