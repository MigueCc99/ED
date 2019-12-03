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

  stack<T> pila;
  stack<T> pila_aux;

public:

  void insertar (T elemento){
    pila.push(elemento);
  }

  void moverIzquierda (){
    pila.push(pila_aux.top());
    pila_aux.pop();
  }

  void moverDerecha (){
    pila_aux.push(pila.top());
    pila.pop();
  }

  void eliminar (){
    pila.pop();
  }

  void mostrarIzquierda (){
    while(!pila.empty()){
      cout << pila.top() << endl;
      pila.pop();
    }
  }

  void mostrarDerecha (){
    while(!pila_aux.empty()){
      cout << pila_aux.top() << endl;
      pila_aux.pop();
    }
  }
};

int main (int argc, char *argv[]){
  Ventana<char> caracteres;

  caracteres.insertar('e');
	caracteres.insertar('p');
	caracteres.insertar('e');
	caracteres.insertar('p');

	cout << "Izquierda: \n";
	caracteres.mostrarIzquierda();

	caracteres.insertar('e');
	caracteres.insertar('p');
	caracteres.insertar('e');
	caracteres.insertar('p');

	caracteres.moverDerecha();
	caracteres.moverIzquierda();

	cout << "Izquierda: \n";
	caracteres.mostrarIzquierda();
	cout << "Derecha: \n";
	caracteres.mostrarDerecha();

	caracteres.insertar('e');
	caracteres.insertar('p');
	caracteres.insertar('e');
	caracteres.insertar('p');

	caracteres.eliminar();

	cout << "Izquierda: \n";
	caracteres.mostrarIzquierda();


	return(0);

}
