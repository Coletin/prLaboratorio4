#include <set>
#include <string>
#include "../Tipos/CargoEmpleado.h"

using namespace std;

class DTHostal;
class DTEmpleado;
class DTHabitacion;
class DTReserva;
class DTCalificacion;

class IHostal{
    public:
        virtual void agregarHostal(string nombre, string direccion, string telefono);
        virtual void asignarEmpleado(string nomN, string emailN, CargoEmpleado cargoN);
        virtual void cancelarAsignacion();
        virtual void confirmarAsigncacion();
        virtual void finalizar();
        virtual set<DTHostal*> listarHostales();
        virtual DTEmpleado* seleccionarHostal(string nom);
        virtual void seleccionarHostalVar(string nombre);
        virtual DTHabitacion* ingresarHabitacion(int numero, float precio, int capacidad);
        virtual void persistirHabitacion();
        virtual set<DTReserva*> listarReservas();
        virtual void cancelarCreacionHabitacion();
        virtual set<DTHostal*> topTres();
        virtual set<DTCalificacion*> calificacionesHostal(string nom); 
};