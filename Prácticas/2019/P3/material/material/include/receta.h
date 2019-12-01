/**
  * @file receta.h
  * @brief Fichero cabecera del TDA Receta
  * 
  */

#ifndef _RECETA_H_
#define _RECETA_H_

#include <iostream>
#include <string>
#include <list>
using namespace std;

/**
  * @brief T.D.A Receta
  *  
  * Una instancia @e ingr del tipo de datos abstracto @c Ingrediente es un objeto
  * que representa un ingrediente. A su vez, este ingrediente se compone de dos cadenas 
  * de caracteres, un nombre y un tipo de ingrediente. Además dispone enteros que determinan
  * la cantidad de calorias, hidratos, proteinas, grasas y fibras que contiene el ingrediente.
  * 
  * Lo representamos como
  * 
  * nombre, calorías, hidratos, proteinas, grasas, fibras, tipo.
  * 
  * Un ejemplo de su uso:
  * @include test_ingredientes.cpp
  * 
  * @author Miguel Ángel Campos Cubillas
  * @date Octubre 2019 
  */ 

class Receta{
private:

    string code;
    unsigned int plato;
    string nombre;
    list<pair<string,unsigned int> > ings;
    float calorias,hc,grasas,proteinas,fibra;

public:

    Receta();

    Receta(string code, int plato, string nombre, list<pair<string,unsigned int> > ings);

    Receta(const Receta &receta);

    Receta & operator=(const Receta &receta);

    const string getNombre() const;

    const int ningredientes();

    friend ostream &operator<<(ostream &os, const Receta &receta);

    friend istream &operator>>(istream &is, Receta &receta);

    /**
      * @brief Clase para iterar sobre los ingredientes 
      */
    class iterator{
      private:
        list<pair<string, unsigned int> >::iterator it;
      public:

        iterator & operator++(){
          ++it;
          return *this;
        }

        iterator & operator--(){
          --it;
          return *this;
        }

        const pair<string, unsigned int> & operator*() const{
          return (*it);
        }

        bool operator==(const iterator &i) const{
          return i.it == it;
        }

        bool operator!=(const iterator &i) const{
          return i.it != it;
        }

        iterator & operator=(const iterator &i){
          it = i.it;
          return *this;
        }

        friend class Receta;

    };
    /**
      * @brief Clase para iterar sobre los ingredientes (modo const)
      */
    class const_iterator{
      private:
        list<pair<string, unsigned int> >::const_iterator it;
      public:

        const_iterator & operator++(){
          ++it;
          return *this;
        }

        const_iterator & operator--(){
          --it;
          return *this;
        }

        const pair<string, unsigned int> & operator*() const{
          return (*it);
        }

        bool operator==(const const_iterator &i) const{
          return i.it == it;
        }

        bool operator!=(const const_iterator &i) const{
          return i.it != it;
        }

        const_iterator & operator=(const const_iterator &i){
          it = i.it;
          return *this;
        }

        friend class Receta;

    };

    /**
      * @brief Inicializa un iterator al comienzo de Receta
      */
    iterator begin(){
      iterator i;
      i.it = ings.begin();
      return i;
    }

    /**
      * @brief Inicializa un iterator al final de Receta
      */
    iterator end(){
      iterator i;
      i.it = ings.end();
      return i;
    }

    /**
      * @brief Inicializa un const_iterator al comienzo de Receta
      */  
    const_iterator begin()const{
      const_iterator i;
      i.it = ings.begin();
      return i;
    }
    /**
      * @brief Inicializa un const_iterator al final de Receta
      */
    const_iterator end()const{
      const_iterator i;
      i.it = ings.end();
      return i;
    }

private:

void copiar(const Receta &receta);

};

#endif