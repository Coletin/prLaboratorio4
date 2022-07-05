#include <iostream>
#include <string>
#include <set>
#include "../Interfaces/IObserver.h"
#include "../Tipos/CargoEmpleado.h"

using namespace std;

class Usuario{
    private:
     string nombre;
     string email;
     string password;
    public:
     Usuario();
     Usuario(string, string, string);
     virtual ~Usuario(){};
     string getEmail();
     string getNombre();
     string getPassword();
     void setEmail(string email);
     void setNombre(string nombre);
     void setPassword(string password);
};

//HUESPED

class Estadia;
class DTHuesped;

class Huesped : public Usuario{
    private:
        bool esFinger;
        set<Estadia*> estadia;
    public:
        Huesped();
        Huesped(string _nombre, string _email, string _password,bool _esFinger);
        void setEsFinger(bool);
        bool getEsFinger();
        bool tieneEstadiasActivas();
        DTHuesped* getDTHuesped();
        Estadia* getEstadia(int);
        set<Estadia*> getEstadias();
        void agregarEstadia(Estadia* estadia);
        void eliminarEstadia(Estadia*);
};


//EMPLEADO


class Notificacion;
class DTNotificacion;
class Habitacion;
class Hostal;
class DTEmpleado;



class Empleado : public Usuario,public IObserver{
    private:
        CargoEmpleado cargo;
        set<Notificacion*> notificaciones;
        Hostal* trabajo;
    public:
        Empleado(string nombre, string email, string password,CargoEmpleado cargo);
        DTEmpleado* getDTEmpleado();
        CargoEmpleado getCargo();
        Hostal* getTrabajo();
        void setCargo(CargoEmpleado _cargo);
        void setTrabajo(Hostal* h);
        void notificar(Notificacion* n);
        set<DTNotificacion*> getNotificaciones();
        void eliminarNotificaciones();
};
