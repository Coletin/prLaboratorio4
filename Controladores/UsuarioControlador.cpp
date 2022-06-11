#include <cstdio>
#include "EstadiaControlador.h"
#include "HostalControlador.h"
#include "RelojControlador.h"
#include "ReservaControlador.h"
#include "UsuarioControlador.h"
    
#include "../Clases/Usuario.h"
#include "../Clases/Fabrica.h"
#include "../Clases/ColeccionesHandler.h"
#include "../Clases/Hostal.h"
#include "../Tipos/tipos.h"


UsuarioControlador * UsuarioControlador::instancia = NULL;

UsuarioControlador::UsuarioControlador(){
    // aca van definiciones del controlador
    nombreACrear = "";
    contraseniaACrear = "";
    usuarioACrear = NULL;
}

UsuarioControlador * UsuarioControlador::getInstancia(){
	if(instancia == NULL)
		instancia = new UsuarioControlador;
	return instancia;
}

void UsuarioControlador::cargarDatosUsuario(string nombre, string contrasenia){
    nombreACrear = nombre;
    contraseniaACrear = contrasenia;
}

void UsuarioControlador::crearHuesped(bool esFinger){
    usuarioACrear = new DTHuesped(nombreACrear,emailACrear,contraseniaACrear,esFinger);
}


void UsuarioControlador::crearEmpleado(CargoEmpleado cargo){
    usuarioACrear = new DTEmpleado(nombreACrear,emailACrear,contraseniaACrear,cargo);
}


bool UsuarioControlador::indicarEmail(string email){
    bool encontre = false;
    ColeccionesHandler* colecciones = ColeccionesHandler::getInstancia();
    set<DTUsuario*> listaUsuarios = colecciones->getUsuarios();

    for(auto& actual = listaUsuarios.cbegin(); actual != listaUsuarios.cend() && !encontre; actual ++){
        DTUsuario *elemento = *actual;
        encontre = email.compare(elemento->getEmail()) == 0;
    }

    if(!encontre)
        emailACrear = email;        

    return !encontre;
}


bool UsuarioControlador::persistirUsuario(){
    Usuario* persistir = NULL;
    if(dynamic_cast<DTEmpleado*>(usuarioACrear)){
        DTEmpleado *dataEmpleado = dynamic_cast<DTEmpleado*>(usuarioACrear);
        persistir = new Empleado(dataEmpleado->getNombre(),dataEmpleado->getEmail(),dataEmpleado->getContrasena(),dataEmpleado->getCargo());
    }else{
        DTHuesped *dataHuesped = dynamic_cast<DTHuesped*>(usuarioACrear);
        persistir = new Huesped(dataHuesped->getNombre(),dataHuesped->getEmail(),dataHuesped->getContrasena(),dataHuesped->getEsFinger());
    }
    
    ColeccionesHandler* colecciones = ColeccionesHandler::getInstancia();
    colecciones->agregarUsuario(persistir);

    limpiarMemoria();
}

void UsuarioControlador::cancelarCreacionUsuario(){
    limpiarMemoria();
}

set<DTUsuario*> UsuarioControlador::listarUsuarios(){
   set<DTUsuario*> setListaUsuarios;
   return setListaUsuarios;
}

DTEmpleado* UsuarioControlador::datosEmpleado(string email){
    DTEmpleado *devolver = NULL;
    ColeccionesHandler* colecciones = ColeccionesHandler::getInstancia();
    set<DTUsuario*> listaUsuarios = colecciones->getUsuarios();

    for(auto actual : listaUsuarios){
        if(email.compare(actual->getEmail()) == 0 && dynamic_cast<DTEmpleado*>(actual))
            devolver = dynamic_cast<DTEmpleado*>(actual);
    }
    return devolver;
}

DTHuesped* UsuarioControlador::datosHuesped(string email){
    DTHuesped *devolver = NULL;
    ColeccionesHandler* colecciones = ColeccionesHandler::getInstancia();
    set<DTUsuario*> listaUsuarios = colecciones->getUsuarios();

    for(auto actual : listaUsuarios){
        if(email.compare(actual->getEmail()) == 0 && dynamic_cast<DTHuesped*>(actual))
            devolver = dynamic_cast<DTHuesped*>(actual);
    }
    return devolver;
}


set<DTCalificacion*> UsuarioControlador::listarCalificacion(string mail){
    set<DTCalificacion*> respuesta;
    
    ColeccionesHandler* colecciones = ColeccionesHandler::getInstancia();

    Empleado* empleado = colecciones->getEmpleado(mail);
    Hostal *hostal = empleado->getTrabajo();
    respuesta = hostal->getCalifs();

    return respuesta;
}

void UsuarioControlador::seleccionarCalificacion(string codigo){

}//codigo = Codigo de la estadia


void UsuarioControlador::responderComentario(string comentario){
}

void UsuarioControlador::limpiarMemoria(){
    nombreACrear = "";
    contraseniaACrear = "";
    delete usuarioACrear;
    usuarioACrear = NULL;
}