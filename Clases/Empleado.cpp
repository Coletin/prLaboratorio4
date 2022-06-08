#include <iostream>
#include <string>
#include <set>

#include "Usuario.h"
#include "Empleado.h"
#include "Hostal.h"
#include "../Tipos/tipos.h"


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

DTEmpleado Empleado::getDTEmpleado(){
    string _nombre = getNombre();
    string _email = getEmail();
    string _password = getPassword();
    CargoEmpleado _cargo = getCargo();
    return DTEmpleado(_nombre,_email,_password,_cargo);
}


void Empleado::setCargo(CargoEmpleado _cargo){
    this->cargo = _cargo;
}

void Empleado::setTrabajo(Hostal h){
    this->trabajo = &h;
}

void Empleado::notificar(Notificacion n){
    this->notificaciones.insert(&n);
}