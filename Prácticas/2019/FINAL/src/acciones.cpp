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

  ostream &operator<<(ostream &os, const Acciones &acciones){
      for(Acciones::const_iterator it = acciones.begin(); it != acciones.end(); ++it)
        os << (*it).first << "\t" << (*it).second << endl;
      return os;
  }

  istream &operator>>(istream &is, Acciones &acciones){
      std::pair<string,unsigned char> accion;
      Acciones::iterator i_acciones;
      string aux;
      const char delim= ' ';

      while(is.peek() != EOF){
          std::getline(is,accion.first,delim);
          std::getline(is,aux);
          //accion.second = stoul(aux);
          accion.second = '1';
          acciones.datos.insert(accion);
      }

      return is;
  }

