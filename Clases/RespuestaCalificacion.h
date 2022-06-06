#include <iostream>
#include <string>
#include <set>
#include "tipos.h"

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