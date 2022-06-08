#include <iostream>
#include <string>
#include <set>
#include "../Tipos/tipos.h"
#include "../Clases/Usuario.h"
#include "../Clases/Estadia.h"


class Huesped : public Usuario{
    private:
        bool esFinger;
        set<Estadia*> estadia;
    public:
        Huesped();
        Huesped(string _nombre, string _email, string _password,bool _esFinger);
        void setEsFinger(bool);
        bool getEsFinger();
        DTHuesped getDTHuesped();
        Estadia getEstadia();
        void agregarEstadia(Estadia estadia);
};
