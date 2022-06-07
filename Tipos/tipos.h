#include <string>
#include <iostream>
#include <set>

using namespace std;

class DTUsuario{
    private:
     string nombre;
     string email;
     string contrasena;
    public:
     DTUsuario();
     DTUsuario(string, string, string);
     string getNombre();
     string getEmail();
     string getContrasena();
     virtual void toString();
};

class DTHuesped : public DTUsuario{
    private:
        bool esFinger;
    public:
        DTHuesped();
        DTHuesped(string, string, string, bool);
        bool getEsFinger();
        void toString();
};

class DTEmpleado : public DTUsuario{
    private:
        CargoEmpleado cargo;
    public:
        DTEmpleado();
        DTEmpleado(string, string, string, CargoEmpleado);
        CargoEmpleado getCargo();
        void toString();
};

class DTHabitacion{
    private:
        int numero;
        float precio;
        int capacidad;
    public:
        DTHabitacion(); 
        DTHabitacion(int, float, int);
        int getNumero();
        float getPrecio();
        int getCapacidad();
        void toString();
};

enum EstadoReserva{
    Abierta = 0,
    Cerrada = 1,
    Cancelada = 2
};

class DTFecha{
    private:
     int dia;
     int mes;
     int anio;
     int hora;
    public:
     DTFecha();
     DTFecha(int, int, int, int);
     int getDia();
     int getMes();
     int getAnio();
     int getHora();
     bool operator==(const DTFecha&);
     bool operator<=(const DTFecha&);
     bool operator>=(const DTFecha&);
     bool operator!=(const DTFecha&);
     bool operator<(const DTFecha&);
     bool operator>(const DTFecha&);
};

class DTReserva{
     private: 
        int codigo;
        DTFecha checkIn;
        DTFecha checkOut;
        EstadoReserva estado;
        float costo;
        int habitacion;
    public:
        DTReserva(int,DTFecha,DTFecha,enum EstadoReserva,float,int);
        DTReserva(int,DTFecha,DTFecha,enum EstadoReserva,int);
        int getCodigo();
        DTFecha getcheckIn(); 
        DTFecha getcheckOut();
        EstadoReserva getEstadoReserva();
        float getCosto();
        int getHabitacion(); 
        //~DTReserva();
        virtual void operacion() = 0;
};

class DataR{
    private:
        string hostal;
        DTFecha checkIn;
        DTFecha checkOut;
        bool esGrupal;
    public:
        DataR(string, DTFecha, DTFecha, bool);
        string getHostal();
        DTFecha getCheckIn();
        DTFecha getCheckOut();
        bool getEsGrupal();
};

class DTReservaIndividual : public DTReserva{
 public: 
    DTReservaIndividual(int,DTFecha,DTFecha,enum EstadoReserva,float,int);
    DTReservaIndividual(int,DTFecha,DTFecha,enum EstadoReserva,int);
    void operacion();
};

class DTReservaGrupal : public DTReserva{
 private: 
    DTHuesped** huespedes;
 public: 
    DTReservaGrupal(int,DTFecha ,DTFecha ,EstadoReserva,float,int,DTHuesped**);
    DTReservaGrupal(int,DTFecha ,DTFecha ,EstadoReserva,int,DTHuesped**);
    DTHuesped** getHuespedes(); 
    void operacion();
};

class DTHostal{
    private:
        string nombre;
        string direccion;
        string telefono;
        float promedioClasi;
        set<DTCalificacion*> caliHabi;
    public:
        DTHostal();
        DTHostal(string, string, string, float, set<DTCalificacion*>);
        string getNombre();
        string getDireccion();
        string getTelefono();
        float getPromedioClasi();
        set<DTCalificacion*> getCaliHabi();
};

class DTCalificacion{
    private:
        int valor;
        string comentario;
        DTFecha fecha;
        int habitacion;
        string estadia;//codigo de la estadia asociada a la calificacion
    public:
        DTCalificacion();
        DTCalificacion(int, string, DTFecha, int, string);
        int getValor();
        string getComentario();
        DTFecha getFecha();
        int getHabitacion();
        string getEstadia();
};

enum CargoEmpleado{
    Administracion = 0,
    Limpieza = 1,
    Recepcion = 2,
    Infraestructura = 3
};

class DTRespuestaCalificacion{
    private:
        string comentario;
    public:
        DTRespuestaCalificacion(string);
        string getComentario();
};

class DTEstadia{
    private:
        string promo;
        DTFecha checkIn;
        DTFecha checkOut;
    public:
        DTEstadia(string, DTFecha, DTFecha);
        string getPromo();
        DTFecha getCheckIn();
        DTFecha getCheckOut();
};






ostream& operator<<(ostream&, DTReservaGrupal&);
ostream& operator<<(ostream&, DTReservaIndividual&);
ostream& operator<<(ostream&, DTFecha&);
istream& operator>>(istream&, DTFecha&);
ostream& operator<<(ostream&, DTReserva&);