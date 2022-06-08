#include <iostream>
#include <string>
#include <set>
#include <typeinfo>
#include <iostream>

#include "../Tipos/tipos.h"
#include "ColeccionesHandler.h"
#include "Hostal.h"
#include "Empleado.h"
#include "Huesped.h"

ColeccionesHandler* ColeccionesHandler::instancia = NULL;

ColeccionesHandler* ColeccionesHandler::getInstancia(){
    if (instancia == NULL){
        instancia = new ColeccionesHandler;
    }
    return instancia;
}

void ColeccionesHandler::addHostal(Hostal hostalN){
    hostales.insert(&hostalN);
}

Hostal ColeccionesHandler::getHostal(string nombre){
    set<Hostal*>::iterator it = hostales.begin();
    bool encontre = false;
    while (it != hostales.end() && !encontre){
        Hostal actual = **it;
        encontre = actual.getNombre() == nombre;
        if(!encontre)
            ++it;
    }
return **it; 
}

set<DTHostal*> ColeccionesHandler::getHostalCol(){
    set<DTHostal*> resu;
    for(set<Hostal*>::iterator it = hostales.begin(); it != hostales.end();++it){
        Hostal actual = **it;
        DTHostal agregar = actual.getDT(); 
        resu.insert(&agregar);
    }
return resu;
}

set<DTEmpleado*> ColeccionesHandler::getEmpleadoNoAsigCol(string nom){
    set<DTEmpleado*> resu;
    for(set<Usuario*>::iterator it = usuarios.begin(); it != usuarios.end();++it){
        Usuario* actual = *it;
        if(dynamic_cast<Empleado*>(actual) != 0){    
            Empleado* empleado = dynamic_cast<Empleado*>(actual); 
            Hostal* trabajo = empleado->getTrabajo();
            if(trabajo->getNombre() == nom){
                DTEmpleado agregar = empleado->getDTEmpleado();
                resu.insert(&agregar);
            }
        }
    }
return resu;
}

set<DTUsuario*> ColeccionesHandler::getUsuarios(){
    set<DTUsuario*> resu;
    for(set<Usuario*>::iterator it = usuarios.begin(); it != usuarios.end();++it){
        Usuario* actual = *it;
        if(dynamic_cast<Empleado*>(actual)){
            Empleado* empleado = dynamic_cast<Empleado*>(actual);
            DTEmpleado agregar = empleado->getDTEmpleado();
            resu.insert(&agregar);
        }
        if(dynamic_cast<Huesped*>(actual)){
            Huesped* huesped = dynamic_cast<Huesped*>(actual);
            DTHuesped agregar = huesped->getDTHuesped();
            resu.insert(&agregar);
        }
    }
return resu;
}



