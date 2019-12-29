/**
  * @file acciones.h
  * @brief Fichero cabecera del TDA Acciones
  * 
  */

#ifndef _ACCIONES_H
#define _ACCIONES_H

#include <iostream>
#include <cstring>
#include <map>
using namespace std;

class Acciones{
private:
  map<string, unsigned char > datos;
public:

  /**
    * @brief Constructor por defecto de la clase
    */
  Acciones();

  /**
    * @brief Constructor de la clase
    * @param datos un map que representa una clave unívoca y una accion asociada
    * @return Crea Acciones {datos}
    */
  Acciones(map<string, unsigned char > datos);

  /**
    * @brief Constructor de copia de la clase
    * @param acciones a copiar
    */    
  Acciones(const Acciones &acciones);

  int getAriedad(string accion);

  /**
    * @brief Sobrecarga del operador=
    * @param acciones acciones a igualar al objeto implícito
    */ 
  Acciones & operator=(const Acciones &acciones);

  /**
    * @brief Salida de Acciones a ostream
    * @param os de salida
    * @param acciones Acciones a escribir
    * @post Se obtiene en \a os la acciones
    * con \e {datos}  
    */
  friend ostream &operator<<(ostream &os, const Acciones &acciones);

  /**
    * @brief Entrada de Acciones desde istream
    * @param is stream de entrada
    * @param acciones Acciones que recibe
    * @retval Las Acciones leído en acciones
    * @pre La entrada tiene el formato datos
    * con \e datos
    */
  friend istream &operator>>(istream &is, Acciones &acciones);

  /**
    * @brief Clase para iterar sobre las acciones 
    */
  class iterator{
    private:
      map<string,unsigned char>::iterator it;
    public:

      iterator & operator++(){
        ++it;
        return *this;
      }

      iterator & operator--(){
        --it;
        return *this;
      }

      pair<const string,unsigned char > & operator*(){
        return (*it);
      }

      bool operator==(const iterator &i){
        return i.it == it;
      }

      bool operator!=(const iterator &i){
        return i.it != it;
      }

      iterator & operator=(const iterator &i){
        it = i.it;
        return *this;
      }
      friend class Acciones;
  };

  /**
    * @brief Clase para iterar sobre las acciones 
    */
  class const_iterator{
    private:
      map<string,unsigned char>::const_iterator it;
    public:

      const_iterator & operator++(){
        ++it;
        return *this;
      }

      const_iterator & operator--(){
        --it;
        return *this;
      }

      const pair<const string,unsigned char > & operator*(){
        return (*it);
      }

      bool operator==(const const_iterator &i){
        return i.it == it;
      }

      bool operator!=(const const_iterator &i){
        return i.it != it;
      }

      const_iterator & operator=(const const_iterator &i){
        it = i.it;
        return *this;
      }
      friend class Acciones;
  };

  /**
    * @brief Inicializa un iterator al comienzo de Acciones
    */  
  iterator begin(){
    iterator i;
    i.it = datos.begin();
    return i;
  }

  /**
    * @brief Inicializa un iterator al final de Acciones
    */  
  iterator end(){
    iterator i;
    i.it = datos.end();
    return i;
  }

  /**
    * @brief Inicializa un const_iterator al comienzo de Acciones
    */  
  const_iterator begin()const{
    const_iterator i;
    i.it = datos.begin();
    return i;
  }

  /**
    * @brief Inicializa un const_iterator al final de Acciones
    */  
  const_iterator end()const{
    const_iterator i;
    i.it = datos.end();
    return i;
  }

};

#endif /* _ACCIONES_H */