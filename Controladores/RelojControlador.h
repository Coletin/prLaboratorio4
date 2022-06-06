#include "../Tipos/tipos.h"

class RelojControlador{
    private:
        DTFecha fecha;
        static RelojControlador * instancia;
    public:
        static RelojControlador * getInstancia();
        void setFecha(DTFecha);
        DTFecha getFecha();
};