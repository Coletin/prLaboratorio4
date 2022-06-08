#include <iostream>
#include <string>
#include <set>
#include "../Tipos/tipos.h"

class Usuario{
    protected:
     string nombre;
     string email;
     string password;
    public:
     Usuario();
     Usuario(string, string, string);
     virtual ~Usuario() = 0;
     string getEmail();
     string getNombre();
     string getPassword();
     void setEmail(string email);
     void setNombre(string nombre);
     void setPassword(string password);
};