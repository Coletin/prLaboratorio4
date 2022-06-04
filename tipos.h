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
     DTUsuario(string nombre, string email, string contrasena);
     string getNombre();
     string getEmail();
     void toString();
     virtual void operacion() = 0;  
};

class DTHuesped : public DTUsuario{
    private:
        bool esFinger;
    public:
        DTHuesped(string nombre, string email, string contrasena, bool esFinger);
        bool getEsFinger();
};

class DTEmpleado : public DTUsuario{
    private:
        CargoEmpleado cargo;
    public:
        DTEmpleado(string nombre, string email, string contrasena, CargoEmpleado cargo);
        CargoEmpleado getCargo();
};

class DTHabitacion{
    private:
        int numero;
        float precio;
        int capacidad;
    public:
        DTHabitacion(); 
        DTHabitacion(int&, float&, int&);
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
    public:
     DTFecha();
     DTFecha(int, int, int);
     int getDia();
     int getMes();
     int getAnio();
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
        DTFecha chekIn;
        DTFecha checkOut;
        EstadoReserva estado;
        float costo;
        int habitacion;
    public: 
        DTReserva(int,DTFecha&,DTFecha&,enum EstadoReserva,float,int);
        DTReserva(int,DTFecha&,DTFecha&,enum EstadoReserva,int);
        int getCodigo();
        DTFecha getchekIn(); 
        DTFecha getchekOut();
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
        void setHostal(string);
        void setCheckIn(DTFecha);
        void setCheckOut(DTFecha);
        void setEsGrupal(bool);
};

class DTReservaIndividual : public DTReserva{
 private: 
    bool pagado;
 public: 
    DTReservaIndividual(int,DTFecha&,DTFecha&,enum EstadoReserva,float,int,bool);
    DTReservaIndividual(int,DTFecha&,DTFecha&,enum EstadoReserva,int,bool);
    bool getPagado(); 
    virtual void operacion();
};

class DTReservaGrupal : public DTReserva{
 private: 
    DTHuesped** huespedes;
 public: 
    DTReservaGrupal(int,DTFecha& ,DTFecha& ,EstadoReserva,float,int,DTHuesped**);
    DTReservaGrupal(int,DTFecha& ,DTFecha& ,EstadoReserva,int,DTHuesped**);
    DTHuesped** getHuespedes(); 
    virtual void operacion();
};

class DTHostal{
    private:
        string nombre;
        string direccion;
        string telefono;
        float promedioClasi;
        set<DTCalificacion*> caliHabi;
    public:
        DTHostal(string nombre, string direccion, string telefono, float promedioClasi, set<DTCalificacion*> caliHabi);
        string getNombre();
        string getDireccion();
        string getTelefono();
        float promedioClasi();
        set<DTCalificacion*> getCaliHabi();
};

class DTCalificacion{
    private:
        int valor;
        string comentario;
        DTFecha fecha;
        int habitacion;
    public:
        DTCalificacion(int valor, string comentario, DTFecha fecha, int habitacion);
        int getValor();
        string getComentario();
        DTFecha getFecha();
        int getHabitacion();
};

class DataR{
    private:
        string hostal;
        DTFecha checkIn;
        DTFecha checkOut;
        bool esGrupal;
    public:
        DataR(string hostal, DTFecha checkIn, DTFecha checkOut, bool esGrupal);
        string getHostal();
        DTFecha getCheckIn();
        DTFecha getCheckOut();
        bool getEsGrupal();
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
        DTEstadia(string promo, DTFecha checkIn, DTFecha checkOut);
        string getPromo();
        DTFecha getCheckIn();
        DTFecha getCheckOut();
};






ostream& operator<<(ostream&, DTReservaGrupal&);
ostream& operator<<(ostream&, DTReservaIndividual&);
ostream& operator<<(ostream&, DTFecha&);
istream& operator>>(istream&, DTFecha&);
ostream& operator<<(ostream&, DTReserva&);