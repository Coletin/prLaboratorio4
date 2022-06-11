#include <set>
#include "../Interfaces/IUsuario.h"

class DTUsuario;
class DTEmpleado;
class DTHuesped;
class DTCalificacion;


class UsuarioControlador:public IUsuario{
    private:
        DTUsuario * usuarioACrear;
        string nombreACrear;
        string emailACrear;
        string contraseniaACrear;
        static UsuarioControlador * instancia;
        void limpiarMemoria();
    public:
        static UsuarioControlador * getInstancia();
        void cargarDatosUsuario(string nombre, string contrasenia);
        void crearHuesped(bool esFinger);
        void crearEmpleado(CargoEmpleado cargo);
        bool indicarEmail(string email);
        bool persistirUsuario();
        void cancelarCreacionUsuario();
        set<DTUsuario*> listarUsuarios();
        DTEmpleado* datosEmpleado(string email);
        DTHuesped* datosHuesped(string email);
        set<DTCalificacion*> listarCalificacion(string mail);
        void seleccionarCalificacion(string codigo);//codigo = Codigo de la estadia
        void responderComentario(string comentario);
};