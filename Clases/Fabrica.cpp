#include "Fabrica.h"
#include "../Controladores/HostalControlador.h"
#include "../Controladores/ReservaControlador.h"
#include "../Controladores/EstadiaControlador.h"
#include "../Controladores/RelojControlador.h"
#include "../Controladores/UsuarioControlador.h"

IHostal* Fabrica::getIHostal(){
    return HostalControlador::getInstancia();
}

IReserva* Fabrica::getIReserva(){
    return ReservaControlador::getInstancia();
}

IUsuario* Fabrica::getIUsuario(){
    return UsuarioControlador::getInstancia();
}

IEstadia* Fabrica::getIEstadia(){
    return EstadiaControlador::getInstancia();
}

IReloj* Fabrica::getIReloj(){
    return RelojControlador::getInstancia();
}