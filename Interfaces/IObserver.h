class Notificacion;

class IObserver{
    public:
        virtual void notificar(Notificacion* n){};
};