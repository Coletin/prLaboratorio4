#include <iostream>
#include <string>
#include <set>
#include "../Tipos/tipos.h"
#include "Hostal.h"

class Reserva;
class Estadia;

class Habitacion{
    private:
     int numero;
     float precio;
     int capacidad;
     set<Reserva*> reservas;
     Hostal* hostal;
    public:
     Habitacion();
     Habitacion(int, float, int);
     int getNumero();
     void setNumero(int _numero);
     float getPrecio();
     void setPrecio(float _precio);
     int getCapacidad();
     void setCapacidad(int _capacidad);
     bool esDeHostal(string nomH);
     bool estaLibre(DataR data); 
     DTHabitacion getDT();
     void asociarRevHab(Reserva *r);
     set<DTEstadia*> getEstadiasDT(); 
     set<DTReserva*> getReservasFinalizadasAsociadas();
     bool existeEstadiasActivas(string email, string nombre);
     set<DTReserva*> getReservasAsociadas(string nombre, string email);
     int getHabEstadia(Estadia* est);
};