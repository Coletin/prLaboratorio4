#include "../Clases/Notificacion.h"

Notificacion::Notificacion(){
    visto = false;
    autor = "";
    puntaje = 1;
    comentario = "";
}

Notificacion::Notificacion(bool _visto, string _autor, int _puntaje, string _comentario){
    visto = _visto;
    autor = _autor;
    puntaje = _puntaje;
    comentario = _comentario;
}

void Notificacion::setComentario(string _comentario){ comentario = _comentario; }
void Notificacion::setVisto(bool _visto){ visto = _visto; }
void Notificacion::setAutor(string _autor){ autor = _autor; }
void Notificacion::setPuntaje(int _puntaje){ puntaje = _puntaje; }
bool Notificacion::getVisto(){ return visto; }
string Notificacion::getAutor(){ return autor; }
int Notificacion::getPuntaje(){ return puntaje; }
string Notificacion::getComentario(){ return comentario; }



/*
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
*/