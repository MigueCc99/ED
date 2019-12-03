/*
 * Ejercicio 8
 * Implementa una función que dada una lista l devuelva una lista que tenga los
 * elementos de l pero en orden inverso.
*/

#include <iostream>
#include <list>

using namespace std;

template <class T>
lista<T> invertir_lista(list<T> list){

  list<T> lista_invertida;

  for(list<T>::iterator it = --list.end(); it != list.begin(); --it)
    lista_invertida.push_back(*it);

  lista_invertida.push_back(*it);

  return lista_invertida;
}

int main(void){

  list<int> lista_original;
  list<int> lista_invertida;

  lista_original.push_back(1);
  lista_original.push_back(2);
  lista_original.push_back(3);
  lista_original.push_back(4);
  lista_original.push_back(5);
  lista_original.push_back(6);

  lista_invertida = invertir_lista(lista_original);

  cout << "Lista inicial: ";
  for(list<int>::iterator it = lista_original.begin(); it != lista_original.end(); ++it)
    cout << (*it) << " ";
  cout << endl;

  cout << "Lista Invertida: ";
  for(list<int>::iterator it = lista_invertida.begin(); it != lista_invertida.end(); ++it)
    cout << (*it) << " ";
  cout << endl;

}
