#include <set>

using namespace std;

class IObserver;
class Notificacion;


class Notificador{
    private:
     set<IObserver*> observers;
     static Notificador* instancia;
    public:
     static Notificador* getInstancia();
     void agregar(IObserver*);
     void eliminar(IObserver*);
     void modificar(Notificacion*);
};