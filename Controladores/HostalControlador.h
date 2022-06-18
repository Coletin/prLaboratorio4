#include <set>
#include "../Interfaces/IHostal.h"

#ifndef CargoEmpleado
#include "../Tipos/CargoEmpleado.h"
#endif

class DTHostal;
class DTEmpleado;
class DTReserva;
class DTCalificacion;

class HostalControlador: public IHostal{
    private:
        string emailN;
        CargoEmpleado cargoN;
        string nom;
        int numero;
        int capacidad;
        float precio;
        set<DTHostal*> t3;
        static HostalControlador * instancia;
        HostalControlador();
    public:
        static HostalControlador * getInstancia();
        void agregarHostal(string nombre, string direccion, string telefono);
        void asignarEmpleado(string emailN, CargoEmpleado cargoN);
        void cancelarAsignacion();
        void confirmarAsigncacion();
        void finalizar();
        set<DTHostal*> listarHostales();
        set<DTEmpleado*> seleccionarHostal(string nom);
        void seleccionarHostalVar(string nombre);
        void ingresarHabitacion(int numero, float precio, int capacidad);
        void persistirHabitacion();
        set<DTReserva*> listarReservas();
        void cancelarCreacionHabitacion();
        set<DTHostal*> topTres();
        set<DTCalificacion*> calificacionesHostal(string nom); 
        void liberarMemoriaTop3();
        bool existeHostal(string _nombre);
        bool habitacionEnHostal(int, string);
        set<DTHabitacion*> listarHabitacionesHostal(string);
};