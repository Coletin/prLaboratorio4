#include <set>

using namespace std;

class DTHostal;
class DTReserva;
class DTEstadia;
class DTCalificacion;
class DTRespuestaCalificacion;

class IEstadia{
    public:
        virtual set<DTHostal*> listarHostales() = 0;
        virtual set<DTReserva*> listarReservas(string email, string hostal) = 0;
        virtual void registrarEstadia(string email, int codigo){};
        virtual bool existenEstadiasActivas(string email, string hostal) = 0;
        virtual void finalizarEstadia(int codigo){};
        virtual set<DTEstadia*> obtenerEstadiasFinalizadas(string email, string hostal) = 0;
        virtual void crearCalificacion(string email, string hostal, string comentario, int valor){};
        virtual set<DTEstadia*> listarEstadias(string)=0;
        virtual int getHabitacionEstadia(int)=0;
        virtual int getReservaEstadia(int)=0;
        virtual DTCalificacion* getCalificacion(int)=0;
        virtual DTRespuestaCalificacion* getRespuestaCalificacion(int)=0;
        virtual DTReserva* getReservaDT(int) = 0;
};