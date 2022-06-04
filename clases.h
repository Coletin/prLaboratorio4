#include <iostream>
#include <string>
#include <set>
#include "tipos.h"
#include "Notificacion.h"
#include "IObserver.h"


using namespace std;

class ColeccionesHandler {
    private:
        static ColeccionesHandler * instancia;
        ColeccionesHandler();
        set<Usuario*> usuarios;
        set<Hostal*> hostales;
        set<Reserva*> reservas;
    public:
        static ColeccionesHandler * getInstancia();
        void addHostal(Hostal hostalN);
        Empleado getUsuario(string email);
        Hostal getHostal(string nombre);
        set<DTHostal*> getHostalCol();
        set<DTEmpleado*> getEmpleadoNoAsigCol(string nom);
        set<DTUsuario*> getUsuarios();
        void agregarCalificacion(Calificacion c);
        Reserva reserva(string email, int codigo);
        void agregarEstadia(Estadia e);
        Empleado getEmpleado(string email);
        IObserver getEmpleadoObs(string email);
        Huesped getHuesped(string email);
        Hostal getReservasHostal(string nomH);
        void eliminarReserva(int codR);
        Reserva getReserva(int codR);
        set<DTHuesped*> getHuespedes();
        void agregarReserva(Reserva r);
        void agregarUsuario(Usuario u);
        bool existeUsuario(string email);
        Reserva devolverReserva(int codigo);
};

class Habitacion{
    private:
     int numero;
     float precio;
     int capacidad;
     set<Reserva*> reservas;
     Hostal* hostal;
    public:
     Habitacion();
     Habitacion(int, float, int);
     int getNumero();
     void setNumero(int _numero);
     float getPrecio();
     void setPrecio(float _precio);
     int getCapacidad();
     void setCapacidad(int _capacidad);
     bool esDeHostal(string nomH);
     bool estaLibre(DataR data); 
     DTHabitacion getDT();
     void asociarRevHab(Habitacion hab);
     set<DTEstadia*> getEstadiasDT(); 
     set<DTReserva*> getReservasFinalizadasAsociadas();
     bool existeEstadiasActivas(string email, string nombre);
     set<DTReserva*> getReservasAsociadas(string nombre, string email);
     int getHabEstadia(Estadia est);
};

class Usuario{
    private:
     string nombre;
     string email;
     string password;
    public:
     Usuario();
     Usuario(string, string, bool);
     virtual ~Usuario() = 0;
     string getEmail();
     string getNombre();
     string getPassword();
     void setEmail(string email);
     void setNombre(string nombre);
     void setPassword(string password);
};

class Huesped : public Usuario{
    private:
        bool esFinger;
        Estadia* estadia;
    public:
        bool getEsFinger();
        DTHuesped getDTHuesped();
        Estadia getEstadia();
        void agregarEstadia(Estadia estadia);
};

class Empleado : public Usuario,public IObserver{
    private:
        CargoEmpleado cargo;
        set<Notificacion*> notificaciones;
        Hostal* trabajo;
    public:
        set<DTEstadia*> getEstadias();
        DTHabitacion getHabDis(DataR datar);
        Habitacion getHabNum(int numeroHab);
        DTEmpleado getDTEmpleado();
        void setTrabajo(Hostal h);
        void notificar(Notificacion n);
};


class Reserva{
    private:
     int codigo;
     DTFecha checkIn;
     DTFecha checkOut;
     EstadoReserva estado;
     set<Estadia*> estadias;
     set<Huesped*> huespedes;
    public:
     Reserva(int,DTFecha,DTFecha,EstadoReserva); 
     ~Reserva();
     virtual float calcularCosto() = 0;
     int getCodigo();
     DTFecha getCheckIn();
     DTFecha getCheckOut();
     EstadoReserva getEstado();
     void setCodigo(int&);
     void setCheckIn(DTFecha&);
     void setCheckOut(DTFecha&);
     void setEstado(EstadoReserva&);
};

class ReservaGrupal : public Reserva{
    private:

    public:
     ReservaGrupal(int,DTFecha,DTFecha,EstadoReserva); 
     ~ReservaGrupal(); 
     virtual float calcularCosto();
     virtual int cantidadHuespedes();
};

class ReservaIndividual : public Reserva{
    private:

    public:
     ReservaIndividual(int,DTFecha,DTFecha,EstadoReserva);
     ~ReservaIndividual();
     virtual float calcularCosto();
};

class Hostal{
    private:
        string nombre;
        string direccion;
        string telefono;
        set<Habitacion*> habitaciones;
        set<Calificacion*> calificaciones;
    public:
        set<DTEstadia*> getEstadiasDT();
        DTHabitacion getHabDis(DataR datar);
        Habitacion getHabNum(int numeroHab);
        float getPromCal();
        set<DTCalificacion*> getCalifs();
        set<DTHabitacion*> getHabitaciones();
        DTHostal getDT();
        bool existeEstadiasActivas(string email, string nombre);
        set<DTReserva*> getReservasFinalizadasAsociadas(string email, string nombre);
        set<DTReserva*> getReservasAsociadas(string nombre, string email);
        void agregarCalificacion(Calificacion cal);
        int getHabEstadia(Estadia est);
};

class Calificacion{
    private:
        int valor;
        string comentario;
        DTFecha fecha;
        int habitacion;
        Estadia* estadia;
        RespuestaCalificacion* respuesta;
    public:
        Calificacion(int,string,DTFecha,int);
        Calificacion();
        ~Calificacion();
        DTCalificacion getDT();
        DTRespuestaCalificacion obtenerRespuestaCalificacion();
        void setEstadia(string promo);
        void setHostal(string nombre);
        void setValor(int valor);
        void setComentario(string comentario);
        void setFecha(DTFecha fecha);
        void setHabitacion(int habitacion);
        int getValor();
        string getComentario();
        DTFecha getFecha();
        int getHabitacion();
};

class RespuestaCalificacion{
    private:
        string comentario;
    public:
        RespuestaCalificacion(string);
        RespuestaCalificacion();
        ~RespuestaCalificacion();
        DTRespuestaCalificacion getDTRespuestaCalificacion();
        void setComentario(string comentario);
        string getComentario();
};

class Estadia{
    private:
        string promo;
        DTFecha checkIn;
        DTFecha checkOut;
        Huesped* huesped;
        Calificacion* calificacion;
    public:
        Estadia(string,DTFecha checkIn, DTFecha checkOut);
        Estadia();
        ~Estadia();
        string getPromo();
        DTFecha getCheckIn();
        DTFecha getCheckOut();
        void setPromo(string);
        void setCheckIn(DTFecha);
        void setCheckOut(DTFecha);
        DTEstadia getDTEstadia();
        bool existeEstadiaActiva();
        void setReserva(int codigo);
        void setHuesped(string email);
        DTReserva obtenerDatosReserva();
        DTRespuestaCalificacion obtenerDatosRespuestaCalificacion();
        DTCalificacion getDatosCalificacion();
        void setCalificacion(Calificacion c);
};
