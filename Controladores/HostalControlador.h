#include <set>
#include "../Tipos/tipos.h"

class HostalControlador{
    private:
        string emailN;
        CargoEmpleado cargoN;
        string nom;
        set<DTHostal*> t3;
        static HostalControlador * instancia;
    public:
        static HostalControlador * getInstancia();
        void agregarHostal(string nombre, string direccion, string telefono);
        void asignarEmpleado(string nomN, string emailN, CargoEmpleado cargoN);
        void cancelarAsignacion();
        void confirmarAsigncacion();
        void finalizar();
        set<DTHostal*> listarHostales();
        DTEmpleado seleccionarHostal(string nom);
        void seleccionarHostalVar(string nombre);
        DTHabitacion ingresarHabitacion(int numero, float precio, int capacidad);
        void persistirHabitacion();
        set<DTReserva*> listarReservas();
        void cancelarCreacionHabitacion();
        set<DTHostal*> topTres();
        set<DTCalificacion*> calificacionesHostal(string nom); 
};