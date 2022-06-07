#include <iostream>
#include <string>
#include <set>
#include "EstadiaControlador.h"
#include "../Tipos/tipos.h"

EstadiaControlador::EstadiaControlador(){}

EstadiaControlador* EstadiaControlador::getInstancia(){
    if (this->instancia == nullptr){
        EstadiaControlador controlador = new EstadiaControlador();
        this->instancia = &controlador;
    }
    return this->instancia;    
}
