#include <iostream>
#include <string>
#include <set>
#include "tipos.h"

class ReservaIndividual : public Reserva{
    private:

    public:
     ReservaIndividual(int,DTFecha,DTFecha,EstadoReserva);
     ~ReservaIndividual();
     virtual float calcularCosto();
};