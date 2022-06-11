#include <set>

using namespace std;

class DTHostal;
class DTReserva;
class DTEstadia;

class IEstadia{
    public:
        virtual set<DTHostal*> listarHostales() = 0;
        virtual set<DTReserva*> listarReservas(string email, string hostal) = 0;
        virtual void registrarEstadia(string email, int codigo){};
        virtual bool existenEstadiasActivas(string email, string hostal) = 0;
        virtual void finalizarEstadia(int codigo){};
        virtual set<DTEstadia*> obtenerEstadiasFinalizadas(string email, string hostal) = 0;
        virtual void crearCalificacion(string email, string hostal, string comentario, int valor){};
};