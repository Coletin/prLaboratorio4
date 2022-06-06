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

DTEmpleado::DTEmpleado(string nombre, string email, string contrasena, CargoEmpleado cargo):DTUsuario(nombre, email, contrasena){
    this->cargo = cargo;
};

CargoEmpleado DTEmpleado::getCargo(){
    return this->cargo;
};

void DTEmpleado::toString(){
    cout << "[nombre: " << this->getNombre() << "; email: " << this->getEmail() << "; cargo: ";
    if(this->getCargo()==Recepcion){
        cout << "Recepcion" << "]" << endl;
    }
    else if(this->getCargo()==Administracion){
        cout << "Administracion" << "]" << endl;
    }
    else if(this->getCargo()==Limpieza){
        cout << "Limpieza" << "]" << endl;
    }
    else if(this->getCargo()==Infraestructura){
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

