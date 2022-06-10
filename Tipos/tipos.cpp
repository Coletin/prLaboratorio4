#include "tipos.h"
#include <iostream>
#include <stdexcept>
using namespace std;


string DTUsuario::getEmail(){
    return this->email;
};

string DTUsuario::getNombre(){
    return this->nombre;
};

string DTUsuario::getContrasena(){
    return this->contrasena;
};

DTHuesped::DTHuesped(){

};

DTHuesped::DTHuesped(string nombre, string email, string contrasena, bool esFinger):DTUsuario(nombre, email, contrasena){
    this->esFinger = esFinger;
};

bool DTHuesped::getEsFinger(){
    return this->esFinger;
}

void DTHuesped::toString(){
    cout << "[nombre: " << this->getNombre() << "; email: " << this->getEmail() << "; Es Finger?: " << this->getEsFinger() << "]" << endl;
};

DTEmpleado::DTEmpleado(){

};

DTEmpleado::DTEmpleado(string nombre, string email, string contrasena, string cargo):DTUsuario(nombre, email, contrasena){
    this->cargo = cargo;
};

string DTEmpleado::getCargo(){
    return this->cargo;
};

void DTEmpleado::toString(){
    cout << "[nombre: " << this->getNombre() << "; email: " << this->getEmail() << "; cargo: ";
    if(this->getCargo()=="Recepcion"){
        cout << "Recepcion" << "]" << endl;
    }
    else if(this->getCargo()=="Administracion"){
        cout << "Administracion" << "]" << endl;
    }
    else if(this->getCargo()=="Limpieza"){
        cout << "Limpieza" << "]" << endl;
    }
    else if(this->getCargo()=="Infraestructura"){
        cout << "Infraestructura" << "]" << endl;
    };
};

DTHabitacion::DTHabitacion(){};

DTHabitacion::DTHabitacion(int numero, float precio, int capacidad){
    this->numero=numero;
    this->precio=precio;
    this->capacidad=capacidad;
};

int DTHabitacion::getNumero(){
    return this->numero;
};

float DTHabitacion::getPrecio(){
    return this->precio;
};

int DTHabitacion::getCapacidad(){
    return this->capacidad;
};

void DTHabitacion::toString(){
    cout << "[numero: " << this->getNumero() << "; capacidad: " << this->getCapacidad() << "; precio: " << this->getPrecio() << "]" << endl ;
};

DTFecha::DTFecha(){
};

DTFecha::DTFecha(int dian, int mesn, int anion, int horan){
    this->dia = dian;
    this->mes = mesn;
    this->anio = anion;
    this->hora = horan;
};

int DTFecha::getHora(){
    return this->hora;
};

int DTFecha::getDia(){
    return this->dia;
};

int DTFecha::getMes(){
    return this->mes;
};

int DTFecha::getAnio(){
    return this->anio;
};

bool DTFecha::operator==(const DTFecha& igual){
    return (this->dia == igual.dia)&&(this->mes == igual.mes)&&(this->anio == igual.anio)&&(this->hora == igual.hora);
};

bool DTFecha::operator!=(const DTFecha& distinta){
    return (this->dia != distinta.dia)||(this->mes != distinta.mes)||(this->anio != distinta.anio)||(this->hora != distinta.hora);
};

bool DTFecha::operator<(const DTFecha& mayor){
    bool resu = false;
    if(this->anio < mayor.anio){
        resu = true;
    }
    else if((this->mes < mayor.mes)&&(this->anio == mayor.anio)){
        resu = true;
    }
    else if((this->dia < mayor.dia)&&(this->mes == mayor.mes)&&(this->anio == mayor.anio)){
        resu = true;
    }
    else if((this->hora < mayor.hora)&&(this->dia == mayor.dia)&&(this->mes == mayor.mes)&&(this->anio == mayor.anio)){
        resu = true;
    };
    return resu;
};

bool DTFecha::operator>(const DTFecha& menor){
    bool resu = false;
    if(this->anio > menor.anio){
        resu = true;
    }
    else if((this->mes > menor.mes)&&(this->anio == menor.anio)){
        resu = true;
    }
    else if((this->dia > menor.dia)&&(this->mes == menor.mes)&&(this->anio == menor.anio)){
        resu = true;
    }
    else if((this->hora > menor.hora)&&(this->dia == menor.dia)&&(this->mes == menor.mes)&&(this->anio == menor.anio)){
        resu = true;
    };
    return resu;
};

bool DTFecha::operator<=(const DTFecha& maIgual){
    bool mayor = false;
    if(this->anio < maIgual.anio){
        mayor = true;
    }
    else if((this->mes < maIgual.mes)&&(this->anio == maIgual.anio)){
        mayor = true;
    }
    else if((this->dia < maIgual.dia)&&(this->mes == maIgual.mes)&&(this->anio == maIgual.anio)){
        mayor = true;
    }
    else if((this->hora < maIgual.hora)&&(this->dia == maIgual.dia)&&(this->mes == maIgual.mes)&&(this->anio == maIgual.anio)){
        mayor = true;
    };
    bool igual = (this->hora == maIgual.hora)&&(this->dia == maIgual.dia)&&(this->mes == maIgual.mes)&&(this->anio == maIgual.anio);

    return mayor||igual;
};

