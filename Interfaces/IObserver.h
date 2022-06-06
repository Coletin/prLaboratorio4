#include "Notificacion.h"

class IObserver{
    public:
        virtual void notificar(Notificacion n);
};