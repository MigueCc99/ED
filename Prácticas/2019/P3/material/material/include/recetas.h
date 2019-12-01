/**
  * @file recetas.h
  * @brief Fichero cabecera del TDA Recetas
  * 
  */

#ifndef _RECETAS_H_
#define _RECETAS_H_

#include "receta.h"
#include <string>
#include <map>
using namespace std;

/**
  * @brief T.D.A Recetas
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

class Recetas{
private:
    map<string,Receta> datos;
public:

    /**
      * @brief Clase para iterar sobre los ingredientes 
      */
    class iterator{
        private:
            map<string,Receta>::iterator it;
        public:
          
          iterator & operator++(){
            ++it;
            return *this;
          }

          iterator & operator--(){
            --it;
            return *this;
          }

          Receta & operator*(){
            return (*it).second;
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

          friend class Recetas;
    };
    /**
      * @brief Clase para iterar sobre los ingredientes (modo const)
      */
    class const_iterator{
        private:
            map<string,Receta>::const_iterator it;  
        public:
          
          const_iterator & operator++(){
            ++it;
            return *this;
          }

          const_iterator & operator--(){
            --it;
            return *this;
          }

          const Receta & operator*()const{
            return (*it).second;
          }

          bool operator==(const const_iterator &i)const{
            return i.it == it;
          }

          bool operator!=(const const_iterator &i)const{
          return i.it != it;
          }

          const_iterator & operator=(const const_iterator &i){
            it = i.it;
            return *this;
          }

          friend class Recetas;        
    };

    /**
      * @brief Inicializa un iterator al comienzo de Receta
      */
    iterator begin(){
        iterator i;
        i.it = datos.begin();
        return i;
    }

    /**
      * @brief Inicializa un iterator al final de Receta
      */
    iterator end(){
        iterator i;
        i.it = datos.end();
        return i;
    }

    /**
      * @brief Inicializa un const_iterator al comienzo de Receta
      */  
    const_iterator begin()const{
        const_iterator i;
        i.it = datos.begin();
        return i;
    }
    /**
      * @brief Inicializa un const_iterator al final de Receta
      */
    const_iterator end()const{
        const_iterator i;
        i.it = datos.end();
        return i;
    }
};

#endif
