#include "ReservaGrupal.h"
#include "Reserva.h"
#include "../Tipos/tipos.h"

ReservaGrupal::ReservaGrupal(int _codigo,DTFecha _checkIn,DTFecha _checkOut,EstadoReserva _estado):Reserva(_codigo, _checkIn, _checkOut, _estado){
};

float ReservaGrupal::calcularCosto(){
    int fing = 0;
    int i = 0;
    set<Huesped*>::iterator it;
    it = this->getHuespedes().begin();
    while (it != this->getHuespedes().end()){
        Huesped *current = *it;
        ++i;
        if(current->getEsFinger()) fing++;
        ++it;
    }
    float costo = (this->getHabitacion()->getPrecio() * diasEntre(this->getCheckIn(),this->getCheckOut())) * (i);
    if(fing > 1)
        costo = costo - costo*0.3;
    return costo;
}


int ReservaGrupal::cantidadHuespedes(){
    int i = 0;
    set<Huesped*>::iterator it;
    it = this->getHuespedes().begin();
    while (it != this->getHuespedes().end()){
        Huesped *current = *it;
        ++i;
        ++it;
    }
    return i;
}

