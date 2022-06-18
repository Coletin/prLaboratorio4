#include <set>
#include <string>

#include "../Tipos/CargoEmpleado.h"

using namespace std;

class DTHostal;
class DTEmpleado;
class DTReserva;
class DTCalificacion;
class DTHabitacion;

class IHostal{
    public:
        virtual void agregarHostal(string nombre, string direccion, string telefono){};
        virtual void asignarEmpleado(string emailN, CargoEmpleado cargoN){};
        virtual void cancelarAsignacion(){};
        virtual void confirmarAsigncacion(){};
        virtual void finalizar(){};
        virtual set<DTHostal*> listarHostales() = 0;
        virtual set<DTEmpleado*> seleccionarHostal(string nom) = 0;
        virtual void seleccionarHostalVar(string nombre){};
        virtual void ingresarHabitacion(int numero, float precio, int capacidad){};
        virtual void persistirHabitacion(){};
        virtual set<DTReserva*> listarReservas() = 0;
        virtual void cancelarCreacionHabitacion(){};
        virtual set<DTHostal*> topTres() = 0;
        virtual set<DTCalificacion*> calificacionesHostal(string nom) = 0; 
        virtual void liberarMemoriaTop3(){};
        virtual bool existeHostal(string _nombre)=0;
        virtual bool habitacionEnHostal(int, string) = 0;
        virtual set<DTHabitacion*> listarHabitacionesHostal(string) = 0;
};