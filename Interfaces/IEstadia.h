#include <set>

using namespace std;

class DTHostal;
class DTReserva;
class DTEstadia;

class IEstadia{
    public:
        virtual set<DTHostal*> listarHostales();
        virtual set<DTReserva*> listarReservas(string email, string hostal);
        virtual void registrarEstadia(string email, int codigo);
        virtual bool existenEstadiasActivas(string email, string hostal);
        virtual void finalizarEstadia(string email);
        virtual set<DTEstadia*> obtenerEstadiasFinalizadas(string email, string hostal);
        virtual void crearCalificacion(string email, string hostal, string comentario, int valor);
};