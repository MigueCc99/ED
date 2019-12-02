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

#include "receta.h"

/**
  * @brief T.D.A Recetas
  *  
  * Una instancia @e ingr del tipo de datos abstracto @c Recetas representa un conjunto de 
  * recetas.
  * 
  * Lo representamos como
  * 
  * datos
  * 
  * Un ejemplo de su uso:
  * @include test_recetas.cpp
  * 
  * @author Miguel Ángel Campos Cubillas
  * @date Noviembre 2019 
  */ 

class Recetas{
private:
/**
  * @page repReceta Rep del TDA Recetas
  * 
  * @section invRecetas Invariante de la representación
  * 
  * El invariante es \e  datos, un vector dinamico
  * 
  * @section faRecetas Función de abstracción
  * 
  * Un objeto válido @e rep del TDA Recetas representa al valor
  * 
  * {datos}
  */
    map<string,Receta> datos;
public:

  /**
    * @brief Constructor por defecto de la clase
    */
  Recetas();

  /**
    * @brief Constructor de la clase
    * @param datos un map que representa una clave unívoca y una receta asociada
    * @return Crea Recetas {datos}
    */
  Recetas(map<string,Receta> datos);

  /**
     * @brief Constructor de copia de la clase
     * @param recetas a copiar
     */    
  Recetas(const Recetas &recetas);

  /**
    * @brief size
    * @return Devuelve el número de recetas 
    */
  const int size();

   /**
     * @brief borrar
     * @param key clave que referencia a la receta a borrar
     * @return elimina la receta asociada a la clave key
     */
  void borrar(const string key);

  /**
     * @brief Sobrecarga del operador=
     * @param recetas recetas a igualar al objeto implícito
     */ 
  Recetas & operator=(const Recetas &recetas);

    /**
     * @brief Sobrecarga del operador[]
     * @param key clave asociada a la receta a devolver
     * @return devuelve la receta asociada a la clave key
     */ 
  Receta & operator[](const string key);

    /**
     * @brief Salida de Recetas a ostream
     * @param os de salida
     * @param recetas Recetas a escribir
     * @post Se obtiene en \a os la recetas
     * con \e {datos}  
     */
  friend ostream &operator<<(ostream &os, const Recetas &recetas);

    /**
     * @brief Entrada de Recetas desde istream
     * @param is stream de entrada
     * @param recetas Recetas que recibe
     * @retval Las Recetas leído en ingrediente
     * @pre La entrada tiene el formato datos
     * con \e datos
     */
  friend istream &operator>>(istream &is, Recetas &recetas);


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
