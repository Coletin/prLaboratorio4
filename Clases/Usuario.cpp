#include <iostream>
#include <string>
#include "Usuario.h"

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