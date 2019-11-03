/**
  * EJERCICIO 9
  * Un tipo ventana es un tipo de dato que permite insertar un elemento, mover derecha, mover izquierda,
  * borrar elemento y que se implementa usando dos pilas. Implementa ese tipo de dato con las operaciones
  * comentadas.
  *
  * @author Miguel Ángel Campos Cubillas
  */

#include <iostream>
#include <stack>
#include <cassert>

using namespace std;

template <class T>
class Ventana{
private:

  stack<T> izquierda;
  stack<T> derecha;

public:
  void insertar (int izd_dcha, T &elemento){
    if(izd_dcha == 0)
      izquierda.push(elemento);
    else
      derecha.push(elemento);
  }

  void borrar (int izd_dcha, int posicion){
    if(izd_dcha == 0){
      assert(posicion>=0 && posicion<=izquierda.size());
      izquierda
    }

  }

};
