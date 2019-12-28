#include "acciones.h"

  Acciones::Acciones(){}

  Acciones::Acciones(map<string,unsigned char> datos){
      this->datos = datos;
  }

  Acciones::Acciones(const Acciones &acciones){
      this->datos = acciones.datos;
  }

  Acciones & Acciones::operator=(const Acciones &acciones){
      if(this != &acciones){
          this->datos = acciones.datos;
      }
      return *this;
  }

  const int Acciones::size(){
      return datos.size();
  }

  ostream &operator<<(ostream &os, const Acciones &acciones){
      for(Acciones::const_iterator it = acciones.begin(); it != acciones.end(); ++it)
          os << (*it).first << "\t" << (*it).second << endl;

      return os;
  }

  istream &operator>>(istream &is, Acciones &acciones){
      std::pair<string,unsigned char> accion;
      Acciones::iterator i_acciones;
      string aux = "";
      const char delim= ' ';

      while(is.peek() != EOF){
          std::getline(is,accion.first,delim);
          std::getline(is,aux); 
          if(aux == "1")
            accion.second = '1';
          else if(aux == "2")
            accion.second = '2';
          acciones.datos.insert(accion);
      }

      return is;
  }

