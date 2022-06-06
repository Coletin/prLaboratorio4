#include <iostream>
#include <string>
#include <set>
#include "tipos.h"

class ReservaGrupal : public Reserva{
    private:

    public:
     ReservaGrupal(int,DTFecha,DTFecha,EstadoReserva); 
     ~ReservaGrupal(); 
     virtual float calcularCosto();
     virtual int cantidadHuespedes();
};