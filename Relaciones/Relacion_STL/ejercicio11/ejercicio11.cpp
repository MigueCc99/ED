/*
 * Ejercicio 11
 * Implementa una función a la que se le pase una lista de enteros y un entero
 * x de manera que cada vez que aparezca en una posición ese valor, se inserte
 * x-1 en la posición siguiente.
*/

#include <iostream>
#include <list>

using namespace std;

template <class T>
void funcion(list<T> &list, int x){
  list<T>::iterator siguiente;

  for(list<T>::iterator it = list.begin(); it != list.end(); ++it){
    siguiente = it;
    ++siguiente;
    if(*it == x)
      l.insert(sig,x-1);
  }
}

int main(){

	list<int> lista;

	lista.push_back(1);
	lista.push_back(2);
	lista.push_back(3);
	lista.push_back(4);
	lista.push_back(5);
	lista.push_back(6);
	lista.push_back(7);

  cout << "Lista Original: ";
  for(list<int>::iterator it = lista1.begin(); it != lista1.end(); ++it)
    cout << (*it) << " ";
  cout << endl;

  funcion(lista,5);

  cout << "Lista Resultante: ";
  for(list<int>::iterator it = lista2.begin(); it != lista2.end(); ++it)
    cout << (*it) << " ";
  cout << endl;

  return 0;
}
