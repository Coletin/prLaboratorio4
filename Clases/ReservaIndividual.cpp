#include "ReservaIndividual.h"
#include "../Tipos/tipos.h"


ReservaIndividual::ReservaIndividual(int _codigo,DTFecha _checkIn,DTFecha _checkOut,EstadoReserva _estado):Reserva(_codigo, _checkIn, _checkOut, _estado){
};

float ReservaIndividual::calcularCosto(){
    int i = 0;
    int fing = 0;
    float costo = 0;
    float costo = (this->getHabitacion()->getPrecio() * diasEntre(this->getCheckIn(),this->getCheckOut()));
    if(fing > 1)
        costo = costo - costo*0.3;
    return costo;
}