bool DTFecha::operator>=(const DTFecha& meIgual){
    bool menor = false;
    if(this->anio > meIgual.anio){
        menor = true;
    }
    else if((this->mes > meIgual.mes)&&(this->anio == meIgual.anio)){
        menor = true;
    }
    else if((this->dia > meIgual.dia)&&(this->mes == meIgual.mes)&&(this->anio == meIgual.anio)){
        menor = true;
    }
    else if((this->hora > meIgual.hora)&&(this->dia == meIgual.dia)&&(this->mes == meIgual.mes)&&(this->anio == meIgual.anio)){
        menor = true;
    };
    bool igual = (this->hora == meIgual.hora)&&(this->dia == meIgual.dia)&&(this->mes == meIgual.mes)&&(this->anio == meIgual.anio);
    return menor||igual;
};

ostream& operator<<(ostream& o, DTFecha& f){
    if((f.getHora()-10) < 0) o << '0';
    o << f.getHora();
    o << '/';
    if((f.getDia()-10) < 0) o << '0';
    o << f.getDia();
    o << '/';
    if((f.getMes()-10) < 0) o << '0';
    o << f.getMes();
    o << '/';
    o << f.getAnio();
    return o;
};

istream& operator>>(istream& i, DTFecha& f){
    char fLeer[15];
    scanf("%s", fLeer);
    string horaS;
    string diaS;
    string mesS;
    string anioS;
    int indice = 0;
    while (fLeer[indice]!='/'){
        horaS = horaS + fLeer[indice];
        indice++;
    }
    while (fLeer[indice]!='/'){
        diaS = diaS + fLeer[indice];
        indice++;
    }
    indice++;
    while (fLeer[indice]!='/'){
        mesS = mesS + fLeer[indice];
        indice++;
    }
    indice++;
    while (fLeer[indice]!='\0'){
        anioS = anioS + fLeer[indice];
        indice++;
    }
    int horaN = stoi(horaS);
    int diaN = stoi(diaS);
    int mesN = stoi(mesS);
    int anioN = stoi(anioS);
    if(horaN > 23 || horaN < 0 ||diaN > 31 || diaN < 1 || mesN > 12 || mesN < 1 || anioN < 1900) throw std::invalid_argument("Fecha fuera de rango");
    DTFecha nueva(horaN, diaN, mesN, anioN);
    f = nueva;
    return i;
};

DTReserva::DTReserva(int _codigo,DTFecha _checkIn,DTFecha _checkOut,bool _estado,float _costo,int _habitacion){
    this->codigo = _codigo;
    this->checkIn = _checkIn;
    this->checkOut = _checkOut;
    this->estado = _estado;
    this->costo = _costo;
    this->habitacion = _habitacion;
};

DTReserva::DTReserva(int _codigo,DTFecha _checkIn,DTFecha _checkOut,bool _estado,int _habitacion){
    this->codigo = _codigo;
    this->checkIn = _checkIn;
    this->checkOut = _checkOut;
    this->estado = _estado;
    this->habitacion = _habitacion;
};

void DTReservaIndividual::operacion(){};

void DTReservaGrupal::operacion(){};

DTFecha DTReserva::getcheckIn(){
    return this->checkIn;
};
DTFecha DTReserva::getcheckOut(){
    return this->checkOut;
};

int DTReserva::getCodigo(){
    return this->codigo;
};

bool DTReserva::getEstadoReserva(){
    return this->estado;
};

float DTReserva::getCosto(){
    return this->costo;
};

int DTReserva::getHabitacion(){
    return this->habitacion;
};

DTReservaIndividual::DTReservaIndividual(int _codigo,DTFecha _checkIn,DTFecha _checkOut,bool _estado,float _costo,int _habitacion):DTReserva(_codigo,_checkIn,_checkOut,_estado,_costo,_habitacion){
};

DTReservaIndividual::DTReservaIndividual(int _codigo,DTFecha _checkIn,DTFecha _checkOut,bool _estado,int _habitacion):DTReserva(_codigo,_checkIn,_checkOut,_estado,_habitacion){
};

DTReservaGrupal::DTReservaGrupal(int _codigo,DTFecha _checkIn,DTFecha _checkOut,bool _estado,float _costo,int _habitacion,DTHuesped** _huespedes):DTReserva(_codigo, _checkIn, _checkOut, _estado, _costo, _habitacion){
    this->huespedes= _huespedes;
};

DTReservaGrupal::DTReservaGrupal(int _codigo,DTFecha _checkIn,DTFecha _checkOut,bool _estado,int _habitacion,DTHuesped** _huespedes):DTReserva(_codigo, _checkIn, _checkOut, _estado, _habitacion){
    this->huespedes= _huespedes;
};

