#include <iostream>
#include <string>
#include <set>
#include "../Tipos/tipos.h"
#include "Usuario.h"
#include "../Interfaces/IObserver.h"

class Notificacion;
class Hostal;
class Habitacion;


class Empleado : public Usuario,public IObserver{
    private:
        CargoEmpleado cargo;
        set<Notificacion*> notificaciones;
        Hostal* trabajo;
    public:
        Empleado(string nombre, string email, string password,CargoEmpleado cargo);
        DTEmpleado getDTEmpleado();
        CargoEmpleado getCargo();
        Hostal* getTrabajo();
        void setCargo(CargoEmpleado _cargo);
        void setTrabajo(Hostal h);
        void notificar(Notificacion n);
};

//operciones de empleado mal en el DCD