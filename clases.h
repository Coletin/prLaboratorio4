#include <iostream>
#include <string>
#include <set>
#include "tipos.h"

using namespace std;

class Notificacion{
    private:
        bool visto;
        string autor;
        int puntaje;
        string comentario;
    public:
        Notificacion();
        Notificacion(bool visto, string autor, int puntaje, string comentario);
        ~Notificacion();
        void setVisto(bool);
        void setAutor(string);
        void setPuntaje(int);
        void setComentario(string);
        bool getVisto();
        string getAutor();
        int getPuntaje();
        string getComentario();
};

class Habitacion{
    private:
     int numero;
     float precio;
     int capacidad;
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
    public:
        bool getEsFinger();
        DTHuesped getDTHuesped();
        Estadia getEstadia();
        void agregarEstadia(Estadia estadia);
};

class Empleado : public Usuario{
    private:
        CargoEmpleado cargo;
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
