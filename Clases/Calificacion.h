#include <iostream>
#include <string>
#include <set>
#include "../Tipos/tipos.h"


class Estadia;
class RespuestaCalificacion;

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
        void setEstadia(Estadia* estadia);
        void setHostal(string nombre);
        void setValor(int valor);
        void setComentario(string comentario);
        void setFecha(DTFecha fecha);
        void setHabitacion(int habitacion);
        int getValor();
        string getComentario();
        DTFecha getFecha();
        int getHabitacion();
        Estadia* getEstadia();
        RespuestaCalificacion* getRespuestaCalificacion();
};
