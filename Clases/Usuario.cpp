#include "Usuario.h"
#include "Estadia.h"
#include "../Tipos/tipos.h"
#include "Hostal.h"
#include "Notificacion.h"

Usuario::Usuario(){}

Usuario::Usuario(string _nombre, string _email, string _pass){
    this->nombre = _nombre;
    this->email = _email;
    this->password = _pass;
}

string Usuario::getEmail(){
    return this->email;
}
string Usuario::getNombre(){
    return this->nombre;
}

string Usuario::getPassword(){
    return this->password;
}

void Usuario::setEmail(string _email){
    this->email = _email;
}

void Usuario::setNombre(string _nombre){
    this->nombre = _nombre;
}

void Usuario::setPassword(string _password){
    this->password = _password;
}


//HUESPED


void Huesped::setEsFinger(bool _esFinger){ esFinger = _esFinger; };
bool Huesped::getEsFinger(){ return esFinger; }

Huesped::Huesped():Usuario(){
    esFinger = false;
    set<Estadia*> lista;
    estadia = lista;
}

Huesped::Huesped(string _nombre, string _email, string _password,bool _esFinger):Usuario(_nombre, _email, _password){
    esFinger = _esFinger;
    set<Estadia*> lista;
    estadia = lista;
}

DTHuesped* Huesped::getDTHuesped(){
    DTHuesped* respuesta = new DTHuesped(this->getNombre(),this->getEmail(),this->getPassword(),esFinger);
    return respuesta;
}

Estadia* Huesped::getEstadia(){
    Estadia* respuesta = new Estadia();
    return respuesta;    
}


void Huesped::agregarEstadia(Estadia* _estadia){
    estadia.insert(_estadia);
}

void Huesped::eliminarEstadia(Estadia* _estadia){
    estadia.erase(_estadia);
}


//EMPLEADO



Empleado::Empleado(string _nombre,string _email, string _password, CargoEmpleado _cargo):
          Usuario(_nombre,_email,_password){
              this->cargo = _cargo;
}

CargoEmpleado Empleado::getCargo(){
    return this->cargo;
}

Hostal* Empleado::getTrabajo(){
    return this->trabajo;
}

DTEmpleado* Empleado::getDTEmpleado(){
    string _nombre = getNombre();
    string _email = getEmail();
    string _password = getPassword();
    string _cargo;
    if(this->getCargo()==Recepcion){
        _cargo = "Recepcion";
    }
    else if(this->getCargo()==Administracion){
         _cargo = "Administracion";
    }
    else if(this->getCargo()==Limpieza){
         _cargo = "Limpieza";
    }
    else if(this->getCargo()==Infraestructura){
         _cargo = "Infraestructura";
    };
    DTEmpleado* res = new DTEmpleado(_nombre,_email,_password,_cargo);
    return res;
}


void Empleado::setCargo(CargoEmpleado _cargo){
    this->cargo = _cargo;
}

void Empleado::setTrabajo(Hostal* h){
    this->trabajo = h;
}

void Empleado::notificar(Notificacion* n){
    this->notificaciones.insert(n);
}