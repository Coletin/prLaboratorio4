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
        int estadiaMem;
        static UsuarioControlador * instancia;
        void limpiarMemoria();
        UsuarioControlador();
    public:
        static UsuarioControlador * getInstancia();
        void cargarDatosUsuario(string nombre, string contrasenia);
        void crearHuesped(bool esFinger);
        void crearEmpleado(CargoEmpleado cargo);
        bool indicarEmail(string email);
        void persistirUsuario();
        void cancelarCreacionUsuario();
        set<DTUsuario*> listarUsuarios();
        DTEmpleado* datosEmpleado(string email);
        DTHuesped* datosHuesped(string email);
        set<DTCalificacion*> listarCalificacion(string mail);
        set<DTCalificacion*> listarCalificacionSinResponder(string mail);
        void seleccionarCalificacion(int codigo);//codigo = Codigo de la estadia
        void responderComentario(string comentario);
        set<DTEmpleado*> obtenerEmpleados();
        void subscribirseANotificaciones(string);
        void desubscribirseDeNotificaciones(string);
        set<DTNotificacion*> listarNotificaciones(string);
        void eliminarNotificaciones(string);
        bool existeUsuario(string email);
        bool existeEmpleado(string email);
        bool existeHuesped(string email);
};