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
    set<DTEstadia*> aux;
    for(set<Habitacion*>::iterator i = habitaciones.begin();i != habitaciones.end();++i){
        Habitacion* actual = *i; 
        aux = actual->getEstadiasDT();
        for(set<DTEstadia*>::iterator it = aux.begin();it != aux.end();++it)
            respuesta.insert(*it);
    }
    return respuesta;
}

set<DTHabitacion*> Hostal::getHabDis(DataR* data){
    set<DTHabitacion*> resu;
    for(set<Habitacion*>::iterator i = habitaciones.begin();i != habitaciones.end();++i){
        Habitacion* actual = *i;
        if(actual->estaLibre(data)) resu.insert(actual->getDT());
    }
    return resu;
}

Habitacion* Hostal::getHabNum(int numeroHab){
    bool encontre = false;
    set<Habitacion*>::iterator it = habitaciones.begin();
    Habitacion* actual;
    while (it != habitaciones.end() && !encontre){
        actual = *it;
        encontre = actual->getNumero() == numeroHab;
        if(!encontre) ++it;
    }
    return actual;
}

float Hostal::getPromCal(){
    float resu = 0.0;
    int i = 0;
    for(set<Calificacion*>::iterator it = calificaciones.begin();it != calificaciones.end();++it){
        Calificacion* actual = *it;
        resu = resu + actual->getValor();
        i++;
    }
    if(i!=0)resu = resu/i;
    return resu;
}

set<DTCalificacion*> Hostal::getCalifs(){
    set<DTCalificacion*> respuesta;
    Calificacion* actual;
    for(set<Calificacion*>::iterator it = calificaciones.begin();it != calificaciones.end();++it){
        actual = *it;
        respuesta.insert(actual->getDT());
    }
    return respuesta;
}

set<DTCalificacion*> Hostal::getCalifsSinReponder(){
    set<DTCalificacion*> respuesta;
    Calificacion* actual;
    for(set<Calificacion*>::iterator it = calificaciones.begin();it != calificaciones.end();++it){
        actual = *it;
        if(actual->getRespuestaCalificacion() == nullptr)respuesta.insert(actual->getDT());
    }
    return respuesta;
}

set<DTHabitacion*> Hostal::getHabitaciones(){
    set<DTHabitacion*> respuesta;
    for(set<Habitacion*>::iterator it = habitaciones.begin();it != habitaciones.end();++it){
        Habitacion* actual = *it;
        respuesta.insert(actual->getDT());
    }
    return respuesta;
}

void Hostal::agregarHabitacion(int numero, float precio, int capacidad){
    Habitacion* hab = new Habitacion(numero,precio,capacidad);
    habitaciones.insert(hab);
    hab->setHostal(this);
}

DTHostal* Hostal::getDT(){
    set<DTCalificacion*> califica = getCalifs();
    float prom = getPromCal();
    DTHostal* respuesta = new DTHostal(nombre,direccion,telefono,prom,califica);
    return respuesta;
}

bool Hostal::existeEstadiasActivas(string _email){
    bool existe = false;
    set<Habitacion*>::iterator it =  habitaciones.begin();
    while (it != habitaciones.end() && !existe){
        Habitacion* actual = *it;
        existe = actual->existeEstadiasActivas(_email);
        ++it;
    }    
    return existe;
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
    Calificacion* add = cal;
    calificaciones.insert(add);
}

//si no encuentra habitacion asosciada a est devuelve -1
int Hostal::getHabEstadia(Estadia* est){
    set<Habitacion*>::iterator it = habitaciones.begin();
    int resu = -1;
    while (it != habitaciones.end() && resu == -1){
        Habitacion* actual = *it;
        resu = actual->getHabEstadia(est);
        ++it;
    }
    return resu;
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