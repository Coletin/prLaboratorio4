#include <iostream>
#include <string>
#include <set>
#include "Tipos/tipos.h"
#include "Clases/Fabrica.h"
#include "Interfaces/IHostal.h"
#include "Interfaces/IEstadia.h"
#include "Interfaces/IReserva.h"
#include "Interfaces/IObserver.h"
#include "Interfaces/IReloj.h"
#include "Interfaces/Iusuario.h"

using namespace std;

int main(){
    Fabrica* f = new Fabrica();
    IHostal* controladorHostal = f->getIHostal();
    IReloj* controladorReloj = f->getIReloj();
    IReserva* controladorReserva = f->getIReserva();
    IEstadia* controladorEstadia = f->getIEstadia();
    IUsuario* controladorUsuario = f->getIUsuario();
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
            case 20: {

            //E1

            //E2

            //E3

            //E4

            //E5


            //H1

            //H2

            //H3

            //H4

            //H5

            //H6


            //HO1
            controladorHostal->agregarHostal("La posada finger", "Av de la playa 123, Maldonado", "099111111");

            //HO2
            controladorHostal->agregarHostal("Mochileros", "Rambla Costanera 333, Rocha", "42579512");

            //HO3
            controladorHostal->agregarHostal("El Pony Pisador", "Bree (preguntar por Gandalf)", "000");

            //HO4
            controladorHostal->agregarHostal("Altos de Fing", "Av del Toro 1424", "099892992");

            //HO5
            controladorHostal->agregarHostal("Caverna Lujuriosa", "Amaya 2515", "233233235");


            //Habitaciones

            //HA1

            //HA2

            //HA3

            //HA4

            //HA5

            //HA6
            

            //AsignarEmpleados
            controladorHostal->seleccionarHostalVar("La posada finger");
            controladorHostal->asignarEmpleado("emilia@mail.com", CargoEmpleado::Recepcion);
            controladorHostal->confirmarAsigncacion();
            controladorHostal->seleccionarHostalVar("Mochileros");
            controladorHostal->asignarEmpleado("leo@mail.com", CargoEmpleado::Recepcion);
            controladorHostal->confirmarAsigncacion();
            controladorHostal->seleccionarHostalVar("Mochileros");
            controladorHostal->asignarEmpleado("alina@mail.com", CargoEmpleado::Administracion);
            controladorHostal->confirmarAsigncacion();
            controladorHostal->seleccionarHostalVar("El Pony Pisador");
            controladorHostal->asignarEmpleado("barli@mail.com", CargoEmpleado::Recepcion);
            controladorHostal->confirmarAsigncacion();


            //Reservas

            //R1

            //R2

            //R3

            //R4


            //Crear Estadias
            DTFecha* fechaSistema = new DTFecha(1,5,2022,18);//Dia,Mes,Año,Hora(0-23)
            controladorReloj->setFecha(fechaSistema);
            //agregar ES1

            fechaSistema = new DTFecha(4,1,2001,21);
            controladorReloj->setFecha(fechaSistema);
            //agregar ES2

            fechaSistema = new DTFecha(4,1,2001,21);
            controladorReloj->setFecha(fechaSistema);
            //agregar ES3

            fechaSistema = new DTFecha(4,1,2001,21);
            controladorReloj->setFecha(fechaSistema);
            //agregar ES4

            fechaSistema = new DTFecha(4,1,2001,21);
            controladorReloj->setFecha(fechaSistema);
            //agregar ES5

            fechaSistema = new DTFecha(7,6,2022,18);
            controladorReloj->setFecha(fechaSistema);
            //agregar ES6


            //Finalizar Estadias
            fechaSistema = new DTFecha(10,5,2022,9);
            controladorReloj->setFecha(fechaSistema);
            //finalizar ES1

            fechaSistema = new DTFecha(5,1,2001,2);
            controladorReloj->setFecha(fechaSistema);
            //finalizar ES2

            fechaSistema = new DTFecha(15,6,2022,22);
            controladorReloj->setFecha(fechaSistema);
            //finalizar ES6



            //Calificar Estadias
            fechaSistema = new DTFecha(11,5,2022,18);
            controladorReloj->setFecha(fechaSistema);
            //agregar C1

            fechaSistema = new DTFecha(5,1,2001,3);
            controladorReloj->setFecha(fechaSistema);
            //agregar C2

            fechaSistema = new DTFecha(15,6,2022,23);
            controladorReloj->setFecha(fechaSistema);
            //agregar C3


            //Comentar Calificaciones
            fechaSistema = new DTFecha(6,1,2001,15);
            controladorReloj->setFecha(fechaSistema);
            //agregar comentario C2
            controladorUsuario->responderComentario("Desapareció y se fue sin pagar");
            break;
            }
            case 21:
            break;
            default:
            cout << "La opcion seleccionada no es valida \n";
        };
    }
    return 0;
}
