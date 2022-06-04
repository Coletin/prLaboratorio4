#include <string>

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