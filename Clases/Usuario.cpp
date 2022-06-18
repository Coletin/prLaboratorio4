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
    estadia.clear();
}

Huesped::Huesped(string _nombre, string _email, string _password,bool _esFinger):Usuario(_nombre, _email, _password){
    esFinger = _esFinger;
    estadia.clear();
}

DTHuesped* Huesped::getDTHuesped(){
    DTHuesped* respuesta = new DTHuesped(this->getNombre(),this->getEmail(),this->getPassword(),esFinger);
    return respuesta;
}

Estadia* Huesped::getEstadia(int codigo){
    set<Estadia*>::iterator it = estadia.begin();
    bool encontre = false;
    Estadia* actual;
    while (it != estadia.end() && !encontre){
        actual = *it;
        encontre = actual->getCodigo() == codigo;
        if(!encontre)
            ++it;
    }
    return actual;
}


void Huesped::agregarEstadia(Estadia* _estadia){
    estadia.insert(_estadia);
}

void Huesped::eliminarEstadia(Estadia* _estadia){
    estadia.erase(_estadia);
}

set<Estadia*> Huesped::getEstadias(){
    return this->estadia;
}


//EMPLEADO



Empleado::Empleado(string _nombre,string _email, string _password, CargoEmpleado _cargo):
          Usuario(_nombre,_email,_password){
              this->cargo = _cargo;
              this->trabajo = nullptr;
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
    string _trabajo = "";
    if(this->getTrabajo() != nullptr)
        _trabajo = this->getTrabajo()->getNombre();
    CargoEmpleado _cargo = getCargo();
    DTEmpleado* res = new DTEmpleado(_nombre,_email,_password,_trabajo,_cargo);
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

set<DTNotificacion*> Empleado::getNotificaciones(){
    set<DTNotificacion*> resu;
    for(set<Notificacion*>::iterator it = this->notificaciones.begin(); it != this->notificaciones.end(); ++it){
        Notificacion* actual = *it;
        DTNotificacion* nueva = new DTNotificacion(actual->getAutor(), actual->getPuntaje(), actual->getComentario());
        resu.insert(nueva);
    }
    return resu;
}

void Empleado::eliminarNotificaciones(){
    for(set<Notificacion*>::iterator it = this->notificaciones.begin();it != this->notificaciones.end(); ++it){delete(*it);};
    this->notificaciones.clear();
}