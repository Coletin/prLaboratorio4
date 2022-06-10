#include "../Tipos/tipos.h"
#include "../Interfaces/IReloj.h"

class RelojControlador:public IReloj{
    private:
        DTFecha fecha;
        static RelojControlador * instancia;
    public:
        static RelojControlador * getInstancia();
        void setFecha(DTFecha);
        DTFecha getFecha();
};