#include <iostream>
#include <string>
#include <set>

using namespace std;

class Hostal;
class Reserva;
class DTReserva;
class DTHabitacion;
class DataR;
class DTEstadia;
class Estadia;
class Huesped;


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
     bool estaLibre(DataR* data); 
     DTHabitacion* getDT();
     void asociarRevHab(Reserva *r);
     set<DTEstadia*> getEstadiasDT(); 
     set<DTEstadia*> getReservasFinalizadasAsociadas(string);
     bool existeEstadiasActivas(string email, string nombre);
     set<DTReserva*> getReservasAsociadas(string email);
     int getHabEstadia(Estadia* est);
     void eliminarReserva(Reserva*);
     string getNomHostal();
};