/**
  * @file ingrediente.h
  * @brief Fichero cabecera del TDA Ingrediente
  * 
  */

#ifndef _INGREDIENTE_H_
#define _INGREDIENTE_H_

#include <iostream>
#include <string>
using namespace std;

/**
  * @brief T.D.A Ingrediente
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

class Ingrediente{
private:
/**
  * @page repIngrediente Rep del TDA Ingrediente
  * 
  * @section invIngrediente Invariante de la representación
  * 
  * El invariante es \e 0 <= rep.hidratos <= 100
  *                  \e 0 <= rep.proteinas <= 100
  *                  \e 0 <= rep.grasas <= 100
  *                  \e 0 <= rep.fibras <= 100
  * 
  * @section faIngrediente Función de abstracción
  * 
  * Un objeto válido @e rep del TDA Ingrediente representa al valor
  * 
  * {Nombre, Calorias, Hidratos, Proteinas, Grasas, Fibras, Tipo}
  */

    string nombre; /**< nombre */
    int calorias;  /**< calorias */
    int hidratos;  /**< hidratos */
    int proteinas; /**< proteinas */
    int grasas;    /**< grasas */
    int fibras;    /**< fibras */
    string tipo;   /**< tipo */

   /**
    * @brief Método privado Copiar. Copia los datos miembro de ingrediente en los del objeto implícito
    * @param ingrediente.nombre
    * @param ingrediente.calorias
    * @param ingrediente.hidratos
    * @param ingrediente.proteinas
    * @param ingrediente.grasas
    * @param ingrediente.fibras
    * @param ingrediente.tipo
    */
    void copiar(const Ingrediente &ingrediente);

public:

    /**
    * @brief Constructor por defecto de la clase. Crea el ingrediente {"nulo",0,0,0,0,0,"nulo"}
    */
    Ingrediente();

    /**
    * @brief Constructor de la clase
    * @param nombre nombre del ingrediente a construir
    * @param calorias cantidad de calorias del ingrediente a construir
    * @param hidratos cantidad de hidratos del ingrediente a construir
    * @param proteinas cantidad de proteinas del ingrediente a construir
    * @param grasas cantidad de grasas del ingrediente a construir
    * @param fibras cantidad de fibras del ingrediente a construir
    * @param tipo tipo de ingrediente del ingrediente a construir
    * @return Crea el ingrediente {nombre,calorias,hidratos,proteinas,grasas,fibras,tipo}
    * @pre 0 <= rep.hidratos <= 100 &&  0 <= rep.proteinas <= 100 && 0 <= rep.grasas <= 100 && 0 <= rep.fibras <= 100
    */
    Ingrediente(string nombre, int calorias, int hidratos, int proteinas, int grasas, int fibras, string tipo);
    
    /**
     * @brief Constructor de copia de la clase
     * @param ingrediente a copiar
     */    
    Ingrediente(const Ingrediente &ingrediente);

    /**
     * @brief Sobrecarga del operador=
     * @param ingrediente ingrediente a igualar al objeto implícito
     */ 
    Ingrediente &operator=(const Ingrediente &ingrediente);

    /**
     * @brief getNombre
     * @return Devuelve el nombre del ingrediente
     */
    const string getNombre() const;

    /**
     * @brief getCalorias
     * @return Devuelve las calorias del ingrediente
     */
    const int getCalorias() const;

    /**
     * @brief getHidratos
     * @return Devuelve los hidratos del ingrediente
     */
    const int getHidratos() const;

    /**
     * @brief getProteinas
     * @return Devuelve las proteinas del ingrediente
     */
    const int getProteinas() const;

    /**
     * @brief getGrasas
     * @return Devuelve las grasas del ingrediente
     */
    const int getGrasas() const;

    /**
     * @brief getFibras
     * @return Devuelve las fibras del ingrediente
     */
    const int getFibras() const;

    /**
     * @brief getTipo
     * @return Devuelve el tipo de ingrediente del ingrediente
     */
    const string getTipo() const;

    /**
      * @brief setNombre
      * @param nombre nombre a asignar
      * @return Asigna al objeto implícito un nombre 
      */
    void setNombre(string nombre);

    /**
      * @brief setCalorias
      * @param calorias calorias a asignar
      * @return Asigna al objeto implícito una cantidad de calorias 
      */
    void setCalorias(int calorias);

    /**
      * @brief setHidratos
      * @param hidratos hidratos a asignar
      * @return Asigna al objeto implícito una cantidad de hidratos 
      */
    void setHidratos(int hidratos);

    /**
      * @brief setProteinas
      * @param proteinas proteinas a asignar
      * @return Asigna al objeto implícito una cantidad de proteinas
      */
    void setProteinas(int proteinas);

    /**
      * @brief setGrasas
      * @param grasas grasas a asignar
      * @return Asigna al objeto implícito una cantidad de grasas 
      */
    void setGrasas(int grasas);

    /**
      * @brief setFibras
      * @param fibras fibras a asignar
      * @return Asigna al objeto implícito una cantidad de fibras
      */
    void setFibras(int fibras);

    /**
      * @brief setTipo
      * @param tipo tipo de ingrediente a asignar
      * @return Asigna al objeto implícito un tipo de ingrediente
      */
    void setTipo(string tipo);

    /**
     * @brief Salida de un Ingrediente a ostream
     * @param os de salida
     * @param ingrediente Ingrediente a escribir
     * @post Se obtiene en \a os varias cadenas con los atributos de ingrediente
     * con \e {nombre,calorias,hidratos,proteinas,grasas,fibras,tipo}  
     */
    friend ostream &operator<<(ostream &os, const Ingrediente &ingrediente);

    /**
     * @brief Entrada de un Ingrediente desde istream
     * @param is stream de entrada
     * @param ingrediente Ingrediente que recibe
     * @retval El Ingrediente leído en ingrediente
     * @pre La entrada tiene el formato nombre;calorias;hidratos;proteinas;grasas;fibras;tipo;
     * con \e nombre, \e calorias, \e hidratos, \e proteinas, \e grasas, \e fibras, \e tipo  
     */
    friend istream &operator>>(istream &is, Ingrediente &ingrediente);

};

#endif