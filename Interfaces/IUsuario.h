#include <set>
#include <string>

#ifndef CargoEmpleado
#include "../Tipos/CargoEmpleado.h"

using namespace std;

class DTUsuario;
class DTEmpleado;
class DTHuesped;
class DTCalificacion;
class DTNotificacion;


class IUsuario{
    public:
        virtual void cargarDatosUsuario(string nombre, string contrasenia) = 0;
        virtual void crearHuesped(bool esFinger) = 0;
        virtual void crearEmpleado(CargoEmpleado cargo) = 0;
        virtual bool indicarEmail(string email) = 0;
        virtual void persistirUsuario() = 0;
        virtual void cancelarCreacionUsuario() = 0;
        virtual set<DTUsuario*> listarUsuarios() = 0;
        virtual DTEmpleado* datosEmpleado(string email) = 0;
        virtual DTHuesped* datosHuesped(string email) = 0;
        virtual set<DTCalificacion*> listarCalificacion(string mail) = 0;
        virtual set<DTCalificacion*> listarCalificacionSinResponder(string mail) = 0;
        virtual void seleccionarCalificacion(int codigo) = 0;//codigo = Codigo de la estadia
        virtual void responderComentario(string comentario){};
        virtual set<DTEmpleado*> obtenerEmpleados()= 0;
        virtual void subscribirseANotificaciones(string){};
        virtual void desubscribirseDeNotificaciones(string){};
        virtual set<DTNotificacion*> listarNotificaciones(string)=0;
        virtual void eliminarNotificaciones(string){};
        virtual bool existeUsuario(string email)=0;
        virtual bool existeEmpleado(string email)=0;
        virtual bool existeHuesped(string email)=0;
};
#endif