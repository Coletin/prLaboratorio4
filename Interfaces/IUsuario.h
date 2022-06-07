#include <set>
#include "../Tipos/tipos.h"

class IUsuario{
    public:
        virtual void cargarDatosUsuario(string nombre, string contrasenia);
        virtual void crearHuesped(bool esFinger);
        virtual void crearEmpleado(CargoEmpleado cargo);
        virtual bool indicarEmail(string email);
        virtual bool persistirUsuario();
        virtual void cancelarCreacionUsuario();
        virtual set<DTUsuario*> listarUsuarios();
        virtual DTEmpleado datosEmpleado(string email);
        virtual DTHuesped datosHuesped(string email);
        virtual set<DTCalificacion*> listarCalificacion(string mail);
        virtual void seleccionarCalificacion(string codigo);//codigo = Codigo de la estadia
        virtual void responderComentario(string comentario);
};