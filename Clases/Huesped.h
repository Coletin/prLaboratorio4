#include <iostream>
#include <string>
#include <set>
#include "tipos.h"
#include "Usuario.h"

class Estadia;

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
