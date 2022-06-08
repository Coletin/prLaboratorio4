#include "../Clases/Huesped.h"

void Huesped::setEsFinger(bool _esFinger){ esFinger = _esFinger; };
bool Huesped::getEsFinger(){ return esFinger; }

Huesped::Huesped():Usuario(){
    esFinger = false;
    set<Estadia*> lista;
    estadia = lista;
}

Huesped::Huesped(string _nombre, string _email, string _password,bool _esFinger):Usuario(_nombre, _email, _password){
    esFinger = _esFinger;
    set<Estadia*> lista;
    estadia = lista;
}

DTHuesped Huesped::getDTHuesped(){
    DTHuesped respuesta = DTHuesped(nombre,email,password,esFinger);
    return respuesta;
}

Estadia Huesped::getEstadia(){
    Estadia respuesta = Estadia();
    return respuesta;    
}


void Huesped::agregarEstadia(Estadia _estadia){
    //estadia.insert(_estadia);
}

/*
class Huesped : public Usuario{
    private:
        bool esFinger;
        set<Estadia*> estadia;
    public:
        bool getEsFinger();
        DTHuesped getDTHuesped();
        Estadia getEstadia();
        void agregarEstadia(Estadia estadia);
};

*/