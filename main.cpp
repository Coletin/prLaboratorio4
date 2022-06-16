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

int main(){
    Fabrica* f = new Fabrica();
    IHostal* controladorHostal = f->getIHostal();
    IReloj* controladorReloj = f->getIReloj();
    IReserva* controladorReserva = f->getIReserva();
    IEstadia* controladorEstadia = f->getIEstadia();
    IUsuario* controladorUsuario = f->getIUsuario();
    int i = 0;
    int _cargaInicial=1;

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
                cin >> nombreUsuarioCrear;
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




            case 12:
/*****************************************************************************************/
/******************************  12 - CONSULTA DE HOSTAL ********************************/
/*****************************************************************************************/ 
    {
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
            set<DTReserva*> reservas=  controladorReserva->listarReservasHostal(nuevo->getNombre());
            


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
            std::cout<<iteranumero<<".-Nombre Hostal: "<<nuevo->getNombre()<<endl;
                while (it != reservas.end())
                {
                    DTReserva* _reserva = *it;
                    ++numero;    
                    std::cout<<iteranumero<<".-Reserva: "<<_reserva->getHabitacion()<<"  "<<".-Habitacion: "<<_reserva->getCodigo()<<endl<<".-Estado: "<<_reserva->getEstadoReserva()<<endl;
                    ++it;
                }
            }
            
            }
            system("pause");
            
            
            
            }
            break;
            case 13:{
/*****************************************************************************************/
/******************************  13 - CONSULTA DE RESERVA  ******************************/
/*****************************************************************************************/ 
            std::cout<<"\n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n "<<endl;
            std::cout<<"**************** 13 - CONSULTA DE RESERVA  ************"<<endl;

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
            std::cout<<"Tengo el hostal pero no puedo listar hanitaciones y reservas------>"<<nuevo->getNombre()<<endl;
            set<DTReserva*> reservas_Hostal=controladorReserva->listarReservasHostal(nuevo->getNombre());
            nuevo->getNombre();
            nuevo->getDireccion();
            nuevo->getTelefono();
            auto itres= reservas_Hostal.begin();

            while (itres != reservas_Hostal.end())
                {
                DTReserva * actual_r = *itres;
                if(dynamic_cast<DTReservaIndividual*>(actual_r)!= 0){DTReservaGrupal * rgrupal= dynamic_cast<DTReservaGrupal*>(actual_r); 
                          set<DTHuesped*> huespedes_por_reserva =rgrupal->getHuespedes();
                            auto itreserva= huespedes_por_reserva .begin();
                            std::cout<<"Reserva INDIVIDUAL- Habitacion : "<<rgrupal->getHabitacion()<<endl;
                            std::cout<<"Reserva INDIVIDUAL- Codigo : "<<rgrupal->getCodigo()<<endl;
                            
                                while (itreserva != huespedes_por_reserva .end())
                                    {
                                        DTHuesped * actual_hues = *itreserva;
                                        std::cout<<"Huesped INDIVIDUAL-"<<actual_hues->getNombre()<<endl;
                                        itreserva++;
                                     }
                 } else {
                          DTReservaGrupal * rgrupal= dynamic_cast<DTReservaGrupal*>(actual_r); 
                          set<DTHuesped*> huespedes_por_reserva =rgrupal->getHuespedes();
                            auto itreserva= huespedes_por_reserva .begin();
                            std::cout<<"Reserva Grupal- Habitacion : "<<rgrupal->getHabitacion()<<endl;
                            std::cout<<"Reserva Grupal- Codigo : "<<rgrupal->getCodigo()<<endl;
                            std::cout<<"Reserva Grupal- Huespedes : "<<rgrupal->getCodigo()<<endl;

                                while (itreserva != huespedes_por_reserva .end())
                                    {
                                        DTHuesped * actual_hues = *itreserva;
                                        std::cout<<"Huesped Grupal: "<<actual_hues->getNombre()<<endl;
                                        itreserva++;
                                     }
                 };



                 }
            }
            system("pause");


            }
            

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

            if(_cargaInicial==1){
            _cargaInicial=0;

          

            DTFecha* fechaSistemaArranque = new DTFecha(1,5,2022,18);//Dia,Mes,Año,Hora(0-23)
            controladorReloj->setFecha(fechaSistemaArranque);



             std::cout<<" \n == CARGA EMPLEADOS: == \n"<<endl;
            //E1
           
            controladorUsuario->cargarDatosUsuario("Emilia","123");
            controladorUsuario->crearEmpleado(Recepcion);
            controladorUsuario->indicarEmail("emilia@mail.com");
            controladorUsuario->persistirUsuario();

            //E2
            controladorUsuario->cargarDatosUsuario("Leonardo","123");
            controladorUsuario->crearEmpleado(Recepcion);
            controladorUsuario->indicarEmail("leo@mail.com");
            controladorUsuario->persistirUsuario();
            //E3
            controladorUsuario->cargarDatosUsuario("Alina","123");
            controladorUsuario->crearEmpleado(Administracion);
            controladorUsuario->indicarEmail("alina@mail.com");
            controladorUsuario->persistirUsuario();
            //E4 
            controladorUsuario->cargarDatosUsuario("Barliman","123");
            controladorUsuario->crearEmpleado(Recepcion);
            controladorUsuario->indicarEmail("barli@mail.com");
            controladorUsuario->persistirUsuario();


            //E5

             std::cout<<" \n == CARGA HUESPEDES: == \n"<<endl;
            //H1
            controladorUsuario->cargarDatosUsuario("Sofia","123");
            controladorUsuario->crearHuesped(true);
            controladorUsuario->indicarEmail("sofia@mail.com");
            controladorUsuario->persistirUsuario();

            //H2
            controladorUsuario->cargarDatosUsuario("Frodo","123");
            controladorUsuario->crearHuesped(true);
            controladorUsuario->indicarEmail("frodo@mail.com");
            controladorUsuario->persistirUsuario();


            //H3
            controladorUsuario->cargarDatosUsuario("Sam","123");
            controladorUsuario->crearHuesped(false);
            controladorUsuario->indicarEmail("sam@mail.com");
            controladorUsuario->persistirUsuario();

            //H4
            controladorUsuario->cargarDatosUsuario("Merry","123");
            controladorUsuario->crearHuesped(false);
            controladorUsuario->indicarEmail("merry@mail.com");
            controladorUsuario->persistirUsuario();

            //H5
            controladorUsuario->cargarDatosUsuario("Pippin","123");
            controladorUsuario->crearHuesped(false);
            controladorUsuario->indicarEmail("pippin@mail.com");
            controladorUsuario->persistirUsuario();

            //H6
            controladorUsuario->cargarDatosUsuario("Seba","123");
            controladorUsuario->crearHuesped(true);
            controladorUsuario->indicarEmail("seba@mail.com");
            controladorUsuario->persistirUsuario();

             std::cout<<" \n == CARGA HOSTALES: == \n"<<endl;

            //HO1
            controladorHostal->agregarHostal("La posada del finger", "Av de la playa 123, Maldonado", "099111111");

            //HO2
            controladorHostal->agregarHostal("Mochileros", "Rambla Costanera 333, Rocha", "42579512");

            //HO3
            controladorHostal->agregarHostal("El Pony Pisador", "Bree (preguntar por Gandalf)", "000");

            //HO4
            controladorHostal->agregarHostal("Altos de Fing", "Av del Toro 1424", "099892992");

            //HO5
            controladorHostal->agregarHostal("Caverna Lujosa", "Amaya 2515", "233233235");

             std::cout<<" \n == FECHA ACTUAL: == \n"<<endl;

            std::cout<<controladorReloj->getFecha()<<endl;

             std::cout<<" \n == CARGA HABITACIONES: == \n"<<endl;
            //Habitaciones

            //HA1
            controladorHostal->seleccionarHostalVar("La posada del finger");
            controladorHostal->ingresarHabitacion(1,40,2);
            controladorHostal->persistirHabitacion();

            //HA2
            controladorHostal->seleccionarHostalVar("La posada del finger");
            controladorHostal->ingresarHabitacion(2,10,7);
            controladorHostal->persistirHabitacion();

            //HA3
            controladorHostal->seleccionarHostalVar("La posada del finger");
            controladorHostal->ingresarHabitacion(3,30,3);
            controladorHostal->persistirHabitacion();

            //HA4
            controladorHostal->seleccionarHostalVar("La posada del finger");
            controladorHostal->ingresarHabitacion(4,5,12);
            controladorHostal->persistirHabitacion();

            //HA5
            controladorHostal->seleccionarHostalVar("Caverna Lujosa");
            controladorHostal->ingresarHabitacion(1,3,2);
            controladorHostal->persistirHabitacion();

            //HA6
            controladorHostal->seleccionarHostalVar("El Pony Pisador");
            controladorHostal->ingresarHabitacion(1,9,5);
            controladorHostal->persistirHabitacion();
            

             std::cout<<" \n == ASIGNAR EMPLEADOS: == \n"<<endl;
            controladorHostal->seleccionarHostalVar("La posada del finger");
            controladorHostal->asignarEmpleado("emilia@mail.com", CargoEmpleado::Recepcion);
            controladorHostal->confirmarAsigncacion();
            controladorHostal->finalizar();
            controladorHostal->seleccionarHostalVar("Mochileros");
            controladorHostal->asignarEmpleado("leo@mail.com", CargoEmpleado::Recepcion);
            controladorHostal->confirmarAsigncacion();
            controladorHostal->finalizar();
            controladorHostal->seleccionarHostalVar("Mochileros");
            controladorHostal->asignarEmpleado("alina@mail.com", CargoEmpleado::Administracion);
            controladorHostal->confirmarAsigncacion();
            controladorHostal->finalizar();

            controladorHostal->seleccionarHostalVar("El Pony Pisador");
            controladorHostal->asignarEmpleado("barli@mail.com", CargoEmpleado::Recepcion);
            std::cout<<" \n == fallo: == \n"<<endl;
            controladorHostal->confirmarAsigncacion();
            controladorHostal->finalizar();





            std::cout<<" \n == CARGA RESERVAS: == \n"<<endl;
            //R1
            DTFecha desder(01,05,2022,14);  
            DTFecha hastar(10,05,2022,10);
            DataR* reseva = new DataR("La posada del finger",desder,hastar,false);//Dia,Mes,Año,Hora(0-23)
            controladorReserva->ingresarDatosReserva(reseva);
            controladorReserva->agregarHabitacionAReserva(1);
            controladorReserva->agregarHuespedAReserva("sofia@mail.com");
            std::cout<<" \n == FALLA: == \n"<<endl;
           // controladorReserva->confirmarReserva();
            //R2
            DTFecha desder2(4,01,2001,20);  
            DTFecha hastar2(5,01,2001,2);
            DataR* reseva2 = new DataR("El Pony Pisador",desder2,hastar2,true);//Dia,Mes,Año,Hora(0-23)
            controladorReserva->ingresarDatosReserva(reseva2);
            controladorReserva->agregarHabitacionAReserva(1);
            controladorReserva->agregarHuespedAReserva("frodo@mail.com");
            controladorReserva->agregarHuespedAReserva("sam@mail.com");
            controladorReserva->agregarHuespedAReserva("merry@mail.com");
            controladorReserva->agregarHuespedAReserva("pipin@mail.com");

            std::cout<<" \n == FALLA: == \n"<<endl;
            //R3
            DTFecha desder3(7,6,2022,14);  
            DTFecha hastar3(30,6,2022,11);
            DataR* reseva3 = new DataR("La posada del finger",desder3,hastar3,false);//Dia,Mes,Año,Hora(0-23)
            controladorReserva->ingresarDatosReserva(reseva3);
            controladorReserva->agregarHabitacionAReserva(3);
            controladorReserva->agregarHuespedAReserva("seba@mail.com");
            std::cout<<" \n == FALLA: == \n"<<endl;

            //R4
            DTFecha desder4(10,6,2022,14);  
            DTFecha hastar4(30,6,2023,11);
            DataR* reseva4 = new DataR("Caverna Lujosa",desder4,hastar4,false);//Dia,Mes,Año,Hora(0-23)
            controladorReserva->ingresarDatosReserva(reseva4);
            controladorReserva->agregarHabitacionAReserva(5);
            controladorReserva->agregarHuespedAReserva("sofia@mail.com");
            std::cout<<" \n == FALLA: == \n"<<endl;

     

             std::cout<<" \n == CARGA ESTADIAS: == \n"<<endl;
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


             std::cout<<" \n == CALIFICAR ESTADIAS: == \n"<<endl;
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

             std::cout<<" \n == RESPONDER CALIFICACIONES: == \n"<<endl;
            //agregar comentario C2
            controladorUsuario->responderComentario("Desapareció y se fue sin pagar");


            } else {std::cout<<"CARGA INICIAL YA REALIZADA"<<endl;
              cout << "La opcion seleccionada no es valida \n"<<endl;
              system("pause");
            };
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