#include <string>
#include <iostream>
#include <set>

using namespace std;

#include "../Tipos/CargoEmpleado.h"
#include "../Tipos/EstadoReserva.h"


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

class DTNotificacion{
    private:
        string autor;
        string comentario;
        int puntaje;
    public:
        DTNotificacion();
        DTNotificacion(string, int, string);
        string getAutor();
        string getComentario();
        int getPuntaje();
};

class DTCalificacion{
    private:
        int valor;
        string comentario;
        DTFecha* fecha;
        int habitacion;
        int estadia;//codigo de la estadia asociada a la calificacion
    public:
        DTCalificacion();
        DTCalificacion(int, string, DTFecha*, int, int);
        int getValor();
        string getComentario();
        DTFecha* getFecha();
        int getHabitacion();
        int getEstadia();
};

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
     virtual void toString(){};
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
        string trabajo;
    public:
        DTEmpleado();
        DTEmpleado(string, string, string, string, CargoEmpleado);
        CargoEmpleado getCargo();
        string getTrabajo();
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


class DTReserva{
     private: 
        int codigo;
        DTFecha checkIn;
        DTFecha checkOut;
        EstadoReserva estado;
        float costo;
        int habitacion;
    public:
        DTReserva(int,DTFecha,DTFecha,EstadoReserva,float,int);
        DTReserva(int,DTFecha,DTFecha,EstadoReserva,int);
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
        DataR();
        DataR(string, DTFecha, DTFecha, bool);
        string getHostal();
        DTFecha getCheckIn();
        DTFecha getCheckOut();
        bool getEsGrupal();
};

class DTReservaIndividual : public DTReserva{
 private:
    DTHuesped* huesped;
 public:
    DTReservaIndividual(int,DTFecha,DTFecha,EstadoReserva,float,int, DTHuesped*);
    DTReservaIndividual(int,DTFecha,DTFecha,EstadoReserva,int, DTHuesped*);
    DTHuesped* getHuesped();
    void operacion();
};

class DTReservaGrupal : public DTReserva{
 private: 
    set<DTHuesped*> huespedes;
 public: 
    DTReservaGrupal(int,DTFecha ,DTFecha ,EstadoReserva,float,int,set<DTHuesped*>);
    DTReservaGrupal(int,DTFecha ,DTFecha ,EstadoReserva,int,set<DTHuesped*>);
    set<DTHuesped*> getHuespedes(); 
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
        int codigo;
        string huesped;
    public:
        DTEstadia(string, DTFecha, DTFecha, int, string);
        string getPromo();
        DTFecha getCheckIn();
        DTFecha getCheckOut();
        int getCodigo();
        string getHuesped();
};


int diasEntre(DTFecha*, DTFecha*);



ostream& operator<<(ostream&, DTReservaGrupal&);
ostream& operator<<(ostream&, DTReservaIndividual&);
ostream& operator<<(ostream&, DTFecha&);
istream& operator>>(istream&, DTFecha&);
ostream& operator<<(ostream&, DTReserva&);

//hola