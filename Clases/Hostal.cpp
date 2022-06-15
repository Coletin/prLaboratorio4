#include "Hostal.h"
#include "Habitacion.h"
#include "../Tipos/tipos.h"
#include "Estadia.h"
#include "Calificacion.h"

string Hostal::getNombre(){ return nombre; }
void Hostal::setNombre(string _nombre){ nombre = _nombre; }
string Hostal::getDireccion(){ return direccion; }
void Hostal::setDireccion(string _direccion){ direccion = _direccion; }
string Hostal::getTelefono(){ return telefono; }
void Hostal::setTelefono(string _telefono){ telefono = _telefono; }

Hostal::Hostal(){};
Hostal::Hostal(string _nombre, string _direccion, string _telefono){
    nombre = _nombre;
    direccion = _direccion;
    telefono = _telefono;    
    set<Habitacion*> listaHabitaciones;
    habitaciones = listaHabitaciones;
    set<Calificacion*> listaCalificaciones;
    calificaciones = listaCalificaciones;
}

set<DTEstadia*> Hostal::getEstadiasDT(){
    set<DTEstadia*> respuesta;
    return respuesta;
}

set<DTHabitacion*> Hostal::getHabDis(DataR* datar){
    set<DTHabitacion*> resu;
    return resu;
}

Habitacion* Hostal::getHabNum(int numeroHab){
    Habitacion* respuesta = new Habitacion();
    return respuesta;
}

float Hostal::getPromCal(){
    return 0.0;
}

set<DTCalificacion*> Hostal::getCalifs(){
    set<DTCalificacion*> respuesta;
    return respuesta;
}

set<DTHabitacion*> Hostal::getHabitaciones(){
    set<DTHabitacion*> respuesta;
    return respuesta;
}

void Hostal::agregarHabitacion(int numero, float precio, int capacidad){
    
}

DTHostal* Hostal::getDT(){
    set<DTCalificacion*> califica = getCalifs();
    float prom = getPromCal();
    DTHostal* respuesta = new DTHostal(nombre,direccion,telefono,prom,califica);
    return respuesta;
}

bool Hostal::existeEstadiasActivas(string _email){
    return false;
}

set<DTEstadia*> Hostal::getReservasFinalizadasAsociadas(string _email){
    set<DTEstadia*> resu;
    for(set<Habitacion*>::iterator it = habitaciones.begin(); it != habitaciones.end();++it){ 
        Habitacion* habActual = *it;
        set<DTEstadia*> resActuales = habActual->getReservasFinalizadasAsociadas(_email);
        for(set<DTEstadia*>::iterator it1 = resActuales.begin(); it1 != resActuales.end();++it1) resu.insert(*it1);
    }
    return resu;
}

set<DTReserva*> Hostal::getReservasAsociadas(string _email){
    set<DTReserva*> resu;
    for(set<Habitacion*>::iterator it = habitaciones.begin(); it != habitaciones.end();++it){ 
        Habitacion* habActual = *it;
        set<DTReserva*> resActuales = habActual->getReservasAsociadas(_email);
        for(set<DTReserva*>::iterator it1 = resActuales.begin(); it1 != resActuales.end();++it1) resu.insert(*it1);
    } 
    return resu;
}

void Hostal::agregarCalificacion(Calificacion* cal){
    calificaciones.insert(cal);
}

int Hostal::getHabEstadia(Estadia* est){
    return 1;
}

void Hostal::eliminarCalificacion(Calificacion* cal){
    this->calificaciones.erase(cal);
}




/*
class Hostal{
    private:
        string nombre;
        string direccion;
        string telefono;
        set<Habitacion*> habitaciones;
        set<Calificacion*> calificaciones;
    public:
        Hostal();
        Hostal(string _nombre, string _direccion, string _telefono);
        void setNombre(string _nombre);
        void setDireccion(string _direccion);
        void setTelefono(string _telefono);
        string getNombre();
        string getDireccion();
        string getTelefono();
        set<DTEstadia*> getEstadiasDT();
        DTHabitacion getHabDis(DataR datar);
        Habitacion getHabNum(int numeroHab);
        float getPromCal();
        set<DTCalificacion*> getCalifs();
        set<DTHabitacion*> getHabitaciones();
        DTHostal getDT();
        bool existeEstadiasActivas(string email, string nombre);
        set<DTReserva*> getReservasFinalizadasAsociadas(string email, string nombre);
        set<DTReserva*> getReservasAsociadas(string nombre, string email);
        void agregarCalificacion(Calificacion cal);
        int getHabEstadia(Estadia est);
};
*/