/**
  * @file vector_dinamico.h
  * @brief Fichero cabecera del TDA Vector_Dinamico
  * 
  */

#ifndef _VECTOR_DINAMICO_H_
#define _VECTOR_DINAMICO_H_
/**
  * @brief T.D.A Vector_Dinamico
  *  
  * Una instancia @e vector_dinamico del tipo de datos abstracto @c Vector_Dinamico es un objeto
  * que representa un conjunto de elementos. A su vez, esta instancia Vector_Dinamico se compone de
  * un puntero a T, un numElementos y un reservados
  * 
  * Lo representamos como
  * 
  * datos
  * numElementos
  * reservados
  * 
  * Un ejemplo de su uso:
  * @include test_ingredientes.cpp
  * 
  * @author Miguel Ángel Campos Cubillas
  * @date Octubre 2019 
  */ 


template <class T>
class Vector_Dinamico{
private:
/**
  * @page repVector_Dinamico Rep del TDA Vector_Dinamico
  * 
  * @section invVector_Dinamico Invariante de la representación
  * 
  * El invariante es \e puntero *datos válido
  * 
  * @section faVector_Dinamico Función de abstracción
  * 
  * Un objeto válido @e rep del TDA Vector_Dinamico representa al valor
  * 
  * {datos, numElementos, reservados}
  */

    T *datos;
    int nelementos;
    int reservados;

public:

/**
  * @brief Constructor por defecto de la clase. Crea el Vector_Dinamico vacío
  */
Vector_Dinamico();

/**
  * @brief Constructor de la clase
  * @param n número elementos a reservar
  * @return Crea el Vector_Dinamico con un número de elementos reeservados n
  * @pre n debe considerarse: 0 <= n
  */
Vector_Dinamico(int n);

/**
  * @brief Constructor de copias de la clase
  * @param original.datos
  * @param original.numElementos número de elementos
  * @param original.reservados número de reservados
  */
Vector_Dinamico(const Vector_Dinamico &original);

/**
  * @brief Destructor de la clase
  * @return puntero de datos apunta a 0  
  */
~Vector_Dinamico();

/**
  * @brief size
  * @return Devuelve en número de reservados 
  */
int size() const;

/**
  * @brief getNumElementos
  * @return Devuelve el número de elementos ocupados del vector 
  */
int getNumElementos() const;

/**
  * @brief resize
  * @param n número de elementos a reservar
  * @return redimensiona el vector a n elementos reservados
  */
void resize(int n);

/**
  * @brief Sorbrecarga del operador[]
  * @param i entero que indica una posicion
  * @return elemento T de la posicion i 
  */
T &operator[](const int i);

/**
  * @brief Sorbrecarga constante del operador[]
  * @param i entero que indica una posicion
  * @return elemento T de la posicion i 
  */
const T &operator[](const int i) const;

/**
  * @brief Sobrecarga del operador=
  * @param original Vector_Dinamico a copiar
  * @return copia el contenido del Vector_Dinamico original
  *         en el Vector_Dinamico *this
  */
Vector_Dinamico &operator=(const Vector_Dinamico &original);

/**
  * @brief aniadeElemento
  * @param elemento elemento de tipo T a añadir
  * @return el elemento de tipo T es añadido al final del Vector_Dinamico 
  */
void aniadeElemento(const T &elemento);

/**
  * @brief borrarElemento
  * @param posicion posición del elemento a eliminar
  * @return el elemento de tipo T de la posición posición es eliminado del
  *         Vector_Dinamico 
  */
void borrarElemento(const int posicion);

/**
  * @brief modificaElemento
  * @param posicion posición del elemento a modificar
  * @param elemento elemento de tipo T para modificar
  * @return el elemento elemento es añadido en la posicion posicion del 
  *         Vector_Dinamico
  */
void modificaElemento(const int posicion, const T &elemento);

};

#include "vector_dinamico.tpp"

#endif 