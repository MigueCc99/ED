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
  * Una instancia @e ingr del tipo de datos abstracto @c Receta es un objeto
  * que representa una Receta. A su vez, esta Receta se compone de un código que la representa
  * únicamente, un entero que representa el tipo de plato que compone (1º,2º,3º), un nombre,
  * una lista de ingredientes y finalmente una secuencia de float que determinan las calorias,
  * hidratos de carbono, grasas, proteinas y fibras de la receta
  * 
  * Lo representamos como
  * 
  * code, plato, nombre, ingredientes, calorias, hc, grasas, proteinas, fibra
  * 
  * Un ejemplo de su uso:
  * @include test_receta.cpp
  * 
  * @author Miguel Ángel Campos Cubillas
  * @date Octubre 2019 
  */ 

class Receta{
private:
/**
  * @page repReceta Rep del TDA Receta
  * 
  * @section invReceta Invariante de la representación
  * 
  * El invariante es \e  code, plato, nombre, ings, calorias, hc, grasas, proteinas,fibra
  * que representan la invariante de Receta
  * 
  * @section faReceta Función de abstracción
  * 
  * Un objeto válido @e rep del TDA Receta representa al valor
  * 
  * {code, plato, nombre, ings, calorias, hc, grasas, proteinas,fibra}
  */
    string code;                              /**< code */
    unsigned int plato;                       /**< plato */
    string nombre;                            /**< nombre */
    list<pair<string,unsigned int> > ings;    /**< ings */
    float calorias,hc,grasas,proteinas,fibra; /**< calorias, hc, grasas, proteinas, fibra */

public:

    /**
    * @brief Constructor por defecto de la clase
    */
    Receta();

    /**
    * @brief Constructor de la clase
    * @param code código de la receta a construir
    * @param plato entero que representa el tipo de plato a construir
    * @param nombre string que representa el nombre de la receta a construir
    * @param ings lista de ingredientes de la receta a construir
    * @return Crea la receta {code,plato,nombre,ings}
    * @pre code = "Ri" &&  1 <= rep.plato <= 3
    */
    Receta(string code, int plato, string nombre, list<pair<string,unsigned int> > ings);

    /**
     * @brief Constructor de copia de la clase
     * @param receta a copiar
     */    
    Receta(const Receta &receta);


    /**
     * @brief Sobrecarga del operador=
     * @param receta receta a igualar al objeto implícito
     */ 
    Receta & operator=(const Receta &receta);

    /**
     * @brief getNombre
     * @return Devuelve el nombre de la receta
     */
    const string getNombre() const;

    /**
     * @brief getCode
     * @return Devuelve el code de la receta
     */
    const string getCode() const;

    /**
     * @brief ningredientes
     * @return Devuelve el número de ingredientes de la receta
     */
    const int ningredientes();

    /**
     * @brief Salida de una Receta a ostream
     * @param os de salida
     * @param receta Receta a escribir
     * @post Se obtiene en \a os la receta
     * con \e {code,plato,nombre,ings}  
     */
    friend ostream &operator<<(ostream &os, const Receta &receta);

    /**
     * @brief Entrada de un Receta desde istream
     * @param is stream de entrada
     * @param receta Receta que recibe
     * @retval El Receta leído en ingrediente
     * @pre La entrada tiene el formato code;plato;nombre;ings
     * con \e code, \e plato, \e nombre, \e ings
     */
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