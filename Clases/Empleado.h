#include <iostream>
#include <string>
#include <set>
#include "tipos.h"
#include "Usuario.h"
#include "IObserver.h"

class Notificacion;
class Hostal;
class Habitacion;


class Empleado : public Usuario,public IObserver{
    private:
        CargoEmpleado cargo;
        set<Notificacion*> notificaciones;
        Hostal* trabajo;
    public:
        set<DTEstadia*> getEstadias();
        DTHabitacion getHabDis(DataR datar);
        Habitacion getHabNum(int numeroHab);
        DTEmpleado getDTEmpleado();
        void setTrabajo(Hostal h);
        void notificar(Notificacion n);
};