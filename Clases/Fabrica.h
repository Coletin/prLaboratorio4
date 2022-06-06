class IHostal;
class IReserva;
class IUsuario;
class IEstadia;
class IReloj;

class Fabrica{
    public:
        IHostal getIHostal();
        IReserva getIReserva();
        IUsuario getIUsuario();
        IEstadia getIEstadia();
        IReloj getIReloj();   
};