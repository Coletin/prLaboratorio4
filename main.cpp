#include <iostream>
#include <string>
#include <set>
#include <conio.h>
#include "Tipos/tipos.h"
#include "Clases/Fabrica.h"
#include "Interfaces/IHostal.h"
#include "Interfaces/IEstadia.h"
#include "Interfaces/IReserva.h"
#include "Interfaces/IObserver.h"
#include "Interfaces/IReloj.h"
#include "Interfaces/Iusuario.h"



using namespace std;

void visualizarUsuarios();

//esta magia chequea si el string contiene solo numeros enteros no negativos. Agregarla a una funcion del sistema?
bool checkNumero(const string s){
  return s.find_first_not_of("0123456789") == string::npos; 
}

//cambiar por su version en linux al subir el codigo
void limpiarPantalla(){
    system("cls");
}

//pide un entero entre 1 y tope. mensajePedir es el mensaje que se muestra siempre mientras que mensajeError se muestra solamente cada vez que ingrese un numero mal.
int pedirEntero(string mensajePedir, string mensajeError, int tope){
    int respuesta = 0;
    bool primerMensaje = true;
    string lectura = "";
    while(respuesta > tope || respuesta < 1){
        limpiarPantalla();
        if(primerMensaje)
            primerMensaje = false;
        else
            cout << mensajeError << "\n";
        cout << mensajePedir;
        cin >> lectura;
        if(checkNumero(lectura))
            respuesta = std::stoi(lectura); //stoi convierte un string a un entero
    }
    return respuesta;
}

int pedirEnteroConCero(string mensajePedir, string mensajeError, int tope){
    int respuesta = -1;
    bool primerMensaje = true;
    string lectura = "";
    while(respuesta > tope || respuesta < 0){
        if(primerMensaje)
            primerMensaje = false;
        else
            cout << mensajeError << "\n";
        cout << mensajePedir;
        cin >> lectura;
        if(checkNumero(lectura))
            respuesta = std::stoi(lectura); //stoi convierte un string a un entero
    }
    return respuesta;
}

