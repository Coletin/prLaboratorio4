#include <iostream>
#include <string>
#include <set>
#include <typeinfo>
#include <iostream>

#include "ColeccionesHandler.h"
#include "Hostal.h"
#include "Estadia.h"
#include "Calificacion.h"
#include "Usuario.h"
#include "Reserva.h"
#include "../Tipos/tipos.h"

ColeccionesHandler* ColeccionesHandler::instancia = NULL;

ColeccionesHandler* ColeccionesHandler::getInstancia(){
    if (instancia == NULL){
        instancia = new ColeccionesHandler;
    }
    return instancia;
}

void ColeccionesHandler::addHostal(Hostal* hostalN){
    hostales.insert(hostalN);
}

Hostal* ColeccionesHandler::getHostal(string nombre){
    set<Hostal*>::iterator it = hostales.begin();
    bool encontre = false;
    Hostal* actual;
    while (it != hostales.end() && !encontre){
        actual = *it;
        encontre = actual->getNombre() == nombre;
        if(!encontre)
            ++it;
    }
    return actual;
}

set<DTHostal*> ColeccionesHandler::getHostalCol(){
    set<DTHostal*> resu;
    for(set<Hostal*>::iterator it = hostales.begin(); it != hostales.end();++it){
        Hostal actual = **it;
        DTHostal* agregar = actual.getDT(); 
        resu.insert(agregar);
    }
    return resu;
}

Estadia* ColeccionesHandler::getEstadia(int codigo){
    set<Estadia*>::iterator it = estadias.begin();
    bool encontre = false;
    Estadia* actual;
    while (it != estadias.end() && !encontre){
        actual = *it;
        encontre = actual->getCodigo() == codigo;
        if(!encontre)
            ++it;
    }
    return actual;
}

set<DTEmpleado*> ColeccionesHandler::getEmpleadoNoAsigCol(string nom){
    set<DTEmpleado*> resu;
    for(set<Usuario*>::iterator it = usuarios.begin(); it != usuarios.end();++it){
        Usuario* actual = *it;
        if(dynamic_cast<Empleado*>(actual) != 0){    
            Empleado* empleado = dynamic_cast<Empleado*>(actual); 
            if(empleado->getTrabajo()->getNombre() == nom){
                DTEmpleado* agregar = empleado->getDTEmpleado();
                resu.insert(agregar);
            }
        }
    }
return resu;
}



set<DTUsuario*> ColeccionesHandler::getUsuarios(){
    set<DTUsuario*> resu;
    for(set<Usuario*>::iterator it = usuarios.begin(); it != usuarios.end();++it){
        Usuario* actual = *it;
        if(dynamic_cast<Empleado*>(actual) != 0){
            Empleado* empleado = dynamic_cast<Empleado*>(actual);
            DTEmpleado* agregar = empleado->getDTEmpleado();
            resu.insert(agregar);
        }
        if(dynamic_cast<Huesped*>(actual) != 0){
            Huesped* huesped = dynamic_cast<Huesped*>(actual);
            DTHuesped* agregar = huesped->getDTHuesped();
            resu.insert(agregar);
        }
    }
return resu;
}

set<Hostal*> ColeccionesHandler::getHostales(){
    return this->hostales;
}

void ColeccionesHandler::agregarEstadia(Estadia* e){
    this->estadias.insert(e);
};

void ColeccionesHandler::eliminarEstadia(Estadia* e){
    this->estadias.erase(e);
};


Empleado* ColeccionesHandler::getEmpleado(string email){
    set<Usuario*>::iterator it = usuarios.begin();
    Empleado* res;
    bool encontre = false;
    while (it != usuarios.end() && !encontre){
        Usuario* actual = *it;
        encontre = actual->getEmail() == email;
        if(!encontre)
            ++it;
        else {
            res = dynamic_cast<Empleado*>(actual);
        };
    }
    return res;
}

