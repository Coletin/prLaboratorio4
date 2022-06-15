#include <iostream>
#include <string>
#include <set>

using namespace std;

class DTRespuestaCalificacion;

class RespuestaCalificacion{
    private:
        string comentario;
    public:
        RespuestaCalificacion();
        RespuestaCalificacion(string);
        ~RespuestaCalificacion(){};
        DTRespuestaCalificacion* getDTRespuestaCalificacion();
        void setComentario(string comentario);
        string getComentario();
};