int main(){
    Fabrica* f = new Fabrica();
    IHostal* controladorHostal = f->getIHostal();
    IReloj* controladorReloj = f->getIReloj();
    IReserva* controladorReserva = f->getIReserva();
    IEstadia* controladorEstadia = f->getIEstadia();
    IUsuario* controladorUsuario = f->getIUsuario();
    int i = 0;

    //variables para creacion de empleado
    string nombreUsuarioCrear = "", claveUsuarioCrear = "", emailUsuarioCrear = "";
    bool emailDisponible = true, esFinger = false;
    CargoEmpleado cargoCrear = Administracion;
    int tipoUsuarioCrear = 0;

    while(i!=21){
        limpiarPantalla();
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
                limpiarPantalla();
                cout << "Ingrese nombre: ";
                cin.ignore();
                getline(cin,nombreUsuarioCrear);
                cout << "Ingrese clave: ";
                cin >> claveUsuarioCrear;
                controladorUsuario->cargarDatosUsuario(nombreUsuarioCrear,claveUsuarioCrear);
                nombreUsuarioCrear = "";
                claveUsuarioCrear = "";
                
                do{
                    limpiarPantalla();
                    if(!emailDisponible)
                        cout << "El email indicado ya se encuentra en uso.\n";
                    cout << "Ingrese email: ";
                    cin >> emailUsuarioCrear;
                    emailDisponible = controladorUsuario->indicarEmail(emailUsuarioCrear);
                }while(!emailDisponible);
                emailUsuarioCrear = "";

                tipoUsuarioCrear = pedirEntero("1-Empleado\n2-Huesped\nIndique el tipo de usuario: ","Opcion incorrecta ",2);

                if(tipoUsuarioCrear == 1){
                    tipoUsuarioCrear = pedirEntero("1-Administracion \n2-Limpieza \n3-Recepcion \n4-Infraestructura \nIndique el cargo del empleado: ","Opcion incorrecta ",4);
                    if(tipoUsuarioCrear == 1)
                        cargoCrear = Administracion;
                    else if(tipoUsuarioCrear == 2)
                        cargoCrear = Limpieza;
                    else if(tipoUsuarioCrear == 3)
                        cargoCrear = Recepcion;
                    else
                        cargoCrear = Infraestructura;                    
                    controladorUsuario->crearEmpleado(cargoCrear);
                }else{
                    tipoUsuarioCrear = pedirEntero("1-Si \n2-No \nEl huesped a crear, es finger? ","Opcion incorrecta ",2);
                    esFinger = tipoUsuarioCrear == 1;
                    controladorUsuario->crearHuesped(esFinger);
                }

                tipoUsuarioCrear = pedirEntero("1-Si \n2-No \nDesea persistir el usuario? ","Opcion incorrecta ",2);
                if(tipoUsuarioCrear == 1){
                    controladorUsuario->persistirUsuario();
                    cout << "Usuario persistido. Presione cualquier tecla para continuar.";
                }
                else{
                    controladorUsuario->cancelarCreacionUsuario();
                    cout << "Operacion cancelada. Presione cualquier tecla para continuar.";
                }
                getch();//esperamos que ingrese cualquier caracter
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
            case 9:{

/*****************************************************************************************/
/******************************  9 - CALIFICAR ESTADIA  ******************************/
/*****************************************************************************************/ 
            std::cout<<"\n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n "<<endl;
            int numero=0;
            string email;
            set<DTHostal*> hostales= controladorHostal->listarHostales();
            if(hostales.size()==0){ std::cout<<"NO HAY HOSTALES EN EL SISTEMA"<<endl;}
            else{ 
            std::cout<<"****************  9 - CALIFICAR ESTADIA  ************"<<endl;

            std::cout<<" \n \n \n Seleccione Hostal: \n"<<endl;   
        
            std::cout<<" \n == HOSTALES: == \n"<<endl;
           //std::cout<<"Digite Hostal Seleccionado: "<<endl;
            auto it= hostales.begin();
                while (it != hostales.end())
                {
                    DTHostal* actual = *it;
                    ++numero;
                    std::cout<<numero<<".-Nombre Hostal: "<<actual->getNombre()<<endl;
                    ++it;
                }
            bool valido=true;
                while(valido){
                    std::cout<<"Digite Hostal Seleccionado: "<<endl;
                    std::cin>>numero;
                    if (numero>0 && numero<=hostales.size()) {
                        valido=false;} else { std::cout<<"Elija un numero de hostal valido por favor!"<<endl;};
                }
            DTHostal* nuevo = *it;
            it= hostales.begin();
            int valor=0;
                while ((valor)!=numero)
                {
                    nuevo = *it;
                    valor++;
                    ++it;
                }

               std::cout<<"Hostal Seleccionado:"<<nuevo->getNombre()<<endl; 
               std::cout<<"Indique MAIL del empleado "<<endl;
               std::cin>>email;
               set<DTEstadia*> _estadiaH=controladorEstadia->obtenerEstadiasFinalizadas(email,nuevo->getNombre());
               auto its= _estadiaH.begin();
                while (its != _estadiaH.end())
                {
                    DTEstadia* actual_estadia = *its;
               
                    std::cout<<numero<<".-Estadia Finalizada: "<< actual_estadia->getPromo()<<endl;
                    ++its;
                }
           
            }
             system("pause");
            
            }
            break;
            case 10:{
                //Responder calificacion
                //+++++++++++++++++++++++
                limpiarPantalla();
                cout << "Ingrese email del empleado: ";
                cin >> emailUsuarioCrear;
                set<DTCalificacion*> calis = controladorUsuario->listarCalificacion(emailUsuarioCrear);
            if(calis.size()==0){ std::cout<<"No existen comentarios"<<endl;}
            else{ 
                int numero=0; 
                set<DTCalificacion*>::iterator it = calis.begin();
                while (it != calis.end())
                {
                    DTCalificacion* actual = *it;
                    ++numero;
                    std::cout<<numero<<".: "<<actual->getComentario()<<endl;
                    ++it;
                }
                tipoUsuarioCrear = pedirEntero("Seleccione un comentario: ","Opcion incorrecta ",numero);
                it = calis.begin();
                for(int i = 1; i < tipoUsuarioCrear; i++) ++it;
                DTCalificacion* cali = *it;
                controladorUsuario->seleccionarCalificacion(cali->getEstadia());
                emailUsuarioCrear = "";
                cout << "Ingrese la respuesta al comentario seleccionado: ";
                getline(cin,emailUsuarioCrear);
                getline(cin,emailUsuarioCrear);
                controladorUsuario->responderComentario(emailUsuarioCrear);
            }
            getch();
            }
            break;
            case 11:{
/*****************************************************************************************/
/******************************  11 - CONSULTA DE USUARIO ********************************/
/*****************************************************************************************/ 
            std::cout<<"\n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n "<<endl;
            std::cout<<"****************  11 - CONSULTA DE USUARIO  ************"<<endl; 
            int numero=0; 
            set<DTUsuario*> usuarios= controladorUsuario->listarUsuarios();
            if(usuarios.size()==0){ std::cout<<"NO HAY USUARIOS EN EL SISTEMA"<<endl;}
            else{ 
            auto it= usuarios.begin();
                while (it != usuarios.end())
                {
                    DTUsuario* actual = *it;
                    ++numero;
                    std::cout<<numero<<".-Usuario: "<<actual->getNombre()<<endl;
                    ++it;
                }
            bool valido=true;
                while(valido){
                    std::cout<<"Seleccione Usuario"<<endl;
                    std::cin>>numero;
                    if (numero>0 && numero<=usuarios.size()) {
                        valido=false;} else { std::cout<<"Elija un numero de usuario valido por favor!"<<endl;};
                }
            DTUsuario* nuevo = *it;
            it= usuarios.begin();
            int valor=0;
                while ((valor)!=numero)
                {
                    nuevo = *it;
                    valor++;
                    ++it;
                }
            
        DTEmpleado * actual_e =controladorUsuario->datosEmpleado( nuevo->getEmail());
        if(dynamic_cast<DTEmpleado*>(actual_e) != 0){
            std::cout<<"Empleado : "<<actual_e->getNombre()<<endl;
            std::cout<<"Email : "<<actual_e->getEmail()<<endl;
            std::cout<<"Cargo : "<<actual_e->getCargo()<<endl;
           // NECESITRAIA UNA FUNCION GET HOSTAL
            system("pause");
            } ;
        
        DTHuesped * actual_h =controladorUsuario->datosHuesped( nuevo->getEmail());
        if(dynamic_cast<DTHuesped*>(actual_h) != 0){ 
            std::cout<<"Huesped : "<<actual_h->getNombre()<<endl;
            std::cout<<"Email : "<<actual_h->getEmail()<<endl;
            string resultado="";
            if(actual_h->getEsFinger()){resultado="SI";} else{resultado="NO";};
            std::cout<<"Finger : "<<actual_h->getEsFinger()<<endl;
           // NECESITRAIA UNA FUNCION GET HOSTAL
        }  
     }
     system("pause");
     }
    break;




            case 12:{
/*****************************************************************************************/
/******************************  12 - CONSULTA DE HOSTAL ********************************/
/*****************************************************************************************/ 
            std::cout<<"\n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n "<<endl;
            std::cout<<"****************  12 - CONSULTA DE HOSTAL  ************"<<endl;

                int numero=0;
               
            set<DTHostal*> hostales= controladorHostal->listarHostales();
            if(hostales.size()==0){ std::cout<<"NO HAY HOSTALES EN EL SISTEMA"<<endl;}
            else{ 
            auto it= hostales.begin();
            std::cout<<" \n == HOSTALES: == \n"<<endl;
            std::cout<<"Digite Hostal Seleccionado: "<<endl;
                while (it != hostales.end())
                {
                    DTHostal* actual = *it;
                    ++numero;
                    std::cout<<numero<<".-Nombre Hostal: "<<actual->getNombre()<<endl;
                    ++it;
                }
            bool valido=true;

                while(valido){
                    std::cout<<"Seleccione el Hostal"<<endl;
                    std::cin>>numero;
                    if (numero>0 && numero<=hostales.size()) {
                        valido=false;} else { std::cout<<"Elija un numero de hostal valido por favor!"<<endl;};
                }
            DTHostal* nuevo = *it;
            it= hostales.begin();
            int valor=0;
                while ((valor)!=numero)
                {
                    nuevo = *it;
                    valor++;
                    ++it;
                }
            std::cout<<"Tengo el hostal pero no puedo listar hanitaciones y reservas"<<nuevo->getNombre()<<endl;
            controladorReserva->listarReservasHostal(nuevo->getNombre());
            }
            system("pause");


            }
            break;
            case 13:
/*****************************************************************************************/
/******************************  13 - CONSULTA DE RESERVA  ******************************/
/*****************************************************************************************/ 
                {
            std::cout<<"\n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n "<<endl;
            std::cout<<"****************  13 - CONSULTA DE RESERVA  ************"<<endl; 

                int numero=0;
               
            set<DTHostal*> hostales= controladorHostal->listarHostales();
            if(hostales.size()==0){ std::cout<<"NO HAY HOSTALES EN EL SISTEMA"<<endl;}

            else{ 
            auto it= hostales.begin();
            std::cout<<" \n == HOSTALES: == \n"<<endl;
            std::cout<<"Digite Hostal Seleccionado: "<<endl;
                while (it != hostales.end())
                {
                    DTHostal* actual = *it;
                    ++numero;
                    std::cout<<numero<<".-Nombre Hostal: "<<actual->getNombre()<<endl;
                    ++it;
                }
            bool valido=true;

                while(valido){
                    std::cout<<"Seleccione el Hostal"<<endl;
                    std::cin>>numero;
                    if (numero>0 && numero<=hostales.size()) {
                        valido=false;} else { std::cout<<"Elija un numero de hostal valido por favor!"<<endl;};
                } 
            DTHostal* nuevo = *it;

           
            it= hostales.begin();
            int valor=0;
                while ((valor)!=numero)
                {
                    nuevo = *it;
                    valor++;
                    ++it;
                }
            set<DTReserva*> reservas=   controladorReserva->listarReservasHostal(nuevo->getNombre());
            


           /* DTReservaGrupal * actual_h =controladorReserva->listarReservasHostal( nuevo->getNombre());
            if(dynamic_cast<DTReservaGrupal*>() != 0){
                
            }
            */


            if(reservas.size()==0){ std::cout<<"NO HAY RESERVAS EN EL SISTEMA"<<endl;}
            else{ 
            std::cout<<" \n == RESERVAS: == \n"<<endl;
            std::cout<<"Digite Reserva Seleccionada: "<<endl;
            auto it= reservas.begin();
            int iteranumero=0;
                while (it != reservas.end())
                {
                    DTReserva* _reserva = *it;
                    ++numero;
                    std::cout<<iteranumero<<".-Nombre Hostal: "<<_reserva->getHabitacion()<<endl;
                    std::cout<<iteranumero<<".-Nombre Hostal: "<<_reserva->getCodigo()<<endl;
                    controladorReserva->listarHuespedes();
                    

                    ++it;
                }
            }
            
            }
            system("pause");
            
            
            
            }

            break;
            case 14:
            break;
            case 15:
            break;
            case 16:{
                set<DTEmpleado*> empleados = controladorUsuario->obtenerEmpleados();
                if(empleados.size()==0){ std::cout<<"No existen empleados"<<endl;}
            else{ 
                int numero=0; 
                set<DTEmpleado*>::iterator it = empleados.begin();
                while (it != empleados.end())
                {
                    DTEmpleado* actual = *it;
                    ++numero;
                    std::cout<<numero<<".: "<<actual->getNombre()<<" "<<actual->getEmail()<<endl;
                    ++it;
                }
                tipoUsuarioCrear = pedirEntero("Seleccione un empleado: ","Opcion incorrecta ",numero);
                it = empleados.begin();
                for(int i = 1; i < tipoUsuarioCrear; i++) ++it;
                DTEmpleado* e = *it;
                controladorUsuario->subscribirseANotificaciones(e->getEmail());
                cout << "Subscripto";
            }
            getch();
            }
            break;
            case 17:{
                 set<DTEmpleado*> empleados = controladorUsuario->obtenerEmpleados();
                if(empleados.size()==0){ std::cout<<"No existen empleados"<<endl;
                getch();
                }
            else{ 
                int numero=0; 
                set<DTEmpleado*>::iterator it = empleados.begin();
                while (it != empleados.end())
                {
                    DTEmpleado* actual = *it;
                    ++numero;
                    std::cout<<numero<<".: "<<actual->getNombre()<<" "<<actual->getEmail()<<endl;
                    ++it;
                }
                tipoUsuarioCrear = pedirEntero("Seleccione un empleado: ","Opcion incorrecta ",numero);
                it = empleados.begin();
                for(int i = 1; i < tipoUsuarioCrear; i++) ++it;
                DTEmpleado* e = *it;
                set<DTNotificacion*> notifs = controladorUsuario->listarNotificaciones(e->getEmail());
                for(set<DTNotificacion*>::iterator it = notifs.begin();it != notifs.end();++it){
                    DTNotificacion* actual = *it;
                    cout <<"Autor: " << actual->getAutor() << " " << "Puntaje: " << actual->getPuntaje() << " " << "Comentario: " << actual->getComentario() << endl;
                }
                controladorUsuario->eliminarNotificaciones(e->getEmail());
                if(notifs.size()==0){cout << "No hay nuevas notificaciones";};
                getch();
            }
            }
            break;
            case 18:{
                set<DTEmpleado*> empleados = controladorUsuario->obtenerEmpleados();
                if(empleados.size()==0){ std::cout<<"No existen empleados"<<endl;}
            else{ 
                int numero=0; 
                set<DTEmpleado*>::iterator it = empleados.begin();
                while (it != empleados.end())
                {
                    DTEmpleado* actual = *it;
                    ++numero;
                    std::cout<<numero<<".: "<<actual->getNombre()<<" "<<actual->getEmail()<<endl;
                    ++it;
                }
                tipoUsuarioCrear = pedirEntero("Seleccione un empleado: ","Opcion incorrecta ",numero);
                it = empleados.begin();
                for(int i = 1; i < tipoUsuarioCrear; i++) ++it;
                DTEmpleado* e = *it;
                controladorUsuario->desubscribirseDeNotificaciones(e->getEmail());
                cout << "Subscripcion eliminada";
            }
            getch();
            }
            break;
            case 19:{
                int anio = pedirEntero("Ingrese el anio: ","Anio invalido ",3000);
                int mes = pedirEntero("Ingrese el mes: ","Mes invalido ",12);
                int dia = pedirEntero("Ingrese el dia: ","Dia invalido ",31);
                int hora = pedirEnteroConCero("Ingrese la hora: ","Hora invalida ",23);
                DTFecha* nueva = new DTFecha(anio, mes, dia, hora);
                controladorReloj->setFecha(nueva);
                cout << "Fecha actualizada";
            }
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


void visualizarUsuarios(){


}