DTHuesped** DTReservaGrupal::getHuespedes(){
    return huespedes;
};

ostream& operator<<(ostream& o, DTReservaIndividual& ri){
    o << "TipoReserva: Individual" << endl;
    o << "FechaCheckIn: ";
    DTFecha f = ri.getcheckIn();
    o << f;
    o << endl;
    o << "FechaCheckOut: ";
    f = ri.getcheckOut();
    o << f;
    o << endl;
    o << "Habitacion: " << ri.getHabitacion() << endl;
    o << "Costo: $" << ri.getCosto() << endl;
    o << endl;
    return o;
};

ostream& operator<<(ostream& o, DTReservaGrupal& rg){
    o << "TipoReserva: Grupal" << endl;
    o << "FechaCheckIn: ";
    DTFecha f = rg.getcheckIn();
    o << f;
    o << endl;
    o << "FechaCheckOut: ";
    f = rg.getcheckOut();
    o << f;
    o << endl;
    o << "Habitacion: " << rg.getHabitacion() << endl;
    o << "Costo: $" << rg.getCosto() << endl;
    o << "Huespedes: ";
    int i = 0;
    while(rg.getHuespedes()[i]!=nullptr){
        o << rg.getHuespedes()[i]->getNombre() << " - " << rg.getHuespedes()[i]->getEmail();
        if(rg.getHuespedes()[i]->getEsFinger()) 
            o << " - es Finger";
        else 
            o << " - no es Finger";
        o << "," << endl << "           ";
        i++;
    }
    o << endl;
    return o;
};

ostream& operator<<(ostream& o, DTReserva &reserva){
    if(dynamic_cast<DTReservaIndividual*>(&reserva) != 0){
        DTReservaIndividual &individual = dynamic_cast<DTReservaIndividual&>(reserva);
        o << individual;
        o << "***********************************" << endl;
    }
    else if(dynamic_cast<DTReservaGrupal*>(&reserva) != 0){
        DTReservaGrupal &grupal = dynamic_cast<DTReservaGrupal&>(reserva);
        o << grupal;
        o << "***********************************" << endl;
    };
    return o;
};

DTHostal::DTHostal(){

};

DTHostal::DTHostal(string nombre, string direccion, string telefono, float promedioClasi, set<DTCalificacion*> caliHabi){
    this->nombre=nombre;
    this->direccion=direccion;
    this->telefono=telefono;
    this->promedioClasi=promedioClasi;
    this->caliHabi=caliHabi;
};

string DTHostal::getNombre(){
    return this->nombre;
};

string DTHostal::getTelefono(){
    return this->telefono;
};

string DTHostal::getDireccion(){
    return this->direccion;
};

float DTHostal::getPromedioClasi(){
    return this->promedioClasi;
};

set<DTCalificacion*> DTHostal::getCaliHabi(){
    return this->caliHabi;
};

DTCalificacion::DTCalificacion(){

};

DTCalificacion::DTCalificacion(int valor, string comentario, DTFecha* fecha, int habitacion, string estadia){
    this->valor=valor;
    this->comentario=comentario;
    this->fecha=fecha;
    this->habitacion=habitacion;
    this->estadia=estadia;
};

int DTCalificacion::getValor(){
    return this->valor;
};

string DTCalificacion::getComentario(){
    return this->comentario;
};

DTFecha* DTCalificacion::getFecha(){
    return this->fecha;
};

int DTCalificacion::getHabitacion(){
    return this->habitacion;
};

string DTCalificacion::getEstadia(){
    return this->estadia;
};

DataR::DataR(){};

DataR::DataR(string hostal, DTFecha checkIn, DTFecha checkOut, bool esGrupal){
    this->hostal = hostal;
    this->checkIn = checkIn;
    this->checkOut = checkOut;
    this->esGrupal = esGrupal;
};

string DataR::getHostal(){
    return this->hostal;
};

DTFecha DataR::getCheckIn(){
    return this->checkIn;
};

DTFecha DataR::getCheckOut(){
    return this->checkOut;
};

bool DataR::getEsGrupal(){
    return this->esGrupal;
};

DTRespuestaCalificacion::DTRespuestaCalificacion(string comentario){
    this->comentario = comentario;
};

string DTRespuestaCalificacion::getComentario(){
    return this->comentario;
};

DTEstadia::DTEstadia(string promo, DTFecha checkIn, DTFecha checkOut){
    this->promo = promo;
    this->checkIn = checkIn;
    this->checkOut = checkOut;
};

string DTEstadia::getPromo(){
    return this->promo;
};

DTFecha DTEstadia::getCheckIn(){
    return this->checkIn;
};

DTFecha DTEstadia::getCheckOut(){
    return this->checkOut;
};

int diasEntre(DTFecha* start, DTFecha* end){
    int diascIn = start->getDia() + ((start->getMes() - 1 ) * 31) + (start->getAnio() * 372);
    int diascOut = end->getDia() + ((end->getMes() - 1) * 31) + (end->getAnio() * 372);
    return diascOut - diascIn + 1;
}