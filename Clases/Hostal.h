#include <iostream>
#include <string>
#include <set>

using namespace std;

class Calificacion;
class DTEstadia;
class DTHabitacion;
class DTCalificacion;
class DataR;
class Estadia;
class DTHostal;
class DTReserva;
class Habitacion;

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
        set<DTHabitacion*> getHabDis(DataR* data);
        void agregarHabitacion(int, float, int);
        Habitacion* getHabNum(int numeroHab);
        float getPromCal();
        set<DTCalificacion*> getCalifs();
        set<DTCalificacion*> getCalifsSinReponder();
        set<DTHabitacion*> getHabitaciones();
        DTHostal* getDT();
        bool existeEstadiasActivas(string email);
        set<DTEstadia*> getReservasFinalizadasAsociadas(string email);
        set<DTReserva*> getReservasAsociadas(string email);
        void agregarCalificacion(Calificacion* cal);
        int getHabEstadia(Estadia* est);
        void eliminarCalificacion(Calificacion* cal);
};