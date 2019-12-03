/**
  * EJERCICIO 7
  * Implementa una función insertar(P, pos, x) que inserte un elemento en la pila P
  * en la posicion pos. La pila debe quedar como estaba (salvo por el nuevo elemento)
  *
  * @author Miguel Ángel Campos Cubillas
  */

#include <iostream>
#include <stack>

using namespace std;

template <class T>
void insertar(stack<T> &pila, const int pos, const T elemento){
  stack<T> aux;

  for (int i=0; i<pos; i++){
    aux.push(pila.top());
    pila.pop();
  }

  pila.push(elemento);

  while(!aux.empty()){
    pila.push(aux.top());
    aux.pop();
  }
}

template <class T>
void imprime_pila(stack<T> pila){
  stack<T> aux;

  while(!pila.empty()){
    aux.push(pila.top());
    cout << pila.top() << " ";
    pila.pop();
  }
}

int main(int argc, char *argv[]){
  stack<int> pila;
  int elemento;
  int posicion;

  cout << "Introduce los elementos, utiliza '-1' para finalizar: " << endl;
  cin >> elemento;

  while(elemento != -1){
    pila.push(elemento);
    cin >> elemento;
  }

  cin.get();
  cout << "Pulsa una tecla para continuar...";
  cin.get();

  cout << "Pila Original => ";
  imprime_pila(pila);
  cout << endl;

  cout << "Pulsa una tecla para continuar...";
  cin.get();

  cout << "Indica un elemento a añadir => ";
  cin >> elemento;
  cout << endl;

  cout << "Indica la posición de la pila en la que introducir el elemento (tomando como referencia el tope de pila) => ";
  cin >> posicion;

  insertar(pila,posicion,elemento);

  cout << "Pila Modificada => ";
  imprime_pila(pila);
  cout << endl;

  return (0);
}
