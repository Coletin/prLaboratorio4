#include "../Interfaces/IHostal.h"
#include "../Controladores/HostalControlador.h"
#include "../Controladores/ReservaControlador.h"
#include "../Controladores/EstadiaControlador.h"
#include "../Controladores/RelojControlador.h"
#include "../Controladores/UsuarioControlador.h"

class Fabrica{
    public:
        IHostal getIHostal();
        IReserva getIReserva();
        IUsuario getIUsuario();
        IEstadia getIEstadia();
        IReloj getIReloj();   
};