IObserver* ColeccionesHandler::getEmpleadoObs(string email){
    set<Usuario*>::iterator it = usuarios.begin();
    IObserver* res;
    bool encontre = false;
    while (it != usuarios.end() && !encontre){
        Usuario* actual = *it;
        encontre = actual->getEmail() == email;
        if(!encontre)
            ++it;
        else{
            res = dynamic_cast<IObserver*>(actual);
        };
    }
    return res;
}

Huesped* ColeccionesHandler::getHuesped(string email){
    set<Usuario*>::iterator it = usuarios.begin();
    Huesped* res;
    bool encontre = false;
    while (it != usuarios.end() && !encontre){
        Usuario* actual = *it;
        encontre = actual->getEmail() == email;
        if(!encontre)
            ++it;
        else if(dynamic_cast<Huesped*>(actual) != 0){
            res = dynamic_cast<Huesped*>(actual);
        };
    }
    return res;
}

set<DTReserva*> ColeccionesHandler::getReservasHostal(string nomH){
    set<DTReserva*> resu;
    for(set<Reserva*>::iterator it = reservas.begin(); it != reservas.end();++it){
        Reserva* actual = *it;
        if(actual->esReservaHostal(nomH)){
            resu.insert(actual->getDT());
        }
    }
    return resu;
}

void ColeccionesHandler::eliminarReserva(int codR){
    set<Reserva*>::iterator it = reservas.begin();
    Reserva* actual = *it;
    while(it != reservas.end() && actual->getCodigo() != codR){
        ++it;
        actual = *it;
    }
    reservas.erase(it);
    delete(actual);
}

Reserva* ColeccionesHandler::getReserva(int codR){
    set<Reserva*>::iterator it = reservas.begin();
    bool encontre = false;
    Reserva* actual;
    while (it != reservas.end() && !encontre){
        actual = *it;
        encontre = actual->getCodigo() == codR;
        if(!encontre) ++it;
    }
    return actual;
}

set<DTHuesped*> ColeccionesHandler::getHuespedes(){
    set<DTHuesped*> resu;
    for(set<Usuario*>::iterator it = usuarios.begin(); it != usuarios.end();++it){
        Usuario* actual = *it;
        if(dynamic_cast<Huesped*>(actual) != 0){
            Huesped* huesped = dynamic_cast<Huesped*>(actual);
            DTHuesped* agregar = huesped->getDTHuesped();
            resu.insert(agregar);
        }
    }
return resu;
}

set<DTEmpleado*> ColeccionesHandler::getEmpleados(){
    set<DTEmpleado*> resu;
    for(set<Usuario*>::iterator it = usuarios.begin(); it != usuarios.end();++it){
        Usuario* actual = *it;
        if(dynamic_cast<Empleado*>(actual) != 0){
            Empleado* empleado = dynamic_cast<Empleado*>(actual);
            DTEmpleado* agregar = empleado->getDTEmpleado();
            resu.insert(agregar);
        }
    }
return resu;
}

void ColeccionesHandler::agregarReserva(Reserva *r){
    this->reservas.insert(r);
}

void ColeccionesHandler::agregarUsuario(Usuario *u){
    this->usuarios.insert(u);
}

bool ColeccionesHandler::existeUsuario(string email){
    set<Usuario*>::iterator it = usuarios.begin();
    bool encontre = false;
    while (it != usuarios.end() && !encontre){
        Usuario* actual = *it;
        encontre = actual->getEmail() == email;
        if(!encontre) ++it;
    };
    return encontre;
}

Reserva* ColeccionesHandler::getReservaEstadia(int codigoE){
    set<Reserva*>::iterator it = reservas.begin();
    bool encontre = false;
    Reserva* actual;
    while((it != reservas.end())&&(!encontre)){
        actual = *it;
        set<Estadia*> estadiasReserva = actual->getEstadias();
        set<Estadia*>::iterator itE = estadiasReserva.begin();
        Estadia* actualE = *itE;
        while((itE != estadiasReserva.end())&&(actualE->getCodigo() != codigoE)){
            ++itE;
            actualE = *itE;
        }
        encontre = itE != estadiasReserva.end();
    }
    return actual;
}
    

