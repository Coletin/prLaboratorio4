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

//pide un entero entre 1 y tope. mensajePedir es el mensaje que se muestra siempre mientras que mensajeError se muestra solamente cada vez que ingrese un numero mal.
int pedirEnteroSinLimpiarPantalla(string mensajePedir, string mensajeError, int tope){
    int respuesta = 0;
    bool primerMensaje = true;
    string lectura = "";
    while(respuesta > tope || respuesta < 1){
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
    DTFecha* fechaSistemaArranque = new DTFecha(1,5,2022,18);//Dia,Mes,Año,Hora(0-23)
    controladorReloj->setFecha(fechaSistemaArranque);
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
            {
/*****************************************************************************************/
/******************************  5 - REALIZAR RESERVA  ********************************/
/*****************************************************************************************/ 
            std::cout<<"\n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n "<<endl;
            set<DTHostal*> hostales = controladorReserva->listarHostales();
            DTFecha fechaNula(0,0,0,0);
        //////////////////////////////////Datos Base///////////////////////////////////////   
            if(hostales.size() == 0) std:cout<<"NO HAY HOSTALES EN EL SISTEMA"<<endl;
            else
             {
             std::cout<<"****************  5 - REALIZAR RESERVA  ************"<<endl;
            
             std::cout<<" \n \n \n Seleccione Hostal: \n" <<endl;
             //lista hostales
             auto it= hostales.begin();
             int hostalNumero = 0;
             while (it != hostales.end()){
                 DTHostal* actualHos = *it;
                 hostalNumero++;
                 std::cout<<"-----------------------------------------"<<endl;
                 std::cout<<hostalNumero<<".-Nombre Hostal: "<<actualHos->getNombre()<<endl;
                 std::cout<<" Direccion: "<<actualHos->getDireccion()<<endl;
                 std::cout<<" Promedio de calificacion: "<<actualHos->getPromedioClasi()<<endl;
                 ++it;
             }
             //selecciona hostal
             bool valido = false;
                 while(!valido){
                     std::cout<<"Digite Hostal Seleccionado: "<<endl;
                     std::cin>>hostalNumero;
                     if (hostalNumero>0 && hostalNumero<=hostales.size()) {
                         valido=true;} else { std::cout<<"Elija un numero de hostal valido"<<endl;};
                 }
             //selecciona fecha
             DTFecha desde = fechaNula;  
             DTFecha hasta = fechaNula;
             valido = false;
             while (!valido){
                 desde = fechaNula;
                 hasta = fechaNula;
                 while (desde == fechaNula){
                     std::cout<<"Ingrese fecha de entrada (DD/MM/AA-HH@m): " <<endl;
                     std::cin>>desde;  
                 }
                 while (hasta == fechaNula){
                     std::cout<<"Ingrese fecha de salida (DD/MM/AA-HH@m): " <<endl;
                     std::cin>>hasta;  
                 }
                 valido = desde < hasta;
                
                 if(!valido) std::cout<<"Fechas no validad, endrada tiene que ser anterior a salida: " <<endl;
             }
             limpiarPantalla();
             //seleccina el tipo de reserva
             int tipoReserva = pedirEntero("1-Grupal\n2-Individual\nSeleccione Tipo de Reserva: ","Opcion incorrecta ",2);
            
             //armo el dataR
             it = hostales.begin();
             int i = 0;
             while(i < hostalNumero){
                 i++;
                 ++it;
             }
             DTHostal* hostalSelecionado = *it;
             string nomHostal = hostalSelecionado->getNombre();
             bool esGrupal = tipoReserva == 1;
             DataR* data = new DataR(nomHostal,desde,hasta,esGrupal);
             controladorReserva->ingresarDatosReserva(data);

        /////////////////////////////////Habitacion///////////////////////////////////////
             //Listar Habitacion
             set<DTHabitacion*> habitaciones = controladorReserva->obtenerHabitacionesDisponiblesEnFecha();
             if(habitaciones.size()==0){std::cout<<"No hay habitaciones disponibles para estas fechas" <<endl;}
             else
              {
              std::cout<<" \n \n \n Seleccione Habitacion: \n" <<endl;
              auto ithab = habitaciones.begin();
              int habNumero = 0;
              while (ithab != habitaciones.end()){
                  DTHabitacion* actualHab = *ithab;
                  habNumero++;
                  std::cout<<"-----------------------------------------"<<endl;
                  std::cout<<habNumero<<".-Numero Habitacion: "<<actualHab->getNumero()<<endl;
                  std::cout<<" Capacidad: "<<actualHab->getCapacidad()<<endl;
                  std::cout<<" Presio: "<<actualHab->getPrecio()<<endl;
                  ++ithab;
              }
             //Selecciona Habitancion
              valido = false;
              while (!valido){
                  std::cout<<"Digite Habitacion Seleccionada: "<<endl;
                  std::cin>>hostalNumero;
                  if (hostalNumero>0 && hostalNumero<=hostales.size()) {
                      valido=true;} else { std::cout<<"Elija un numero de habitacion valido"<<endl;};
              }
              limpiarPantalla();
              ithab = habitaciones.begin();
              i = 0;
              while(i < habNumero){
                  i++;
                  ++ithab;
              }
              DTHabitacion* habitacionSeleccinada = *ithab;
              controladorReserva->agregarHabitacionAReserva(habitacionSeleccinada->getNumero());
        
        /////////////////////////////////Huesped///////////////////////////////////////    
             //Listar Huesped
              set<DTHuesped*> huespedes = controladorReserva->listarHuespedes();
              if(huespedes.size()==0 && (esGrupal && huespedes.size()<2)){std::cout<<"No hay suficientes huespedes en el sistema"<<endl;}
              else
               {
               std::cout<<" \n \n \n Seleccione Huesped Prinsipal: \n" <<endl;
               auto ithue = huespedes.begin();
               int hueNumero = 0;
               while (ithue != huespedes.end()){
                   DTHuesped* actualHue = *ithue;
                   hueNumero++;
                   std::cout<<"-----------------------------------------"<<endl;
                   std::cout<<hueNumero<<".-Nombre: "<<actualHue->getNombre()<<endl;
                   std::cout<<" Email: "<<actualHue->getEmail()<<endl;
                   ++ithab;
               }
             //Seleccionar Huesped
               valido = false;
               while (!valido){
                   std::cout<<"Digite Huesped Seleccionado: "<<endl;
                   std::cin>>hueNumero;
                   if(hueNumero>0 && hueNumero<=huespedes.size()){
                       valido = true;}else{ std::cout<<"Elija un numero de huesped valido"<<endl;};
               }
               ithue = huespedes.begin();
               i = 0;
               while (i < hueNumero){
                   i++;
                   ++ithue;
                }
             //Lo pasa al controlador y lo borra de la lista 
                DTHuesped* huespedSeleccionado = *ithue;
                huespedes.erase(ithue);
                controladorReserva->agregarHuespedAReserva(huespedSeleccionado->getEmail());
                delete huespedSeleccionado;
             
             //Si es grupal sigue listando huspedes pero sin el seleccionado anteriormente 
                if(esGrupal){
                 bool seguir = true; 
                 while(seguir)
                 {
                     if(huespedes.size()==0){std::cout<<"No hay mas huespedes en el sistema"<<endl;seguir=false;}
                     else
                     {
             //Lista los huespedes que quedan
                     std::cout<<" \n \n \n Seleccione Huesped: \n" <<endl;
                     ithue = huespedes.begin();
                     hueNumero = 0;
                     while (ithue != huespedes.end()){
                         DTHuesped* actualHue = *ithue;
                         hueNumero++;
                         std::cout<<"-----------------------------------------"<<endl;
                         std::cout<<hueNumero<<".-Nombre: "<<actualHue->getNombre()<<endl;
                         std::cout<<" Email: "<<actualHue->getEmail()<<endl;
                         ++ithab;
                     }
             //Selecciona huesped        
                     valido = false;
                     while (!valido){
                         std::cout<<"Digite Huesped Seleccionado: "<<endl;
                         std::cin>>hueNumero;
                         if(hueNumero>0 && hueNumero<=huespedes.size()){
                             valido = true;}else{ std::cout<<"Elija un numero de habitacion valido por favor!"<<endl;};
                     }
                     limpiarPantalla();
                     ithue = huespedes.begin();
                     i = 0;
                     while (i < hueNumero){
                        i++;
                        ++ithue;
                     }
             //Lo pasa al controlador y lo borra de la lista 
                     DTHuesped* huespedSeleccionado = *ithue;
                     huespedes.erase(ithue);
                     controladorReserva->agregarHuespedAReserva(huespedSeleccionado->getEmail());
                     delete huespedSeleccionado;
             //Pregunta si seguir
                     int seguirN = pedirEntero("1-Si \n2-No \nDesea Sguir Agregando Huespedes? ","Opcion incorrecta ",2);
                     seguir = seguirN == 1;
                     }
                 }
                }
               int confirmarN = pedirEntero("1-Si \n2-No \nDesea Confirmar La Reserva? ","Opcion incorrecta ",2);
               if(confirmarN == 1)controladorReserva->confirmarReserva();
               else controladorReserva->cancelarReserva(); 
               }//if de Huespedes
              }//if de Habitacines
             }//if de Hostales
            }//case 5
            break;
            case 6:{
/*****************************************************************************************/
/******************************  6 - CONSULTAR TOP 3 HOSTALES  ********************************/
/*****************************************************************************************/ 
            std::cout<<"\n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n "<<endl;
            set<DTHostal*> hostalesEnsistema = controladorHostal->listarHostales();
            int cantidadHostalesEnSistema = hostalesEnsistema.size();
            std::cout<<"****************  6 - CONSULTAR TOP 3 HOSTALES  ************"<<endl;
            if(cantidadHostalesEnSistema<3){std::cout<<"No hay suficientes hostales para hacer un top tres";}
            else
             {
            set<DTHostal*> top3 = controladorHostal->topTres();                
             auto it= top3.begin();
             int opcion = 0;
             while (it != top3.end()){
                DTHostal* actualHos = *it;
                opcion++;
                std::cout<<opcion<<".-Nombre Hostal: "<<actualHos->getNombre()<<endl;
                ++it;
             }
             std::cout<<"4.-No mostrar mas informacion\n"<<endl;
             std::cout<<"Elija el numero de hostal del cual desea tener mas informacion"<<endl; 
            //Seleccionar Opcion
             bool valido = false;
             while (!valido){
                std::cin>>opcion;
                if(opcion>0 && opcion <= top3.size() + 1){
                    valido = true;}else{ std::cout<<"Elija una opcion valida"<<endl;}
                }
             if(opcion <= top3.size()){
                limpiarPantalla();
                it = top3.begin();
                int i = 0;
                while (i < opcion){
                    i++;
                    ++it;
                }
                DTHostal* actual = *it;
                std::cout<<opcion<<"º hostal: "<<actual->getNombre()<<endl;
                set<DTCalificacion*> cali = actual->getCaliHabi();
                set<DTCalificacion*>::iterator itcal = cali.begin();  
                std::cout<<"Calificaciones: "<<endl;
                while (itcal != cali.end()){
                    DTCalificacion* calActual= *itcal; 
                    std::cout<<"Valor: "<<calActual->getValor()<<endl;
                    std::cout<<"Comentario:\n"<<calActual->getComentario()<<endl;
                    ++itcal;
                }      
             }else{controladorHostal->liberarMemoriaTop3();}
             }
            }//case 6
            break;
            case 7:{
                /******************************  7 - Registrar ESTADIA  ******************************/
                limpiarPantalla();
                set<DTHostal*> hostales7 = controladorEstadia->listarHostales();
                string mailHuesped;
                int numSeleccionado = 0;
                int numero = 1;
                if(hostales7.size() == 0){
                    cout << "No hay hostales en el sistema.";
                }else{
                    cout << "Nombres de hostales:";
                    set<DTHostal*>::iterator it = hostales7.begin();
                    while(it != hostales7.end()){
                        DTHostal* hostal = *it;
                        cout << numero<<"- "<< hostal->getNombre()<<endl;
                        numero++;
                        it++;
                    };

                    numSeleccionado = pedirEnteroSinLimpiarPantalla("Ingrese el numero del hostal:", "Numero invalido, ingrese que aparece en la lista ", numero - 1);
                    numero = 0; 
                    it = hostales7.begin();
                    DTHostal* seleccionado = *it;
                    while(numero != numSeleccionado){
                        seleccionado = *it;
                        numero++;
                        it++;
                    };

                    cout << endl;
                    cout << "Ingrese mail del huesped:";
                    cin >> mailHuesped; //no se checkea que el email exista en el sistema y puede romper le metodo de listarReservas

                    set<DTReserva*> reservas = controladorEstadia->listarReservas(mailHuesped, seleccionado->getNombre());
                    cout << "Codigos, fechas de inicio y habitaciones de las reservas:";
                    set<DTReserva*>::iterator it2 = reservas.begin();
                    numero = 1;
                    while(it2 != reservas.end()){
                        DTReserva* reserva = *it2;
                        DTFecha checkIn = reserva->getcheckIn();
                        cout << numero<<"- Codigo: "<<reserva->getCodigo()<<", Dia de checkIn: "<<checkIn.getDia()<<"/"<<checkIn.getMes()<<"/"<<checkIn.getAnio()<<", Habitacion: "<<reserva->getHabitacion()<<endl;
                        numero++;
                        it2++;
                    };

                    numSeleccionado = pedirEnteroSinLimpiarPantalla("Ingrese el codigo de la reserva:", "Numero invalido, ingrese que aparece en la lista ", 250);

                    // por si lo quiero hacer con el numero que aparece en la lista
                    // numero = 0; 
                    // it = reservas.begin();
                    // DTReserva* seleccionadoRes = *it;
                    // while(numero != numSeleccionado){
                    //     seleccionadoRes = *it;
                    //     numero++;
                    //     it++;
                    // };
                    // controladorEstadia->registrarEstadia(mailHuesped, seleccionadoRes->getCodigo());

                    controladorEstadia->registrarEstadia(mailHuesped, numSeleccionado);

                    cout << "Operacion hecha con exito! Ingrese cualquier caracter para continuar.";
                    getch();//esperamos que ingrese cualquier caracter;
                }
            };          
            break;
            case 8:{
                /******************************  8 - Finalizar ESTADIA  ******************************/
                limpiarPantalla();
                set<DTHostal*> hostales = controladorEstadia->listarHostales();
                string mailHuesped8;
                int numSeleccionado = 0;
                int numero = 1;
                if(hostales.size() == 0){
                    cout << "No hay hostales en el sistema.";
                }else{
                    cout << "Nombres de hostales:";
                    set<DTHostal*>::iterator it = hostales.begin();
                    while(it != hostales.end()){
                        DTHostal* hostal = *it;
                        cout << numero<<"- "<< hostal->getNombre()<<endl;
                        numero++;
                        it++;
                    };

                    numSeleccionado = pedirEnteroSinLimpiarPantalla("Ingrese el numero del hostal:", "Numero invalido, ingrese que aparece en la lista ", numero - 1);
                    numero = 0; 
                    it = hostales.begin();
                    DTHostal* seleccionado = *it;
                    while(numero != numSeleccionado){
                        seleccionado = *it;
                        numero++;
                        it++;
                    };

                    cout << endl;
                    cout << "Ingrese mail del huesped:";
                    cin >> mailHuesped8; //no se checkea que el email exista en el sistema y puede romper le metodo de listarReservas

                    if(controladorEstadia->existenEstadiasActivas(mailHuesped8, seleccionado->getNombre())){
                        int codigo = pedirEnteroSinLimpiarPantalla("Ingrese el codigo de la estadia:", "Numero invalido ", 250);
                        controladorEstadia->finalizarEstadia(codigo);
                        cout << "Operacion realisada con exito. Presione cualquier caracter para continuar.";
                    }else{
                        cout << "No existen estadias activas en el sistema. Presione cualquier caracter para continuar.";
                    }
                    getch();//esperamos que ingrese cualquier caracter;                    
                }
            };        
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
                cin.ignore();
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
            case 14:{
                set<DTHostal*> hostales = controladorHostal->listarHostales();
                if(hostales.size()==0){ 
                    std::cout<<"No existen hostales en el sistema"<<endl;
                    getch();
                }
            else{ 
                int numero=0; 
                set<DTHostal*>::iterator it = hostales.begin();
                while (it != hostales.end())
                {
                    DTHostal* actual = *it;
                    ++numero;
                    std::cout<<numero<<".: "<<actual->getNombre();
                    ++it;
                }
                tipoUsuarioCrear = pedirEntero("Seleccione un empleado: ","Opcion incorrecta ",numero);
                it = hostales.begin();
                for(int i = 1; i < tipoUsuarioCrear; i++) ++it;
                DTHostal* h = *it;
                set<DTEstadia*> estadias = controladorEstadia->listarEstadias(h->getNombre());
                if(estadias.size()==0){ std::cout<<"No existen estadias en el hostal"<<endl;}
            else{ 
                int numero=0; 
                set<DTEstadia*>::iterator ite = estadias.begin();
                while (ite != estadias.end())
                {
                    DTEstadia* actual = *ite;
                    ++numero;
                    std::cout<<numero<<".: "<<actual->getCodigo();
                    ++ite;
                }
                tipoUsuarioCrear = pedirEntero("Seleccione una estadia: ","Opcion incorrecta ",numero);
                ite = estadias.begin();
                for(int i = 1; i < tipoUsuarioCrear; i++) ++ite;
                DTEstadia* e = *ite;
                cout << "Hostal: " << h->getNombre() << endl;
                cout << "Huesped: " << e->getHuesped() << endl;
                int habEstadia = controladorEstadia->getHabitacionEstadia(e->getCodigo());
                int resEstadia = controladorEstadia->getReservaEstadia(e->getCodigo());
                cout << "Habitacion: " << habEstadia << endl;
                cout << "Check-In: " << e->getCheckIn().getDia()<<"/"<<e->getCheckIn().getMes()<<"/"<<e->getCheckIn().getAnio()<< "  " << e->getCheckIn().getHora() << " hs";
                if(e->getCheckOut().getDia() != -1){
                    cout << "Check-Out: ";
                    cout << e->getCheckIn().getDia()<<"/"<<e->getCheckIn().getMes()<<"/"<<e->getCheckIn().getAnio()<< "  " << e->getCheckIn().getHora() << " hs";
                }
                else cout << "No ha sido finalizada aun" << endl;
                cout << "Promo: " << e->getPromo();
                cout << "Reserva: " << resEstadia << endl;
                cout << "Desea ver la calificacion de esta estadia? 1.Si 2.No :" << endl;
                int opcion = 0;
                cin >> opcion;
                if(opcion == 1){
                    DTCalificacion* cali = controladorEstadia->getCalificacion(e->getCodigo());
                    DTRespuestaCalificacion* resp = controladorEstadia->getRespuestaCalificacion(e->getCodigo());
                    std::cout<<"Valor: "<<cali->getValor()<<endl;
                    std::cout<<"Comentario:\n"<<cali->getComentario()<<endl;
                    std::cout<<"Respuesta:\n"<<resp->getComentario()<<endl;
                }
                cout << "Desea ver la reserva asociada a esta estadia? 1.Si 2.No :" << endl;
                opcion = 0;
                cin >> opcion;
                if(opcion == 1){
                    DTReserva* res = controladorEstadia->getReservaDT(resEstadia);
                    cout << res;
                }
                }
                getch();
            }
            }
            break;
            case 15:{
/*****************************************************************************************/
/******************************  15 - BAJA RESERVA  ********************************/
/*****************************************************************************************/ 
            std::cout<<"\n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n "<<endl;
            set<DTHostal*> hostales = controladorReserva->listarHostales();
        //////////////////////////////////Seleccionar Hostal///////////////////////////////////////   
            if(hostales.size() == 0) std::cout<<"NO HAY HOSTALES EN EL SISTEMA"<<endl;
            else
             {
             std::cout<<"****************  15 - BAJA RESERVA  ************"<<endl;
            
             std::cout<<" \n \n \n Seleccione Hostal: \n" <<endl;
             //lista hostales
             auto it= hostales.begin();
             int hostalNumero = 0;
             while (it != hostales.end()){
                 DTHostal* actualHos = *it;
                 hostalNumero++;
                 std::cout<<hostalNumero<<".-Nombre Hostal: "<<actualHos->getNombre()<<endl;
                 ++it;
             }
             //selecciona hostal
             bool valido = false;
                 while(!valido){
                     std::cout<<"Digite Hostal Seleccionado: "<<endl;
                     std::cin>>hostalNumero;
                     if (hostalNumero>0 && hostalNumero<=hostales.size()) {
                         valido=true;} else { std::cout<<"Elija un numero de hostal valido"<<endl;};
                 }
             it = hostales.begin();
             int i = 0;
             while(i < hostalNumero){
                 i++;
                 ++it;
             }
             DTHostal* hostalSelecionado = *it;
             string nomHostal = hostalSelecionado->getNombre();
             //listar reservas
             set<DTReserva*> reservas = controladorReserva->listarReservasHostal(nomHostal);
             if(reservas.size() == 0){std::cout<<"NO HAY RESERVAS SOBRE EL HOSTAL SELECCIONADO"<<endl;}
             else
              {
              std::cout<<" \n \n \n Seleccione Reserva: \n" <<endl;
              auto itr=reservas.begin();
              int reservaNumero = 0;
              while (itr != reservas.end()){
                DTReserva* actualRes = *itr;
                reservaNumero++;
                std::cout<<"-----------------------------------------"<<endl;
                std::cout<<reservaNumero<<".-Codigo Reserva: "<<actualRes->getCodigo()<<endl;
                std::cout<<" Estado "<<actualRes->getEstadoReserva()<<endl;
              }
              valido = false;
              int codR;
              while (!valido){
                std::cout<<"Ingrese un codigo valido que corresponda con el de la reserva a eliminar"<<endl;
                std::cin>>codR;
                bool encontre = false;
                itr=reservas.begin();
                while (itr != reservas.end() && !encontre){
                    DTReserva* actualRes = *itr;
                    encontre = actualRes->getCodigo() == codR;
                }
                valido = encontre;
              }
              limpiarPantalla();
              //Confirmar Baja o canselar
              controladorReserva->seleccionarReserva(codR);
              int confirmarN = pedirEntero("1-Si \n2-No \nDesea Confirmar La Baja Reserva? ","Opcion incorrecta ",2);
              if(confirmarN == 1)controladorReserva->confirmarBajaReserva();
              else controladorReserva->cancelarBajaReserva();
              }
             }               
            }//case 15
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

            if(_cargaInicial==1){
            _cargaInicial=0;



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
            controladorUsuario->indicarEmail("sofia@mail.com");
            controladorUsuario->crearHuesped(true);
            controladorUsuario->persistirUsuario();

            //H2
            controladorUsuario->cargarDatosUsuario("Frodo","123");
            controladorUsuario->indicarEmail("frodo@mail.com");
            controladorUsuario->crearHuesped(true);
            controladorUsuario->persistirUsuario();


            //H3
            controladorUsuario->cargarDatosUsuario("Sam","123");
            controladorUsuario->indicarEmail("sam@mail.com");
            controladorUsuario->crearHuesped(false);
            controladorUsuario->persistirUsuario();

            //H4
            controladorUsuario->cargarDatosUsuario("Merry","123");
            controladorUsuario->indicarEmail("merry@mail.com");
            controladorUsuario->crearHuesped(false);
            controladorUsuario->persistirUsuario();

            //H5
            controladorUsuario->cargarDatosUsuario("Pippin","123");
            controladorUsuario->indicarEmail("pippin@mail.com");
            controladorUsuario->crearHuesped(false);
            controladorUsuario->persistirUsuario();

            //H6
            controladorUsuario->cargarDatosUsuario("Seba","123");
            controladorUsuario->indicarEmail("seba@mail.com");
            controladorUsuario->crearHuesped(true);
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

            std::cout<< *controladorReloj->getFecha()<<endl;

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
            controladorReserva->confirmarReserva();
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
            controladorReserva->confirmarReserva();
            //R3
            DTFecha desder3(7,6,2022,14);  
            DTFecha hastar3(30,6,2022,11);
            DataR* reseva3 = new DataR("La posada del finger",desder3,hastar3,false);//Dia,Mes,Año,Hora(0-23)
            controladorReserva->ingresarDatosReserva(reseva3);
            controladorReserva->agregarHabitacionAReserva(3);
            controladorReserva->agregarHuespedAReserva("sofia@mail.com");
            controladorReserva->confirmarReserva();
            //R4
            DTFecha desder4(10,6,2022,14);  
            DTFecha hastar4(30,6,2022,11);
            DataR* reseva4 = new DataR("Caverna Lujosa",desder4,hastar4,false);//Dia,Mes,Año,Hora(0-23)
            controladorReserva->ingresarDatosReserva(reseva4);
            controladorReserva->agregarHabitacionAReserva(1);
            controladorReserva->agregarHuespedAReserva("seba@mail.com");
            controladorReserva->confirmarReserva();
     

             std::cout<<" \n == CARGA ESTADIAS: == \n"<<endl;
            //Crear Estadias
            DTFecha* fechaSistema = new DTFecha(1,5,2022,18);//Dia,Mes,Año,Hora(0-23)
            controladorReloj->setFecha(fechaSistema);
            //agregar ES1
            controladorEstadia->registrarEstadia("sofia@mail.com", 1);

            fechaSistema = new DTFecha(4,1,2001,21);
            controladorReloj->setFecha(fechaSistema);
            //agregar ES2
            controladorEstadia->registrarEstadia("frodo@mail.com", 2);

            fechaSistema = new DTFecha(4,1,2001,21);
            controladorReloj->setFecha(fechaSistema);
            //agregar ES3
            controladorEstadia->registrarEstadia("sam@mail.com", 2);

            fechaSistema = new DTFecha(4,1,2001,21);
            controladorReloj->setFecha(fechaSistema);
            //agregar ES4
            controladorEstadia->registrarEstadia("merry@mail.com", 2);

            fechaSistema = new DTFecha(4,1,2001,21);
            controladorReloj->setFecha(fechaSistema);
            //agregar ES5
            controladorEstadia->registrarEstadia("pippin@mail.com", 2);

            fechaSistema = new DTFecha(7,6,2022,18);
            controladorReloj->setFecha(fechaSistema);
            //agregar ES6
            controladorEstadia->registrarEstadia("seba@mail.com", 4);
            

            //Finalizar Estadias
            fechaSistema = new DTFecha(10,5,2022,9);
            controladorReloj->setFecha(fechaSistema);
            //finalizar ES1
            controladorEstadia->finalizarEstadia(1);

            fechaSistema = new DTFecha(5,1,2001,2);
            controladorReloj->setFecha(fechaSistema);
            //finalizar ES2
            controladorEstadia->finalizarEstadia(2);

            fechaSistema = new DTFecha(15,6,2022,22);
            controladorReloj->setFecha(fechaSistema);
            //finalizar ES6
            controladorEstadia->finalizarEstadia(6);


             std::cout<<" \n == CALIFICAR ESTADIAS: == \n"<<endl;
            //Calificar Estadias

            fechaSistema = new DTFecha(11,5,2022,18);
            controladorReloj->setFecha(fechaSistema);
            //agregar C1
            controladorEstadia->crearCalificacion("sofia@mail.com","La posada del finger","Un poco caro para lo que ofrecen. El famoso gimnasio era una caminadora (que hacia tremendo ruido) y 2 pesas, la piscina parecia el lago del Parque Rodo y el desayuno eran 2 tostadas con mermelada. Internet se pasaba cayendo. No vuelvo.",3,1);

            fechaSistema = new DTFecha(5,1,2001,3);
            controladorReloj->setFecha(fechaSistema);
            //agregar C2
            controladorEstadia->crearCalificacion("frodo@mail.com","El Pony Pisador","Se pone peligroso de noche, no recomiendo. Ademas no hay caja fuerte para guardar anillos.",2,2);

            fechaSistema = new DTFecha(15,6,2022,23);
            controladorReloj->setFecha(fechaSistema);
            //agregar C3
            controladorEstadia->crearCalificacion("seba@mail.com","Caverna Lujosa","Habia pulgas en la habitacion. Que lugar mas mamarracho",1,6);


            //Comentar Calificaciones
            fechaSistema = new DTFecha(6,1,2001,15);
            controladorReloj->setFecha(fechaSistema);

             std::cout<<" \n == RESPONDER CALIFICACIONES: == \n"<<endl;
            //agregar comentario C2
            controladorUsuario->listarCalificacion("barli@mail.com");
            controladorUsuario->seleccionarCalificacion(2);
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