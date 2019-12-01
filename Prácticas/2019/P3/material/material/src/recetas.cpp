#include "recetas.h"

  Recetas::Recetas(){}

  Recetas::Recetas(map<string,Receta> datos){
      this->datos = datos;
  }

  Recetas::Recetas(const Recetas &recetas){
      this->datos = recetas.datos;
  }

  const int Recetas::size(){
      return datos.size();
  }

  Receta & Recetas::operator[](const string key){
      return datos[key];
  }

  Recetas & Recetas::operator=(const Recetas &recetas){
      if(this != &recetas){
          this->datos = recetas.datos;
      }
      return *this;
  }

  ostream &operator<<(ostream &os, const Recetas &recetas){
      for(Recetas::const_iterator it = recetas.begin(); it != recetas.end(); ++it)
        os << (*it) << endl;
      return os;
  }

  istream &operator>>(istream &is, Recetas &recetas){
      Receta auxiliar;
      Receta::iterator i_receta;

      while (is.peek() != EOF){
          is >> auxiliar; 
          i_receta = auxiliar.begin();
          recetas.datos.insert(std::pair<string,Receta>(auxiliar.getCode(),auxiliar));
          cout << auxiliar.getCode() << endl;
      }

      return is;
  }