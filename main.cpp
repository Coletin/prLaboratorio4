#include <iostream>
#include <string>
#include <set>
#include "Tipos/tipos.h"

using namespace std;

int main(){
    int i = 0;
    while(i!=21){
        cout << "1-Alta de Usuario" << "\n";
        cout << "2-Alta de Hostal" << "\n";
        cout << "3-Alta de Habitacion"<< "\n";
        cout << "4-Asignar empleado a hostal"<< "\n";
        cout << "5-Realizar Reserva"<< "\n";
        cout << "6-Consultar top 3 hostales"<< "\n";
        cout << "7-Registrar Estadia"<< "\n";
        cout << "8-Finalizar Estadia"<< "\n";
        cout << "9-Calificar Estadia"<< "\n";
        cout << "10-Comentar Calificacion"<< "\n";
        cout << "11-Consulta de Usuario"<< "\n";
        cout << "12-Consulta de Hostal"<< "\n";
        cout << "13-Consulta de Reserva"<< "\n";
        cout << "14-Consulta de Estadia"<< "\n";
        cout << "15-Baja de Reserva"<< "\n";
        cout << "16-Subscribirse a notificaciones"<< "\n";
        cout << "17-Consulta de notificaciones"<< "\n";
        cout << "18-Eliminar Subscripcion"<< "\n";
        cout << "19-Modificar fecha del sistema"<< "\n";
        cout << "20-Cargar datos predefinidos"<< "\n";
        cout << "21-Salir"<< "\n";
        cin >> i;
        switch(i){
            case 1:

            break;
            case 2:
            break;
            case 3:
            break;
            case 4:
            break;
            case 5:
            break;
            case 6:
            break;
            case 7:
            break;
            case 8:
            break;
            case 9:
            break;
            case 10:
            break;
            case 11:
            break;
            case 12:
            break;
            case 13:
            break;
            case 14:
            break;
            case 15:
            break;
            case 16:
            break;
            case 17:
            break;
            case 18:
            break;
            case 19:
            break;
            case 20:
            break;
            case 21:
            break;
            default:
            cout << "La opcion seleccionada no es valida \n";
        };
    }
    return 0;
}
