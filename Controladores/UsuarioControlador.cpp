#include <cstdio>
#include "EstadiaControlador.h"
#include "HostalControlador.h"
#include "RelojControlador.h"
#include "ReservaControlador.h"
#include "UsuarioControlador.h"
    
#include "../Clases/Usuario.h"
#include "../Clases/Empleado.h"
#include "../Clases/Huesped.h"
#include "../Clases/Fabrica.h"


UsuarioControlador * UsuarioControlador::instancia = NULL;

UsuarioControlador::UsuarioControlador(){
// aca van definiciones del controlador

}

UsuarioControlador * UsuarioControlador::getInstancia(){
	if(instancia == NULL)
		instancia = new UsuarioControlador;

	return instancia;
}






void UsuarioControlador::cargarDatosUsuario(string nombre, string contrasenia){

}


void UsuarioControlador::crearHuesped(bool esFinger){
}


void UsuarioControlador::crearEmpleado(CargoEmpleado cargo){
    Empleado * nuevo= new Empleado(cargo);

}


bool UsuarioControlador::indicarEmail(string email){

}


bool UsuarioControlador::persistirUsuario(){

}




void UsuarioControlador::cancelarCreacionUsuario(){

}




set<DTUsuario*> UsuarioControlador::listarUsuarios(){
   set<DTUsuario*> setListaUsuarios;
   return setListaUsuarios;
}



DTEmpleado UsuarioControlador::datosEmpleado(string email){

}



DTHuesped UsuarioControlador::datosHuesped(string email){
       
}


set<DTCalificacion*> UsuarioControlador::listarCalificacion(string mail){
       set<DTCalificacion*> setListaCalificacion;
return setListaCalificacion;
}



void UsuarioControlador::seleccionarCalificacion(string codigo){

}//codigo = Codigo de la estadia


void UsuarioControlador::responderComentario(string comentario){
}