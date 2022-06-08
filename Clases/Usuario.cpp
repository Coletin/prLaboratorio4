#include <iostream>
#include <string>
#include "Usuario.h"

Usuario::Usuario(){}

Usuario::Usuario(String _nombre, string _email, string _pass){
    this->nombre = _nombre;
    this->email = _email;
    this->password = _pass;
}

String Usuario::getEmail(){
    return this->email;
}

String Usuario::getNombre(){
    return this->nombre;
}

String Usuario::getPassword(){
    return this->password;
}

void Usuario::setEmail(String _email){
    this->email = _email;
}

void Usuario::setNombre(String _nombre){
    this->nombre = _nombre;
}

void Usuario::setPassword(String _password){
    this->password = _password;
}