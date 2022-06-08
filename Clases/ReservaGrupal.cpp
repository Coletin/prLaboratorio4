#include "ReservaGrupal.h"
#include "Reserva.h"
#include "../Tipos/tipos.h"

ReservaGrupal::ReservaGrupal(int _codigo,DTFecha _checkIn,DTFecha _checkOut,EstadoReserva _estado):Reserva(_codigo, _checkIn, _checkOut, _estado){
};

float ReservaGrupal::calcularCosto(){
    int i = 0;
    int fing = 0;
    while(this->huespedes[i] != nullptr){
        if(this->huespedes[i]->getEsFinger())
            fing++;
        i++;
    }
    float costo = 0;
    // float costo = (this->getHabitacion()->getPrecio() * diasDeReserva(this->getCheckIn(),this->getCheckOut())) * (i);
    if(fing > 1)
        costo = costo - costo*0.3;
    return costo;
}

//falta una referencia a la habitacion

int ReservaGrupal::cantidadHuespedes(){
    int i = 0;
    while(this->huespedes[i] != nullptr){
        i++;
    }
    return i;
}

