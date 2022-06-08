#include "ReservaIndividual.h"
#include "../Tipos/tipos.h"


ReservaIndividual::ReservaIndividual(int _codigo,DTFecha _checkIn,DTFecha _checkOut,EstadoReserva _estado):Reserva(_codigo, _checkIn, _checkOut, _estado){
};

float ReservaGrupal::calcularCosto(){
    int i = 0;
    int fing = 0;
    float costo = 0;
    // float costo = (this->getHabitacion()->getPrecio() * diasDeReserva(this->getCheckIn(),this->getCheckOut()));
    if(fing > 1)
        costo = costo - costo*0.3;
    return costo;
}

//falta una referencia a la habitacion por lo menos en la reserva