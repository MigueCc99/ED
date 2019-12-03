/*
 * Ejercicio 13
 * Tenemos dos listas: l, que contiene n elementos y otra li que contiene una
 * serie de posiciones de la lista anterior (valores de la clase iterador).
 * Construye una función a la que se le pasen esas dos listas y devuelva otra
 * que contenga los elementos de l indicados por las posiciones de la lista li.
*/

#include <iostream>
#include <list>

using namespace std;

template <class T>
T get_elemento(int pos, list<T> l){
  list<T>::iterator it;
  for(int i = 0; i < pos; i++)
    ++it;
  return *it;
}

template <class T>
list<T> obtener_lista(list<T> &l, list<T> &li){
  list<T> lista_res;
  for(list<T>::iterator it = li.begin(); it != li.end(); ++it){
    if(*it < l.size())
      lista_res.push_back(get_elemento(*it,l));
    else
      cout << "La posicion " << *it << " no es correcta" << endl;
  }
  return lista_res;
}

int main(){

  list<int>lista1,lista2, lista_resultante;

  lista1.push_back(3);
  lista1.push_back(1);
  lista1.push_back(3);
  lista1.push_back(1);
  lista1.push_back(7);
  lista1.push_back(3);
  lista1.push_back(5);
  lista1.push_back(4);
  lista1.push_back(0);

  lista2.push_back(2);
  lista2.push_back(4);
  lista2.push_back(5);
  lista2.push_back(2);
  lista2.push_back(1);

  cout << "Lista de valores: ";
  for(list<int>::iterator it = lista1.begin(); it != lista1.end(); ++it)
    cout << (*it) << " ";
  cout << endl;

  cout << "Lista de posiciones: ";
  for(list<int>::iterator it = lista2.begin(); it != lista2.end(); ++it)
    cout << (*it) << " ";
  cout << endl;

  lista_resultante = obtener_lista(lista1,lista2);

  cout << "Lista resultante: ";
  for(list<int>::iterator it = lista_resultante.begin(); it != lista_resultante.end(); ++it)
    cout << (*it) << " ";
  cout << endl;


}
